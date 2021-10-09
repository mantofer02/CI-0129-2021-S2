#include "../headers/SolucionadorSkynet.h"
#include "../headers/Estado.h"
#include "../headers/Solucion.h"
#include "../headers/Lista.h"
#include "../headers/Problema.h"
#include <unistd.h>
#include <time.h>
typedef struct timespec walltime_t;

Solucion * SolucionadorSkynet::solucione( Problema * problema) {
    walltime_t start;
    walltime_t finish;

    clock_gettime(CLOCK_MONOTONIC, &start);



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
    
    clock_gettime(CLOCK_MONOTONIC, &finish);
    double elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_sec ) / 1000000000.0;

    printf("Execution time: %lfs\n", elapsed);

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
