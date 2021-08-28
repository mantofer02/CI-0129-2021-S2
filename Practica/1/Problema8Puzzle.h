#ifndef PUZZLE_PROBLEM
#define PUZZLE_PROBLEM

#include "Problema.h"
#include "Lista.h"

class Problema8Puzzle : public Problema {
   public:
      Problema8Puzzle();
      Estado * getEstadoInicial();
      int esSolucion( Estado * );
      int heuristica(Estado *);
      Lista * getSiguientes( Estado * );      
};


#endif
