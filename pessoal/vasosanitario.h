#ifndef VASOSANITARIO_H
#define VASOSANITARIO_H

#include <objeto.h>
#include <cubo.h>

class VasoSanitario : public Objeto {
    Model3DS* vaso_sanitario;
public:
    VasoSanitario();
    VasoSanitario(Vetor3D t, Vetor3D r, Vetor3D e);
    ~VasoSanitario();
    void desenha();
};

#endif // VASOSANITARIO_H
