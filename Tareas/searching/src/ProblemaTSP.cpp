#include "../headers/Lista.h"
#include "../headers/Problema.h"
#include "../headers/ProblemaTSP.h"
#include "../headers/EstadoTSP.h"

ProblemaTSP::ProblemaTSP(){

}

Estado * ProblemaTSP::getEstadoInicial(){
   return new EstadoTSP();
}

int ProblemaTSP::esSolucion( Estado * estado){
   int esUnaSolucion = 1;//asumo que si
   int vecesRecorridas = 0;
   list <int> listaVisitados;
   list <int> :: iterator it;
   EstadoTSP * estadoT = dynamic_cast< EstadoTSP * >(estado);
   for(int filas = 0; filas < 10; filas++){
      //cout  << "NOSRAIDEAAN" << endl;
      for(int columnas = 0; columnas < 10; columnas++){
         //cout  << "RUSTT" << endl;
         if(estadoT->recorrido[filas][columnas]==1){
            vecesRecorridas++;
         }
         it = find ( listaVisitados.begin() , listaVisitados.end() , columnas) ;
         if(it == listaVisitados.end()){
            listaVisitados.push_back(columnas);
         }else{
            esUnaSolucion = 0;
            filas = 10;
            columnas = 10;
         }
      }
      if(vecesRecorridas != 1){
         esUnaSolucion = 0;
         filas = 10;
      }
      vecesRecorridas = 0;
   }
   return esUnaSolucion;
}

int ProblemaTSP::heuristica(Estado * estado){
   int faltantes = 10; 
   list <int> listaVisitados;
   list <int> :: iterator it;
   EstadoTSP * estadoT = dynamic_cast< EstadoTSP * >(estado);
   for(int filas = 0; filas < 10; filas++){
      for(int columnas = 0; columnas < 10; columnas++){
         if(estadoT->recorrido[filas][columnas]==1){
            it = find ( listaVisitados.begin() , listaVisitados.end() , columnas) ;
            if(it == listaVisitados.end()){
               faltantes--;
               columnas = 10;
               listaVisitados.push_back(columnas);
            }else{
               faltantes = 10; 
               columnas = 10;
               filas = 10;
            }
            
         }
      }
   }
   return faltantes;
}

Lista * ProblemaTSP::getSiguientes( Estado * estado){
   
   int visitado = 0;
   list <int> listaVisitados;
   list <int> :: iterator it;
   EstadoTSP * estadoT = dynamic_cast< EstadoTSP * >(estado);
   Lista * siguientesEstados = new Lista();
   
   if(estadoT){
      for(int filas = 0; filas < 10; filas++){
         //cout  << "AYUDADENTROOOO" << endl;
         for(int columnas = 0; columnas < 10; columnas++ ){
            //cout  << "AYUDAMASADENTROOOO" << endl;
            if(estadoT->recorrido[filas][columnas] == 1){
               //cout  << "TRAMAZON" << endl;
               it = find ( listaVisitados.begin() , listaVisitados.end() , filas) ;
               if(it == listaVisitados.end()){
                  //cout  << "CASA" << endl;
                  listaVisitados.push_back(filas);
                  if(columnas != 0){
                     //cout  << "SOLA" << endl;
                     filas = columnas-1;
                  }else{
                     //cout  << "MIA" << endl;
                     filas = columnas;
                  }
               }
               visitado = 1;
               columnas = 10;
            }
         }
         if(visitado == 0){
             for(int caminos = 0; caminos < 10; caminos++ ){
                if(estadoT->mapa[filas][caminos] == 1){
                   EstadoTSP* estadoClonado = estadoT->clonar();
                   estadoClonado->recorrido[filas][caminos] = 1;
                   siguientesEstados->push_back(estadoClonado);
                   delete estadoClonado;
                }
             }
             filas = 10;
         }else{
            visitado = 0;
         }
      }
   }
   return siguientesEstados;
}