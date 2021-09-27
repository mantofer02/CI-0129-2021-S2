#include "../headers/SolucionadorIdaStarFactory.h"

SolucionadorIdaStar* SolucionadorIdaStarFactory::producir() {
	return new SolucionadorIdaStar();
}
