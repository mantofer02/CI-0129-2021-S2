#include "Problema8Puzzle.h"
#include "Lista.h"
#include "Problema.h"
#include "Problema8Puzzle.h"
#include "Estado8Puzzle.h"

Problema8Puzzle::Problema8Puzzle() {

}

Estado *Problema8Puzzle::getEstadoInicial() {
  return new Estado8Puzzle();
}
int Problema8Puzzle::esSolucion(Estado * estado) {
  int esUnaSolucion = 1;
  Estado8Puzzle * estado8 = dynamic_cast< Estado8Puzzle * >(estado);
    if (estado8) {
      for (int i = 0; i < 8; ++i) {
        if(!(estado8->board[i] == i + 1)) {
          esUnaSolucion = 0;
          i = 10;
        }
      }
      if (esUnaSolucion) {
        esUnaSolucion = !(estado8->board[8]) ? 1 : 0;
      }
    }
}
int Problema8Puzzle::heuristica(Estado *) {

}
Lista *Problema8Puzzle::getSiguientes(Estado *) {

}