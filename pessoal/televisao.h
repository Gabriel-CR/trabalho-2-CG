#ifndef TELEVISAO_H
#define TELEVISAO_H

#include <objeto.h>
#include <cubo.h>

class Televisao : public Objeto {
public:
    Televisao();
    Televisao(Vetor3D t, Vetor3D r, Vetor3D e);
    ~Televisao();
    void desenha();
};

#endif // TELEVISAO_H
