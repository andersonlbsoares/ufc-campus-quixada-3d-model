#ifndef piso_header
#define piso_header

#include "objeto.h"

class piso: public Objeto{
    public:
        piso();
        piso(bool selecionado, bool origem, int tipo);
        piso(float Tx, float Ty, float Tz, float Rx, float Ry, float Rz, float Sx, float Sy, float Sz, bool selecionado, bool origem, int tipo);
        void desenha() override;
};

#endif
