#include "../headers/SolucionadorMalo.h"
#include "../headers/Estado.h"
#include "../headers/Solucion.h"
#include "../headers/Lista.h"
#include "../headers/Problema.h"
 
Solucion * SolucionadorMalo::solucione( Problema * problema){
   Estado  * inicio = problema->getEstadoInicial();
   Lista * pasos = problema->getSiguientes( inicio );   
   Solucion * solucionMala = new Solucion( pasos ); 

   delete inicio;
   // La unica cosas que no destruyo es la lista de pasos
   return solucionMala;
}
