# Tarea Searching

## Tabla de contenidos

- [Descripción del Problema](#descripción-del-problema)
  - [Enunciado](#enunciado)
- [Diseño de la Tarea](#diseño-de-la-tarea)
- [Manual de Usuario](#manual-de-usuario)
- [Resultados](#resultados)
- [Créditos](#créditos)

## Descripción del Problema

En las últimas semanas en el curso de Inteligencia Artificial hemos visto algoritmos de búsqueda. Entre estos algoritmos de busqueda están los **informados** y los **no informados.**

Los algritmos de búsqueda informados utilizan una medida conocida como la **heurística**, una medida que nos permita determinar que tan lejos o cerca está un estado de la solución.

### Enunciado

  [Tarea Search Avanzada](assets/TareaSearchAvanzada.pdf)

### Diseño de la Tarea

Para la elaboración de esta tarea se cambio la estructura del proyecto de su primera versión.

- `assets/` En esta carpeta se encuenta el material de apoyo, específicamente el enunciado del trabajo anterior, así como el enunciado de esta tarea.

- `bin/` `build/` Carpetas generadas automáticamente en el momento de compilación. En la carpeta `bin/` se encuentra el archivo ejecutable.

- `doc/` Carpeta en dónde se econtrara documentación adicional.

- `headers/` Folder en dónde se encuentra los `.h` del programa.

- `src/` Carpeta en dónde se encuentra la implementación de los `.h` respectivos.

- `tests/` Carpeta de material de apoyo. Acá se encuentra imagenes de ejemplos de los problemas de juguete de este proyecto.

## Manual de Usuario

Este proyecto incluye un archivo `Makefile` proporcionado por el profesor Jeisson Hidalgo de la **ECCI** de la **UCR**.

Para compilar el poyecto, se puede correr el `Makefile` siempre y cuando sea bajo un sistema operativo `UNIX`.

- Compilación: `make`

Para ejecutar el archivo, se debe de ingresar de parámetros el nombre de un problema y de un solucionador.

Problemas:

- [`8Puzzle`](doc/problemas/8Puzzle.md)
- [`8Reinas`](doc/problemas/8Reinas.md)
- [`MagicSquare`](doc/problemas/MagicSquare.md)
- [`TSP`](doc/problemas/Viajero.md)

Solucionadores:

- [`AnchoPrimero`](doc/algoritmos/AnchoPrimero.md)
- [`A*`](doc/algoritmos/AStar.md)
- [`IDA*`](doc/algoritmos/IDAStar.md)

Ejecución:


`searching.out nombre_problema nombre_solucionador`


## Resultados
[Resultados](doc/Resultados.md)

## Créditos

Marco Ferraro | **B82957**
  
- Estado y Problema 8Puzzle
- Estado y Problema Magic Square
- Solucionador Ancho Primero (Skynet)
- Solucionador A*
- Documentación

Gabriel Revillat | **B86524**

- Estado y Problema 8Puzzle
- Estado y Problema 8 Reinas
- Solucionador Ancho Primero (Skynet)
- Solucionador IDA*

Steven Nuñez | **B95614**

- Estado y Problema 8Puzzle
- Estado y Problema TSP
- Solucionador Ancho Primero (Skynet)