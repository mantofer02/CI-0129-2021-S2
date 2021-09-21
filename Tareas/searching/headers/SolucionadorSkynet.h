#ifndef SOLUCIONADOR_SKYNET
#define SOLUCIONADOR_SKYNET
#include "Solucionador.h"

class SolucionadorSkynet : public Solucionador {
   public:
      Solucion * solucione(Problema *);
      Lista * hacerListaPasos(Lista *, Problema *);
};

#endif
