#include "../h/Habitacion.h"
#include <iterator>
#include <vector>

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

vector<DTEstadia> Habitacion::getEstadiasFinalizadas(string emailHuesped){
    map<int, Reserva*> rs = reservas;
    map<int, Reserva*>::iterator itr;
    vector<DTEstadia> res;
    for (itr = rs.begin(); itr != rs.end(); ++itr) {
        vector<DTEstadia> aux = itr->second->getEstadiasFinalizadas(emailHuesped);
        // agregar aux a res
        vector<DTEstadia>::iterator itr2;
        for (itr2 = aux.begin(); itr2 != aux.end(); ++itr){
            res.emplace_back(*itr2);
        }
    }
    return res;
}
vector<DTEstadia> Habitacion::getDTEstadias(){
    map<int, Reserva*>::iterator itr;
    vector<DTEstadia> res;
    map<int, Reserva*> aux = this->getReservas();
    for (itr = aux.begin(); itr != aux.end(); itr++) {
        vector<DTEstadia> aux2 = itr->second->getDTEstadias();
        vector<DTEstadia>::iterator itr2;
        for (itr2 = aux2.begin(); itr2 != aux2.end(); itr2++){
            res.emplace_back(*itr2);
        }
    }
    return res;
}
void Habitacion::addReserva(Reserva* reserva){
    reservas.insert({reserva->getCodigoReserva(), reserva});
}
bool Habitacion::isReservado(Fecha checkIn, Fecha checkOut){
    map<int, Reserva*>::iterator it = reservas.begin();
    for(; it != reservas.end(); it++)
    {   
        Reserva* reserva = it->second;
        if (Fecha::areOverlapping(checkIn, checkOut, reserva->getCheckIn(), reserva->getCheckOut())) return true;
    }
    return false;

}