#include "arvore.h"

arvore::arvore(bool selecionado, bool origem, int tipo){
    this->selecionado = selecionado;
    this->origem = origem;
    this->tipo = tipo;
}

arvore::arvore(float Tx, float Ty, float Tz, float Rx, float Ry, float Rz, float Sx, float Sy, float Sz, bool selecionado, bool origem, int tipo){
    Vetor3D translacao(Tx,Ty,Tz);
    Vetor3D rotacao(Rx,Ry,Rz);
    Vetor3D escala(Sx,Sy,Sz);

    this->selecionado = selecionado;
    this->origem = origem;
    this->translacao = translacao;
    this->rotacao = rotacao;
    this->escala = escala;
    this->tipo = tipo;

}

void arvore::desenha(){
    
    Objeto::desenha();

    if(this->origem == 1){
        GUI::drawOrigin(0.5);
    }

    if(this->selecionado == 1){
        GUI::setColor(1,0,0);
        //TRONCO
        glBegin(GL_QUADS);
            glNormal3f(0, -1, 0);
            glVertex3f(-0.15, 0, -0.15);
            glVertex3f(0.15, 0, -0.15);
            glVertex3f(0.15, 0, 0.15);
            glVertex3f(-0.15, 0, 0.15);
        glEnd();

        glBegin(GL_QUADS);
            glNormal3f(0, 1, 0);
            glVertex3f(-0.15, 1, 0.15);
            glVertex3f(0.15, 1, 0.15);
            glVertex3f(0.15, 1, -0.15);
            glVertex3f(-0.15, 1, -0.15);
        glEnd();

        glBegin(GL_QUADS);
            glNormal3f(0, 0, 1);
            glVertex3f(-0.15, 0, 0.15);
            glVertex3f(0.15, 0, 0.15);
            glVertex3f(0.15, 1, 0.15);
            glVertex3f(-0.15, 1, 0.15);
        glEnd();

        glBegin(GL_QUADS);
            glNormal3f(0, 0, -1);
            glVertex3f(0.15, 0, -0.15);
            glVertex3f(-0.15, 0, -0.15);
            glVertex3f(-0.15, 1, -0.15);
            glVertex3f(0.15, 1, -0.15);
        glEnd();

        glBegin(GL_QUADS);
            glNormal3f(-1, 0, 0);
            glVertex3f(-0.15, 0, -0.15);
            glVertex3f(-0.15, 0, 0.15);
            glVertex3f(-0.15, 1, 0.15);
            glVertex3f(-0.15, 1, -0.15);
        glEnd();

        glBegin(GL_QUADS);
            glNormal3f(1, 0, 0);
            glVertex3f(0.15, 0, 0.15);
            glVertex3f(0.15, 0, -0.15);
            glVertex3f(0.15, 1, -0.15);
            glVertex3f(0.15, 1, 0.15);
        glEnd();

        //COPA
        glTranslatef(0,1.6,0);
        glutSolidSphere(1,5,5);
    }else{
        GUI::setColor(1,0.5,0);

        //TRONCO
        glBegin(GL_QUADS);
            glNormal3f(0, -1, 0);
            glVertex3f(-0.15, 0, -0.15);
            glVertex3f(0.15, 0, -0.15);
            glVertex3f(0.15, 0, 0.15);
            glVertex3f(-0.15, 0, 0.15);
        glEnd();

        glBegin(GL_QUADS);
            glNormal3f(0, 1, 0);
            glVertex3f(-0.15, 1, 0.15);
            glVertex3f(0.15, 1, 0.15);
            glVertex3f(0.15, 1, -0.15);
            glVertex3f(-0.15, 1, -0.15);
        glEnd();

        glBegin(GL_QUADS);
            glNormal3f(0, 0, 1);
            glVertex3f(-0.15, 0, 0.15);
            glVertex3f(0.15, 0, 0.15);
            glVertex3f(0.15, 1, 0.15);
            glVertex3f(-0.15, 1, 0.15);
        glEnd();

        glBegin(GL_QUADS);
            glNormal3f(0, 0, -1);
            glVertex3f(0.15, 0, -0.15);
            glVertex3f(-0.15, 0, -0.15);
            glVertex3f(-0.15, 1, -0.15);
            glVertex3f(0.15, 1, -0.15);
        glEnd();

        glBegin(GL_QUADS);
            glNormal3f(-1, 0, 0);
            glVertex3f(-0.15, 0, -0.15);
            glVertex3f(-0.15, 0, 0.15);
            glVertex3f(-0.15, 1, 0.15);
            glVertex3f(-0.15, 1, -0.15);
        glEnd();

        glBegin(GL_QUADS);
            glNormal3f(1, 0, 0);
            glVertex3f(0.15, 0, 0.15);
            glVertex3f(0.15, 0, -0.15);
            glVertex3f(0.15, 1, -0.15);
            glVertex3f(0.15, 1, 0.15);
        glEnd();

        //COPA
        GUI::setColor(0,1,0);
        glTranslatef(0,1.6,0);
        glutSolidSphere(1,5,5);
    }


    
}
