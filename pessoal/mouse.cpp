#include "mouse.h"

Mouse::Mouse() {
    mouse = new Model3DS("../3ds/mouse.3ds");
}

Mouse::~Mouse() {
    delete mouse;
}

void Mouse::desenha() {
    Cubo c = Cubo();

    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glTranslatef(0, 0.04, 0);
            glRotatef(-90, 1, 0, 0);
            glScalef(0.01, 0.01, 0.01);
            mouse->draw();
        glPopMatrix();
        if (this->selecionado) {
            glPushMatrix();
                GUI::setColor(0, 1, 0, 0.6);
                glScalef(0.2, 0.1, 0.3);
                c.desenha();
            glPopMatrix();
        }
    glPopMatrix();
}
