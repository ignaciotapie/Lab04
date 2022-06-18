#include <Habitacion.h>
#include <iterator>

using namespace std;

     
Habitacion::Habitacion(int numero, int precio, int capacidad, Hostal* phostal, map<int, Reserva*> preservas){
    this->numero = numero;
    this->precio = precio;
    this->capacidad = capacidad;
    this->hostal = phostal;
    this->reservas = preservas;
}

int Habitacion::getNumero(){
    return this->numero;
}

int Habitacion::getCapacidad(){
    return this->capacidad;
}

int Habitacion::getPrecio(){
    return this->precio;
}

Hostal* Habitacion::getHostal(){
    return this->hostal;
}

map<int, Reserva*> Habitacion::getReservas(){
    return this->reservas;
}

set<DTEstadia> Habitacion::getEstadiasFinalizadas(string emailHuesped){
    map<int, Reserva*> rs = this->getReservas();
    map<int, Reserva*>::iterator itr;
    set<DTEstadia> res;
    for (itr = rs.begin(); itr != rs.end(); ++itr) {
        set<DTEstadia> aux = itr->second->getEstadiasFinalizadas(emailHuesped);
        // agregar aux a res
        set<DTEstadia>::iterator itr2;
        for (itr2 = aux.begin(); itr2 != aux.end(); ++itr){
            res.insert(*itr2);
        }
        aux.~set();
    }
    return res;
}
set<DTEstadia> Habitacion::getDTEstadias(){
    map<int, Reserva*>::iterator itr;
    set<DTEstadia> res;
    map<int, Reserva*> aux = this->getReservas();
    for (itr = aux.begin(); itr != aux.end(); itr++) {
        set<DTEstadia> aux2 = itr->second->getDTEstadias();
        set<DTEstadia>::iterator itr2;
        for (itr2 = aux2.begin(); itr2 != aux2.end(); itr2++){
            res.insert(*itr2);
        }
    }
}
void Habitacion::addReserva(Reserva*){
    ;
}
bool Habitacion::isReservado(Fecha){
    ;
}