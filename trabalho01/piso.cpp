#include "piso.h"

piso::piso(bool selecionado, bool origem, int tipo){
    this->selecionado = selecionado;
    this->origem = origem;
    this->tipo = tipo;
}

piso::piso(float Tx, float Ty, float Tz, float Rx, float Ry, float Rz, float Sx, float Sy, float Sz, bool selecionado, bool origem, int tipo){
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

void piso::desenha(){
    
    Objeto::desenha();

    if(this->origem == 1){
        GUI::drawOrigin(0.5);
    }

    if(this->selecionado == 1){
        GUI::setColor(1,0,0);
        GUI::drawBox(-0.5,0,-0.5,0.5,0.05,0.5);
    }else{
        GUI::setColor(0.4,0.42,0.36);
        GUI::drawBox(-0.5,0,-0.5,0.5,0.05,0.5);
    }
    
}


