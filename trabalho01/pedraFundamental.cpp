#include "pedraFundamental.h"

pedraFundamental::pedraFundamental(bool selecionado, bool origem, int tipo){
    this->selecionado = selecionado;
    this->origem = origem;
    this->tipo = tipo;
}

pedraFundamental::pedraFundamental(float Tx, float Ty, float Tz, float Rx, float Ry, float Rz, float Sx, float Sy, float Sz, bool selecionado, bool origem, int tipo){
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

void pedraFundamental::desenha(){
    
    Objeto::desenha();

    if(this->origem == 1){
        GUI::drawOrigin(0.5);
    }

    if(this->selecionado == 1){
        GUI::setColor(1,0,0);

        glBegin(GL_QUADS);          //Tampa da pedra
            glNormal3f(0, 1, 0);
            glVertex3f(-0.05, 0.185, 0.35);
            glVertex3f(0.35, 0.185, 0.35);
            glVertex3f(0.35, 0.318, -0.05);
            glVertex3f(-0.05, 0.318, -0.05);
        glEnd();

        glBegin(GL_QUADS);          //Tampa da pedra inversa
            glNormal3f(0, -1, 0);
            glVertex3f(-0.05, 0.318, -0.05);
            glVertex3f(0.35, 0.318, -0.05);
            glVertex3f(0.35, 0.185, 0.35);
            glVertex3f(-0.05, 0.185, 0.35);
        glEnd();

        glBegin(GL_QUADS);          //inferior
            glNormal3f(0, -0.3, 0);
            glVertex3f(0, 0, 0);
            glVertex3f(0.3, 0, 0);
            glVertex3f(0.3, 0, 0.3);
            glVertex3f(0, 0, 0.3);
        glEnd();

        glBegin(GL_QUADS);         //frontal
            glNormal3f(0, 0, 1);
            glVertex3f(0, 0, 0.3);
            glVertex3f(0.3, 0, 0.3);
            glVertex3f(0.3, 0.2, 0.3);
            glVertex3f(0, 0.2, 0.3);
        glEnd();

        glBegin(GL_QUADS);      //traseira
            glNormal3f(0, 0, -1);
            glVertex3f(0.3, 0, 0);
            glVertex3f(0, 0, 0);
            glVertex3f(0, 0.3, 0);
            glVertex3f(0.3, 0.3, 0);
        glEnd();

        glBegin(GL_QUADS);      //lado esq
            glNormal3f(-1, 0, 0);
            glVertex3f(0, 0, 0);
            glVertex3f(0, 0, 0.3);
            glVertex3f(0, 0.2, 0.3);
            glVertex3f(0, 0.3, 0);
        glEnd();

        glBegin(GL_QUADS);      //lado dir
            glNormal3f(1, 0, 0);
            glVertex3f(0.3, 0, 0.3);
            glVertex3f(0.3, 0, 0);
            glVertex3f(0.3, 0.3, 0);
            glVertex3f(0.3, 0.2, 0.3);
        glEnd();
    }else{

    GUI::setColor(0.9, 0.9, 0.9);

    glBegin(GL_QUADS);          //Tampa da pedra
        glNormal3f(0, 1, 0);
        glVertex3f(-0.05, 0.185, 0.35);
        glVertex3f(0.35, 0.185, 0.35);
        glVertex3f(0.35, 0.318, -0.05);
        glVertex3f(-0.05, 0.318, -0.05);
    glEnd();

     glBegin(GL_QUADS);          //Tampa da pedra inversa
        glNormal3f(0, -1, 0);
        glVertex3f(-0.05, 0.318, -0.05);
        glVertex3f(0.35, 0.318, -0.05);
        glVertex3f(0.35, 0.185, 0.35);
        glVertex3f(-0.05, 0.185, 0.35);
    glEnd();

    GUI::setColor(0.3, 0.3, 0.3);
    
    glBegin(GL_QUADS);          //inferior
        glNormal3f(0, -0.3, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0.3, 0, 0);
        glVertex3f(0.3, 0, 0.3);
        glVertex3f(0, 0, 0.3);
    glEnd();

    glBegin(GL_QUADS);         //frontal
        glNormal3f(0, 0, 1);
        glVertex3f(0, 0, 0.3);
        glVertex3f(0.3, 0, 0.3);
        glVertex3f(0.3, 0.2, 0.3);
        glVertex3f(0, 0.2, 0.3);
    glEnd();

    glBegin(GL_QUADS);      //traseira
        glNormal3f(0, 0, -1);
        glVertex3f(0.3, 0, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0.3, 0);
        glVertex3f(0.3, 0.3, 0);
    glEnd();

    glBegin(GL_QUADS);      //lado esq
        glNormal3f(-1, 0, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, 0.3);
        glVertex3f(0, 0.2, 0.3);
        glVertex3f(0, 0.3, 0);
    glEnd();

    glBegin(GL_QUADS);      //lado dir
        glNormal3f(1, 0, 0);
        glVertex3f(0.3, 0, 0.3);
        glVertex3f(0.3, 0, 0);
        glVertex3f(0.3, 0.3, 0);
        glVertex3f(0.3, 0.2, 0.3);
    glEnd();
    }
    
}
