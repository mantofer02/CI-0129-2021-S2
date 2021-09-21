#include "../headers/SolucionadorMaloFactory.h"
#include "../headers/SolucionadorMalo.h"

SolucionadorMalo * SolucionadorMaloFactory::producir(){
   return new SolucionadorMalo();
}
