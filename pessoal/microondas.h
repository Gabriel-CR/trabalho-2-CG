#ifndef MICROONDAS_H
#define MICROONDAS_H

#include <objeto.h>
#include <cubo.h>

class Microondas : public Objeto {
    Model3DS* microondas;
public:
    Microondas();
    Microondas(Vetor3D t, Vetor3D r, Vetor3D e);
    ~Microondas();
    void desenha();
};

#endif // MICROONDAS_H
