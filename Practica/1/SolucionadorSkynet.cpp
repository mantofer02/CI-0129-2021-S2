#include "SolucionadorSkynet.h"
#include "Estado.h"
#include "Solucion.h"
#include "Lista.h"
#include "Problema.h"
 
Solucion * SolucionadorSkynet::solucione( Problema * problema){
    Estado  * inicio = problema->getEstadoInicial();
  
    
    Lista * solucion = new Lista();
    Lista * explorados = new Lista();
    Lista * frontera = problema->getSiguientes(inicio);
    Estado * estadoActual = frontera->pop_front();
    
    solucion->push_front(inicio);
    explorados->push_back(inicio);

    

    int haySolucion = 0;

    Lista::Iterador it;
    
    while (!haySolucion) {
      if (explorados->buscar(estadoActual) == explorados->end()) {
        std::cout << "NOT FAIL" << std::endl;
        if (problema->esSolucion(estadoActual)) {
          haySolucion = 1;
        } else {
          siguienteGen = problema->getSiguientes(estadoActual);
          for (it = siguienteGen->begin(); it != siguienteGen->end(); it++) {
            frontera->push_back(*it);
          }
          explorados->push_back(estadoActual);
          solucion->push_back(estadoActual);
          estadoActual = frontera->pop_back();
        }
      } else {
        solucion->pop_back();
        estadoActual = frontera->pop_back();
      }
    }
    
    Solucion * solucionMala = new Solucion(solucion);
    delete inicio;
    return solucionMala;
}
