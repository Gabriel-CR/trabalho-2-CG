#include "escorregador.h"

Escorregador::Escorregador() {
}

Escorregador::Escorregador(Vetor3D t, Vetor3D r, Vetor3D e) : Objeto(t, r, e) {
}

Escorregador::~Escorregador() {
}

void Escorregador::desenha() {
    Cubo c = Cubo();

    glPushMatrix();
        Objeto::desenha();
        glPushMatrix(); // TAMPO
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.58, 0.29, 0);
            glTranslatef(0, 1.3, 0);
            glScalef(1.8, 0.1, 1.8);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // PE FRENTE DIREITA
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.8, 0.8, 0.8);
            glTranslatef(0.7, 0, 0.7);
            glScalef(0.15, 3, 0.15);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // PE FRENTE ESQUERDA
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.8, 0.8, 0.8);
            glTranslatef(-0.7, 0, 0.7);
            glScalef(0.15, 3, 0.15);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // PE TRAS DIREITA
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.8, 0.8, 0.8);
            glTranslatef(0.7, 0, -0.7);
            glScalef(0.15, 3, 0.15);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // PE TRAS ESQUERDA
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.8, 0.8, 0.8);
            glTranslatef(-0.7, 0, -0.7);
            glScalef(0.15, 3, 0.15);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // ESCORREGADOR
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.58, 0.29, 0);
            glTranslatef(0, 0.6, 1.6);
            glRotatef(40, 1, 0, 0);
            glScalef(0.7, 0.1, 2.1);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // TETO DIREITO
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.58, 0.29, 0);
            glTranslatef(0.6, 3.1, 0);
            glRotatef(-45, 0, 0, 1);
            glScalef(1.8, 0.1, 1.8);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // TETO ESQUERDO
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.58, 0.29, 0);
            glTranslatef(-0.6, 3.1, 0);
            glRotatef(45, 0, 0, 1);
            glScalef(1.8, 0.1, 1.8);
            c.desenha();
        glPopMatrix();
    glPopMatrix();
}
