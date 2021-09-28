
#include <iostream>
#include "../headers/EstadoSungJae.h"



EstadoSungJae ::EstadoSungJae(){
   inicializar();
   ponerLibros();

}

void  EstadoSungJae::inicializar (){


	for (int i=0; i<filas;i++){
		
		for (int j=0;j<columnas;j++ ){
			
			libros[i][j]='_';
			
		}
	}
	
	libros[0][0]='m';//Filas fijas  
	libros[0][columnas-1]='m';//Filas Fijas 
	libros[filas-1][0]='p';//columnsa fijas
	libros[filas-1][columnas-1]='p';// columnas fijas 
	

}

// ponerLibros  () coloca el libro M y P en positions específicas de la matriz 



void EstadoSungJae::ponerLibros(){

   libros[3][2]='M';
   libros[4][2]='P';		
}




ostream& EstadoSungJae::imprimir(ostream& salida) {
   for(int f=0; f < filas; ++f){
      for(int c=0; c < columnas; ++c){ 
         salida << libros[f][c] << " ";
      }
      salida << endl;
   }
   salida << endl;
   return salida;
}


istream& EstadoSungJae::cargar(istream& entrada ){
 inicializar();

 int pos1 ,pos2;


 if(pos1>=0&&pos2>=0 && pos1<=5&&pos1<=5 ) {

    entrada >> pos1; entrada  >> pos2;
    libros[pos1][pos2]='M';
 }else {

 }


 if(pos1>=0&&pos2>=0 && pos1<=5&&pos1<=5 ) {

    entrada >> pos1; entrada  >> pos2;
    libros[pos1][pos2]='P';
 }else {
 	
 }


}


int  EstadoSungJae::operator==(Estado*otro ){

   EstadoSungJae *state=0;
   state=dynamic_cast< EstadoSungJae* >(otro);
   int comparador =1 ;
   for (int i=0;comparador==true && i<filas;i++){
      for (int j=0; j<columnas;j++){
         if (this->libros[i][j]!=state->libros[i][j]){				
            comparador=0;


         }			
      }		
   }	

return comparador ; 

}

int EstadoSungJae::sonIguales(Estado * otro) {
  
   EstadoSungJae *state=0;
   state=dynamic_cast< EstadoSungJae* >(otro);
   int comparador =1 ;
   for (int i=0;comparador==true && i<filas;i++){
      for (int j=0; j<columnas;j++){
         if (this->libros[i][j]!=state->libros[i][j]){				
            comparador=0;


         }			
      }		
   }	
  return comparador ; 
}


int EstadoSungJae::operator!=(Estado*otro ){

   return !(*this==otro);

}



EstadoSungJae * EstadoSungJae::clonar(){
  EstadoSungJae *nuevo	=new EstadoSungJae();
  for(int i=0;i<filas;i++){
    for(int j=0;j<columnas;j++){

      nuevo->libros[i][j]=this->libros[i][j];
   }

}
return nuevo;


}




