#include "caramujao.h"

caramujao::caramujao(bool selecionado, bool origem, int tipo){
    this->selecionado = selecionado;
    this->origem = origem;
    this->tipo = tipo;
}

caramujao::caramujao(float Tx, float Ty, float Tz, float Rx, float Ry, float Rz, float Sx, float Sy, float Sz, bool selecionado, bool origem, int tipo){
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

void caramujao::desenha(){
    
    Objeto::desenha();

    if(this->origem == 1){
        GUI::drawOrigin(0.5);
    }
    if(this->selecionado == 1){
        GUI::setColor(1,0,0);
        glPushMatrix();
            GUI::drawBox(-0.1,0,-0.1,0.1,1,0.1);
            glPushMatrix();
                GUI::drawBox(-0.7,1,-0.15,0.7,1.1,0.15);
            glPopMatrix();
            glPushMatrix();
                GUI::drawBox(-0.7,1.1,-0.5,-0.6,1.2,0.5);
                GUI::drawBox(-0.5,1.1,-0.5,-0.4,1.2,0.5);
                GUI::drawBox(-0.3,1.1,-0.5,-0.2,1.2,0.5);
                GUI::drawBox(-0.1,1.1,-0.5,0.0,1.2,0.5);
                GUI::drawBox(0.1,1.1,-0.5,0.2,1.2,0.5);
                GUI::drawBox(0.3,1.1,-0.5,0.4,1.2,0.5);
                GUI::drawBox(0.5,1.1,-0.5,0.6,1.2,0.5);
            glPopMatrix();
        glPopMatrix();    
    }else{
        glPushMatrix();
            GUI::setColor(0.2,0.2,0.2);
            GUI::drawBox(-0.1,0,-0.1,0.1,1,0.1);
            glPushMatrix();
                GUI::setColor(0.4,0.4,0.4);
                GUI::drawBox(-0.7,1,-0.15,0.7,1.1,0.15);
            glPopMatrix();
            glPushMatrix();
                GUI::setColor(0.6,0.6,0.6);
                GUI::drawBox(-0.7,1.1,-0.5,-0.6,1.2,0.5);
                GUI::drawBox(-0.5,1.1,-0.5,-0.4,1.2,0.5);
                GUI::drawBox(-0.3,1.1,-0.5,-0.2,1.2,0.5);
                GUI::drawBox(-0.1,1.1,-0.5,0.0,1.2,0.5);
                GUI::drawBox(0.1,1.1,-0.5,0.2,1.2,0.5);
                GUI::drawBox(0.3,1.1,-0.5,0.4,1.2,0.5);
                GUI::drawBox(0.5,1.1,-0.5,0.6,1.2,0.5);
            glPopMatrix();
        glPopMatrix();         
    }
}
