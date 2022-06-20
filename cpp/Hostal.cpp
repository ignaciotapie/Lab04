#include "../h/Hostal.h"
#include "../h/DTHostal.h"
#include "../h/Calificacion.h"
#include "../h/Habitacion.h"
#include "../h/Usuario.h"
#include "../h/DTCalificacion.h"
#include "../h/DTEstadia.h"

Hostal::Hostal(){
}

Hostal::Hostal(string nombreHostal, string direccion, string telefono)
{
    this->nombreHostal = nombreHostal;
    this->direccion = direccion;
    this->telefono = telefono;
}

Hostal::Hostal(string nombreHostal, string direccion, string telefono, map<int, Habitacion*> habitaciones, set<Calificacion*> calificaciones, map<string, Empleado*> empleados){
	this->nombreHostal = nombreHostal;
	this->direccion = direccion;
	this->telefono = telefono;
	this->habitaciones = habitaciones;
	this->calificaciones = calificaciones;
	this->empleados = empleados;
}

const string Hostal::getNombreHostal() const{
    return this->nombreHostal;
}

const string Hostal::getDireccion() const{
    return this->direccion;
}

const string Hostal::getTelefono() const {
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

const float Hostal::getPromedioPuntaje() const{
    float sum = 0;
	float iteraciones = 0;
    set<Calificacion*>::iterator iter;
	for(iter = this->calificaciones.begin(); iter != this->calificaciones.end(); iter++ ) {
		sum = sum + (*iter)->getPuntaje();
		iteraciones++;
	}
	if (iteraciones == 0){
        return 0;
    }else{
	    return sum/iteraciones;
    }
}

 
vector<DTCalificacion> Hostal::getDetalles(){
	vector<DTCalificacion> res;
    set<Calificacion*>::iterator iter;
	for (iter = this->calificaciones.begin(); iter != this->calificaciones.end(); iter++){
		DTCalificacion nuevo = DTCalificacion((*iter)->getPuntaje(), (*iter)->getComentario(), /*TEMPORAL*/"temporal", 0);
		res.emplace_back(nuevo);
	}
	return res;
}

void Hostal::nuevaHabitacion(int numero, int precio, int capacidad, Hostal* h){
    Habitacion* nueva = new Habitacion(numero, precio, capacidad, h);
    this->habitaciones.insert(pair<int,Habitacion*>(numero, nueva));

}

DTHostal Hostal::getDataHostal()
{
    int promedio = getPromedioPuntaje();
    return DTHostal(nombreHostal, direccion, telefono, promedio);
}

vector<DTEstadia> Hostal::getEstadiasFinalizadas(string emailHuesped){
    map<int, Habitacion*> hs = this->getHabitaciones();
    map<int, Habitacion*>::iterator itr;
    vector<DTEstadia> res;
    for (itr = hs.begin(); itr != hs.end(); ++itr) {
        vector<DTEstadia> aux = itr->second->getEstadiasFinalizadas(emailHuesped);
        // agregar aux a res
        vector<DTEstadia>::iterator itr2;
        for (itr2 = aux.begin(); itr2 != aux.end(); ++itr){
            res.emplace_back(*itr2);
        }
    }
    return res;
}

vector<DTCalificacion> Hostal::getCalificacionesSinResponder(){
    set<Calificacion*> cals = this->calificaciones;
    set<Calificacion*>::iterator itr;
    vector<DTCalificacion> res;
    for (itr = cals.begin(); itr != cals.end(); itr++) {
        Calificacion* aux = *itr;
        if (aux->noEstaRespuesta()){
            res.emplace_back(aux->getDTCalificacion());
        }
    }
    return res;
}

vector<DTEstadia> Hostal::getDTEstadias(){
    map<int, Habitacion*>::iterator itr;
    vector<DTEstadia> res;
    map<int, Habitacion*> aux = this->getHabitaciones();
    for (itr = aux.begin(); itr != aux.end(); itr++) {
        vector<DTEstadia> aux2 = itr->second->getDTEstadias();
        vector<DTEstadia>::iterator itr2;
        for (itr2 = aux2.begin(); itr2 != aux2.end(); itr2++){
            res.emplace_back(*itr2);
        }
    }
    return res;
}

void Hostal::asignarEmpleado(Empleado* empleado)
{
	empleados.insert(pair<string, Empleado*>(empleado->getEmail(), empleado));
}

void Hostal::reservarHabitacion(Reserva* reserva, int habitacion)
{
    Habitacion* habitacionAReservar = habitaciones.find(habitacion)->second;

    habitacionAReservar->addReserva(reserva);

}

set<int> Hostal::getHabitacionesLibres(Fecha CheckIn, Fecha CheckOut)
{
    set<int> habitacionesLibres;
    map<int,Habitacion*>::iterator it = habitaciones.begin();
    for (; it != habitaciones.end(); it++)
    {
        if (!(it->second->isReservado(CheckIn, CheckOut))) habitacionesLibres.insert(it->second->getNumero());
    }
    return habitacionesLibres;
}

Habitacion* Hostal::getHabitacion(int num)
{
    return habitaciones.find(num)->second;
}

bool Hostal::checkHab(int h){
    return this->habitaciones.find(h) != this->habitaciones.end();
}

vector<DTHabitacion> Hostal::getDTHabitaciones(){

    vector<DTHabitacion> nuevo;

    for (map<int, Habitacion*>::iterator ite = this->habitaciones.begin();ite != this->habitaciones.end(); ite++){
        nuevo.emplace_back(ite->second->getDTHabitacion());
    }
    return nuevo;
}