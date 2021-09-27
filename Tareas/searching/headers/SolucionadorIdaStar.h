#ifndef SOLUCIONADOR_IDS_H
#define SOLUCIONADOR_IDS_H

#include <algorithm>
#include <climits>
#include <cmath>
#include <list>

#include "Solucionador.h"

class SolucionadorIdaStar : public Solucionador {
public:
	Solucion* solucione(Problema*);

private:
	Solucion* buscarEnProfundidadLimitada(Problema*, int);
	Solucion* buscarRecursivo(Estado*, Problema*, int);
	int buscar(Problema*, std::list<Estado*>*, int, int);
	int calcularCosto(int, int);
	bool estaGuardadoEnCamino(std::list<Estado*>*, Estado*);
};

#endif /* SOLUCIONADOR_IDS_H */
