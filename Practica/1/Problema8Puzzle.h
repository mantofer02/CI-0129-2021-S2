#ifndef PUZZLE_PROBLEM
#define PUZZLE_PROBLEM

#include "Problema.h"
#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>

class Problema8Puzzle : public Problema {
   public:
      Problema8Puzzle();
      Estado * getEstadoInicial();
      int esSolucion( Estado * ); 
      int heuristica(Estado *);
      int distanciaManhattan(int, int);
      Lista * getSiguientes( Estado * );
      Estado * swapIzquierda(Estado *, int);
      Estado * swapDerecha(Estado *, int);
      Estado * swapAbjo(Estado *, int);
      Estado * swapArriba(Estado *, int);
};

#endif
