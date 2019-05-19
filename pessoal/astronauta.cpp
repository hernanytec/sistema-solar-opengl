#include "astronauta.h"

Astronauta::Astronauta()
{
    model = new Model3DS("3ds/astronaut/astronaut1.3ds");
    tipo = "astronaut";
}

void Astronauta::desenha(double rotationRate){
    glPushMatrix();
        Objeto::desenha();
        glTranslatef(3,0,0);
        glRotatef(rotationRate,1,1,0);
        glScalef(.001,.001,.001);
        if(draw_sist_coord)
            GUI::drawOrigin(1);

        model->draw();
    glPopMatrix();
}
