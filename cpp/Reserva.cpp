#include "h/Reserva.h"

Reserva::Reserva(int codRes, Fecha checkIn, Fecha checkOut, EstadoReserva estado, int costo){
	this->codigoReserva = codRes;
	this->checkIn = checkIn;
	this->checkOut = checkOut;
	this->estado = estado;
	this->costo = costo;
}

Reserva::~Reserva(){

}

int Reserva::getCodigoReserva(){
    return this->codigoReserva;
}

Fecha Reserva::getCheckIn(){
    return this->checkIn;
}

Fecha Reserva::getCheckOut(){
    return this->checkOut;
}

EstadoReserva Reserva::getEstado(){
    return this->estado;
}

int Reserva::getCosto(){
    return this->costo;
}

Habitacion* Reserva::getHabitacion(){
    return this->habitacion;
}

map<string, Estadia*> Reserva::getEstadias(){
    return this->estadias;
}

Huesped* Reserva::getHuesped(){
    return this->huesped;
}

void Reserva::setCerradaReserva(Fecha fechaAct, int promo, Reserva* res, Huesped* hues){  
	Estadia nueva = Estadia(fechaAct, Fecha(), promo, res, hues, NULL); //links de estadia a reserva y huesped
	this->estado = Cerrada;
	this->estadias.insert(nueva); //link de reserva a estadia
	hues->estadias.insertar(nueva); //link de huesped a estadia
}

set<DTEstadia> Reserva::getEstadiasFinalizadas(string emailHuesped){
    map<string, Estadia*> es = this->getEstadias();
    map<string, Estadia*>::iterator itr;
    set<DTEstadia> res;
    for (itr = es.begin(); itr != es.end(); ++itr) {
        //si esta finalizada
        if (itr->second->esHues(emailHuesped) && itr->second->estaFinalizada()){
            DTEstadia aux = itr->second->getDTEstadia();
            res.emplace(aux);
        }
    }
    return res;
}
Estadia* Reserva::getEstadia(string emailHuesped){
    Estadia* est = this->estadias.find(emailHuesped)->second;
    return est;
}
set<DTEstadia> Reserva::getDTEstadias(){
    map<string, Estadia*>::iterator itr;
    set<DTEstadia> res;
    map<string, Estadia*> aux = this->getEstadias();
    for (itr = aux.begin(); itr != aux.end(); itr++) {
        res.insert(itr->second->getDTEstadia());
    }
}
DTReserva Reserva::getDTReserva(){

}