#ifndef PROBLEMA_TSP_FACTORY
#define PROBLEMA_TSP_FACTORY
#include "Fabrica.h"
#include "ProblemaTSP.h"

class ProblemaTSPFactory : public Fabrica {
    public:
       ProblemaTSP * producir();
};

#endif