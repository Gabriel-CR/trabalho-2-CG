#ifndef SHAPE_H
#define SHAPE_H

#include <objeto.h>

class Shape : public Objeto {
public:
    Shape();
    Shape(Vetor3D t, Vetor3D r, Vetor3D e);
    ~Shape();
    void desenha();
};

#endif // SHAPE_H
