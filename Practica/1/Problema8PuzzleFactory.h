#ifndef PROBLEMA_PUZZLE_FACTORY
#define PROBLEMA_PUZZLE_FACTORY
#include "Fabrica.h"
#include "Problema8Puzzle.h"

class Problema8PuzzleFactory : public Fabrica {
    public:
      Problema8Puzzle * producir();
};

#endif
