#ifndef PROBLEMA_P_FACTORY
#define PROBLEMA_P_FACTORY
#include "Fabrica.h"
#include "ProblemaSungJae.h"

class ProblemaSungJaeFactory : public Fabrica {
    public:
      ProblemaSungJae * producir();
};

#endif
