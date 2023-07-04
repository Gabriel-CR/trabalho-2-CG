#include "fogao.h"

Fogao::Fogao() {
    fogao = new Model3DS("../3ds/fogao.3ds");
}

Fogao::Fogao(Vetor3D t, Vetor3D r, Vetor3D e) : Objeto(t, r, e) {
    fogao = new Model3DS("../3ds/fogao.3ds");
}

Fogao::~Fogao() {
    delete fogao;
}

void Fogao::desenha() {
    Cubo c = Cubo();

    glPushMatrix();
        Objeto::desenha();
        glPushMatrix(); // NORMALIZANDO TAMANHO DO OBJETO
            glTranslatef(0, 1.7, 0);
            glRotatef(-90, 0, 1, 0);
            glRotatef(-90, 1, 0, 0);
            glScalef(0.003, 0.003, 0.003);
            fogao->draw();
        glPopMatrix();
        glPushMatrix(); // CORPO
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(1, 1, 1);
            glTranslatef(0, 0.2, 0);
            glScalef(1.5, 1.43, 1.6);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // FORNO
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.08, 0.08, 0.08);
            glTranslatef(0, 0.4, 0.8);
            glScalef(1.4, 1, 0.1);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // PUXADOR FORNO
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.8, 0.8, 0.8);
            glTranslatef(0, 1.2, 0.85);
            glScalef(0.5, 0.1, 0.1);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // PE FRENTE DIREITA
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.08, 0.08, 0.08);
            glTranslatef(0.6, 0, 0.6);
            glScalef(0.2, 0.6, 0.2);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // PE FRENTE ESQUERDA
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.08, 0.08, 0.08);
            glTranslatef(-0.6, 0, 0.6);
            glScalef(0.2, 0.6, 0.2);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // PE TRAS DIREITA
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.08, 0.08, 0.08);
            glTranslatef(0.6, 0, -0.6);
            glScalef(0.2, 0.6, 0.2);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // PE TRAS ESQUERDA
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(0.08, 0.08, 0.08);
            glTranslatef(-0.6, 0, -0.6);
            glScalef(0.2, 0.6, 0.2);
            c.desenha();
        glPopMatrix();
    glPopMatrix();
}
