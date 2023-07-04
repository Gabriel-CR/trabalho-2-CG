#ifndef PISCINA_H
#define PISCINA_H

#include <objeto.h>
#include <cubo.h>
#include <shape.h>

class Piscina : public Objeto {
public:
    Piscina();
    Piscina(Vetor3D t, Vetor3D r, Vetor3D e);
    ~Piscina();
    void desenha();
};

#endif // PISCINA_H
