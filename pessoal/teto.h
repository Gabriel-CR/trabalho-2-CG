#ifndef TETO_H
#define TETO_H

#include <objeto.h>
#include <cubo.h>

class Teto : public Objeto {
public:
    Teto();
    Teto(Vetor3D t, Vetor3D r, Vetor3D e);
    ~Teto();
    void desenha();
};

#endif // TETO_H
