#ifndef FOGAO_H
#define FOGAO_H

#include <objeto.h>
#include <cubo.h>


class Fogao : public Objeto {
    Model3DS* fogao;
public:
    Fogao();
    Fogao(Vetor3D t, Vetor3D r, Vetor3D e);
    ~Fogao();
    void desenha();
};

#endif // FOGAO_H
