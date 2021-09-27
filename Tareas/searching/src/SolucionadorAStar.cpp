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

Solucion * SolucionadorAStar::solucione(Problema * problema) {
  Estado * inicio = problema->getEstadoInicial();
  inicio->generacion = 1;

  int * pesos = new int(2);


  std::multimap<int , Estado*> mapaGeneral;


  int menorEuristica = problema->heuristica(inicio);
  int peorEuristica = menorEuristica; 

  Estado * estadoMenorEuristica = inicio;
  Estado * copiaEstadoMenorE = inicio;
  Estado * aux;

  //Lista * listaGeneral = new Lista();
  Lista * pasos = new Lista();
  
  Lista * siguienteGen = problema->getSiguientes(inicio);
  
  while (!siguienteGen->isEmpty())
  {
    aux = siguienteGen->front();
    aux->generacion = inicio->generacion + 1;
    mapaGeneral.insert(std::make_pair(problema->heuristica(aux) + aux->generacion, (siguienteGen->pop_front())));
  }


  auto it = mapaGeneral.begin();

  while (!problema->esSolucion(it->second)) {
    cout << it->first << endl;
    cout << "----------------------" << endl;
    cout << it->second << endl;
  

    siguienteGen = problema->getSiguientes(estadoMenorEuristica);
    std::cout << "gen del OG" << estadoMenorEuristica->generacion << std::endl;
    while (!siguienteGen->isEmpty()) {
      aux = siguienteGen->front();
      aux->generacion = estadoMenorEuristica->generacion + 1;
      std::cout << " gen del HIJO" << aux->generacion << std::endl;
      mapaGeneral.insert(std::make_pair(problema->heuristica(aux) + aux->generacion, (siguienteGen->pop_front())));
    }
    
    usleep(1000000);
    mapaGeneral.erase(mapaGeneral.begin());
    it = mapaGeneral.begin();
  }

  pasos->push_back(it->second);
  Solucion * solucionMala = new Solucion(pasos);
  return solucionMala;
}

