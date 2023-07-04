#include "circle.h"

Circle::Circle(float raio, int qtd_linhas) {
    this->raio = raio;
    this->qtd_linhas = qtd_linhas;
}

Circle::Circle() {
}

void Circle::desenha() { // modificar nome das variáveis
    glTranslatef(0, 0, -0.5);
    glRotatef(90, 1, 0, 0);
//    glScalef(1, 2, 1);
    GUI::setColor(0.8, 0, 0, 1, true);
    GLUquadric* quad = gluNewQuadric();
    Desenha::gluClosedCylinder(quad, this->raio, this->raio, 1, this->qtd_linhas, this->qtd_linhas);
    gluDeleteQuadric(quad);
}
