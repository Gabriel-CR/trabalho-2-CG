#ifndef CUBO_H
#define CUBO_H

#include <objeto.h>
#include <shape.h>
#include <vector>

class Cubo : public Objeto {
public:
    Cubo();
    Cubo(Vetor3D t, Vetor3D r, Vetor3D e);
    ~Cubo();
    void desenha();
};

#endif // CUBO_H
