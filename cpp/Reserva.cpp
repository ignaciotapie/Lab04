#include "../h/Reserva.h"
#include "../h/ControladorUsuarios.h"
#include "../h/Fecha.h"

Reserva::Reserva(int codRes, Fecha checkIn, Fecha checkOut, EstadoReserva estado, int costo){
	this->codigoReserva = codRes;
	this->checkIn = checkIn;
	this->checkOut = checkOut;
	this->estado = estado;
	this->costo = costo;
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
	/*
    Estadia nueva = Estadia(fechaAct, Fecha(), promo, res, hues, NULL); //links de estadia a reserva y huesped
	this->estado = Cerrada;
	this->estadias.insert(nueva); //link de reserva a estadia
	hues->e.insert(nueva); //link de huesped a estadia

    // no podes entrar a las cosas privadas de otras clases...

    */
}

vector<DTEstadia> Reserva::getEstadiasFinalizadas(string emailHuesped){
    map<string, Estadia*> es = this->getEstadias();
    map<string, Estadia*>::iterator itr;
    vector<DTEstadia> res;
    for (itr = es.begin(); itr != es.end(); ++itr) {
        //si esta finalizada
        if (itr->second->esHues(emailHuesped) && itr->second->estaFinalizada()){
            DTEstadia aux = itr->second->getDTEstadia();
            res.emplace_back(aux);
        }
    }
    return res;
}
Estadia* Reserva::getEstadia(string emailHuesped){
    Estadia* est = this->estadias.find(emailHuesped)->second;
    return est;
}
vector<DTEstadia> Reserva::getDTEstadias(){
    map<string, Estadia*>::iterator itr;
    vector<DTEstadia> res;
    map<string, Estadia*> aux = this->getEstadias();
    for (itr = aux.begin(); itr != aux.end(); itr++) {
        res.emplace_back(itr->second->getDTEstadia());
    }
    return res;
}
DTReserva Reserva::getDTReserva(){
    return DTReserva(this->codigoReserva, this->checkIn, this->checkOut, this->estado, this->costo, habitacion->getNumero());
}

void Reserva::setCheckIn(Fecha checkIn)
{
    this->checkIn = checkIn;
}

void Reserva::setCheckOut(Fecha checkOut)
{
    this->checkOut = checkOut;
}
void Reserva::setHuespedes(set<string> huespedes)
{
    set<string>::iterator it = huespedes.begin();
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    Huesped* huesped = cu->getHuesped(*it);
    this->huesped = huesped;
    it++;
    ReservaGrupal* aux = dynamic_cast<ReservaGrupal*>(this);
    if (aux)
    {
        for (; it != huespedes.end(); it++)
        {
            huesped = cu->getHuesped(*it);
            aux->agregarHuespedExtra(huesped);
            huesped->addReserva(this);
        }
    }
}

void ReservaGrupal::agregarHuespedExtra(Huesped* h)
{
    this->huespedesExtra.insert(pair<string,Huesped*>(h->getNombre(), h));
}
