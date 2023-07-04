#include "cubo.h"

Cubo::Cubo() {
}

Cubo::Cubo(Vetor3D t, Vetor3D r, Vetor3D e) : Objeto(t, r, e) {
}

Cubo::~Cubo() {
}

void Cubo::desenha() {
    Shape s = Shape();

    glPushMatrix();
        glRotatef(180, 0.5, 0, 0);
        s.desenha();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0, 0.5, 0.5);
        glRotatef(90, 1, 0, 0);
        s.desenha();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0, 0.5, -0.5);
        glRotatef(-90, 1, 0, 0);
        s.desenha();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.5, 0.5, 0);
        glRotatef(-90, 0, 0, 1);
        s.desenha();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.5, 0.5, 0);
        glRotatef(90, 0, 0, 1);
        s.desenha();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0, 1, 0);
        s.desenha();
    glPopMatrix();
}
