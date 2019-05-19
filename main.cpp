#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

#include <planeta.h>
#include <astronauta.h>
#include<texturemanager.h>

vector<Objeto*> objetos;
TextureManager* textureManager = new TextureManager();
GLuint sunTexture = NULL;
GLuint starsTexture = NULL;

bool translation = false;
int posSelecionado = -1;
int rotationRate = 1;
double earth_translate_value;

void desenha() {
    GUI::displayInit();

    GUI::setLight(1, 0, 0, 0, true, false);

     if(starsTexture == NULL)
        starsTexture = textureManager->LoadBitmap("textures/stars_milky_way.bmp");

    //Desenhando fundo estrelado
    glPushMatrix();
        glDisable(GL_CULL_FACE);
        glEnable(GL_COLOR_MATERIAL);
        glEnable (GL_TEXTURE_2D);
            glBindTexture (GL_TEXTURE_2D, starsTexture);
            GUI::drawSphere(0, 0, 0, 100);
        glDisable(GL_TEXTURE_2D);
     glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();


    //carregando textura do sol caso ainda não esteja carregada
    if(sunTexture == NULL)
        sunTexture = textureManager->LoadBitmap("textures/sun.bmp");

    //desenhando sol e aplicando textura
    glPushMatrix();
        glEnable(GL_COLOR_MATERIAL);
        glEnable (GL_TEXTURE_2D);
            glBindTexture (GL_TEXTURE_2D, sunTexture);
            glRotatef(rotationRate/10.0,0,0,1);
            GUI::drawSphere(0, 0, 0, 0.6);
        glDisable(GL_TEXTURE_2D);
     glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();


    //desenhando órbita dos planetas
    for(int i = 1; i < 9; i++){
        glPushMatrix();
            glBegin(GL_LINE_LOOP);
            for(int j = 1; j <= 360; j++){
                double angle = 2 * PI * j / 360;
                double x = i * cos(angle);
                double y = i * sin(angle);
                glVertex2d(x, y);
            }
            glEnd();
        glPopMatrix();
    }

    //Desenhando o vetor de objetos
    for (int i = 0; i < objetos.size(); i++) {
        if(objetos[i]->tipo == "planet"){
            glPushMatrix();
                Planeta* p = dynamic_cast<Planeta*>(objetos[i]);

                if(p->planet_texture == NULL){
                    char * texture_path =  p->texture_name_map.find(p->index)->second;
                    p->planet_texture = textureManager->LoadBitmap(texture_path);
                }

                //se a translação estiver habilitada, faz as alterações necessárias
                if(translation){
                    int index = p->index;
                    double v = p->translate_current_value_map[index];
                    v += p->translate_rate_map[index];
                    p->translate_current_value_map[index] = v;
                }

                //rotaciona de acordo com o valor
                glRotatef(p->translate_current_value_map[p->index], 0,0,1);
                if(p->index == 3)
                    earth_translate_value = p->translate_current_value_map[p->index];
                glEnable ( GL_TEXTURE_2D );
                    glBindTexture (GL_TEXTURE_2D, p->planet_texture);
                    p->desenha(rotationRate/(double)p->index);
                glDisable(GL_TEXTURE_2D);
            glPopMatrix();
        }
        else if(objetos[i]->tipo == "astronaut"){
            Astronauta* ast = dynamic_cast<Astronauta*>(objetos[i]);
            glPushMatrix();
                ast->t.x -= 0.005;
                glRotatef(earth_translate_value,0,0,1);
                if(ast->t.x > -3)
                ast->desenha(rotationRate);
            glPopMatrix();
        }
    }

    if (posSelecionado >= 0 and posSelecionado < (int) objetos.size()) {

        objetos[posSelecionado]->t.x += glutGUI::dtx;
        objetos[posSelecionado]->t.y += glutGUI::dty;
        objetos[posSelecionado]->t.z += glutGUI::dtz;

        objetos[posSelecionado]->a.x += glutGUI::dax;
        objetos[posSelecionado]->a.y += glutGUI::day;
        objetos[posSelecionado]->a.z += glutGUI::daz;

        objetos[posSelecionado]->s.x += glutGUI::dsx;
        objetos[posSelecionado]->s.y += glutGUI::dsy;
        objetos[posSelecionado]->s.z += glutGUI::dsz;
    }

    rotationRate++;
    GUI::displayEnd();
}

