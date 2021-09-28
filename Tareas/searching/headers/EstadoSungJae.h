#ifndef ESTADO_SJM
#define ESTADO_SJM
#include <iostream>
#include"Estado.h"

using namespace std;


class EstadoSungJae: public Estado {
	

   friend class ProblemaSungJae;

 private : 

 const static int filas= 6;
 const static int  columnas =6;
 
 char libros[filas][columnas];
 
	
	
public : 
    ~EstadoSungJae(){};
   

    EstadoSungJae();
    

    EstadoSungJae * clonar();
    istream& cargar(istream&); 
    ostream& imprimir(ostream&);
    int operator==(Estado*); 
    int sonIguales(Estado*); 
    int operator!=(Estado*); 
    void inicializar ();
	void ponerLibros();
	
	
	
	
	
	
	
};
#endif
