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
int Problema8Puzzle::heuristica(Estado * estado) {
  int valor = 0;
  Estado8Puzzle * estado8 = dynamic_cast< Estado8Puzzle *>(estado);
  if (estado8) {
    for (int i = 0; i < 9; ++i) {
      valor += distanciaManhattan(i, estado8->board[i]);
    }
  }
  return valor;
}

int Problema8Puzzle::distanciaManhattan(int posicion, int ficha) {
  int filaFicha = (int)posicion/3;
  int colFicha = posicion%3;

  int filaIdeal = ((int)ficha/3) - 1;
  if (ficha- 1 < 0) {filaIdeal = 2;}
  int colIdeal = (ficha - 1)%3;
  if (ficha - 1 < 0) {colIdeal = 2;}

  return (abs(filaIdeal - filaFicha) + abs(colIdeal - colFicha));
}

Lista *Problema8Puzzle::getSiguientes(Estado *) {

}