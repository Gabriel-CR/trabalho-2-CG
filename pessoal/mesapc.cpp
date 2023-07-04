#include "mesapc.h"

MesaPc::MesaPc() {
}

MesaPc::MesaPc(Vetor3D t, Vetor3D r, Vetor3D e) : Objeto(t, r, e) {
}

void MesaPc::desenha() {
    Cubo c = Cubo();

    glPushMatrix();
        Objeto::desenha();
        (this->selecionado) ? GUI::setColor(0, 1, 0) : GUI::setColor(1, 1, 1);
        glPushMatrix(); // TAMPO
            glTranslatef(0, 1, 0);
            glScalef(2.5, 0.1, 1.2);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // SUPORTE EM BAIXO
            glTranslatef(0, 0.7, -0.3);
            glRotatef(90, 1, 0, 0);
            glScalef(2.5, 0.1, 0.6);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // PE DIREITO
            glTranslatef(1.2, 0, 0);
            glScalef(0.1, 1, 1.2);
            c.desenha();
        glPopMatrix();
        glPushMatrix(); // PE ESQUERDO
            glTranslatef(-1.2, 0, 0);
            glScalef(0.1, 1, 1.2);
            c.desenha();
        glPopMatrix();
    glPopMatrix();
}
