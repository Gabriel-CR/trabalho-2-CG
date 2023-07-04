#include "chuveiro.h"

Chuveiro::Chuveiro() {
    chuveiro = new Model3DS("../3ds/chuveiro.3DS");
}

Chuveiro::Chuveiro(Vetor3D t, Vetor3D r, Vetor3D e) : Objeto(t, r, e) {
    chuveiro = new Model3DS("../3ds/chuveiro.3DS");
}

Chuveiro::~Chuveiro() {
    delete chuveiro;
}

void Chuveiro::desenha() {
    Cubo c = Cubo();

    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glTranslatef(0, 1.5, 0);
            glRotatef(90, 0, 1, 0);
            glRotatef(-90, 1, 0, 0);
            glScalef(0.03, 0.03, 0.03);
            chuveiro->draw();
        glPopMatrix();
        if (this->selecionado) {
            glPushMatrix();
                GUI::setColor(0, 1, 0, 0.5);
                glTranslatef(0, 0, 0.35);
                glScalef(0.5, 1.7, 0.8);
                c.desenha();
            glPopMatrix();
        }
    glPopMatrix();
}
