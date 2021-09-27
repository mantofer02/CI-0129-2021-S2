#include "../headers/SolucionadorIdaStar.h"
#include "../headers/Estado.h"
#include "../headers/Solucion.h"
#include "../headers/Lista.h"
#include "../headers/Problema.h"

Solucion* SolucionadorIdaStar::solucione(Problema * problema) {

	std::list<Estado*>* camino = new std::list<Estado*>();
	Lista* caminoSolucion = new Lista();
	Estado* estadoInicial = problema->getEstadoInicial();
	camino->push_back(estadoInicial);
	int limite = problema->heuristica(estadoInicial);

	int resultado = INT_MAX;

	while (true) {
		resultado = buscar(problema, camino, 0, limite);

		if (resultado == 0) {
			for (std::list<Estado*>::iterator iteracion = camino->begin();
				   iteracion != camino->end(); ++iteracion) {
				caminoSolucion->push_back(*iteracion);
			}
			return new Solucion(caminoSolucion);
		}

		limite = resultado;
	}

	return nullptr;
}

int SolucionadorIdaStar::buscar(Problema* problema, std::list<Estado*>* camino,
																int costoEstadoActual, int limite) {
	Estado* estadoActual = camino->back();
	// std::cout << estadoActual << '\n';
	// std::cout << "Heuristica: " << problema->heuristica(estadoActual) << '\n';
	Lista* estadosSiguientes = problema->getSiguientes(estadoActual);
	int costo = costoEstadoActual + problema->heuristica(estadoActual);

	if (costo > limite)
		return costo;

	if (problema->esSolucion(estadoActual))
		return 0;

	int minimo = INT_MAX;

	// Recorrer la lista de sucesores
	for (Lista::Iterador iteracion = estadosSiguientes->begin();
		   iteracion != estadosSiguientes->end(); ++iteracion) {
		// Si el sucesor actual no se encuentra en la lista camino
		if (!estaGuardadoEnCamino(camino, *iteracion)) {
			camino->push_back(*iteracion);
			int nuevoCosto = costoEstadoActual
											 + calcularCosto(problema->heuristica(estadoActual), problema->heuristica(*iteracion));

			int resultado = buscar(problema, camino, nuevoCosto, limite);

			if (resultado == 0)
				return 0;

			if (resultado < minimo)
				minimo = resultado;

			camino->pop_back();
		}
	}

	return minimo;
}

int SolucionadorIdaStar::calcularCosto(int heuristica1, int heuristica2) {
	return abs(heuristica1 - heuristica2);
}

bool SolucionadorIdaStar::estaGuardadoEnCamino(std::list<Estado*>* camino, Estado* estado) {
	for (std::list<Estado*>::iterator iteracion = camino->begin();
		   iteracion != camino->end(); ++iteracion) {
		if ((*iteracion)->sonIguales(estado))
			return true;
	}
	return false;
}
