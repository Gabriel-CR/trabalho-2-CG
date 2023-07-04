#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <objeto.h>

class Personagem : public Objeto
{
public:
    int teste = 0;
    Personagem();

    void desenha();
};

#endif // PERSONAGEM_H
