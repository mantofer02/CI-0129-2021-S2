#include "../headers/SolucionadorSkynetFactory.h"
#include "../headers/SolucionadorSkynet.h"

SolucionadorSkynet * SolucionadorSkynetFactory::producir(){
   return new SolucionadorSkynet();
}
