#ifndef PAREDE_H
#define PAREDE_H

#include <objeto.h>
#include <cubo.h>

class Parede : public Objeto {
public:
    Parede();
    Parede(Vetor3D t, Vetor3D r, Vetor3D e);
    ~Parede();
    void desenha();
};

#endif // PAREDE_H
