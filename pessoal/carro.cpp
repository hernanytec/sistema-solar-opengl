#include "carro.h"

Carro::Carro()
{
    model = new Model3DS("../3ds/Bridge/Bridge.3ds");
}

void Carro::desenha()
{
    glPushMatrix();
        Objeto::desenha();
        glRotatef(-90,1,0,0);
        model->draw();
    glPopMatrix();
}
