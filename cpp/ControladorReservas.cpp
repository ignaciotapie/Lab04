#include "../h/ControladorReservas.h"
#include "../h/ControladorUsuarios.h"
#include "../h/ControladorReloj.h"
#include "../h/ControladorHostales.h"
#include "../h/Reserva.h"
#include "../h/Estadia.h"
#include "../h/Calificacion.h"
#include "../h/DTReserva.h"
#include "../h/Hostal.h"
#include "../h/DTEstadiaPlus.h"
#include "../h/DTCalificacion.h"
#include "../h/DTEstadia.h"
#include "../h/RespuestaEmpleado.h"

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

int ControladorReservas::getCodigoReservaACrear()
{
    int codigo = sigCodigoReserva;
    sigCodigoReserva++;
    return codigo;
}

bool ControladorReservas::existeCalificacion(){
    Estadia* est = reservas.find(codigoReservaEstadia)->second->getEstadia(emailHuespedEstadia);
    return est->getCalificacion() != NULL;
}

bool ControladorReservas::existeRespuestaEmpleado(){
    Estadia* est = reservas.find(codigoReservaEstadia)->second->getEstadia(emailHuespedEstadia);
    if (est->getCalificacion() != NULL){
        if (est->getCalificacion()->getRespuestaempleados() != NULL){
            return 1;
        }
    }
    return 0;
}

string ControladorReservas::getRespuestaEmpleado(){
    Estadia* est = reservas.find(codigoReservaEstadia)->second->getEstadia(emailHuespedEstadia);
    return est->getCalificacion()->getRespuestaempleados()->getMensaje();
}

void ControladorReservas::cargaDatos()
{
    ControladorHostales* ch = ControladorHostales::getInstance();


    //R1
    Hostal* finger = ch->getHostal("La posada del finger");
    Habitacion* habFinger = finger->getHabitacion(1);
    Reserva* r = new ReservaIndividual(1, Fecha(14.00, 1, 5, 2022), Fecha(10.00, 10, 5, 2022), EstadoReserva::Abierta, habFinger);
    set<string> huespedes;
    huespedes.insert("sofia@mail.com");
    r->setHuespedes(huespedes);
    finger->reservarHabitacion(r, 1);
    this->addReserva(r);


    //R2
    Hostal* pony = ch->getHostal("El Pony Pisador");
    Habitacion* habPony = pony->getHabitacion(1);
    Reserva* re = new ReservaGrupal(2, Fecha(20.00,4,1,2001), Fecha(2.00, 5,1,2001), EstadoReserva::Abierta, habPony);
    set<string> huespedesPony;
    huespedesPony.insert("frodo@mail.com");
    huespedesPony.insert("sam@mail.com");
    huespedesPony.insert("merry@mail.com");
    huespedesPony.insert("pippin@mail.com");
    re->setHuespedes(huespedesPony);
    pony->reservarHabitacion(re, 1);
    this->addReserva(re);


    //R3
    Habitacion* habFingerDos = finger->getHabitacion(3);
    Reserva* res = new ReservaIndividual(3, Fecha(14.00, 7,6,2022), Fecha(11.00,30,6,2022), EstadoReserva::Abierta, habFingerDos);
    set<string> huespedesFingerDos;
    huespedesFingerDos.insert("sofia@mail.com");
    res->setHuespedes(huespedesFingerDos);    
    finger->reservarHabitacion(res, 3);
    this->addReserva(res);


    //R4
    Hostal* caverna = ch->getHostal("Caverna Lujosa");
    Habitacion* habCaverna = caverna->getHabitacion(1);
    Reserva* rese = new ReservaIndividual(4, Fecha(14.00, 10, 6, 2022), Fecha(11.00, 30, 6, 2022), EstadoReserva::Abierta, habCaverna);
    set<string> huespedesCaverna;
    huespedesCaverna.insert("seba@mail.com");
    rese->setHuespedes(huespedesCaverna);
    caverna->reservarHabitacion(rese, 1);
    this->addReserva(rese);



    


}