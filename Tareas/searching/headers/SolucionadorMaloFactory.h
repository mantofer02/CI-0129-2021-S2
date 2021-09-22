#ifndef SOLUCIONADOR_MALO_FACTORY
#define SOLUCIONADOR_MALO_FACTORY
#include "Fabrica.h"
#include "SolucionadorMalo.h"

class SolucionadorMaloFactory : public Fabrica {
    public:
       SolucionadorMalo * producir();
};

#endif
