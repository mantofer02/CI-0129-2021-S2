# Problema 8Puzzle

## Tabla de contenidos

- [Descripción del Problema](#descripción-del-problema)
- [Implementación del Problema](#implementación-del-problema)
  - [Heurística](#heurística)

## Descripción de Problema

8Puzzle es un problema de juguete en donde se tienen 8 fichas en un tablero 3x3 y un espacio vacio.

![8PuzzleTestCase](../../tests/8Puzzle/Case01.png)

La idea es que, por medio de intercambio de fichas, se pueda llevar a un **estado** en donde los numero se encuentren en orden ascendente.

## Implementación del Problema

Para implementar este problema se "simuló" un tablero de 9 fichas por medio de un array. Cada estado es una variación del tablero.

Para probar el problema y sus estados, generamos estados predeterminados en los cuáles sabemos que van a tener una solución.

### Heurística

Para calcular la **Heurística** de un estado se implemetó un metodo que calcula la sumatoria de la distancia de cada ficha, con respecto a su posicion en el estado de solución. Por lo tanto, si una heurística tiene valor 0, significa que es una solución del problema.

[Inicio](../../README.md)
