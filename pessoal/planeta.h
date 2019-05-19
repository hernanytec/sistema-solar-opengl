#ifndef PLANETA_H
#define PLANETA_H

#include <objeto.h>
#include <map>

class Planeta: public Objeto
{
public:
    int index;
    int translate_iter = 1;
    GLuint planet_texture = NULL;

    map<int, char*> texture_name_map;
    map<int, double> translate_rate_map;
    map<int, double> translate_current_value_map;

    Planeta(int i);
    void desenha(double rotationRate);
};

#endif // PLANETA_H
