#include "../headers/EstadoTSP.h"
#include "../headers/Estado.h"

#include<iostream>
using namespace std;

EstadoTSP::EstadoTSP() {
  /**
   * @brief Se lee asi, en la posicion 0 está la ficha 0,
   * en la posicion 1, esté la ficha 1,
   * en la posicion 2 está la ficha 3, etc...
   */

  //Generacion del mapa
  srand(time(NULL));
  int columna;

  for (int fila = 0; fila < 10; ++fila){
    for (int columna = 0; columna < 10; ++columna){
      this->mapa[fila][columna] = 0;
      this->recorrido[fila][columna] = 0;
    }
  }

  for (int fila = 0; fila < 10; ++fila){
      for (int rellenar = 0; rellenar < 3; ++rellenar){
          
          do{
            columna = rand() % 9;
          }while(columna == fila || (this->mapa[fila][columna] == 1));
          if(fila == 0 && rellenar == 1){
            this->recorrido[0][columna] = 1;
          }
          this->mapa[fila][columna] = 1;
      }
  }
}

EstadoTSP * EstadoTSP::clonar() {
    EstadoTSP * nuevoEstado = new EstadoTSP();
    for (int fila = 0; fila < 10; ++fila){
        for (int columna = 0; columna < 10; ++columna){
            nuevoEstado->recorrido[fila][columna] = this->recorrido[fila][columna];
            nuevoEstado->mapa[fila][columna] = this->mapa[fila][columna];
        }
    }
    return nuevoEstado;
}

istream& EstadoTSP::cargar(istream& entrada){

  for (int fila = 0; fila < 10; ++fila){
      for (int columna = 0; columna < 10; ++columna){
            entrada >> this->recorrido[fila][columna];
      }
  }  
  return entrada;
}

ostream& EstadoTSP::imprimir(ostream& salida){
  for (int fila = 0; fila < 10; ++fila) {
    salida << fila+1 << "--> \t";
       for (int columna = 0; columna < 10; ++columna) {
            salida << " [ ";
            salida << this->recorrido[fila][columna];
            salida << " ] ";
        }
        salida << '\n';
  }

  cout << "------------" <<endl;
  for (int fila = 0; fila < 10; ++fila) {
    salida << fila+1 << "--> \t";
       for (int columna = 0; columna < 10; ++columna) {
            salida << " [ ";
            salida << this->mapa[fila][columna];
            salida << " ] ";
        }
        salida << '\n';
  }


  return salida;
}

int EstadoTSP::sonIguales(Estado* otroEstado)
{
  EstadoTSP* copiaEstado = dynamic_cast<EstadoTSP*>(otroEstado);

  for (int fila = 0; fila < 10; ++fila)
    for (int columna = 0; columna < 10; ++columna)
      if (this->recorrido[fila][columna] != copiaEstado->recorrido[fila][columna])
        return false;

  return true;
}

int EstadoTSP::operator==(Estado * otroEstado) {
  EstadoTSP* copiaEstado = dynamic_cast<EstadoTSP*>(otroEstado);

  for (int fila = 0; fila < 10; ++fila)
    for (int columna = 0; columna < 10; ++columna)
      if (this->recorrido[fila][columna] != copiaEstado->recorrido[fila][columna])
        return false;

  return true;
}

int EstadoTSP::operator!=(Estado * otroEstado) {
  return !(*this==otroEstado);
}