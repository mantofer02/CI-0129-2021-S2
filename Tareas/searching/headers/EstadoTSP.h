#ifndef TSP_PROBLEM_STATE
#define TSP_PROBLEM_STATE

#include "ProblemaTSP.h"
#include "Estado.h"

#include <cstdlib>
#include <ctime>

#include <array>

class EstadoTSP : public Estado {
   friend class ProblemaTSP;

   private:
      /**
       * @brief Lista es el conjunt de 8 Puzzle. 
       * Está indexado # ficha y posición. 
      */
      int mapa[10][10];
      int recorrido[10][10];
   public:
      EstadoTSP();
      EstadoTSP * clonar();
      istream& cargar(istream&);
      ostream& imprimir(ostream&);
      int operator==(Estado *);
      int operator!=(Estado *);
      int sonIguales(Estado *);

};

#endif