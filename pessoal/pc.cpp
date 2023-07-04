#include "pc.h"

Pc::Pc() {
    pc = new Model3DS("../3ds/pc.3DS");
}

Pc::Pc(Vetor3D t, Vetor3D r, Vetor3D e) : Objeto(t, r, e) {
    pc = new Model3DS("../3ds/pc.3DS");
}

Pc::~Pc() {
    delete pc;
}

void Pc::desenha() {
    Cubo c = Cubo();
    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glTranslatef(0, 0.45, 0);
            glRotatef(90, 1, 0, 0);
            glRotatef(102.5, 0, 0, 1);
            glScalef(0.005, 0.005, 0.005);
            pc->draw();
        glPopMatrix();
        if (this->selecionado) {
            glPushMatrix();
                GUI::setColor(0, 1, 0, 0.6);
                glTranslatef(0, -0.05, 0);
                glScalef(0.5, 1, 1);
                c.desenha();
            glPopMatrix();
        }
    glPopMatrix();
}
