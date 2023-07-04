#include "pia.h"

Pia::Pia() {
}

Pia::Pia(Vetor3D t, Vetor3D r, Vetor3D e) : Objeto(t, r, e) {
}

Pia::~Pia() {
}

void Pia::desenha() {
    Cubo c = Cubo();

    glPushMatrix();
        Objeto::desenha();
        glPushMatrix(); // BASE
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.7, 0.7, 0.7);
            glScalef(0.7, 0.1, 0.7);
            c.desenha();
        glPopMatrix();
        glPushMatrix();
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.7, 0.7, 0.7);
            glTranslatef(0, 0.2, 0.25);
            glRotatef(90, 1, 0, 0);
            glScalef(0.7, 0.1, 0.25);
            c.desenha();
        glPopMatrix();
        glPushMatrix();
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.7, 0.7, 0.7);
            glTranslatef(0, 0.2, -0.35);
            glRotatef(90, 1, 0, 0);
            glScalef(0.7, 0.1, 0.25);
            c.desenha();
        glPopMatrix();
        glPushMatrix();
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.7, 0.7, 0.7);
            glTranslatef(0.25, 0.2, 0);
            glRotatef(90, 0, 1, 0);
            glRotatef(90, 1, 0, 0);
            glScalef(0.7, 0.1, 0.25);
            c.desenha();
        glPopMatrix();
        glPushMatrix();
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.7, 0.7, 0.7);
            glTranslatef(-0.35, 0.2, 0);
            glRotatef(90, 0, 1, 0);
            glRotatef(90, 1, 0, 0);
            glScalef(0.7, 0.1, 0.25);
            c.desenha();
        glPopMatrix();
        glPushMatrix();
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.7, 0.7, 0.7);
            glTranslatef(-0.35, 0.4, 0);
            glRotatef(90, 0, 1, 0);
            glRotatef(90, 1, 0, 0);
            glScalef(0.1, 0.1, 0.55);
            c.desenha();
        glPopMatrix();
        glPushMatrix();
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.7, 0.7, 0.7);
            glTranslatef(-0.15, 0.5, 0);
            glRotatef(90, 0, 1, 0);
            glScalef(0.1, 0.1, 0.35);
            c.desenha();
        glPopMatrix();
    glPopMatrix();
}
