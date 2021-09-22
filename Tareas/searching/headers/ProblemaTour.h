#ifndef TOUR_PROBLEM
#define TOUR_PROBLEM

#include <stdio.h>
#include <stdlib.h>
 #include "Problema.h"
#include "Lista.h"
#include "EstadoTour.h"

class ProblemaTour : public Problema {
   public:
      ProblemaTour();
      Estado * getEstadoInicial();
      int esSolucion( Estado * );
      int heuristica(Estado *);
      Lista * getSiguientes( Estado * );      
};


#endif