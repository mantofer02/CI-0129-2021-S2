#include "../headers/EstadoMagicSquare.h"

EstadoMagicSquare::EstadoMagicSquare() {
  this->numbers = initNumbers();
  this->sum = getSum();
  this->validNumbers = initValidNumbers();
}

EstadoMagicSquare::~EstadoMagicSquare() {
  if (this->numbers) {delete this->numbers;}
  if (this->validNumbers) {delete this->validNumbers;}
}

int EstadoMagicSquare::getSum() {
  return (SIZE*(SIZE*SIZE + 1))/2;
}

int * EstadoMagicSquare::initNumbers() {
  int size = SIZE * SIZE;
  int * numbers = new int[size];
  
  for (int i = 0; i < size; i++) {
    numbers[i] = i + 1;
  }
  
  return numbers;
}

int ** EstadoMagicSquare::initBoard() {
  int ** board = new int*[SIZE];
  for (int i = 0; i < SIZE; i++) {
    board[i] = new int[SIZE];
    for (int j = 0; j < SIZE; j++) {
      board[i][j] = 0;
    }
  }

  return board;
}

bool * EstadoMagicSquare::initValidNumbers() {
  int size = SIZE * SIZE;
  bool * validNumbers = new bool[size];

  for (int i = 0; i < size; i++) {
    validNumbers[i] = true;
  }

  return validNumbers;
}

EstadoMagicSquare * EstadoMagicSquare::clonar() {
  EstadoMagicSquare * nuevo = new EstadoMagicSquare();
  
  for (int i = 0; i < SIZE; i++) {
    for(int j = 0; j < SIZE; j++) {
      nuevo->board[i][j] = this->board[i][j];
    }
  }

  return nuevo;
}

istream& EstadoMagicSquare::cargar(istream& entrada) {
  // no hace nada
}

ostream& EstadoMagicSquare::imprimir(ostream& salida) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      salida << "[";
      if (this->board[i][j] == 0) {
        salida << " ";
      } else {
        salida << this->board[i][j];
      }
      salida << "]";
    }
    salida << endl; 
  }
}

int EstadoMagicSquare::operator==(Estado * otroEstado) {
  EstadoMagicSquare * ec = dynamic_cast< EstadoMagicSquare * >(otroEstado);
  int esIgual = 0;
  if(ec && (ec->getSum() == this->getSum())) {
    esIgual = 1;
    for(int i=0; i < SIZE; ++i) {
      for (int j = 0; j < SIZE; j++) {
        if (this->board[i][j] != ec->board[i][j]) {
          esIgual = 0;
          j = SIZE;
          i = SIZE;
        }
      }
    }
  }
  return esIgual;
}

int EstadoMagicSquare::operator!=(Estado * otroEstado) {
  return !sonIguales(otroEstado);
}

int EstadoMagicSquare::sonIguales(Estado * otroEstado) {
  EstadoMagicSquare * ec = dynamic_cast< EstadoMagicSquare * >(otroEstado);
  int esIgual = 0;
  if(ec && (ec->getSum() == this->getSum())) {
    esIgual = 1;
    for(int i=0; i < SIZE; ++i) {
      for (int j = 0; j < SIZE; j++) {
        if (this->board[i][j] != ec->board[i][j]) {
          esIgual = 0;
          j = SIZE;
          i = SIZE;
        }
      }
    }
  }
  return esIgual;
}