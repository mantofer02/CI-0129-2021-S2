#include "Problema8PuzzleFactory.h"

Problema8Puzzle * Problema8PuzzleFactory :: producir() {
  return new Problema8Puzzle();
}