#ifndef PROBLEMA_8REINAS_FACTORY
#define PROBLEMA_8REINAS_FACTORY
#include "Fabrica.h"
#include "Problema8Reinas.h"

class Problema8ReinasFactory : public Fabrica {
    public:
       Problema8Reinas * producir();
};

#endif
