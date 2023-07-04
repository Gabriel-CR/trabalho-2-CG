#ifndef PC_H
#define PC_H

#include <objeto.h>
#include <cubo.h>

class Pc : public Objeto {
    Model3DS* pc;
public:
    Pc();
    Pc(Vetor3D t, Vetor3D r, Vetor3D e);
    ~Pc();
    void desenha();
};

#endif // PC_H
