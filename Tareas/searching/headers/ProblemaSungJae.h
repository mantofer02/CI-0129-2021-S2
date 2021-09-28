/* Problema organiza nuevos libros según libros existentes a columnas y filas para alinear libros,
 M para libros de matemática y P para libros de programación*/
#ifndef PROBLEMA_SJM
#define PROBLEMA_SJM
#include"Problema.h"
#include "Lista.h"
#include "EstadoSungJae.h"

class ProblemaSungJae :public Problema {
	
	
	
	// Retorna el estado inicial del problema
	
	
	public:
	  
      Estado * getEstadoInicial();

 
        int esSolucion( Estado * );

      // Retorna un valor estimado optimista que sugiere
      // en cuantos pasos cree que de ese estado que recibe
        int heuristica(Estado *);

      // El problema retorna los siguientes estados
        Lista * getSiguientes( Estado * );

	    void movimientoLibros(int fila, int columna, Lista *lis, EstadoSungJae *pointer, char contrario, char contraFijo, char uso, char usoFijo);
    	 	
	
	
};
#endif
