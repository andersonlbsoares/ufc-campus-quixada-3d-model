#include "banco.h"

banco::banco(bool selecionado, bool origem, int tipo){
    this->selecionado = selecionado;
    this->origem = origem;
    this->tipo = tipo;
}

banco::banco(float Tx, float Ty, float Tz, float Rx, float Ry, float Rz, float Sx, float Sy, float Sz, bool selecionado, bool origem, int tipo){
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

void banco::desenha(){
    
    Objeto::desenha();

    if(this->origem == 1){
        GUI::drawOrigin(0.5);
    }

    if(this->selecionado == 1){
        GUI::setColor(1,0,0);
        glPushMatrix();
            GUI::drawBox(-0.5,0,-0.15,0.5,0.3,0.15);
            glPushMatrix();
                GUI::drawBox(-0.55,0.3,-0.20,0.55,0.35,0.2);
            glPopMatrix();
        glPopMatrix();
    }else{
        glPushMatrix();
            GUI::setColor(0.5,0.5,0.5);
            GUI::drawBox(-0.5,0,-0.15,0.5,0.3,0.15);
            glPushMatrix();
                GUI::setColor(0.7,0.7,0.7);
                GUI::drawBox(-0.55,0.3,-0.20,0.55,0.35,0.2);
            glPopMatrix();
        glPopMatrix();
    }
    
}
