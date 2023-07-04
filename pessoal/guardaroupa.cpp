#include "guardaroupa.h"

GuardaRoupa::GuardaRoupa() {
}

GuardaRoupa::GuardaRoupa(Vetor3D t, Vetor3D r, Vetor3D e) : Objeto(t, r, e) {
}

GuardaRoupa::~GuardaRoupa() {
}

void GuardaRoupa::desenha() {
    Shape s = Shape();
    Cubo c = Cubo();

    glPushMatrix();
        Objeto::desenha();
        glPushMatrix(); // base
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.8, 0.8, 0.8);
            glScalef(2.5, 2.5, 0.7);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // porta esquerda
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.1, 0.1, 0.1);
            glTranslatef(-0.6, 0.5, 0.35);
            glScalef(1.1, 1.9, 0.05);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // porta direita
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.1, 0.1, 0.1);
            glTranslatef(0.6, 0.5, 0.35);
            glScalef(1.1, 1.9, 0.05);
            c.desenha();
        glPopMatrix();

        glPushMatrix(); // gaveta esquerda
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.1, 0.1, 0.1);
            glTranslatef(-0.6, 0.1, 0.35);
            glScalef(1.1, 0.3, 0.05);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // gaveta direita
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.1, 0.1, 0.1);
            glTranslatef(0.6, 0.1, 0.35);
            glScalef(1.1, 0.3, 0.05);
            c.desenha();
        glPopMatrix();

        glPushMatrix(); // puxador porta esquerda
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(1, 1, 1);
            glTranslatef(-0.2, 1.2, 0.39);
            glScalef(0.1, 0.3, 0.05);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // puxador porta direita
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(1, 1, 1);
            glTranslatef(0.2, 1.2, 0.39);
            glScalef(0.1, 0.3, 0.05);
            c.desenha();
        glPopMatrix();

        glPushMatrix(); // puxador gaveta esquerda
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(1, 1, 1);
            glTranslatef(-0.45, 0.3, 0.39);
            glRotatef(90, 0, 0, 1);
            glScalef(0.06, 0.3, 0.05);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // puxador gaveta esquerda
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(1, 1, 1);
            glTranslatef(0.75, 0.3, 0.39);
            glRotatef(90, 0, 0, 1);
            glScalef(0.06, 0.3, 0.05);
            c.desenha();
        glPopMatrix();
    glPopMatrix();
}
