#ifndef bloco_header
#define bloco_header

#include "objeto.h"

class bloco: public Objeto{
    public:
        bloco();
        bloco(bool selecionado, bool origem, int tipo);
        bloco(float Tx, float Ty, float Tz, float Rx, float Ry, float Rz, float Sx, float Sy, float Sz, bool selecionado, bool origem, int tipo);
        void desenha() override;
};

#endif
