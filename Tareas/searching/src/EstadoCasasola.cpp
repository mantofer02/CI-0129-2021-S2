#include "EstadoCasasola.h"
#include "Estado.h"

#include<iostream>
using namespace std;

EstadoCasasola::EstadoCasasola(){
  for(int i=0; i<3; ++i){
    n[i]=0;
  }
}

EstadoCasasola * EstadoCasasola::clonar(){
    EstadoCasasola * nuevo= new EstadoCasasola();
    for(int i=0; i<3; ++i){
       nuevo->n[i]= this->n[i];
    }
    return nuevo;
}

istream& EstadoCasasola::cargar(istream& entrada){
  for(int i=0; i<3; ++i){
     entrada >> n[i];
  }
  return entrada;
}

ostream& EstadoCasasola::imprimir(ostream& salida){
   salida << " [" << n[0] << "|" << n[1] << "|" << n[2] << "] ";
   return salida;
}

int EstadoCasasola::operator==(Estado * otroEstado){
    EstadoCasasola * ec = dynamic_cast< EstadoCasasola * >(otroEstado);
    int esIgual = 0;
    if(ec){
       esIgual = 1;
       for(int i=0; esIgual && i<3; ++i){
          esIgual = this->n[i]== ec->n[i];
       }
    }
    return esIgual;
}

int EstadoCasasola::operator!=(Estado * otroEstado){
   return !(*this==otroEstado);
}
