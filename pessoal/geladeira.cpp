#include "geladeira.h"

Geladeira::Geladeira() {
    geladeira = new Model3DS("../3ds/geladeira.3DS");
}

Geladeira::Geladeira(Vetor3D t, Vetor3D r, Vetor3D e) : Objeto(t, r, e) {
    geladeira = new Model3DS("../3ds/geladeira.3DS");
}

Geladeira::~Geladeira() {
    delete geladeira;
}

void Geladeira::desenha() {
    Cubo c = Cubo();

    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glScalef(0.85, 0.85, 0.85);
            glPushMatrix();
                glScalef(1, 1, 1.2);
                glRotatef(-90, 1, 0, 0);
                glScalef(0.04, 0.04, 0.04);
                geladeira->draw();
            glPopMatrix();
            if (this->selecionado) {
                GUI::setColor(0, 1, 0, 0.5);
                glScalef(1.5, 2.8, 1.5);
                c.desenha();
            }
        glPopMatrix();
    glPopMatrix();
}
