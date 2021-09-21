#include "../headers/EstadoTour.h"
#include "../headers/Estado.h"

#include<iostream>
using namespace std;

EstadoTour::EstadoTour() {
  /**
   * @brief Se lee asi, en la posicion 0 está la ficha 0,
   * en la posicion 1, esté la ficha 1,
   * en la posicion 2 está la ficha 3, etc...
   */
    
    listaS.push_back(ubicacion{"San Jose", 0});
    listaS.push_back(ubicacion{"Alajuela", 12});
    listaS.push_back(ubicacion{"Heredia", 8});
    listaS.push_back(ubicacion{"limon", 12});
    
    listaA.push_back(ubicacion{"Alajuela", 0});
    listaA.push_back(ubicacion{"San Jose", 12});
    listaA.push_back(ubicacion{"Heredia", 10});
    listaA.push_back(ubicacion{"San Ramon", 12});

    listaH.push_back(ubicacion{"Heredia", 0});
    listaH.push_back(ubicacion{"Alajuela", 10});
    listaH.push_back(ubicacion{"San Jose", 8});
    listaH.push_back(ubicacion{"Limon", 11});
    listaH.push_back(ubicacion{"Puntarenas", 3});
    listaH.push_back(ubicacion{"San Ramon", 9});

    listaSR.push_back(ubicacion{"San Ramon", 0});
    listaSR.push_back(ubicacion{"Alajuela", 12});
    listaSR.push_back(ubicacion{"Heredia", 9});
    listaSR.push_back(ubicacion{"Puntarenas", 7});
    listaSR.push_back(ubicacion{"Guanacaste", 9});
    
    listaP.push_back(ubicacion{"Puntarenas", 0});
    listaP.push_back(ubicacion{"San Ramon", 7});
    listaP.push_back(ubicacion{"Heredia", 3});
    listaP.push_back(ubicacion{"Limon", 11});
    listaP.push_back(ubicacion{"Guanacaste", 6});

    listaL.push_back(ubicacion{"Limon", 0});
    listaL.push_back(ubicacion{"San Jose", 12});
    listaL.push_back(ubicacion{"Heredia", 11});
    listaL.push_back(ubicacion{"Puntarenas", 11});
    listaL.push_back(ubicacion{"Guanacaste", 10});
    
    listaG.push_back(ubicacion{"Guanacaste", 0});
    listaG.push_back(ubicacion{"San Ramon", 9});
    listaG.push_back(ubicacion{"Puntarenas", 6});
    listaG.push_back(ubicacion{"Limon", 10});

    mapa.push_back(listaS);
    mapa.push_back(listaA);
    mapa.push_back(listaH);
    mapa.push_back(listaSR);
    mapa.push_back(listaP);
    mapa.push_back(listaL);
    mapa.push_back(listaG);

    recorrido.nombre = "Alajuela";
    recorrido.distancia = 0;

    destino.nombre = "Guanacaste";
    destino.distancia = 0; 
}

EstadoTour * EstadoTour::clonar() {
    EstadoTour * nuevo = new EstadoTour();
    nuevo->recorrido.nombre = this->recorrido.nombre;
    nuevo->recorrido.distancia = this->recorrido.distancia;
    return nuevo;
}

istream& EstadoTour::cargar(istream& entrada){
  entrada >> this->recorrido.nombre;
  entrada >> this->recorrido.distancia;
  return entrada;
}

ostream& EstadoTour::imprimir(ostream& salida){

    salida << "<\t Mi destino es: "  << destino.nombre << "\n" <<"[ Ubicacion actual: " << recorrido.nombre << "--->  Distancia recorrida hasta mi ubicacion actual: " << recorrido.distancia << " ]" << endl;
    return salida;
}

int EstadoTour::operator==(Estado * otroEstado) {
  EstadoTour * ec = dynamic_cast< EstadoTour * >(otroEstado);
  int esIgual = 0;
  if(ec) {
    esIgual = 1;
    if(this->recorrido.nombre != ec->recorrido.nombre || this->recorrido.distancia != ec->recorrido.distancia){
        esIgual = 0;
    };
  }
  return esIgual;
}

int EstadoTour::operator!=(Estado * otroEstado) {
  return !(*this==otroEstado);
}

int EstadoTour::sonIguales(Estado * otroEstado) {
  EstadoTour * ec = dynamic_cast< EstadoTour * >(otroEstado);
  int esIgual = 0;
  if(ec) {
    esIgual = 1;
    if(this->recorrido.nombre != ec->recorrido.nombre || this->recorrido.distancia != ec->recorrido.distancia){
        esIgual = 0;
    };
  }
  return esIgual;
}