#ifndef PROBLEMA_8_REINAS_H
#define PROBLEMA_8_REINAS_H

#include "Problema.h"

class Problema8Reinas : public Problema
{
public:
	Problema8Reinas();
	Estado* getEstadoInicial();
	int esSolucion(Estado*);
	int heuristica(Estado*);
	Lista* getSiguientes(Estado*);
};

#endif /* PROBLEMA_8_REINAS_H */
