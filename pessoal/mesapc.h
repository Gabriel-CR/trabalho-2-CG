#ifndef MESAPC_H
#define MESAPC_H

#include <objeto.h>
#include <cubo.h>

class MesaPc : public Objeto {
public:
    MesaPc();
    MesaPc(Vetor3D t, Vetor3D r, Vetor3D e);
    void desenha();
};

#endif // MESAPC_H
