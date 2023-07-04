#ifndef CIRCLE_H
#define CIRCLE_H

#include <objeto.h>
#include <shape.h>

class Circle : public Objeto {
    float raio = 1.0;
    int qtd_linhas = 20;
public:
    Circle(float raio, int qtd_linhas);
    Circle();
    void desenha();
};

#endif // CIRCLE_H
