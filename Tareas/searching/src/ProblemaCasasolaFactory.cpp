#include "../headers/ProblemaCasasolaFactory.h"
#include "../headers/ProblemaCasasola.h"

ProblemaCasasola * ProblemaCasasolaFactory::producir(){
   return new ProblemaCasasola();
}
