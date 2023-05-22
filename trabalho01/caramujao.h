#ifndef caramujao_header
#define caramujao_header

#include "objeto.h"

class caramujao: public Objeto{
    public:
        caramujao();
        caramujao(bool selecionado, bool origem, int tipo);
        caramujao(float Tx, float Ty, float Tz, float Rx, float Ry, float Rz, float Sx, float Sy, float Sz, bool selecionado, bool origem, int tipo);
        void desenha() override;
};

#endif
