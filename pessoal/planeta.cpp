#include "planeta.h"

#include <map>

Planeta::Planeta(int i = 1)
{
    this->planet_texture = NULL;
    this->tipo = "planet";

    this->index = i;
    this->texture_name_map[1] = "textures/mercury.bmp";
    this->texture_name_map[2] = "textures/venus_surface.bmp";
    this->texture_name_map[3] = "textures/earth.bmp";
    this->texture_name_map[4] = "textures/mars.bmp";
    this->texture_name_map[5] = "textures/jupiter.bmp";
    this->texture_name_map[6] = "textures/saturn.bmp";
    this->texture_name_map[7] = "textures/uranus.bmp";
    this->texture_name_map[8] = "textures/neptune.bmp";

    for(int i = 1; i < 9; i++){
        this->translate_current_value_map[i] = 1;
    }

    this->translate_rate_map[1] = 2;
    this->translate_rate_map[2] = 1.9;
    this->translate_rate_map[3] = 1.8;
    this->translate_rate_map[4] = 1.7;
    this->translate_rate_map[5] = 1.6;
    this->translate_rate_map[6] = 1.5;
    this->translate_rate_map[7] = 1.4;
    this->translate_rate_map[8] = 1.3;

}

void Planeta::desenha(double rotationRate){
    map<int, double> size_planet_map;

    size_planet_map[1] = 0.1;
    size_planet_map[2] = 0.25;
    size_planet_map[3] = 0.3;
    size_planet_map[4] = 0.23;
    size_planet_map[5] = 0.45;
    size_planet_map[6] = 0.35;
    size_planet_map[7] = 0.25;
    size_planet_map[8] = 0.25;


    glPushMatrix();
        Objeto::desenha();
        glTranslatef(index,0,0);
        glRotated(rotationRate,0,0,1);

        if(draw_sist_coord)
            GUI::drawOrigin(1);
        GUI::drawSphere(0, 0, 0, size_planet_map[index]);

    glPopMatrix();
}
