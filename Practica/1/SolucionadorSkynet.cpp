#include "SolucionadorSkynet.h"
#include "Estado.h"
#include "Solucion.h"
#include "Lista.h"
#include "Problema.h"
 
Solucion * SolucionadorSkynet::solucione( Problema * problema){
    Estado  * inicio = problema->getEstadoInicial();
    Lista * pasos = problema->getSiguientes(inicio);
    Lista * siguienteGen;   

    Estado * mejorEstado;

    Lista::Iterador estadoConMenorEuristica = pasos->begin();
    int menorEuristica = problema->heuristica(*estadoConMenorEuristica); 
    int tengoSolucion = 0;

      
    for (Lista::Iterador it = pasos->begin(); it != pasos->end(); ++it) {
      if (problema->heuristica(*it) < menorEuristica) {
        menorEuristica = problema->heuristica(*it);
        estadoConMenorEuristica = it;
      }
    }

    siguienteGen = problema->getSiguientes(*estadoConMenorEuristica);
    pasos->push_back(*estadoConMenorEuristica);

    while (!tengoSolucion) {
      for (Lista::Iterador it = siguienteGen->begin(); it != siguienteGen->end(); ++it) {
        if (problema->heuristica(*it) < menorEuristica) {
          menorEuristica = problema->heuristica(*it);
          estadoConMenorEuristica = it;
        }
      }    
      siguienteGen = problema->getSiguientes(*estadoConMenorEuristica);
      pasos->push_back(*estadoConMenorEuristica);
      tengoSolucion = problema->esSolucion(*estadoConMenorEuristica);
    }
    
    Solucion * solucionMala = new Solucion( pasos );
    delete inicio;
    return solucionMala;
}
