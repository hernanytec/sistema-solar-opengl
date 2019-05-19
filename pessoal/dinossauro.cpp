#include "dinossauro.h"


typedef enum {
    RESERVED, BODY_SIDE, BODY_EDGE, BODY_WHOLE, ARM_SIDE, ARM_EDGE, ARM_WHOLE,
    LEG_SIDE, LEG_EDGE, LEG_WHOLE, EYE_SIDE, EYE_EDGE, EYE_WHOLE, DINOSAUR
} displayLists;


Dinossauro::Dinossauro()
{

}
void Dinossauro::desenha(){
    Objeto::desenha();
    glutSolidSphere(1, 32, 32);

    //glutSolidTeapot(2);
    //glutSolidTorus(0.5,2,32,32);
    // glutSolidCone(2,10,32,32);
}
