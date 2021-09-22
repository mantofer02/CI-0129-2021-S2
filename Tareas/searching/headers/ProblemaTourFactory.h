#ifndef PROBLEMA_TOUR_FACTORY
#define PROBLEMA_TOUR_FACTORY
#include "Fabrica.h"
#include "ProblemaTour.h"

class ProblemaTourFactory : public Fabrica {
    public:
      ProblemaTour * producir();
};

#endif
