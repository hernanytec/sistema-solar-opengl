#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H

#include <objeto.h>

class Astronauta : public Objeto
{
public:
    Model3DS * model;
    Astronauta();
    virtual void desenha(double rotationRate);
};

#endif // ASTRONAUTA_H
