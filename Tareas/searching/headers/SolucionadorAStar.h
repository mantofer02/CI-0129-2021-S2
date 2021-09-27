#ifndef SOLUCIONADOR_ASTAR
#define SOLUCIONADOR_ASTAR
#include "Solucionador.h"

class SolucionadorAStar : public Solucionador {
   public:
      Solucion * solucione(Problema *);
};

#endif
