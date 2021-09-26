#ifndef MAGIC_SQUARE_PROBLEM_STATE
#define MAGIC_SQUARE_PROBLEM_STATE

#include "ProblemaMagicSquare.h"
#include "Estado.h"
#define SIZE 4

class EstadoMagicSquare : public Estado {
   friend class ProblemaCasasola;
   private:
      int board[SIZE][SIZE];
   public:
      EstadoMagicSquare();
      EstadoMagicSquare * clonar();
      istream& cargar(istream&);
      ostream& imprimir(ostream&);
      int operator==(Estado *);
      int operator!=(Estado *);
      int sonIguales(Estado *);
};


#endif
