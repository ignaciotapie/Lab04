#include "../h/ControladorReservas.h"

using namespace std;

ControladorReservas* ControladorReservas::instance = NULL;

ControladorReservas* ControladorReservas::getInstance(){
    if (!instance)
    {
        instance = new ControladorReservas();
    }
    return instance;
}

// Registrar Estadia
void ControladorReservas::registrarEstadia(int codigoReserva, Huesped* hues)
{
	ControladorReloj* cr = ControladorReloj::getInstance();
	Fecha fechaAct = cr->getFechaActual();
	map<int, Reserva*>::iterator it = reservas.find(codigoReserva);
	Reserva* res = it->second;
	int promo = 0;
	res->setCerradaReserva(fechaAct, promo, res, hues);
}

set<string> ControladorReservas::getHostales(){
    ControladorHostales* ch = ControladorHostales::getInstance();
    set<string> res = ch->getHostales(); //Por que no vas directo a controlador hostales para pedir los hostales? 
	return res;
}

void ControladorReservas::seleccionarEstadia(int i, string s){
    codigoReservaEstadia = i;
    emailHuespedEstadia = s;
}
/*void ControladorReservas::seleccionarEstadia(string hostal, string email) {
	this->nombreHostal = hostal;
	this->emailHuesped = email;
}*/ //cual?

void ControladorReservas::finalizarEstadia(){
    /*ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	ControladorReloj* cr = ControladorReloj::getInstance();
	Fecha fechaA = cr->getFechaActual();
	Huesped* h = cu->getHuesped(this->emailHuespedEstadia); 

    
    map<int,Estadia*>::iterator iter = h->estadias.begin(); //no podes entrar a los private de otro controlador, tenes que hacer una funcion aparte.
	for (; iter != h->estadias->end(); iter++){
		if (!iter->second->estaFinalizada()){
			iter->second->setCheckOut(fechaA);
		}
	}*/
}
void ControladorReservas::setCalificacion(string comentario, int calificacion){
    map<int, Reserva*>::iterator itr = reservas.find(codigoReservaEstadia);
    Reserva* res = itr->second;
    Estadia* est = res->getEstadia(emailHuespedEstadia);
    ControladorHostales* ch = ControladorHostales::getInstance();
    Hostal* h = ch->getHostal(hostalSeleccionado);
    est->setCalificacion(comentario, calificacion, h);
    Calificacion* c = est->getCalificacion();
    Notificacion* n = c->crearNotificacion(emailHuespedEstadia);
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    cu->notificarObservadores(n);
}
vector<DTCalificacion> ControladorReservas::getCalificacionesSinResponder(string emailEmpleado){
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    vector<DTCalificacion> res = cu->getCalificacionesSinResponder(emailEmpleado);
    empleadoGuardado = cu->getEmpleado(emailEmpleado);
    return res;
}
void ControladorReservas::setComentarioCalificacion(string comentario){
    Reserva* res = reservas.find(codigoReservaEstadia)->second;
    Estadia* est = res->getEstadia(emailHuespedEstadia);
    Calificacion* cal = est->getCalificacion();
    cal->setComentarioCalificacion(comentario, empleadoGuardado, cal);
}
void ControladorReservas::selectCalificacion(string email, int codigo){
    codigoReservaEstadia = codigo;
    emailHuespedEstadia = email;
}
vector<DTEstadia> ControladorReservas::getEstadias(){
    ControladorHostales* ch = ControladorHostales::getInstance();
    Hostal* h = ch->getHostal(hostalSeleccionado);
    return h->getDTEstadias();
}
DTEstadiaPlus ControladorReservas::getEstadiaPlus(){
    Estadia* est = reservas.find(codigoReservaEstadia)->second->getEstadia(emailHuespedEstadia);
    DTEstadiaPlus res = est->getDTEstadiaPlus();
    return res;
}
DTReserva ControladorReservas::getDTReserva(){
    Estadia* est = reservas.find(codigoReservaEstadia)->second->getEstadia(emailHuespedEstadia);
    DTReserva res = est->getDTReserva();
    return res;
}
DTCalificacion ControladorReservas::getDTCalificacion(){
    Estadia* est = reservas.find(codigoReservaEstadia)->second->getEstadia(emailHuespedEstadia);
    DTCalificacion res = est->getDTCalificacion();
    return res;
}
void ControladorReservas::seleccionarHostal(string h){
    hostalSeleccionado = h;
}
vector<DTEstadia> ControladorReservas::getEstadiasFinalizadas(string emailHuesped){
    ControladorHostales* ch = ControladorHostales::getInstance();
    Hostal* h = ch->getHostal(hostalSeleccionado);
    vector<DTEstadia> res = h->getEstadiasFinalizadas(emailHuesped);
    return res;
}
void ControladorReservas::finConsultaEstadia(){

}

void ControladorReservas::addReserva(Reserva* r)
{
	reservas.insert(pair<int, Reserva*>(r->getCodigoReserva(), r));
}
