#include "Problema8Puzzle.h"
#include "Lista.h"
#include "Problema.h"
#include "Problema8Puzzle.h"
#include "Estado8Puzzle.h"
#include <cmath>

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

Lista *Problema8Puzzle::getSiguientes(Estado * estado) {
  Estado8Puzzle * estado8 = dynamic_cast< Estado8Puzzle * >(estado);
  Lista * siguientes = new Lista();
  if(estado8) {
    int posEspacio;
    int estadosPosibles = 3;
    for (int i = 0; i < 9; ++i) {
      if (estado8->board[i] == 0) {
        posEspacio = i;
        i = 10;
      }
    }
    if (posEspacio == 0 || posEspacio == 2 || posEspacio == 6 || posEspacio == 8) {
      
    }

    // for ( i:4) 
    // switch ()
    // newEstado = swapC
    // 
    
    if (posEspacio == 4) {estadosPosibles = 4;}

  }
}


Estado8Puzzle *Problema8Puzzle::swapIzquierda(Estado8Puzzle * estado, int posNull) {
  Estado8Puzzle * clon1 = estado->clonar();
  if (posNull != 0 || posNull != 3 || posNull != 6){
    clon1->board[posNull] =  clon1->board[posNull-1];
    clon1->board[posNull-1] = 0;
  }else{
    clon1 = nullptr;
  }
  return clon1;
}

Estado8Puzzle *Problema8Puzzle::swapDerecha(Estado8Puzzle * estado, int posNull) {
  Estado8Puzzle * clon1 = estado->clonar();
  if (posNull != 2 || posNull != 5|| posNull != 8){
    clon1->board[posNull] =  clon1->board[posNull+1];
    clon1->board[posNull+1] =  0;
  }else{
    clon1 = nullptr;
  }
  return clon1;
}  

Estado8Puzzle* Problema8Puzzle::swapAbajo(Estado8Puzzle* estado, int posicionEspacio) {
  Estado8Puzzle* resultado = estado->clonar();
  int posicionSuperior = posicionEspacio - 3;

  if (posicionSuperior > 0) {
    resultado->board[posicionEspacio] = resultado->board[posicionSuperior];
    resultado->board[posicionSuperior] = 0;
  } else {
    resultado = nullptr;
  }

  return resultado;
}

Estado8Puzzle* Problema8Puzzle::swapArriba(Estado8Puzzle* estado, int posicionEspacio) {
  Estado8Puzzle* resultado = estado->clonar();
  int posicionInferior = posicionEspacio + 3;

  if (posicionInferior < 9) {
    resultado->board[posicionEspacio] = resultado->board[posicionInferior];
    resultado->board[posicionInferior] = 0;
  } else {
    resultado = nullptr;
  }

  return resultado;

}