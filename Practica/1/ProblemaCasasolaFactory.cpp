#include "ProblemaCasasolaFactory.h"
#include "ProblemaCasasola.h"

ProblemaCasasola * ProblemaCasasolaFactory::producir(){
   return new ProblemaCasasola();
}
