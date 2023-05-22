#ifndef pedraFundamental_header
#define pedraFundamental_header

#include "objeto.h"

class pedraFundamental: public Objeto{
    public:
        pedraFundamental();
        pedraFundamental(bool selecionado, bool origem, int tipo);
        pedraFundamental(float Tx, float Ty, float Tz, float Rx, float Ry, float Rz, float Sx, float Sy, float Sz, bool selecionado, bool origem, int tipo);
        void desenha() override;
};

#endif
