#include "SolucionadorSkynet.h"
#include "Estado.h"
#include "Solucion.h"
#include "Lista.h"
#include "Problema.h"
 
Solucion * SolucionadorSkynet::solucione(Problema * problema) {
    Estado  * inicio = problema->getEstadoInicial();
    // Lista * pasos = problema->getSiguientes(inicio);
    
    Lista * frontera = problema->getSiguientes(inicio);
    Lista * explorados;
    Lista * pasos;
    
    Lista * siguienteGen;
    int haySolucion = 0;
    anchoPrimero(frontera, explorados, inicio, problema);


    // Lista::Iterador it = pasos->begin();
    
    // while (!haySolucion) {
    //   if (problema->esSolucion(*it)) {
    //     haySolucion = 1;
    //     // para meter la ultima, corregir
    //     siguienteGen = problema->getSiguientes(*it);
    //     for (Lista::Iterador sigIt = siguienteGen->begin(); sigIt != siguienteGen->end(); sigIt++)
    //     {
    //       pasos->push_back(*sigIt);
    //     }
    //   } else {
    //     siguienteGen = problema->getSiguientes(*it);
    //     for (Lista::Iterador sigIt = siguienteGen->begin(); sigIt != siguienteGen->end(); sigIt++)
    //     {
    //       pasos->push_back(*sigIt);
    //     }
    //     it++;
    //   }
    // }
    


    Solucion * solucionMala = new Solucion( pasos );
    delete inicio;
    return solucionMala;
}

int SolucionadorSkynet::anchoPrimero(Lista * frontera, Lista * explorados, Estado * padre, Problema * problema) {
  // explorados->push_back(padre);
  Lista::Iterador aux;
  Lista * miniFrontera;
  int haySolucion = 0;

  Estado * estadoAct = frontera->pop_front();
  aux = explorados->buscar(estadoAct);
  if (aux != explorados->end()) {
    explorados->push_back(estadoAct);
  }


  // for (Lista::Iterador it = frontera->begin(); it != frontera->end() && !haySolucion; it++) {
  //   aux = explorados->buscar(*it);
  //   if (aux != explorados->end()) {
  //     explorados->push_back(*aux);
  //     miniFrontera
  //   }
  // }
  
  
  if (!problema->esSolucion(padre)) {

  }
} 