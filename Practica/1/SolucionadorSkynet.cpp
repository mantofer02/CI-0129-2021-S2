#include "SolucionadorSkynet.h"
#include "Estado.h"
#include "Solucion.h"
#include "Lista.h"
#include "Problema.h"
 
Solucion * SolucionadorSkynet::solucione(Problema * problema) {
    // Obtener estado inicial.
    Estado * inicio = problema->getEstadoInicial();
    // Obtener pasos posibles y guardarlos en una lista.
    Lista * posiblesSiguientes = problema->getSiguientes(inicio);
    Lista* pasosSolucion = new Lista();

    // Lista de pasos para solucionar el 8Puzzle.
    Lista * siguienteGen;   
    Estado * mejorEstado;

    // Iterador
    Lista::Iterador estadoConMenorEuristica = posiblesSiguientes->begin(); 
    int menorEuristica = problema->heuristica(*estadoConMenorEuristica);
    int tengoSolucion = 0;

      
    for (Lista::Iterador it = posiblesSiguientes->begin(); it != posiblesSiguientes->end(); ++it) {
      if (problema->heuristica(*it) < menorEuristica) {
        menorEuristica = problema->heuristica(*it);
        estadoConMenorEuristica = it;
      }
    }

    // Ahora vuelve a sacar los siguientes pero del estado con menor eurística.
    siguienteGen = problema->getSiguientes(*estadoConMenorEuristica);
    pasosSolucion->push_back(*estadoConMenorEuristica);
    tengoSolucion = problema->esSolucion(*estadoConMenorEuristica);

    while (!tengoSolucion) {
      for (Lista::Iterador it = siguienteGen->begin(); it != siguienteGen->end(); ++it) {
        if (problema->heuristica(*it) < menorEuristica) {
          menorEuristica = problema->heuristica(*it);
          estadoConMenorEuristica = it;
        }
      }    
      siguienteGen = problema->getSiguientes(*estadoConMenorEuristica);
      pasosSolucion->push_back(*estadoConMenorEuristica);
      tengoSolucion = problema->esSolucion(*estadoConMenorEuristica);
    }
    
    Solucion * solucionMala = new Solucion( pasosSolucion );
    delete inicio;
    return solucionMala;
}
