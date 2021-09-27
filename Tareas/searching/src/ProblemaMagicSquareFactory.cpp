#include "../headers/ProblemaMagicSquareFactory.h"
#include "../headers/ProblemaMagicSquare.h"

ProblemaMagicSquare * ProblemaMagicSquareFactory::producir(){
   return new ProblemaMagicSquare();
}
