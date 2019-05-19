#include "casa.h"

Casa::Casa()
{

}

void Casa::desenha()
{
    glPushMatrix();
        Objeto::desenha();
        if (selecionado) {
            GUI::setColor(1,1,1);
        }
        //face frente
        glBegin(GL_QUADS);
            glNormal3f(0,0,1);
            glVertex3f(0,0,1);
            glVertex3f(1,0,1);
            glVertex3f(1,2,1);
            glVertex3f(0,2,1);
        glEnd();
        //face tras
        glBegin(GL_QUADS);
            glNormal3f(0,0,-1);
            glVertex3f(0,0,0);
            glVertex3f(0,1,0);
            glVertex3f(1,1,0);
            glVertex3f(1,0,0);
        glEnd();
        //face direita
        glBegin(GL_QUADS);
            glNormal3f(1,0,0);
            glVertex3f(1,0,1);
            glVertex3f(1,0,0);
            glVertex3f(1,1,0);
            glVertex3f(1,1,1);
        glEnd();

        //lateral-d
        glPushMatrix();
            glTranslatef(0,-.25,-.5);
            glRotated(-90,0,1,0);
            glBegin(GL_POLYGON);
                glVertex3f(1,0,.5);
                glVertex3f(1,0,0);
                glVertex3f(1,1,0);
               // glVertex3f(1,1,1);
            glEnd();
        glPopMatrix();
        //face esquerda
        glBegin(GL_QUADS);
            glNormal3f(-1,0,0);
            glVertex3f(0,0,1);
            glVertex3f(0,1,1);
            glVertex3f(0,1,0);
            glVertex3f(0,0,0);
        glEnd();
        //lateral-d
        glPushMatrix();
            glTranslatef(1,-.25,-.5);
            glRotated(-90,0,0,1);
            glRotated(-90,0,1,0);
            glBegin(GL_POLYGON);
                glVertex3f(1,0,1);
                glVertex3f(1,0,0);
                glVertex3f(1,.5,0);
               // glVertex3f(1,1,1);
            glEnd();
        glPopMatrix();
        //face superior
        glBegin(GL_QUADS);
            glNormal3f(0,1,0);
            glVertex3f(0,1,0);
            glVertex3f(0,1,1);
            glVertex3f(1,1,1);
            glVertex3f(1,1,0);
        glEnd();
        //face inferior
        glBegin(GL_QUADS);
            glNormal3f(0,-1,0);
            glVertex3f(0,0,0);
            glVertex3f(1,0,0);
            glVertex3f(1,0,1);
            glVertex3f(0,0,1);
        glEnd();
        //telhado
        //esquerda
        //glBegin(GL_POLYGON);
        //    glNormal3f(-1,1,0);
        //    glVertex3f(0,1,0);
        //    glVertex3f(0,1,1);
        //    glVertex3f(0.5,1.5,0.5);
        //glEnd();
        glPushMatrix();
            glTranslatef(0,1,0);
            glRotatef(-90,0,1,0);
            glRotatef(-45,1,0,0);
            glScalef(1,1.4,1);
            //GUI::drawOrigin(0.5);
            glBegin(GL_POLYGON);
                glNormal3f(0,0,1);
                glVertex3f(0,0,0);
                glVertex3f(1,0,0);
                glVertex3f(0.5,0.5,0);
            glEnd();
        glPopMatrix();
        //frente
        glBegin(GL_POLYGON);
            glNormal3f(0,1,1);
            glVertex3f(0,1,1);
            glVertex3f(1,1,1);
            glVertex3f(0.5,1.5,0.5);
        glEnd();
        //tras
        glBegin(GL_POLYGON);
            glNormal3f(0,1,-1);
            glVertex3f(1,1,0);
            glVertex3f(0,1,0);
            glVertex3f(0.5,1.5,0.5);
        glEnd();
        //direita
        glBegin(GL_POLYGON);
            glNormal3f(1,1,0);
            glVertex3f(1,1,1);
            glVertex3f(1,1,0);
            glVertex3f(0.5,1.5,0.5);
        glEnd();
    glPopMatrix();
}
