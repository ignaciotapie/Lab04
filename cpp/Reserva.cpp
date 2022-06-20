#include "../h/Reserva.h"
#include "../h/ControladorUsuarios.h"
#include "../h/Fecha.h"
#include "../h/Estadia.h"
#include "../h/DTReserva.h"
#include "../h/DTEstadia.h"
#include "../h/Usuario.h"
#include "../h/Habitacion.h"

ReservaIndividual::ReservaIndividual(int codRes, Fecha checkIn, Fecha checkOut, EstadoReserva estado, Habitacion* h)
{
    this->codigoReserva = codRes;
    this->checkIn = checkIn;
    this->checkOut = checkOut;
    this->estado = estado;
    this->habitacion = h;
}

ReservaIndividual::ReservaIndividual(int codRes, Fecha checkIn, Fecha checkOut, EstadoReserva estado, int costo)
{
    this->codigoReserva = codRes;
    this->checkIn = checkIn;
    this->checkOut = checkOut;
    this->estado = estado;
    this->costo = costo;
}

ReservaGrupal::ReservaGrupal(int codRes, Fecha checkIn, Fecha checkOut, EstadoReserva estado, int costo)
{
    this->codigoReserva = codRes;
    this->checkIn = checkIn;
    this->checkOut = checkOut;
    this->estado = estado;
    this->costo = costo;
}

ReservaGrupal::ReservaGrupal(int codRes, Fecha checkIn, Fecha checkOut, EstadoReserva estado, Habitacion* h)
{
    this->codigoReserva = codRes;
    this->checkIn = checkIn;
    this->checkOut = checkOut;
    this->estado = estado;
    this->habitacion = h;
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

set<Estadia*> Reserva::getEstadias(){
    return this->estadias;
}

Huesped* Reserva::getHuesped(){
    return this->huesped;
}

void Reserva::setCerradaReserva(Fecha fechaAct, int promo, Reserva* res, Huesped* hues){  
    Estadia nueva = Estadia(fechaAct, Fecha(), promo, res, hues, NULL); //links de estadia a reserva y huesped
	Estadia* e = &nueva; 
    this->estado = Cerrada;
	this->estadias.insert(e); //link de reserva a estadia
	hues->agregarEstadia(e); //link de huesped a estadia
}

vector<DTEstadia> Reserva::getEstadiasFinalizadas(string emailHuesped){
    set<Estadia*> es = this->getEstadias();
    set<Estadia*>::iterator itr;
    vector<DTEstadia> res;
    for (itr = es.begin(); itr != es.end(); ++itr) {
        //si esta finalizada
        if ((*itr)->esHues(emailHuesped) && (*itr)->estaFinalizada()){
            DTEstadia aux = (*itr)->getDTEstadia();
            res.emplace_back(aux);
        }
    }
    return res;
}
Estadia* Reserva::getEstadia(string emailHuesped){
    set<Estadia*> es = this->getEstadias();
    set<Estadia*>::iterator itr;
    Estadia* res;
    for (itr = es.begin(); itr != es.end(); ++itr) {
        if ((*itr)->esHues(emailHuesped)){
            res = *itr;
        }
    }
    return res;
}
vector<DTEstadia> Reserva::getDTEstadias(){
    set<Estadia*>::iterator itr;
    vector<DTEstadia> res;
    set<Estadia*> aux = this->getEstadias();
    for (itr = aux.begin(); itr != aux.end(); itr++) {
        res.emplace_back((*itr)->getDTEstadia());
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

void ReservaGrupal::calcularCosto() 
{
    int diferenciaAnio = checkOut.getAnio() - checkIn.getAnio();
    int diferenciaMes = checkOut.getMes() - checkIn.getMes();
    int diferenciaDia = checkOut.getDia() - checkIn.getDia();
    
    int cantidadFingers = 0;
    if (huesped->getEsFinger()) ++cantidadFingers;
    map<string, Huesped*>::iterator it = huespedesExtra.begin();
    for (; it != huespedesExtra.end(); ++it)
    {
        if (it->second->getEsFinger()) ++cantidadFingers;
    } 
    costo = ((diferenciaAnio * 365) + (diferenciaMes * 31) + (diferenciaDia)) * habitacion->getPrecio() * ((cantidadFingers >=2) ? 0.70 : 1);
}


void ReservaIndividual::calcularCosto()
{
    int diferenciaAnio = checkOut.getAnio() - checkIn.getAnio();
    int diferenciaMes = checkOut.getMes() - checkIn.getMes();
    int diferenciaDia = checkOut.getDia() - checkIn.getDia();

    costo = ((diferenciaAnio * 365) + (diferenciaMes * 31) + (diferenciaDia)) * habitacion->getPrecio();
    
}

