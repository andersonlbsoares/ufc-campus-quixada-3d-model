#include "bloco.h"

bloco::bloco(bool selecionado, bool origem, int tipo){
    this->selecionado = selecionado;
    this->origem = origem;
    this->tipo = tipo;
}

bloco::bloco(float Tx, float Ty, float Tz, float Rx, float Ry, float Rz, float Sx, float Sy, float Sz, bool selecionado, bool origem, int tipo){
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

void bloco::desenha(){
    
    Objeto::desenha();

    if(this->origem == 1){
        GUI::drawOrigin(0.5);
    }

    if(this->selecionado == 1){
        GUI::setColor(1,0,0);
        GUI::drawBox(-2,0,-4,2,3,4);
        GUI::drawBox(2.01,0,-3.9,2.3,3,-3.8);
        GUI::drawBox(2.01,0,-3,2.3,3,-3.1);
        GUI::drawBox(2.01,0,-2.1,2.3,3,-2.2);
        GUI::drawBox(2.01,0,-1.2,2.3,3,-1.3);
        GUI::drawBox(2.01,0,-0.3,2.3,3,-0.4);
        GUI::drawBox(2.01,0,0.6,2.3,3,0.5);
        GUI::drawBox(2.01,0,1.5,2.3,3,1.4);
        GUI::drawBox(2.01,0,2.4,2.3,3,2.3);
        GUI::drawBox(2.01,0,3.3,2.3,3,3.2);

        GUI::drawBox(2.01,2.45,-4,2.3,3,4);

        GUI::drawBox(2.01,2.2,-3.9,2.2,2.25,3.2);
        GUI::drawBox(2.01,2,-3.9,2.2,2.05,3.2);
        GUI::drawBox(2.01,1.8,-3.9,2.2,1.85,3.2);

        GUI::drawBox(2.01,2.45,-4,2.3,3,4);
        GUI::drawBox(2.01,0.9,-3.9,2.2,0.95,3.2);
        GUI::drawBox(2.01,0.7,-3.9,2.2,0.75,3.2);
        GUI::drawBox(2.01,0.5,-3.9,2.2,0.55,3.2);
        // Dou outro lado agora

        GUI::drawBox(-2.3,0,-3.9,-1.99,3,-3.8);
        GUI::drawBox(-2.3,0,-3,-1.99,3,-3.1);
        GUI::drawBox(-2.3,0,-2.1,-1.99,3,-2.2);
        GUI::drawBox(-2.3,0,-1.2,-1.99,3,-1.3);
        GUI::drawBox(-2.3,0,-0.3,-1.99,3,-0.4);
        GUI::drawBox(-2.3,0,0.6,-1.99,3,0.5);
        GUI::drawBox(-2.3,0,1.5,-1.99,3,1.4);
        GUI::drawBox(-2.3,0,2.4,-1.99,3,2.3);
        GUI::drawBox(-2.3,0,3.3,-1.99,3,3.2);
        
        GUI::drawBox(-2.3,2.45,-4,-1.99,3,4);

        GUI::drawBox(-2.3,2.2,-3.9,-1.99,2.25,3.2);
        GUI::drawBox(-2.3,2,-3.9,-1.99,2.05,3.2);
        GUI::drawBox(-2.3,1.8,-3.9,-1.99,1.85,3.2);

        GUI::drawBox(-2.3,0.9,-3.9,-1.99,0.95,3.2);
        GUI::drawBox(-2.3,0.7,-3.9,-1.99,0.75,3.2);
        GUI::drawBox(-2.3,0.5,-3.9,-1.99,0.55,3.2);

    }else{
        // GUI::drawBox(x,y,z,X,Y,Z);
        GUI::setColor(0.77,0.89,0.69);
        GUI::drawBox(-2,0,-4,2,3,4);
        GUI::setColor(1,1,1);
        GUI::drawBox(2.01,0,-3.9,2.3,3,-3.8);
        GUI::drawBox(2.01,0,-3,2.3,3,-3.1);
        GUI::drawBox(2.01,0,-2.1,2.3,3,-2.2);
        GUI::drawBox(2.01,0,-1.2,2.3,3,-1.3);
        GUI::drawBox(2.01,0,-0.3,2.3,3,-0.4);
        GUI::drawBox(2.01,0,0.6,2.3,3,0.5);
        GUI::drawBox(2.01,0,1.5,2.3,3,1.4);
        GUI::drawBox(2.01,0,2.4,2.3,3,2.3);
        GUI::drawBox(2.01,0,3.3,2.3,3,3.2);

        GUI::drawBox(2.01,2.45,-4,2.3,3,4);

        GUI::drawBox(2.01,2.2,-3.9,2.2,2.25,3.2);
        GUI::drawBox(2.01,2,-3.9,2.2,2.05,3.2);
        GUI::drawBox(2.01,1.8,-3.9,2.2,1.85,3.2);

        GUI::drawBox(2.01,2.45,-4,2.3,3,4);
        GUI::drawBox(2.01,0.9,-3.9,2.2,0.95,3.2);
        GUI::drawBox(2.01,0.7,-3.9,2.2,0.75,3.2);
        GUI::drawBox(2.01,0.5,-3.9,2.2,0.55,3.2);
        // Dou outro lado agora

        GUI::drawBox(-2.3,0,-3.9,-1.99,3,-3.8);
        GUI::drawBox(-2.3,0,-3,-1.99,3,-3.1);
        GUI::drawBox(-2.3,0,-2.1,-1.99,3,-2.2);
        GUI::drawBox(-2.3,0,-1.2,-1.99,3,-1.3);
        GUI::drawBox(-2.3,0,-0.3,-1.99,3,-0.4);
        GUI::drawBox(-2.3,0,0.6,-1.99,3,0.5);
        GUI::drawBox(-2.3,0,1.5,-1.99,3,1.4);
        GUI::drawBox(-2.3,0,2.4,-1.99,3,2.3);
        GUI::drawBox(-2.3,0,3.3,-1.99,3,3.2);
        
        GUI::drawBox(-2.3,2.45,-4,-1.99,3,4);

        GUI::drawBox(-2.3,2.2,-3.9,-1.99,2.25,3.2);
        GUI::drawBox(-2.3,2,-3.9,-1.99,2.05,3.2);
        GUI::drawBox(-2.3,1.8,-3.9,-1.99,1.85,3.2);

        GUI::drawBox(-2.3,0.9,-3.9,-1.99,0.95,3.2);
        GUI::drawBox(-2.3,0.7,-3.9,-1.99,0.75,3.2);
        GUI::drawBox(-2.3,0.5,-3.9,-1.99,0.55,3.2);


    }

    
}

