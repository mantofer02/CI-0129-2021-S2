#ifndef SOLUCIONADOR_A_FACTORY
#define SOLUCIONADOR_A_FACTORY
#include "Fabrica.h"
#include "SolucionadorAStar.h"

class SolucionadorAStarFactory : public Fabrica {
    public:
       SolucionadorAStar * producir();
};

#endif
