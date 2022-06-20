#include "../h/Habitacion.h"
#include "../h/Reserva.h"
#include "../h/Fecha.h"
#include "../h/DTEstadia.h"

#include <iterator>
#include <vector>

using namespace std;

     
Habitacion::Habitacion(int numero, int precio, int capacidad, Hostal* phostal){
    this->numero = numero;
    this->precio = precio;
    this->capacidad = capacidad;
    this->hostal = phostal;
    map<int, Reserva*> preservas;
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
    map<int, Reserva*> res = this->reservas;
    vector<DTEstadia> nuevo;
    for (map<int, Reserva*>::iterator ite = res.begin(); ite != res.end(); ite++){
        vector<DTEstadia> est = (*ite).second->getEstadiasFinalizadas(emailHuesped);
        for (vector<DTEstadia>::iterator ite2 = est.begin(); ite2 != est.end(); ite2++){
            nuevo.emplace_back((*ite2));
        }
    }
    return nuevo;
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
     reservas.insert(pair<int,Reserva*>(reserva->getCodigoReserva(), reserva));
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
