#include "objeto.h"

Objeto::Objeto()
{

}

int val, l = 40;
void Objeto::desenha()
{
    glTranslatef(t.x,t.y,t.z);
    glRotatef(a.z,0,0,1);
    glRotatef(a.y,0,1,0);
    glRotatef(a.x,1,0,0);
    glScalef(s.x, s.y, s.z);

    if(selecionado){
        if(val < l / 20)
            glScalef(.0001, .0001, .0001);
        val = (val+1) % l;
    }
}
