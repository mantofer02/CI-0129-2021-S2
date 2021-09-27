#ifndef MAGIC_PROBLEM
#define MAGIC_PROBLEM

#include "Problema.h"
#include "Lista.h"
#include "EstadoMagicSquare.h"

#define DIAGONALS 2

class ProblemaMagicSquare : public Problema {
   public:
      ProblemaMagicSquare();
      Estado * getEstadoInicial();
      int esSolucion( Estado * );
      int heuristica(Estado *);
      Lista * getSiguientes( Estado * );
      int checkRows(Estado *, int);
      int checkColumns(Estado *, int);
      int checkDiagonals(Estado *, int);
};


#endif
