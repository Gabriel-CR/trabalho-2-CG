#ifndef CADEIRA_H
#define CADEIRA_H

#include <objeto.h>
#include <cubo.h>

class Cadeira : public Objeto {
public:
    Cadeira();
    Cadeira(Vetor3D t, Vetor3D r, Vetor3D e);
    ~Cadeira();
    void desenha();
};

#endif // CADEIRA_H
