#ifndef banco_header
#define banco_header

#include "objeto.h"

class banco: public Objeto{
    public:
        banco();
        banco(bool selecionado, bool origem, int tipo);
        banco(float Tx, float Ty, float Tz, float Rx, float Ry, float Rz, float Sx, float Sy, float Sz, bool selecionado, bool origem, int tipo);
        void desenha() override;
};

#endif
