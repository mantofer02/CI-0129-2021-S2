#include "SolucionadorSkynet.h"
#include "Estado.h"
#include "Solucion.h"
#include "Lista.h"
#include "Problema.h"
#include <unistd.h>
 
Solucion * SolucionadorSkynet::solucione( Problema * problema){
    Estado  * inicio = problema->getEstadoInicial();
    Estado * segundo = problema->getEstadoInicial();


    std::cout << "--------------------PRIMERA CORRIDA------------------------" << std::endl;
    std::cout << (inicio == segundo) << std::endl;
    std::cout << inicio << std::endl;
    std::cout << segundo << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    sleep(1000000);

    Lista * solucion = new Lista();
    Lista * explorados = new Lista();
    Lista * siguienteGen;
    Lista * frontera = problema->getSiguientes(inicio);
    Estado * estadoActual = frontera->pop_front();
    
    solucion->push_front(inicio);
    explorados->push_back(inicio);

    int haySolucion = 0;
    
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
        }
      }
      estadoActual = frontera->pop_front();
    }
    
    //Solucion * solucionMala = new Solucion(hacerListaPasos(explorados, problema));
     Solucion * solucionMala = new Solucion(explorados);
    delete inicio;
    return solucionMala;
}


Lista * SolucionadorSkynet::hacerListaPasos(Lista * explorados, Problema * problema) {
  Lista *pasos = new Lista();
  Lista *siguienteGen;
  Estado *estadoActual;
  Estado *estadoAux;
  int stop = 1;

  if (!explorados->isEmpty())
  {
    estadoActual = explorados->pop_back();
    pasos->push_front(estadoActual);

    while (!explorados->isEmpty())
    {

      estadoActual = explorados->pop_back();
      if (explorados->isEmpty())
      {
        pasos->push_front(estadoActual);
      }
      else
      {
        siguienteGen = problema->getSiguientes(estadoActual);

        while (!siguienteGen->isEmpty())
        {
          estadoAux = siguienteGen->pop_back();
          std::cout << "--------------------------------------------" << std::endl;
          std::cout << (estadoAux == pasos->front()) << std::endl;
          std::cout << "--------------------------------------------" << std::endl;
          // if (estadoAux == pasos->front()) {
          //   pasos->push_front(estadoActual);
          // }

          //   if (stop) {
          //     std::cout << "--------------------------" << std::endl;
          //     std::cout << siguienteGen->pop_back() << std::endl;
          //   }
          //   std::cout << "FRONT" << std::endl;
          //   std::cout << pasos->front() << std::endl;
          // }
          // stop = 0;
        }
      }
    }
  }
  return pasos;
}
