#ifndef OBJETO_H
#define OBJETO_H

#include <gui.h>

class Objeto
{
public:
    Vetor3D t = Vetor3D(0,0,0);
    Vetor3D a = Vetor3D(0,0,0);
    Vetor3D s = Vetor3D(1,1,1);

    bool selecionado = false;
    bool draw_sist_coord = false;
    bool draw_shadow = true;
    string tipo = "objeto";
public:
    Objeto();
    virtual void desenha();
};

#endif // OBJETO_H
