#ifndef OBJETO_H
#define OBJETO_H

#include <gui.h>

class Objeto {
public:
    Vetor3D translacao = Vetor3D(0, 0, 0);
    Vetor3D rotacao = Vetor3D(0, 0, 0);
    Vetor3D escala = Vetor3D(1, 1, 1);

    bool selecionado = false;
    bool desenha_local = false;

public:
    Objeto();
    Objeto(Vetor3D t, Vetor3D r, Vetor3D e);
    ~Objeto();
    virtual void desenha();
};

#endif // OBJETO_H
