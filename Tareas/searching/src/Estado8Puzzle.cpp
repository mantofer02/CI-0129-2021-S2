#include "../headers/Estado8Puzzle.h"
#include "../headers/Estado.h"

#include<iostream>
using namespace std;

Estado8Puzzle::Estado8Puzzle() {
  /**
   * @brief Se lee asi, en la posicion 0 está la ficha 0,
   * en la posicion 1, esté la ficha 1,
   * en la posicion 2 está la ficha 3, etc...
   */
  
  this->board[0] = 4;
  this->board[1] = 5;
  this->board[2] = 7;
  this->board[3] = 8;
  this->board[4] = 1;
  this->board[5] = 2;
  this->board[6] = 3;
  this->board[7] = 6;
  this->board[8] = 0;
}

Estado8Puzzle * Estado8Puzzle::clonar() {
    Estado8Puzzle * nuevo = new Estado8Puzzle();
    for(int i = 0; i < 9; ++i){
      nuevo->board[i] = this->board[i];
    }
    return nuevo;
}

istream& Estado8Puzzle::cargar(istream& entrada){
  for(int i = 0; i < 9; ++i){
     entrada >> this->board[i];
  }
  return entrada;
}

ostream& Estado8Puzzle::imprimir(ostream& salida){
  int level = 1;
  for (int i = 0; i < 9; ++i) {
    salida << " [";
    if (this->board[i]) {
      salida << this->board[i];
    } else {
      salida << '_';
    }
    salida << "] ";
    if (level%3 == 0) {
      salida << "\n";
    }
    ++level;
  }
  return salida;
}

int Estado8Puzzle::operator==(Estado * otroEstado) {
  Estado8Puzzle * ec = dynamic_cast< Estado8Puzzle * >(otroEstado);
  int esIgual = 0;
  if(ec) {
    esIgual = 1;
    for(int i=0; i < 9; ++i){
      if(this->board[i] != ec->board[i]) {
        esIgual = 0;
        i = 10;
      };
    }
  }
  return esIgual;
}

int Estado8Puzzle::operator!=(Estado * otroEstado) {
  return !(*this==otroEstado);
}

int Estado8Puzzle::sonIguales(Estado * otroEstado) {
  Estado8Puzzle * ec = dynamic_cast< Estado8Puzzle * >(otroEstado);
  int esIgual = 0;
  if(ec) {
    esIgual = 1;
    for(int i=0; i < 9; ++i){
      if(this->board[i] != ec->board[i]) {
        esIgual = 0;
        i = 10;
      };
    }
  }
  return esIgual;
}