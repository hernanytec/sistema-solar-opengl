#ifndef CARRO_H
#define CARRO_H

#include <objeto.h>

class Carro : public Objeto
{
public:
    Model3DS* model;
public:
    Carro();
    void desenha();
};

#endif // CARRO_H
