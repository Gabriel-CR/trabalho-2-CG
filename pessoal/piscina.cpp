#include "piscina.h"

Piscina::Piscina() {
}

Piscina::Piscina(Vetor3D t, Vetor3D r, Vetor3D e) : Objeto(t, r, e) {
}

Piscina::~Piscina() {
}

void Piscina::desenha() {
    Cubo c = Cubo();
    Shape s = Shape();

    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glTranslatef(0, -0.9, 0);
            glPushMatrix();
                (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(1, 1, 1);
                glTranslatef(0, 0, 1.5);
                glScalef(5, 1, 0.2);
                c.desenha();
            glPopMatrix();
            glPushMatrix();
                glScalef(5, 0.05, 2.8);
                c.desenha();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0, 0, -1.5);
                glScalef(5, 1, 0.2);
                c.desenha();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(-2.4, 0, 0);
                glRotatef(90, 0, 1, 0);
                glScalef(3, 1, 0.2);
                c.desenha();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(2.4, 0, 0);
                glRotatef(90, 0, 1, 0);
                glScalef(3, 1, 0.2);
                c.desenha();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(1, 0, -0.75);
                glRotatef(90, 0, 1, 0);
                glScalef(1.5, 1, 0.2);
                c.desenha();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(1.65, 0, 0);
                glRotatef(180, 0, 1, 0);
                glScalef(1.5, 1, 0.2);
                c.desenha();
            glPopMatrix();
            glPushMatrix();
                (this->selecionado) ? GUI::setColor(0, 1, 0, 0.9) : GUI::setColor(0.25, 0.41, 1, 0.9);
                glTranslatef(0, 0.9, 0);
                glScalef(5, 0.05, 2.8);
                s.desenha();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}
