#include "h/Hostal.h"

Hostal::Hostal(){
}

Hostal::Hostal(string nombreHostal, string direccion, int telefono)
{
    this->nombreHostal = nombreHostal;
    this->direccion = direccion;
    this->telefono = telefono;
}

Hostal::Hostal(string nombreHostal, string direccion, int telefono, map<int, Habitacion*> habitaciones, set<Calificacion*> calificaciones, map<string, Empleado*> empleados){
	this->nombreHostal = nombreHostal;
	this->direccion = direccion;
	this->telefono = telefono;
	this->habitaciones = habitaciones;
	this->calificaciones = calificaciones;
	this->empleados = empleados;
}

Hostal::~Hostal(){

}

string Hostal::getNombreHostal(){
    return this->nombreHostal;
}

string Hostal::getDireccion(){
    return this->direccion;
}

int Hostal::getTelefono(){
    return this->telefono;
}

map<int, Habitacion*> Hostal::getHabitaciones(){
    return this->habitaciones;
}

set<Calificacion*> Hostal::getCalificaciones(){
    return this->calificaciones;
}

map<string, Empleado*> Hostal::getEmpleados(){
    return this->empleados;
}

void Hostal::agregarCalificacion(Calificacion* c){
    this->calificaciones.insert(c);
}

int Hostal::getPromedioPuntaje(){
    int sum = 0;
	int iteraciones = 0;
    set<Calificacion*>::iterator iter;
	for(iter = this->calificaciones.begin(); iter != this->calificaciones.end(); iter++ ) {
		sum = sum + (*iter)->getPuntaje();
		iteraciones++;
	}
	return sum/iteraciones;
}

 
set<DTCalificacion> Hostal::getDetalles(){
	set<DTCalificacion> res;
    set<Calificacion*>::iterator iter;
	for (iter = this->calificaciones.begin(); iter != this->calificaciones.end(); iter++){
		DTCalificacion nuevo = DTCalificacion((*iter)->getPuntaje(), (*iter)->getComentario(), /*TEMPORAL*/"temporal", 0);
		res.insert(nuevo);
	}
	return res;
}

void Hostal::nuevaHabitacion(int, int, int){

}

DTHostal Hostal::getDataHostal()
{
    return DTHostal(nombreHostal, direccion, telefono, getPromedioPuntaje());
}

set<DTEstadia> Hostal::getEstadiasFinalizadas(string emailHuesped){
    map<int, Habitacion*> hs = this->getHabitaciones();
    map<int, Habitacion*>::iterator itr;
    set<DTEstadia> res;
    for (itr = hs.begin(); itr != hs.end(); ++itr) {
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

set<DTCalificacion> Hostal::getCalificacionesSinResponder(){
    set<Calificacion*> cals = this->calificaciones;
    set<Calificacion*>::iterator itr;
    set<DTCalificacion> res;
    for (itr = cals.begin(); itr != cals.end(); itr++) {
        Calificacion* aux = *itr;
        if (aux->noEstaRespuesta()){
            res.insert(aux->getDTCalificacion());
        }
    }
    return res;
}

set<DTEstadia> Hostal::getDTEstadias(){
    map<int, Habitacion*>::iterator itr;
    set<DTEstadia> res;
    map<int, Habitacion*> aux = this->getHabitaciones();
    for (itr = aux.begin(); itr != aux.end(); itr++) {
        set<DTEstadia> aux2 = itr->second->getDTEstadias();
        set<DTEstadia>::iterator itr2;
        for (itr2 = aux2.begin(); itr2 != aux2.end(); itr2++){
            res.insert(*itr2);
        }
    }
}

void Hostal::asignarEmpleado(Empleado* empleado)
{
    empleados.insert({empleado->getNombre(), empleado});
}

void Hostal::reservarHabitacion(Reserva*, int){

}

set<int> Hostal::getHabitacionesLibres(Fecha CheckIn, Fecha CheckOut)
{

}