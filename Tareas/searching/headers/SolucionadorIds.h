#ifndef SOLUCIONADOR_IDS_H
#define SOLUCIONADOR_IDS_H

#include "Solucionador.h"

class SolucionadorIds : public Solucionador {
public:
	Solucion* solucione(Problema*);

private:
	Solucion* buscarEnProfundidadLimitada(Problema*, int);
	Solucion* buscarRecursivo(Estado*, Problema*, int);
};

#endif /* SOLUCIONADOR_IDS_H */
