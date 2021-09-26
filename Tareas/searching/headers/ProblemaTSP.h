#ifndef TSP_PROBLEM
#define TSP_PROBLEM

#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <algorithm>
 #include "Problema.h"
#include "Lista.h"
#include "EstadoTSP.h"

class ProblemaTSP : public Problema {
   public:
      ProblemaTSP();
      Estado * getEstadoInicial();
      int esSolucion( Estado * );
      int heuristica(Estado *);
      Lista * getSiguientes( Estado * ); 
};

#endif