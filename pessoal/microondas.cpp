#include "microondas.h"

Microondas::Microondas() {
    microondas = new Model3DS("../3ds/microondas.3ds");
}

Microondas::Microondas(Vetor3D t, Vetor3D r, Vetor3D e) : Objeto(t, r, e) {
    microondas = new Model3DS("../3ds/microondas.3ds");
}

Microondas::~Microondas() {
    delete microondas;
}

void Microondas::desenha() {
    Cubo c = Cubo();

    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glTranslatef(0, 0.38, 0);
            glRotatef(-90, 1, 0, 0);
            glScalef(0.03, 0.03, 0.03);
            microondas->draw();
        glPopMatrix();
        glPushMatrix();
            GUI::setColor(0.08, 0.08, 0.08);
            glTranslatef(0.52, 0.12, 0.38);
            glScalef(0.23, 0.48, 0.05);
            c.desenha();
        glPopMatrix();
        glPushMatrix();
            GUI::setColor(0.5, 0.5, 0.5, 0.8);
            glTranslatef(-0.15, 0.12, 0.35);
            glScalef(0.8, 0.48, 0.05);
            c.desenha();
        glPopMatrix();
        if (this->selecionado) {
            GUI::setColor(0, 1, 0, 0.5);
            glScalef(1.4, 0.77, 0.9);
            c.desenha();
        }
    glPopMatrix();
}
