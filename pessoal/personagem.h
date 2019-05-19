#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <objeto.h>

class Personagem : public Objeto
{
public:
    Personagem();
    void desenha();
};

#endif // PERSONAGEM_H
