#include "../headers/ProblemaSungJaeFactory.h"
#include "../headers/ProblemaSungJae.h"

ProblemaSungJae * ProblemaSungJaeFactory::producir(){
   return new ProblemaSungJae();
}
