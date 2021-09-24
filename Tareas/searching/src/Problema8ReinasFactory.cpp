#include "../headers/Problema8ReinasFactory.h"
#include "../headers/Problema8Reinas.h"

Problema8Reinas * Problema8ReinasFactory::producir(){
   return new Problema8Reinas();
}
