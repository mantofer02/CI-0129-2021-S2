#ifndef PROBLEMA_8_REINAS_H
#define PROBLEMA_8_REINAS_H

#include <algorithm>
#include <array>
#include <vector>

#include "Estado8Reinas.h"
#include "Lista.h"
#include "Problema.h"

class Problema8Reinas : public Problema
{
public:
  Problema8Reinas();
  Estado* getEstadoInicial();
  int esSolucion(Estado*);
  int heuristica(Estado*);
  Lista* getSiguientes(Estado*);

private:
  bool paresEstanGuardados(std::vector<std::array<int, 4>>,
                           int, int, int, int);
  bool esEspacioValido(int, int);

  /**
   * Verifica si el espacio al que se puede mover una reina es valido
   * o si el espacio no tiene otra reina. Mueve la reina si es posible
   * e inserta el estado a la lista.
   * @param 
   */
  void moverReina(Lista*, Estado*, int, int, int, int);
};

#endif /* PROBLEMA_8_REINAS_H */
