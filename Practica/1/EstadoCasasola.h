#ifndef CASA_PROBLEM_STATE
#define CASA_PROBLEM_STATE

#include "ProblemaCasasola.h"

#include "Estado.h"

class EstadoCasasola : public Estado {
   friend class ProblemaCasasola;
   private:
      int n[3];
   public:
      EstadoCasasola();
      EstadoCasasola * clonar();
      istream& cargar(istream&);
      ostream& imprimir(ostream&);
      int operator==(Estado *);
      int operator!=(Estado *);
      int sonIguales(Estado *);
};


#endif
