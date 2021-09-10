#include "SolucionadorSkynet.h"
#include "Estado.h"
#include "Solucion.h"
#include "Lista.h"
#include "Problema.h"
#include <unistd.h>

Solucion * SolucionadorSkynet::solucione( Problema * problema) {
    Estado  * inicio = problema->getEstadoInicial();
    Lista * siguienteGen;
    Lista * explorados = new Lista();
    Lista * frontera = problema->getSiguientes(inicio);
    Estado * estadoActual = frontera->pop_front();
    
    int haySolucion = problema->esSolucion(inicio);
    explorados->push_back(inicio);

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
        }
      }
      estadoActual = frontera->pop_front();
    }
    
    Solucion * solucionMala = new Solucion(hacerListaPasos(explorados, problema));
    delete inicio;
    return solucionMala;
}


Lista * SolucionadorSkynet::hacerListaPasos(Lista * explorados, Problema * problema) {
  Lista *pasos = new Lista();
  Lista *siguienteGen;
  Estado *estadoActual;
  Estado *estadoAux;

  if (!explorados->isEmpty()) {
    estadoActual = explorados->pop_back();
    pasos->push_front(estadoActual);
    
    while (!explorados->isEmpty()) {
      estadoActual = explorados->pop_back();
      if (explorados->isEmpty()) {
        pasos->push_front(estadoActual);
      } else {
        siguienteGen = problema->getSiguientes(estadoActual);
        while (!siguienteGen->isEmpty()) {
          estadoAux = siguienteGen->pop_back();
          if (estadoAux->sonIguales(pasos->front())) {
            pasos->push_front(estadoActual);
          }
        }
      }
    }

  }
  return pasos;
}
