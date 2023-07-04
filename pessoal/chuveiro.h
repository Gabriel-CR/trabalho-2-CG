#ifndef CHUVEIRO_H
#define CHUVEIRO_H

#include <objeto.h>
#include <cubo.h>

class Chuveiro : public Objeto {
    Model3DS* chuveiro;
public:
    Chuveiro();
    Chuveiro(Vetor3D t, Vetor3D r, Vetor3D e);
    ~Chuveiro();
    void desenha();
};

#endif // CHUVEIRO_H
