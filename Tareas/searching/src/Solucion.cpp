#include "../headers/Lista.h"
#include "../headers/Solucion.h"

Solucion::Solucion(Lista * listaPtr){
   this->lista= listaPtr;
}

Solucion::~Solucion(){
   if(lista){
      delete lista;
   }
}

