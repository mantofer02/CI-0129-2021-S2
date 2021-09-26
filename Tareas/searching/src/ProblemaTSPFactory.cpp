#include "../headers/ProblemaTSPFactory.h"
#include "../headers/ProblemaTSP.h"

ProblemaTSP * ProblemaTSPFactory::producir(){
   return new ProblemaTSP();
}
