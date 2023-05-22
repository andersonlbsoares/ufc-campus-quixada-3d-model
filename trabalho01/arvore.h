#ifndef arvore_header
#define arvore_header

#include "objeto.h"

class arvore: public Objeto{
    public:
        arvore();
        arvore(bool selecionado, bool origem, int tipo);
        arvore(float Tx, float Ty, float Tz, float Rx, float Ry, float Rz, float Sx, float Sy, float Sz, bool selecionado, bool origem, int tipo);
        void desenha() override;
};

#endif
