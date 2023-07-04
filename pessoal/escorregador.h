#ifndef ESCORREGADOR_H
#define ESCORREGADOR_H

#include <objeto.h>
#include <cubo.h>

class Escorregador : public Objeto {
public:
    Escorregador();
    Escorregador(Vetor3D t, Vetor3D r, Vetor3D e);
    ~Escorregador();
    void desenha();
};

#endif // ESCORREGADOR_H
