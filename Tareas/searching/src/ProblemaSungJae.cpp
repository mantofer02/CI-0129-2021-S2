/* Problema organiza nuevos libros según libros existentes a columnas y filas para alinear libros,
 M para libros de matemática y P para libros de programación*/
#include "../headers/Lista.h"
#include "../headers/Problema.h"
#include "../headers/ProblemaSungJae.h"


Estado * ProblemaSungJae::getEstadoInicial(){
	
	return new EstadoSungJae();	
	
}


int ProblemaSungJae::esSolucion( Estado * otro ){
	int esSolucion=0;
	EstadoSungJae *otroC=dynamic_cast<EstadoSungJae*>(otro);
	if(otroC){
		if((otroC->libros[0][1]=='M'||otroC->libros[0][2]=='M'||otroC->libros[0][3]=='M'||otroC->libros[0][4]=='M')&&(otroC->libros[5][1]=='P'||otroC->libros[5][2]=='P'||otroC->libros[5][3]=='P'||otroC->libros[5][4]=='M')){

			esSolucion=1;

		}	
	}
	return esSolucion;
}

 // heurística calcula la distancia de los libros C y P a las filas correspondientes 0 y 5 
int ProblemaSungJae::heuristica(Estado * otro){
	int heuri=0; 
	int control=0;
	EstadoSungJae *estadoC = dynamic_cast< EstadoSungJae* >(otro);
	
	for (int i=0; i<estadoC->filas;i++){
		for(int j=0;j<estadoC->columnas;j++){
			if(estadoC->libros[i][j]=='M'){
				heuri=heuri+j;

			}	
			if(estadoC->libros[i][j]=='P'){
				heuri+= 5-j;


			}	
			
		}
	}
	return heuri;	
	
}

// get siguientes estados posibles
Lista * ProblemaSungJae::getSiguientes( Estado *otro ){

	EstadoSungJae *inicio = dynamic_cast< EstadoSungJae* >(otro);
	Lista * siguientes = new Lista();
	for (int i=0;i<inicio->filas;i++){
		for(int j=0;j<inicio->columnas;j++){
 			//Expandir libros de matemática
			if(inicio->libros[i][j]=='M'){
				if(i!=0){
					movimientoLibros(i, j, siguientes, inicio, 'P', 'p', 'M', 'm');


				}		
			}
 			//Expandir libros de programación
			if(inicio->libros[i][j]=='P'){
				if(i!= 5){
					movimientoLibros(i, j, siguientes, inicio, 'M', 'm', 'P', 'p');


				}	


			}

		}

	}
	return siguientes;


}

 // mueve los libros arriba izq der o abajo
void  ProblemaSungJae::movimientoLibros(int fila, int columna, Lista *lis, EstadoSungJae *pointer, char contrario, char contrarioFijo, char uso, char usoFijo){
 	//Agregar izquierda 
	if(columna!=0){
		EstadoSungJae * clon1 = pointer->clonar();
		if(clon1->libros[fila][columna-1]!=contrario && clon1->libros[fila][columna-1]!=contrarioFijo){


			clon1->libros[fila][columna-1]=uso;
			clon1->libros[fila][columna]='_';
			lis->push_back( clon1 );
		}
		delete clon1;

	}
 	//Agregar a la derecha 

	EstadoSungJae * clon2 = pointer->clonar();
	if(columna!=clon2->columnas-1){
		if(clon2->libros[fila][columna+1]!=contrario && clon2->libros[fila][columna+1]!=contrarioFijo){

			clon2->libros[fila][columna+1]=uso;
			clon2->libros[fila][columna]='_';
			lis->push_back( clon2 );
		}
		delete clon2;


	}

 	//Agregar arriba 

	EstadoSungJae * clon3 = pointer->clonar();

	if(clon3->libros[fila-1][columna]!=contrario && clon3->libros[fila-1][columna]!=usoFijo){


		clon3->libros[fila-1][columna]=uso;
		clon3->libros[fila][columna]='_';
		lis->push_back( clon3 );
		delete clon3;
	}



 	//Agregar abajo 
	EstadoSungJae * clon4 = pointer->clonar();
	if(fila!=clon4->filas-1){
		if(clon4->libros[fila+1][columna]!=contrario && clon4->libros[fila+1][columna]!=contrarioFijo){

			clon4->libros[fila+1][columna]=uso;
			clon4->libros[fila][columna]='_';
			lis->push_back( clon4 );
		}
		delete clon4;

	}
}

