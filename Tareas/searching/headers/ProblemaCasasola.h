#ifndef CASA_PROBLEM
#define CASA_PROBLEM

#include "Problema.h"
#include "Lista.h"

class ProblemaCasasola : public Problema {
   public:
      ProblemaCasasola();
      Estado * getEstadoInicial();
      int esSolucion( Estado * );
      int heuristica(Estado *);
      Lista * getSiguientes( Estado * );      
};


#endif
