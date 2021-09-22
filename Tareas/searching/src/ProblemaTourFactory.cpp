#include "../headers/ProblemaTourFactory.h"

ProblemaTour * ProblemaTourFactory :: producir() {
  return new ProblemaTour();
}