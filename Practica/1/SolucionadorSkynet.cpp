#include "SolucionadorSkynet.h"
#include "Estado.h"
#include "Solucion.h"
#include "Lista.h"
#include "Problema.h"
 
Solucion * SolucionadorSkynet::solucione( Problema * problema){
    Estado  * inicio = problema->getEstadoInicial();
    Lista * pasos = problema->getSiguientes( inicio );   
    Solucion * solucionMala = new Solucion( pasos );

    Estado * mejorEstado;

    int tengoSolucion = 0;


    // while (!tengoSolucion) {
      
      for (Lista::Iterador it = pasos->begin(); it != pasos->end(); ++it) {
        std::cout << "Heuristica " << std::endl;
        std::cout << problema->heuristica(*it) << std::endl;
        
      }



  // }   

  delete inicio;
   // La unica cosas que no destruyo es la lista de pasos
  return solucionMala;
}
