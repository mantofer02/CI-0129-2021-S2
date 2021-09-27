#include "../headers/ProblemaMagicSquare.h"
#include "../headers/EstadoMagicSquare.h"
#include "../headers/Lista.h"
#include "../headers/Problema.h"
#include <cmath>

ProblemaMagicSquare::ProblemaMagicSquare() {

}

Estado *ProblemaMagicSquare::getEstadoInicial() {
  return new EstadoMagicSquare();
}

int ProblemaMagicSquare::esSolucion(Estado * estado) {
  int esUnaSolucion = 0;
  EstadoMagicSquare * estadoMS = dynamic_cast< EstadoMagicSquare * >(estado);
    if (estadoMS) {
      int esUnaSolucion = 1;
      int sum = estadoMS->getSum();
      for (int i = 0; i < SIZE; i++) {
        if (checkRows(estadoMS, i) != sum || checkColumns(estadoMS, i) != sum) {
          esUnaSolucion = 0;
          i = SIZE;
        }
      }
      if (esUnaSolucion) {
        for (int d = 0; d < DIAGONALS; d++) {
          if (checkDiagonals(estadoMS, d) != sum) {
            esUnaSolucion = 0;
            d = DIAGONALS;
          }
        }
      }
    }
    return esUnaSolucion;
}

int ProblemaMagicSquare::checkRows(Estado * estado, int rowNum) {
  int total = 0;
  EstadoMagicSquare * estadoMS = dynamic_cast< EstadoMagicSquare * >(estado);
  if (rowNum < SIZE) {
    for (int j = 0; j < SIZE; j++) {
      total +=  estadoMS->board[rowNum][j];
    }
  }
  return total;
}

int ProblemaMagicSquare::checkColumns(Estado * estado, int colNum) {
  int total = 0;
  EstadoMagicSquare * estadoMS = dynamic_cast< EstadoMagicSquare * >(estado);
  if (colNum < SIZE) {
    for (int i = 0; i < SIZE; i++) {
      total +=  estadoMS->board[i][colNum];
    }
  }
  return total;
}

int ProblemaMagicSquare::checkDiagonals(Estado * estado, int diagNum) {
  int total = 0;
  EstadoMagicSquare * estadoMS = dynamic_cast< EstadoMagicSquare * >(estado);
  if (diagNum < DIAGONALS) {
    if (diagNum == 0) {
      for (int i = 0; i < SIZE; i++) {
        total += estadoMS->board[i][i];
      }
    } else {
      int j = SIZE - 1;
      for (int i = 0; i < SIZE; i++) {
        total += estadoMS->board[i][j];
        --j;
      }
    }
  }
  return total;
}


int ProblemaMagicSquare::heuristica(Estado * estado) {
  int valor = -1;
  EstadoMagicSquare * estadoMS = dynamic_cast< EstadoMagicSquare *>(estado);
  if (estadoMS) {
    int sumaParcial = 0;
    int sum = estadoMS->getSum();

    for (int i = 0; i < SIZE; i++) {
      sumaParcial += abs(checkRows(estadoMS, i) - sum);        
      sumaParcial += abs(checkColumns(estadoMS, i) - sum); 
    }
      
    for (int d = 0; d < DIAGONALS; d++) {
      sumaParcial += abs(checkDiagonals(estadoMS, d) - sum);
    }
  }
  return valor;
}


Lista *ProblemaMagicSquare::getSiguientes(Estado * estado) {
  EstadoMagicSquare * estadoMS = dynamic_cast< EstadoMagicSquare * >(estado);
  Lista * siguientes = new Lista();
  EstadoMagicSquare * clon;
  if(estadoMS) {
    
    int estaLleno = 1;
    int ultimoNumero = 0;
    
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        ultimoNumero = estadoMS->board[i][j];
        if (estadoMS->board[i][j] == 0) {
          for (int k = 0; k < SIZE*SIZE; k++) {
            if (estadoMS->validNumbers[k] == true) {
              clon = estadoMS->clonar();

              // std::cout << "OG TIENE UN " << estadoMS->numbers[k] << std::endl;
              // std::cout << "HIJO VA A TENER UN " <<  clon->numbers[k] << std::endl; 

              clon->board[i][j] = clon->numbers[k];
              
              clon->invalidateNumbers();
              clon->validNumbers[k] = false;

              std::cout << "ESTADO OG" << std::endl;
              std::cout << estadoMS << std::endl;
              std::cout << "ESTADO HIJO" << std::endl;
              std::cout << clon << std::endl;

              siguientes->push_back(clon);
            }
          }
          estaLleno = 0;
          i = SIZE;
          j = SIZE;
        }
      }
    }

    if (estaLleno) {
      clon = new EstadoMagicSquare();
      clon->board[0][0] = ultimoNumero;

      for (int k = 0; k < SIZE*SIZE; k++) {
        if (clon->numbers[k] == ultimoNumero) {
          clon->validNumbers[k] = false;
        }
      }
      siguientes->push_back(clon);
    }
  }
  return siguientes;
}

