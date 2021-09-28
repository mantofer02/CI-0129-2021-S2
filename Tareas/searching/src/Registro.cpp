#include "../headers/Registro.h"
#include "../headers/Fabrica.h"
// AGREGUE UNA FABRICA DE SOLUCIONADOR Y UNA DE PROBLEMA
// POR CADA MIEMBRO Z DE SU GRUPO XX EQUIPO YY
// MIEMBRO 0
#include "../headers/ProblemaCasasolaFactory.h"
#include "../headers/SolucionadorMaloFactory.h"
// MIEMBRO 2
#include "../headers/Problema8PuzzleFactory.h"
#include "../headers/SolucionadorSkynetFactory.h"
#include "../headers/SolucionadorAStarFactory.h"
#include "../headers/SolucionadorIdaStarFactory.h"

// MIEMBRO 3
#include "../headers/Problema8ReinasFactory.h"
#include "../headers/ProblemaMagicSquareFactory.h"
#include "../headers/ProblemaTSPFactory.h"
// #include "ProblemXXYY3Factory.h"
// #include "SolverXXYY3Factory.h"

void Registro::add(const char * nombre, Fabrica * fabrica){
   if(cantidad<CAPACIDAD){
      if(fabrica){
         fabrica->setNombre(nombre);
         this->fabrica[cantidad++] = fabrica;
      }
   }
}

Registro::Registro(){
   // AL INICIO HAY 0 FABRICAS INSCRITAS
   cantidad = 0;
   // SE CREAN INSTANCIAS DE FABRICA Y SE REGISTRAN

   // Registran los del miembro 1 del equipo YY del grupo XX
   // Ejemplo:

   this->add("Suma12", new ProblemaCasasolaFactory() );
   this->add("MaloSolver", new SolucionadorMaloFactory() );
  
   // Registran los del miembro 2 del equipo YY del grupo XX
   this->add("8Puzzle", new Problema8PuzzleFactory() );
   this->add("AnchoPrimero", new SolucionadorSkynetFactory() );

   this->add("8Reinas", new Problema8ReinasFactory());
   this->add("MagicSquare", new ProblemaMagicSquareFactory());
   
   this->add("AStar", new SolucionadorAStarFactory());
   this->add("IDAStar", new SolucionadorIdaStarFactory());
   // Registran los del miembro 3 del equipo YY del grupo XX
   // ... agregar lineas aqui
}

Registro::~Registro(){
   for(int i=0; i<cantidad; ++i){
      if(fabrica[i]){
         delete fabrica[i];
      }
   }
}

Fabrica * Registro::getFabrica(const char * nombre){
   Fabrica * fabricaPtr = 0;
   for(int i=0; !fabricaPtr && i<cantidad; ++i){
      if( this->fabrica[i]->produce( nombre ) ){
         fabricaPtr = this->fabrica[i];
      }
   }   
   return fabricaPtr;
}
