#ifndef SOLUCIONADOR_SKYNET_FACTORY
#define SOLUCIONADOR_SKYNET_FACTORY
#include "Fabrica.h"
#include "SolucionadorSkynet.h"

class SolucionadorSkynetFactory : public Fabrica {
    public:
       SolucionadorSkynet * producir();
};

#endif
