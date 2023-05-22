#ifndef objeto_header
#define objeto_header

#include <gui.h>

class Objeto{
    public:
        Vetor3D translacao = Vetor3D(0,0,0);
        Vetor3D rotacao = Vetor3D(0,0,0);
        Vetor3D escala = Vetor3D(1,1,1);
        
        bool selecionado = false;
        bool origem  = false;

        int tipo = 0;
    
        Objeto();
        virtual void desenha();
        void setSelecionado();
        void setOrigem();
        string getSelecionado();
        Vetor3D getTranslacao();
        Vetor3D getRotacao();
        Vetor3D getEscala();
        int getTipo();
};

#endif
