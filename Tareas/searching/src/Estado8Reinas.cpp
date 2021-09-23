#include "../headers/Estado8Reinas.h"
#include "../headers/Estado.h"

Estado8Reinas::Estado8Reinas()
{
  srand(time(NULL));

  for (int fila = 0; fila < 8; ++fila)
    for (int columna = 0; columna < 8; ++columna)
      this->tablero[fila][columna] = 0;

  for (int fila = 0; fila < 8; ++fila)
  {
    this->tablero[fila][rand() % 7] = 1;
  }
}

Estado8Reinas* Estado8Reinas::clonar()
{
  Estado8Reinas* nuevoEstado = new Estado8Reinas();
  for (int fila = 0; fila < 8; ++fila)
    for (int columna = 0; columna < 8; ++columna)
      nuevoEstado->tablero[fila][columna] = this->tablero[fila][columna];

  return nuevoEstado;
}

std::istream& Estado8Reinas::cargar(std::istream& entrada)
{
  std::string textoEntrada;
  int contadorDeReinas = 0;
  int filaActual = 0;
  int columnaActual = 0;
  bool stop = false;
  int espacios[64] = {};
  int indice = 0;

  while (indice < 64 && !stop)
  {
    entrada >> textoEntrada;
    if (textoEntrada.size() == 1)
    {
      espacios[indice++] = atoi(textoEntrada.c_str());
    }
    else
    {
      std::cerr << "Cada espacio debe ser 0 (espacio vacío) o 1 (reina).\n";
      stop = true;
    }
    textoEntrada.clear();
  }

  indice = 0;
  for (int fila = 0; fila < 8; ++fila)
  {
    for (int columna = 0; columna < 8 && !stop; ++columna)
    {
      if (espacios[indice] == 0 || espacios[indice] == 1)
      {
        this->tablero[fila][columna] = espacios[indice];

        if (this->tablero[fila][columna] == 1)
        {
          ++contadorDeReinas;

          if (contadorDeReinas == 8)
          {
            filaActual = fila;
            columnaActual = columna;
            stop = true;
          }
        }
        ++indice;
      }
      else
      {
        std::cerr << "Cada espacio de su entrada debe ser 0 (espacio vacío) o 1 (reina).\n";
        stop = true;
      }
    }
  }

  for (; filaActual < 8; ++filaActual)
    for (; columnaActual < 8; ++columnaActual)
      this->tablero[filaActual][columnaActual] = 0;

  return entrada;
}

std::ostream& Estado8Reinas::imprimir(std::ostream& salida)
{
  for (int fila = 0; fila < 8; ++fila)
  {
    for (int columna = 0; columna < 8; ++columna)
      salida << '[' << (this->tablero[fila][columna] ? 'Q' : '_') << ']';

    salida << '\n';
  }

  return salida;
}

int Estado8Reinas::sonIguales(Estado* otroEstado)
{
  Estado8Reinas* copiaEstado = dynamic_cast<Estado8Reinas*>(otroEstado);

  for (int fila = 0; fila < 8; ++fila)
    for (int columna = 0; columna < 8; ++columna)
      if (this->tablero[fila][columna] != copiaEstado->tablero[fila][columna])
        return false;

  return true;
}

int Estado8Reinas::operator==(Estado* otroEstado)
{
  Estado8Reinas* copiaEstado = dynamic_cast<Estado8Reinas*>(otroEstado);

  for (int fila = 0; fila < 8; ++fila)
    for (int columna = 0; columna < 8; ++columna)
      if (this->tablero[fila][columna] != copiaEstado->tablero[fila][columna])
        return false;

  return true;
}

int Estado8Reinas::operator!=(Estado* otroEstado)
{
  return !(*this == otroEstado);
}