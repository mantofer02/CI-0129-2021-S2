#ifndef PUZZLE_PROBLEM_STATE
#define PUZZLE_PROBLEM_STATE

#include "Problema8Puzzle.h"

#include "Estado.h"

class Estado8Puzzle : public Estado {
   friend class Problema8Puzzle;
   private:
      /**
       * @brief Board es el tablero de 8 Puzzle. 
       * Está indexado # ficha y posición. 
       */
      int board[9];
   public:
      Estado8Puzzle();
      Estado8Puzzle * clonar();
      istream& cargar(istream&);
      ostream& imprimir(ostream&);
      int operator==(Estado *);
      int operator!=(Estado *);
};


#endif
