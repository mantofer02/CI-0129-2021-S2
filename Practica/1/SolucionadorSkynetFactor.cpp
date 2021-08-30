#include "SolucionadorSkynetFactory.h"
#include "SolucionadorSkynet.h"

SolucionadorSkynet * SolucionadorSkynetFactory::producir(){
   return new SolucionadorSkynet();
}
