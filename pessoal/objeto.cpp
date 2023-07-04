#include "objeto.h"

Objeto::Objeto() {
}

Objeto::Objeto(Vetor3D t, Vetor3D r, Vetor3D e) {
    this->translacao.add(t);
    this->rotacao.add(r);
    this->escala.add(e);
}

Objeto::~Objeto() {
}

void Objeto::desenha() {
    glTranslatef(translacao.x, translacao.y, translacao.z);
    glRotatef(rotacao.z, 0, 0, 1);
    glRotatef(rotacao.y, 0, 1, 0);
    glRotatef(rotacao.x, 1, 0, 0);
    if (this->desenha_local) { GUI::drawOrigin(1); }
    glScalef(escala.x, escala.y, escala.z);
}
