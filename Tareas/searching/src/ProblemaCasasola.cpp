#include "../headers/Lista.h"
#include "../headers/Problema.h"
#include "../headers/ProblemaCasasola.h"
#include "../headers/EstadoCasasola.h"

ProblemaCasasola::ProblemaCasasola(){

}

Estado * ProblemaCasasola::getEstadoInicial(){
   return new EstadoCasasola();
}

int ProblemaCasasola::esSolucion( Estado * estado){
   int esUnaSolucion = 0;//asumo que no
   EstadoCasasola * estadoC = dynamic_cast< EstadoCasasola * >(estado);
   if(estadoC){
      esUnaSolucion = ((estadoC->n[0]+estadoC->n[1]+estadoC->n[2])==12);
   }
   return esUnaSolucion;
}

int ProblemaCasasola::heuristica(Estado * estado){
   int valor = 13; // lejísimos
   EstadoCasasola * estadoC = dynamic_cast< EstadoCasasola * >(estado);
   if(estadoC){ 
      valor = 12 - (estadoC->n[0]+estadoC->n[1]+estadoC->n[2]);
   }
   if(valor<0){
      valor = 13;
   }
   return valor;
}

Lista * ProblemaCasasola::getSiguientes( Estado * estado){
   EstadoCasasola * estadoC = dynamic_cast< EstadoCasasola * >(estado);
   Lista * siguientes = new Lista();
   if(estadoC){
      EstadoCasasola * clon1 = estadoC->clonar();
      ++(clon1->n[0]);
      if(clon1->n[0]<10){
          siguientes->push_back( clon1 );
      } 
      delete clon1;
      EstadoCasasola * clon2 = estadoC->clonar();
      ++(clon2->n[1]);
      if(clon2->n[1]<10){
          siguientes->push_back( clon2 );
      }
      delete clon2; 
      EstadoCasasola * clon3 = estadoC->clonar();
      ++(clon3->n[2]);
      if(clon3->n[2]<10){
          siguientes->push_back( clon3 );
      }
      delete clon3;
   }
   return siguientes;
}
