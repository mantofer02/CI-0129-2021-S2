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
      Estado8Puzzle * swapIzquierda(Estado8Puzzle *, int);
      Estado8Puzzle * swapDerecha(Estado8Puzzle *, int);
      Estado8Puzzle * swapAbjo(Estado8Puzzle *, int);
      Estado8Puzzle * swapArriba(Estado8Puzzle *, int);
};

#endif
