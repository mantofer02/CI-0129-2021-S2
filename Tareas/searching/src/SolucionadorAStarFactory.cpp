#include "../headers/SolucionadorAStarFactory.h"

SolucionadorAStar * SolucionadorAStarFactory::producir() {
   return new SolucionadorAStar();
}
