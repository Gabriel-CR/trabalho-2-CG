#ifndef CAMA_H
#define CAMA_H

#include <objeto.h>
#include <cubo.h>

class Cama : public Objeto {
public:
    Cama();
    Cama(Vetor3D t, Vetor3D r, Vetor3D e);
    ~Cama();
    void cama_solteiro();
    void desenha();
};

#endif // CAMA_H
