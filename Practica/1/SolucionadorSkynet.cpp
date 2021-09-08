#include "SolucionadorSkynet.h"
#include "Estado.h"
#include "Solucion.h"
#include "Lista.h"
#include "Problema.h"
 
Solucion * SolucionadorSkynet::solucione( Problema * problema){
    Estado  * inicio = problema->getEstadoInicial();
  
    
    Lista * solucion = new Lista();
    Lista * explorados = new Lista();
    Lista * siguienteGen;
    Lista * frontera = problema->getSiguientes(inicio);
    Estado * estadoActual = frontera->pop_front();
    
    solucion->push_front(inicio);
    explorados->push_back(inicio);



    int haySolucion = 0;

    Lista::Iterador it;
    
    while (!haySolucion) {
      if (explorados->buscar(estadoActual) == explorados->end()) {
        
        if (problema->esSolucion(estadoActual)) {
          haySolucion = 1;
          explorados->push_back(estadoActual);
        } else {
          siguienteGen = problema->getSiguientes(estadoActual);

          while (!siguienteGen->isEmpty()) {
            frontera->push_front(siguienteGen->pop_back());
          }

          explorados->push_back(estadoActual);
          // solucion->push_back(estadoActual);
          estadoActual = frontera->pop_front();
        }
      } else {
        estadoActual = frontera->pop_front();
      }
    }
    
    Solucion * solucionMala = new Solucion(explorados);
    delete inicio;
    return solucionMala;
}
