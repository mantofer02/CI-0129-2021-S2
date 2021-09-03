#include "Problema8Puzzle.h"
#include "Lista.h"
#include "Problema.h"
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
    return esUnaSolucion;
}
int Problema8Puzzle::heuristica(Estado * estado) {
  int valor = 0;
  Estado8Puzzle * estado8 = dynamic_cast< Estado8Puzzle *>(estado);
  if (estado8) {
    for (int i = 0; i < 9; ++i) {
      // std::cout << "VALOR ACTUAL " << valor << std::endl;
      valor += distanciaManhattan(i, estado8->board[i]);
    }
  }
  return valor;
}

int Problema8Puzzle::distanciaManhattan(int posicion, int ficha) {
  int filaFicha = (int)posicion / 3;
  int colFicha = posicion % 3;

  int filaIdeal = (int)(ficha - 1) / 3;
  int colIdeal = (ficha - 1) % 3;

  if (ficha - 1 < 0) {
    filaIdeal = 2;
    colIdeal = 2;
  }

  // std::cout << "FICHA " << ficha << " en posicion " << posicion << std::endl;
  // std::cout << "Manhattan " << abs(filaIdeal - filaFicha) + abs(colIdeal - colFicha) << std::endl;

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
    swapIzquierda(siguientes, estado8, posEspacio);
    swapDerecha(siguientes, estado8, posEspacio);
    swapArriba(siguientes, estado8, posEspacio);
    swapAbajo(siguientes, estado8, posEspacio);
  }
  return siguientes;
}

void Problema8Puzzle::swapIzquierda(Lista * siguientes, Estado * estado, int posNull) {
  Estado8Puzzle * estado8 = dynamic_cast< Estado8Puzzle * >(estado);
  Estado8Puzzle * clon1 = estado8->clonar();

  if (posNull != 0 && posNull != 3 && posNull != 6){
    std::cout << posNull << std::endl;
    clon1->board[posNull] =  clon1->board[posNull - 1];
    clon1->board[posNull-1] = 0;
  } else{
    clon1 = nullptr;
  }
  if (clon1) {
    siguientes->push_back(clon1);
  }
}

void Problema8Puzzle::swapDerecha(Lista * siguientes, Estado * estado, int posNull) {
  Estado8Puzzle * estado8 = dynamic_cast< Estado8Puzzle * >(estado);
  Estado8Puzzle * clon1 = estado8->clonar();

  if (posNull != 2 && posNull != 5 && posNull != 8){
    clon1->board[posNull] =  clon1->board[posNull+1];
    clon1->board[posNull+1] =  0;
  }else{
    clon1 = nullptr;
  }

  if (clon1) {
    siguientes->push_back(clon1);
  }
}  

void Problema8Puzzle::swapAbajo(Lista * siguientes, Estado* estado, int posicionEspacio) {
  Estado8Puzzle * estado8 = dynamic_cast< Estado8Puzzle * >(estado);
  Estado8Puzzle * resultado = estado8->clonar();

  int posicionSuperior = posicionEspacio - 3;

  if (posicionSuperior > 0) {
    resultado->board[posicionEspacio] = resultado->board[posicionSuperior];
    resultado->board[posicionSuperior] = 0;
  } else {
    resultado = nullptr;
  }
  if (resultado) {
    siguientes->push_back(resultado);
  }
}

void Problema8Puzzle::swapArriba(Lista * siguientes, Estado* estado, int posicionEspacio) {
  Estado8Puzzle * estado8 = dynamic_cast< Estado8Puzzle * >(estado);
  Estado8Puzzle * resultado = estado8->clonar();

  int posicionInferior = posicionEspacio + 3;

  if (posicionInferior < 9) {
    resultado->board[posicionEspacio] = resultado->board[posicionInferior];
    resultado->board[posicionInferior] = 0;
  } else {
    resultado = nullptr;
  }
  if (resultado) {
    siguientes->push_back(resultado);
  }
}