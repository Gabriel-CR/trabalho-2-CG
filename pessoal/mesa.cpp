#include "mesa.h"

Mesa::Mesa() {
}

Mesa::Mesa(Vetor3D t, Vetor3D r, Vetor3D e) : Objeto(t, r, e) {
}

Mesa::~Mesa() {
}

void Mesa::desenha() {
    Cubo c = Cubo();

    glPushMatrix();
        Objeto::desenha();
        glPushMatrix(); // TAMPO
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.08, 0.08, 0.08);
            glTranslatef(0, 1, 0);
            glScalef(2.2, 0.2, 2.2);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // PE FRENTE DIREITA
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.8, 0.8, 0.8);
            glTranslatef(0.9, 0, 0.9);
            glScalef(0.2, 1, 0.2);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // PE FRENTE ESQUERDA
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.8, 0.8, 0.8);
            glTranslatef(-0.9, 0, 0.9);
            glScalef(0.2, 1, 0.2);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // PE TRAS DIREITA
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.8, 0.8, 0.8);
            glTranslatef(0.9, 0, -0.9);
            glScalef(0.2, 1, 0.2);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // PE TRAS ESQUERDA
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.8, 0.8, 0.8);
            glTranslatef(-0.9, 0, -0.9);
            glScalef(0.2, 1, 0.2);
            c.desenha();
        glPopMatrix();
    glPopMatrix();
}
