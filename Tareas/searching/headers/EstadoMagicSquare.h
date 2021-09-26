#ifndef MAGIC_SQUARE_PROBLEM_STATE
#define MAGIC_SQUARE_PROBLEM_STATE

#include "ProblemaMagicSquare.h"
#include "Estado.h"
#define SIZE 4

class EstadoMagicSquare : public Estado {
   friend class ProblemaMagicSquare;
   private:
      int ** board;
      int * numbers;
      int sum;
      bool * validNumbers;
   public:
      EstadoMagicSquare();
      ~EstadoMagicSquare();
      int ** initBoard();
      int * initNumbers();
      int getSum();
      bool * initValidNumbers();
      EstadoMagicSquare * clonar();
      istream& cargar(istream&);
      ostream& imprimir(ostream&);
      int operator==(Estado *);
      int operator!=(Estado *);
      int sonIguales(Estado *);
};


#endif
