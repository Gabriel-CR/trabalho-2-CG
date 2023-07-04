#ifndef SOFA_H
#define SOFA_H

#include <objeto.h>
#include <cubo.h>

class Sofa : public Objeto {
public:
    Sofa();
    Sofa(Vetor3D t, Vetor3D r, Vetor3D e);
    ~Sofa();
    void desenha();
};

#endif // SOFA_H