void teclado(unsigned char key, int x, int y) {
    GUI::keyInit(key,x,y);

    switch (key) {
    case 'T':
        glutGUI::trans_obj = !glutGUI::trans_obj;
        break;
    case 'n':
        if (posSelecionado >= 0 and posSelecionado < (int) objetos.size()) {
            objetos[posSelecionado]->selecionado = false;
        }
        posSelecionado++;

        posSelecionado = (posSelecionado == (int) objetos.size()) ? -1 : posSelecionado % objetos.size();

        if (posSelecionado >= 0 and posSelecionado < (int) objetos.size()) {
            objetos[posSelecionado]->selecionado = true;
        }
        break;
    case 'b':
        if (posSelecionado >= 0 and posSelecionado < (int) objetos.size()) {
            objetos[posSelecionado]->selecionado = false;
        }

        posSelecionado = (posSelecionado < 0) ? objetos.size()-1 : posSelecionado-1;

        if (posSelecionado >= 0 and posSelecionado < (int) objetos.size()) {
            objetos[posSelecionado]->selecionado = true;
        }
        break;

    case '1':
        objetos.push_back( new Planeta(1) );
        break;
    case '2':
        objetos.push_back( new Planeta(2) );
        break;
    case '3':
        objetos.push_back( new Planeta(3) );
        break;
    case '4':
        objetos.push_back( new Planeta(4) );
        break;
    case '5':
        objetos.push_back( new Planeta(5) );
        break;
    case '6':
        objetos.push_back( new Planeta(6) );
        break;
    case '7':
        objetos.push_back( new Planeta(7) );
        break;
    case '8':
        objetos.push_back( new Planeta(8) );
        break;
    case '9':
        for(int i = 1; i  < 9; i++){
            objetos.push_back( new Planeta(i));
        }
        break;
    case 'a':
        objetos.push_back(new Astronauta());
        break;
    case 'A':
            for(Objeto* obj: objetos){
                if(obj->tipo == "planet"){
                    Planeta* p =  dynamic_cast<Planeta*>(obj);
                    p->t.x = 0;
                    p->t.y = 0;
                    p->translate_current_value_map[p->index] = 0;
            }
        }
        break;
    case 'd':
        if (posSelecionado >= 0 and posSelecionado < (int) objetos.size()) {
            objetos[posSelecionado]->draw_sist_coord = !objetos[posSelecionado]->draw_sist_coord;
        }
        break;
    case 'D':
        if (posSelecionado >= 0 and posSelecionado < (int) objetos.size()){
            objetos.erase(objetos.begin()+posSelecionado);
            posSelecionado = -1;
        }
        break;
    case 't':
        translation = !translation;
        break;
    case 'w':
    {
        ofstream save ("data/save_data.txt");
        if (save.is_open()){
            int cont = 0;

            for(auto obj : objetos)
                if(obj->tipo == "planet")
                    cont++;
            save << cont << endl;

            for(Objeto * obj : objetos){
                if(obj->tipo ==  "planet"){
                    Planeta * p = dynamic_cast<Planeta*>(obj);
                    //salvando a matriz de tranformações
                    save << p->index << endl;

                    save << p->t.x << endl;
                    save << p->t.y << endl;
                    save << p->t.z << endl;

                    save << p->a.x << endl;
                    save << p->a.y << endl;
                    save << p->a.z << endl;

                    save << p->s.x << endl;
                    save << p->s.y << endl;
                    save << p->s.z << endl;

                    save << p->translate_current_value_map[p->index] << endl;
                }

            }
            save.close();
        }
        else
            cout << "Não foi possível abrir o arquivo";
        break;
    }
    case 'r':
    {
        string linha;
        ifstream load ("data/save_data.txt");
        if(load.is_open()){
            getline(load,linha);
            int qtdPlanets = stoi(linha);

            while(qtdPlanets--){
                //vejo qual o planeta
                getline(load,linha);

                //adiciono no vetor de objetos
                Planeta* p = new Planeta(stoi(linha));

                //carrego o restante dos dados
                getline(load,linha);
                p->t.x = stof(linha);
                getline(load,linha);
                p->t.y = stof(linha);
                getline(load,linha);
                p->t.z = stof(linha);

                getline(load,linha);
                p->a.x = stof(linha);
                getline(load,linha);
                p->a.y = stof(linha);
                getline(load,linha);
                p->a.z = stof(linha);

                getline(load,linha);
                p->s.x = stof(linha);
                getline(load,linha);
                p->s.y = stof(linha);
                getline(load,linha);
                p->s.z = stof(linha);

                getline(load, linha);
                p->translate_current_value_map[p->index] = stof(linha);
                objetos.push_back(p);
            }
            load.close();
        }
        break;
    }

    }
}

void menu(){
    cout << "1 - adiciona Mercúrio na sua órbita\n";
    cout << "2 - adiciona Vênus na sua órbita\n";
    cout << "3 - adiciona Terra na sua órbita\n";
    cout << "4 - adiciona Marte na sua órbita\n";
    cout << "5 - adiciona Júpiter na sua órbita\n";
    cout << "6 - adiciona Saturno na sua órbita\n";
    cout << "7 - adiciona Urano na sua órbita\n";
    cout << "8 - adiciona Neturno na sua órbita\n";
    cout << "9 - adiciona todos os planetas de uma vez\n";
    cout << "a - manda um astronauta da terra para o sol\n";
    cout << "t - inicia/para o movimento de translação dos planetas\n";
    cout << "A - recoloca os planetas na posição incial\n";
    cout << "n para avançar e b para voltar na lista de objetos\n";
    cout << "   obs1: o objeto selecionado começará a piscar\n";
    cout << "   obs2: o sol e as órbitas dos planetas não estão contidos na lista\n";
    cout << "com um objeto selecionado:\n";
    cout << "   d para desenhar/ocultar o sist. de coordenadas\n";
    cout << "   D para deletar o objeto\n";
    cout << "s - salva o estado atual da câmera\n";
    cout << "C - alterna entre 3 posições diferentes de câmera (incluindo o estado salvo)\n";
    cout << "c - restaura para a câmera original\n";
    cout << "z/Z - zoom in/zoom out\n";
    cout << "w - salva o cenário em um arquivo\n";
    cout << "r - carrega o cenário do arquivo\n";
    cout << "q ou esc para sair.\n";
}

int main()
{
    cout << "Hello Universe!" << endl;
    menu();
    GUI gui = GUI(800,600, desenha, teclado, "Sistema solar");
}
