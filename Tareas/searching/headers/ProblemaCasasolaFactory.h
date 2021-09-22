#ifndef PROBLEMA_CASASOLA_FACTORY
#define PROBLEMA_CASASOLA_FACTORY
#include "Fabrica.h"
#include "ProblemaCasasola.h"

class ProblemaCasasolaFactory : public Fabrica {
    public:
       ProblemaCasasola * producir();
};

#endif
