#ifndef GELADEIRA_H
#define GELADEIRA_H

#include <objeto.h>
#include <cubo.h>

class Geladeira : public Objeto {
    Model3DS* geladeira;
public:
    Geladeira();
    Geladeira(Vetor3D t, Vetor3D r, Vetor3D e);
    ~Geladeira();
    void desenha();
};

#endif // GELADEIRA_H
