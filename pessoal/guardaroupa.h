#ifndef GUARDAROUPA_H
#define GUARDAROUPA_H

#include <objeto.h>
#include <shape.h>
#include <cubo.h>

class GuardaRoupa : public Objeto {
public:
    GuardaRoupa();
    GuardaRoupa(Vetor3D t, Vetor3D r, Vetor3D e);
    ~GuardaRoupa();
    void desenha();
};

#endif // GUARDAROUPA_H
