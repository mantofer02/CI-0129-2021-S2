#ifndef PUZZLE_PROBLEM
#define PUZZLE_PROBLEM

#include <stdio.h>
#include <stdlib.h>
 #include "Problema.h"
#include "Lista.h"
#include "Estado8Puzzle.h"

class Problema8Puzzle : public Problema {
  public:
    Problema8Puzzle();
    Estado * getEstadoInicial();
    int esSolucion( Estado * ); 
    int heuristica(Estado *);
    int distanciaManhattan(int, int);
    Lista * getSiguientes( Estado * );
    void swapIzquierda(Lista*, Estado*, int);
    void swapDerecha(Lista*, Estado*, int);
    void swapAbajo(Lista*, Estado*, int);
    void swapArriba(Lista*, Estado*, int);
};

#endif
