#include "cama.h"

Cama::Cama() {
}

Cama::Cama(Vetor3D t, Vetor3D r, Vetor3D e) : Objeto(t, r, e) {
}

Cama::~Cama() {
}

void Cama::cama_solteiro() {
    Cubo c = Cubo();

    glPushMatrix();
//        Objeto::desenha();
        glPushMatrix(); // colchao
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.5, 0, 0);
            glTranslatef(0, 0.15, 0);
            glScalef(2, 0.25, 1);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // base
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(1, 1, 1);
            glScalef(2, 0.15, 1);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // travesseiro
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(1, 1, 1);
            glTranslatef(0.7, 0.35, 0);
            glScalef(0.5, 0.15, 0.7);
            c.desenha();
        glPopMatrix();
    glPopMatrix();
}

void Cama::desenha() {
    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glTranslatef(0, 0, 0.49);
            cama_solteiro();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0, 0, -0.49);
            cama_solteiro();
        glPopMatrix();
    glPopMatrix();
}
