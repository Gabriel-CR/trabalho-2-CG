#include "caixasom.h"

CaixaSom::CaixaSom() {
}

void CaixaSom::desenha() {
    Cubo c = Cubo();

    glPushMatrix();
        Objeto::desenha();

        glPushMatrix();
            (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(1*1.6, 1*1.6, 1*1.6);
            glScalef(1, 1.5, 1);
            c.desenha();
        glPopMatrix();
    glPopMatrix();
}
