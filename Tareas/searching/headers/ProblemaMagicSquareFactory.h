#ifndef PROBLEMA_MAGICSQUARE_FACTORY
#define PROBLEMA_MAGICSQUARE_FACTORY
#include "Fabrica.h"
#include "ProblemaMagicSquare.h"

class ProblemaMagicSquareFactory : public Fabrica {
    public:
      ProblemaMagicSquare * producir();
};

#endif
