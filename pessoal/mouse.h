#ifndef MOUSE_H
#define MOUSE_H

#include <objeto.h>
#include <cubo.h>

class Mouse : public Objeto {
    Model3DS* mouse;
public:
    Mouse();
    ~Mouse();
    void desenha();
};

#endif // MOUSE_H
