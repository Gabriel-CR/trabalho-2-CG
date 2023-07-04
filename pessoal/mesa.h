#ifndef MESA_H
#define MESA_H

#include <objeto.h>
#include <cubo.h>

class Mesa : public Objeto {
public:
    Mesa();
    Mesa(Vetor3D t, Vetor3D r, Vetor3D e);
    ~Mesa();
    void desenha();
};

#endif // MESA_H
