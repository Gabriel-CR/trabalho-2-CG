#include "televisao.h"

Televisao::Televisao() {
}

Televisao::Televisao(Vetor3D t, Vetor3D r, Vetor3D e) : Objeto(t, r, e) {
}

Televisao::~Televisao() {
}

void Televisao::desenha() {
    Cubo c = Cubo();

    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glTranslatef(0, 0.5, 0);
            glPushMatrix(); // PARTE DE TRAS
                (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.4, 0.4, 0.4);
                glScalef(4, 1, 1);
                glScalef(1, 2, 1);
                glScalef(1, 1, 0.5);
                c.desenha();
            glPopMatrix();
            glPushMatrix(); // TELA
                (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.169, 0.169, 0.169);
                glTranslatef(0, 0.25, 0.25);
                glScalef(3.5, 1, 1);
                glScalef(1, 1.5, 1);
                glScalef(1, 1, 0.125);
                c.desenha();
            glPopMatrix();
        glPopMatrix();
        glPushMatrix(); // BASE
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.4, 0.4, 0.4);
            glScalef(3, 1, 1);
            glScalef(1, 0.25, 1);
            glScalef(1, 1, 0.5);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // SUPORTE DA BASE
            glTranslatef(-1, 0.25, 0);
            glScalef(0.2, 1, 1);
            glScalef(1, 0.25, 1);
            glScalef(1, 1, 0.25);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // SUPORTE DA BASE
            glTranslatef(1, 0.25, 0);
            glScalef(0.2, 1, 1);
            glScalef(1, 0.25, 1);
            glScalef(1, 1, 0.25);
            c.desenha();
        glPopMatrix();
    glPopMatrix();
}
