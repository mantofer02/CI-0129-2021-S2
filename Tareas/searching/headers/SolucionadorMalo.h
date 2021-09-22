#ifndef SOLUCIONADOR_CASASOLA
#define SOLUCIONADOR_CASASOLA
#include "Solucionador.h"

class SolucionadorMalo : public Solucionador {
   public:
      Solucion * solucione(Problema *);
};

#endif
