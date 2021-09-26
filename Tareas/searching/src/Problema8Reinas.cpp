#include "../headers/Problema.h"
#include "../headers/Problema8Reinas.h"

Problema8Reinas::Problema8Reinas()
{
}

Estado* Problema8Reinas::getEstadoInicial()
{
  return new Estado8Reinas();
}

int Problema8Reinas::esSolucion(Estado* estado)
{
  return (heuristica(estado) == 0);
}

int Problema8Reinas::heuristica(Estado* estado)
{
  int valorHeuristica = 0;
  std::vector<std::array<int, 4>> paresDeReinas;
  Estado8Reinas* copiaEstado = dynamic_cast<Estado8Reinas*>(estado);

  if (copiaEstado != nullptr)
  {
    for (int fila = 0; fila < 8; ++fila)
    {
      for (int columna = 0; columna < 8; ++columna)
      {
        if (copiaEstado->tablero[fila][columna] == 1)
        {
          // Horizontal.
          for (int indice = 0; indice < 8; ++indice)
          {
            if (copiaEstado->tablero[fila][indice] == 1
                && indice != columna
                && !paresEstanGuardados(paresDeReinas, fila, columna, fila, indice))
            {
              std::array<int, 4> parDeReinas{ fila, columna, fila, indice };
              paresDeReinas.push_back(parDeReinas);
              ++valorHeuristica;
            }
          }

          // Vertical.
          for (int indice = 0; indice < 8; ++indice)
          {
            if (copiaEstado->tablero[indice][columna] == 1
                && fila != indice
                && !paresEstanGuardados(paresDeReinas, fila, columna, indice, columna))
            {
              std::array<int, 4> parDeReinas{ fila, columna, indice, columna };
              paresDeReinas.push_back(parDeReinas);
              ++valorHeuristica;
            }
          }

          // Diagonal hacia la derecha y arriba.
          int filaTemp = fila - 1;
          int columnaTemp = columna + 1;

          while (esEspacioValido(filaTemp, columnaTemp))
          {
            if (copiaEstado->tablero[filaTemp][columnaTemp] == 1
                && !paresEstanGuardados(paresDeReinas, fila, columna,
                                                       filaTemp, columnaTemp))
            {
              std::array<int, 4> parDeReinas{ fila, columna, filaTemp, columnaTemp };
              paresDeReinas.push_back(parDeReinas);
              ++valorHeuristica;
            }

            filaTemp = filaTemp - 1;
            columnaTemp = columnaTemp + 1;
          }

          // Diagonal hacia la izquierda y abajo.
          filaTemp = fila + 1;
          columnaTemp = columna - 1;

          while (esEspacioValido(filaTemp, columnaTemp))
          {
            if (copiaEstado->tablero[filaTemp][columnaTemp] == 1
                && !paresEstanGuardados(paresDeReinas, fila, columna,
                                                       filaTemp, columnaTemp))
            {
              std::array<int, 4> parDeReinas{ fila, columna, filaTemp, columnaTemp };
              paresDeReinas.push_back(parDeReinas);
              ++valorHeuristica;
            }

            filaTemp = filaTemp + 1;
            columnaTemp = columnaTemp - 1;
          }

          // Diagonal hacia la izquierda y arriba.
          filaTemp = fila - 1;
          columnaTemp = columna - 1;

          while (esEspacioValido(filaTemp, columnaTemp))
          {
            if (copiaEstado->tablero[filaTemp][columnaTemp] == 1
              && !paresEstanGuardados(paresDeReinas, fila, columna,
                filaTemp, columnaTemp))
            {
              std::array<int, 4> parDeReinas{ fila, columna, filaTemp, columnaTemp };
              paresDeReinas.push_back(parDeReinas);
              ++valorHeuristica;
            }

            filaTemp = filaTemp - 1;
            columnaTemp = columnaTemp - 1;
          }

          // Diagonal hacia la derecha y abajo.
          filaTemp = fila + 1;
          columnaTemp = columna + 1;

          while (esEspacioValido(filaTemp, columnaTemp))
          {
            if (copiaEstado->tablero[filaTemp][columnaTemp] == 1
              && !paresEstanGuardados(paresDeReinas, fila, columna,
                filaTemp, columnaTemp))
            {
              std::array<int, 4> parDeReinas{ fila, columna, filaTemp, columnaTemp };
              paresDeReinas.push_back(parDeReinas);
              ++valorHeuristica;
            }

            filaTemp = filaTemp + 1;
            columnaTemp = columnaTemp + 1;
          }
        }
      }
    }
  }
  return valorHeuristica;
}

Lista* Problema8Reinas::getSiguientes(Estado* estado)
{
  Lista* estadosSiguientes = new Lista();
  Estado8Reinas* copiaEstado = dynamic_cast<Estado8Reinas*>(estado);

  if (copiaEstado != nullptr)
  {
    for (int fila = 0; fila < 8; ++fila)
    {
      for (int columna = 0; columna < 8; ++columna)
      {
        if (copiaEstado->tablero[fila][columna] == 1)
        {
          moverReina(estadosSiguientes, copiaEstado, fila, columna, fila + 1, columna);
          moverReina(estadosSiguientes, copiaEstado, fila, columna, fila - 1, columna);
          moverReina(estadosSiguientes, copiaEstado, fila, columna, fila, columna + 1);
          moverReina(estadosSiguientes, copiaEstado, fila, columna, fila, columna - 1);
          moverReina(estadosSiguientes, copiaEstado, fila, columna, fila + 1, columna + 1);
          moverReina(estadosSiguientes, copiaEstado, fila, columna, fila - 1, columna + 1);
          moverReina(estadosSiguientes, copiaEstado, fila, columna, fila - 1, columna - 1);
          moverReina(estadosSiguientes, copiaEstado, fila, columna, fila + 1, columna - 1);
        }
      }
    }
  }

  return estadosSiguientes;
}

bool Problema8Reinas::paresEstanGuardados(std::vector<std::array<int, 4>> paresDeReinas,
                                          int fila1, int columna1,
                                          int fila2, int columna2)
{
  std::array<int, 4> par1{ fila1, columna1, fila2, columna2 };
  std::array<int, 4> par2{ fila2, columna2, fila1, columna1 };

  if (std::find(paresDeReinas.begin(), paresDeReinas.end(), par1) != paresDeReinas.end()
      || std::find(paresDeReinas.begin(), paresDeReinas.end(), par2) != paresDeReinas.end())
  {
    return true;
  }

  return false;
}

bool Problema8Reinas::esEspacioValido(int fila, int columna)
{
  return ((fila >= 0 && fila < 8) && (columna >= 0 && columna < 8));
}

void Problema8Reinas::moverReina(Lista* estadosSiguientes, Estado* estadoActual,
                                 int filaActual, int columnaActual, int nuevaFila,
                                 int nuevaColumna)
{
  Estado8Reinas* copiaEstado = dynamic_cast<Estado8Reinas*>(estadoActual);

  if (copiaEstado != nullptr)
  {
    Estado8Reinas* estadoClonado = copiaEstado->clonar();

    if (estadoClonado != nullptr)
    {
      if (esEspacioValido(nuevaFila, nuevaColumna)
        && estadoClonado->tablero[nuevaFila][nuevaColumna] != 1)
      {
        estadoClonado->tablero[filaActual][columnaActual] = 0;
        estadoClonado->tablero[nuevaFila][nuevaColumna] = 1;

        estadosSiguientes->push_back(estadoClonado);
      }
    }
  }
}