#include "../headers/Problema8ReinasFactory.h"

Problema8Reinas* Problema8ReinasFactory::producir()
{
   return new Problema8Reinas();
}
