#include "parede.h"

Parede::Parede() {
}

Parede::Parede(Vetor3D t, Vetor3D r, Vetor3D e) : Objeto(t, r, e) {
}

Parede::~Parede() {
}

void Parede::desenha() {
    Cubo c = Cubo();

    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glTranslatef(-3, 0, 0);
            glPushMatrix(); // PAREDE ESQUERDA
                (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(1, 1, 1);
                glTranslatef(-1.5, 0, -4);
                glScalef(0.05, 2.5, 5);
                c.desenha();
            glPopMatrix();
            glPushMatrix(); // CHAO
                (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.9, 0.9, 0.9);
                glTranslatef(3, 0, 0);
                glScalef(9, 0.05, 13);
                c.desenha();
            glPopMatrix();
            glPushMatrix(); // PAREDE DIREITA
                (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(1, 1, 1);
                glTranslatef(7.5, 0, 0);
                glScalef(0.05, 2.5, 13);
                c.desenha();
            glPopMatrix();
            glPushMatrix(); // PAREDE FRENTE
                glTranslatef(3, 0, 6.5);
                glRotatef(90, 0, 1, 0);
                glScalef(0.05, 2.5, 9);
                c.desenha();
            glPopMatrix();
            glPushMatrix(); // PAREDE TRAS
                glTranslatef(3, 0, -6.5);
                glRotatef(90, 0, 1, 0);
                glScalef(0.05, 2.5, 9);
                c.desenha();
            glPopMatrix();
            glPushMatrix(); // PAREDE COZINHA SALA
                glTranslatef(1, 0, -3.5);
                glRotatef(90, 0, 1, 0);
                glScalef(0.05, 2.5, 5);
                c.desenha();
            glPopMatrix();
            glPushMatrix(); // PAREDE SALA QUARTO
                glTranslatef(1, 0, 1.5);
                glRotatef(90, 0, 1, 0);
                glScalef(0.05, 2.5, 5);
                c.desenha();
            glPopMatrix();
            glPushMatrix(); // PAREDE BANHEIRO
                glTranslatef(5.5, 0, 1.5);
                glRotatef(90, 0, 1, 0);
                glScalef(0.05, 2.5, 2);
                c.desenha();
            glPopMatrix();
            glPushMatrix(); // PAREDE QUARTO BANHEIRO
                glTranslatef(4.5, 0, 4);
                glScalef(0.05, 2.5, 5);
                c.desenha();
            glPopMatrix();
            glPushMatrix(); // VIDRO PORTA QUARTO
                (this->selecionado) ? GUI::setColor(0, 1, 0, 0.5) : GUI::setColor(1, 1, 1, 0.5);
                glTranslatef(-1.5, 0, 5.2);
                glScalef(0.05, 2.5, 2.7);
                c.desenha();
            glPopMatrix();
            glPushMatrix(); // VIDRO PORTA QUARTO
                (this->selecionado) ? GUI::setColor(0, 1, 0, 0.5) : GUI::setColor(1, 1, 1, 0.5);
                glTranslatef(-1.55, 0, 2.8);
                glScalef(0.05, 2.5, 2.7);
                c.desenha();
            glPopMatrix();
            glPushMatrix(); // VIDRO PORTA SALA
                (this->selecionado) ? GUI::setColor(0, 1, 0, 0.5) : GUI::setColor(1, 1, 1, 0.5);
                glTranslatef(-1.5, 0, -0.7);
                glScalef(0.05, 2.5, 1.7);
                c.desenha();
            glPopMatrix();
            glPushMatrix(); // VIDRO PORTA SALA
                (this->selecionado) ? GUI::setColor(0, 1, 0, 0.5) : GUI::setColor(1, 1, 1, 0.5);
                glTranslatef(-1.55, 0, -0.3);
                glScalef(0.05, 2.5, 1.7);
                c.desenha();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}
