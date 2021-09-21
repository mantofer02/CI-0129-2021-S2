#ifndef ESTADO_8_REINAS_H
#define ESTADO_8_REINAS_H

#include <cstdlib>
#include <ctime>

#include "Estado.h"


class Estado8Reinas
{
private:
	int tablero[8][8];

public:
	Estado8Reinas();
	Estado8Reinas* clonar();
	std::istream& cargar(std::istream&);
	std::ostream& imprimir(std::ostream&);
	int operator==(Estado*);
	int operator!=(Estado*);
};

#endif /* ESTADO_8_REINAS_H */
