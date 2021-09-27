#ifndef SOLUCIONADOR_IDASTAR_FACTORY_H
#define SOLUCIONADOR_IDASTAR_FACTORY_H

#include "Fabrica.h"
#include "SolucionadorIdaStar.h"

class SolucionadorIdaStarFactory : public Fabrica {
public:
	SolucionadorIdaStar* producir();
};

#endif /* SOLUCIONADOR_IDASTAR_FACTORY_H */
