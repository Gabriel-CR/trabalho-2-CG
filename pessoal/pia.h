#ifndef PIA_H
#define PIA_H

#include <objeto.h>
#include <cubo.h>

class Pia : public Objeto {
public:
    Pia();
    Pia(Vetor3D t, Vetor3D r, Vetor3D e);
    ~Pia();
    void desenha();
};

#endif // PIA_H
