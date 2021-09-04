#include "SolucionadorSkynet.h"
#include "Estado.h"
#include "Solucion.h"
#include "Lista.h"
#include "Problema.h"
 
Solucion * SolucionadorSkynet::solucione( Problema * problema){
    Estado  * inicio = problema->getEstadoInicial();
    Lista * pasos = problema->getSiguientes(inicio);
    Lista * siguienteGen;
    int haySolucion = 0;

    Lista::Iterador it = pasos->begin();
    
    while (!haySolucion) {
      if (problema->esSolucion(*it)) {
        haySolucion = 1;
        // para meter la ultima, corregir
        siguienteGen = problema->getSiguientes(*it);
        for (Lista::Iterador sigIt = siguienteGen->begin(); sigIt != siguienteGen->end(); sigIt++)
        {
          pasos->push_back(*sigIt);
        }
      } else {
        siguienteGen = problema->getSiguientes(*it);
        for (Lista::Iterador sigIt = siguienteGen->begin(); sigIt != siguienteGen->end(); sigIt++)
        {
          pasos->push_back(*sigIt);
        }
        it++;
      }
    }
    
    Solucion * solucionMala = new Solucion( pasos );
    delete inicio;
    return solucionMala;
}
