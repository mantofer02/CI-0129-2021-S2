#ifndef MAGIC_PROBLEM
#define MAGIC_PROBLEM

#include "Problema.h"
#include "Lista.h"

class ProblemaMagicSquare : public Problema {
   public:
      ProblemaMagicSquare();
      Estado * getEstadoInicial();
      int esSolucion( Estado * );
      int heuristica(Estado *);
      Lista * getSiguientes( Estado * );      
};


#endif
