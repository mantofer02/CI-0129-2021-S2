#include "../headers/EstadoTSP.h"
#include "../headers/Estado.h"

#include<iostream>
using namespace std;

EstadoTSP::EstadoTSP() {

  //Generacion del mapa
  srand(time(NULL));
  int columna; 

  list <int> :: iterator it;
  for (int fila = 0; fila < 10; ++fila){
    for (int columna = 0; columna < 10; ++columna){
      this->mapa[fila][columna] = 0;
      this->recorrido[fila][columna] = 0;
    }
  }

  // Se define aunque sea una solucion en caso de que al generar numeros random no haya solución
  this->recorrido[0][3] = 1;
  this->mapa[0][3] = 1;
  this->mapa[1][0] = 1;
  this->mapa[2][7] = 1;
  this->mapa[3][6] = 1;
  this->mapa[4][1] = 1;
  this->mapa[5][9] = 1;
  this->mapa[6][2] = 1;
  this->mapa[7][8] = 1;
  this->mapa[8][5] = 1;
  this->mapa[9][4] = 1;

  for (int fila = 0; fila < 10; ++fila){
      for (int rellenar = 0; rellenar < 2; ++rellenar){
          do{
            columna = rand() % 10;
          }while(columna == fila || this->mapa[fila][columna] == 1 );
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
            cout << "Ingrese un 1 si desea que la fila: "<< fila << ", columna: " << columna << " sea camino para la solución. Ingrese 0 si no desea esto" << endl;
            entrada >> this->recorrido[fila][columna];
            cout << "Ingrese un 1 si desea que la fila: "<< fila << ", columna: " << columna << " sea parte de los caminos disponibles en el mapa. Ingrese 0 si no desea esto" << endl;
            entrada >> this->mapa[fila][columna];
      }
  }  
  return entrada;
}

ostream& EstadoTSP::imprimir(ostream& salida){
   salida << "                                          !MAPA!"<<'\n';

  for (int fila = 0; fila < 10; ++fila) {
      salida << fila+1 << " > \t";
        for (int columna = 0; columna < 10; ++columna) {
              salida << " [ ";
              salida << this->mapa[fila][columna];
              salida << " ] ";
          }
          salida << '\n';
  }
  salida << "           ^      ^      ^      ^      ^      ^      ^      ^      ^      ^" << '\n' << "           1      2      3      4      5      6      7      8      9      10" << '\n';
  salida << "-----------------------------------------------------------------------------------------"<<'\n';
  
  int imprimir = 1;

  salida << "                                   !Recorrido Solucion!"<<'\n';
  for (int fila = 0; fila < 10; ++fila) {
    salida << fila+1 << " > \t";
       for (int columna = 0; columna < 10; ++columna) {
            salida << " [ ";
            salida << ((this->recorrido[fila][columna])? "1" : "_");
            salida << " ] ";
        }
        salida << '\n';
  }
  salida << "           ^      ^      ^      ^      ^      ^      ^      ^      ^      ^" << '\n' << "           1      2      3      4      5      6      7      8      9      10" << '\n';

  return salida;
}

int EstadoTSP::sonIguales(Estado* otroEstado)
{
  EstadoTSP* copiaEstado = dynamic_cast<EstadoTSP*>(otroEstado);

  for (int fila = 0; fila < 10; ++fila)
    for (int columna = 0; columna < 10; ++columna)
      if ((this->recorrido[fila][columna] != copiaEstado->recorrido[fila][columna])||(this->mapa[fila][columna] != copiaEstado->mapa[fila][columna])){
        return false;
      }
  return true;
}

int EstadoTSP::operator==(Estado * otroEstado) {
  EstadoTSP* copiaEstado = dynamic_cast<EstadoTSP*>(otroEstado);

  for (int fila = 0; fila < 10; ++fila)
    for (int columna = 0; columna < 10; ++columna)
      if ((this->recorrido[fila][columna] != copiaEstado->recorrido[fila][columna])||(this->mapa[fila][columna] != copiaEstado->mapa[fila][columna])){
        return false;
      }
  return true;
}

int EstadoTSP::operator!=(Estado * otroEstado) {
  return !(*this==otroEstado);
}