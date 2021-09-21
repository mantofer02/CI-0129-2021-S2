#ifndef TOUR_PROBLEMA
#define TOUR_PROBLEMA

//#include "ProblemaTour.h"
#include "Estado.h"
 
#include <list>
#include <array>

struct ubicacion{
    string nombre;
    int distancia;
};

class EstadoTour : public Estado {
   //friend class ProblemaTour;

   private:
      /**
       * @brief Lista es el conjunt de 8 Puzzle. 
       * Está indexado # ficha y posición. 
      */
      list<ubicacion> listaS;
      list<ubicacion> listaA;
      list<ubicacion> listaH;
      list<ubicacion> listaSR;
      list<ubicacion> listaP;
      list<ubicacion> listaL;
      list<ubicacion> listaG;
      list<list<ubicacion>> mapa;

      ubicacion recorrido;
      ubicacion destino;

   public:
      EstadoTour();
      EstadoTour * clonar();
      istream& cargar(istream&);
      ostream& imprimir(ostream&);
      int operator==(Estado *);
      int operator!=(Estado *);
      int sonIguales(Estado *);
};

#endif