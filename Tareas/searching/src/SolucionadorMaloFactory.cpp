#include "SolucionadorMaloFactory.h"
#include "SolucionadorMalo.h"

SolucionadorMalo * SolucionadorMaloFactory::producir(){
   return new SolucionadorMalo();
}
