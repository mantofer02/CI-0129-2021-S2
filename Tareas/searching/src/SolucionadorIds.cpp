#include "../headers/SolucionadorIds.h"
#include "../headers/Estado.h"
#include "../headers/Solucion.h"
#include "../headers/Lista.h"
#include "../headers/Problema.h"

Solucion* SolucionadorIds::solucione(Problema * problema) {
	Solucion* resultado = nullptr;
	int profundidad = 0;

	while (true) {
		resultado = buscarEnProfundidadLimitada(problema, profundidad);
		++profundidad;

		if (resultado != nullptr)
			return resultado;
	}
	return nullptr;
}

Solucion* SolucionadorIds::buscarEnProfundidadLimitada(Problema* problema, int limite) {
	Estado* estadoInicial = problema->getEstadoInicial();
	return buscarRecursivo(estadoInicial, problema, limite);
}

Solucion* SolucionadorIds::buscarRecursivo(Estado* estadoActual, Problema* problema, int limite) {
	// Probablemente falta una lista de pasos de la solucion como parametro.
	if (problema->esSolucion(estadoActual))
	{
		// Retornar solucion.
	}
	else if (limite == 0)
	{
		// Retornar cutoff (null).
		return nullptr;
	}
	else
	{
		bool huboCorte = false;

		// Insertar codigo aqui xdDdxd
		
		if (huboCorte)
			return nullptr;
	}
}

