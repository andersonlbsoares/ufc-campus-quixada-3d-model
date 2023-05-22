#include "entrada.h"

entrada::entrada(bool selecionado, bool origem, int tipo){
    this->selecionado = selecionado;
    this->origem = origem;
    this->tipo = tipo;
}

entrada::entrada(float Tx, float Ty, float Tz, float Rx, float Ry, float Rz, float Sx, float Sy, float Sz, bool selecionado, bool origem, int tipo){
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

void entrada::desenha(){
    
    Objeto::desenha();

    if(this->origem == 1){
        GUI::drawOrigin(0.5);
    }
    if(this->selecionado == 1){
        GUI::setColor(1,0,0);
        GUI::drawBox(-1,0,-0.5,-0.8,1.5,0.5);
        GUI::drawBox(-0.8,1.3,-0.4,1.5,1.4,-0.2);
        GUI::drawBox(-0.8,1.3,-0.1,1.5,1.4,0.09);
        
        GUI::drawBox(-0.7,1.2,-0.5,1.3,1.3,0.5);
        GUI::drawBox(1.1,0,-0.5,1.7,1.5,0.1);
    }else{
        //GUI::drawBox(x,y,z,X,Y,Z);
        GUI::setColor(0.5,0.5,0.5);
        GUI::drawBox(-1,0,-0.5,-0.8,1.5,0.5);
        GUI::drawBox(-0.8,1.3,-0.4,1.5,1.4,-0.2);
        GUI::drawBox(-0.8,1.3,-0.1,1.5,1.4,0.09);
        
        GUI::setColor(0.9,0.9,0.9);
        GUI::drawBox(-0.7,1.2,-0.5,1.3,1.3,0.5);
        GUI::drawBox(1.1,0,-0.5,1.7,1.5,0.1);

    }
}
