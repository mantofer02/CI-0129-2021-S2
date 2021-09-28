#include "../headers/SolucionadorAStar.h"
#include "../headers/Estado.h"
#include "../headers/Solucion.h"
#include "../headers/Lista.h"
#include "../headers/Problema.h"
#include <list>
#include <map>
#include <utility>
#include <cstdlib>
#include <unistd.h>
#include <time.h>
typedef struct timespec walltime_t;

Solucion * SolucionadorAStar::solucione(Problema * problema) {
  walltime_t start;
  walltime_t finish;

  clock_gettime(CLOCK_MONOTONIC, &start);
  
  Estado * inicio = problema->getEstadoInicial();
  std::multimap<int , Estado*> mapaGeneral;



  inicio->setGeneracion(0);

  mapaGeneral.insert(std::make_pair(problema->heuristica(inicio), (inicio)));

  int menorEuristica = problema->heuristica(inicio);

  Estado * estadoMenorEuristica = inicio;
  Estado * aux;

  //Lista * listaGeneral = new Lista();
  Lista * pasos = new Lista();

  Lista * siguienteGen = problema->getSiguientes(inicio);
  
  int i = 0;
  auto it = mapaGeneral.begin();
  int haySolucion = 0;

  while (!haySolucion) {
    haySolucion = problema->esSolucion(it->second);
    
    if (haySolucion == 0) {
      siguienteGen = problema->getSiguientes(it->second);
      while (!siguienteGen->isEmpty()) {
          aux = siguienteGen->front();
          aux->setGeneracion(it->second->getGeneracion() + 1);
          mapaGeneral.insert(std::make_pair(problema->heuristica(aux) + aux->getGeneracion(), (siguienteGen->pop_front())));
      }
    i++;
    mapaGeneral.erase(mapaGeneral.begin());
    it = mapaGeneral.begin();
    }
  }

  pasos->push_back(it->second);

  clock_gettime(CLOCK_MONOTONIC, &finish);
  double elapsed = (finish.tv_sec - start.tv_sec);
  elapsed += (finish.tv_nsec - start.tv_sec ) / 1000000000.0;

  printf("Execution time: %lfs\n", elapsed);

  Solucion * solucionMala = new Solucion(pasos);
  return solucionMala;
}