#include "objeto.h"

Objeto::Objeto(){

}

void Objeto::desenha(){
    glTranslatef(translacao.x,translacao.y,translacao.z);
    glRotatef(rotacao.z,0,0,1);
    glRotatef(rotacao.y,0,1,0);
    glRotatef(rotacao.x,1,0,0);
    glScalef(escala.x,escala.y,escala.z);
}

void Objeto::setSelecionado(){
    if(this->selecionado == 1){
        this->selecionado = 0;
    }else{
        this->selecionado = 1;
    }
}

void Objeto::setOrigem(){
    if(this->origem == 1){
        this->origem = 0;
    }else{
        this->origem = 1;
    }
}

string Objeto::getSelecionado(){
    if(this->selecionado == 1){
        return "Selecionado";
    }else{
        return "Nao selecionado";
    }
}

Vetor3D Objeto::getTranslacao(){
    return this->translacao;
}

Vetor3D Objeto::getRotacao(){
    return this->rotacao;
}

Vetor3D Objeto::getEscala(){
    return this->escala;
}

int Objeto::getTipo(){
    return this->tipo;
}
