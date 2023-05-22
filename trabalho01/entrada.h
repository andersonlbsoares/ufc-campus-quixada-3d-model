#ifndef entrada_header
#define entrada_header

#include "objeto.h"

class entrada: public Objeto{
    public:
        entrada();
        entrada(bool selecionado, bool origem, int tipo);
        entrada(float Tx, float Ty, float Tz, float Rx, float Ry, float Rz, float Sx, float Sy, float Sz, bool selecionado, bool origem, int tipo);
        void desenha() override;
};

#endif
