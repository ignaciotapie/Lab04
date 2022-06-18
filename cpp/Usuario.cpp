#include "h/Usuario.h"

Empleado::Empleado(string nombre, string email, string password, CargoEmpleado cargo)
{
    this->nombre = nombre;
    this->email = email;
    this->password = password;
    this->cargo = cargo;
}

Huesped::Huesped(string nombre, string email, string password, bool esFinger)
{
    this->nombre = nombre;
    this->email = email;
    this->password = password;
    this->esFinger = esFinger;
}

string Usuario::getPassword(){ 
	return this->password;
}

CargoEmpleado Empleado::getCargoEmpleado(){
    return this->cargo;
}

bool Huesped::getEsFinger(){
    return this->esFinger;
}

void Empleado::notificarCalificacion(Notificacion*){
    
}

set<DTCalificacion> Empleado::getCalificacionesSinResponder(){
    return this->hostal->getCalificacionesSinResponder();
}

void Empleado::setRespuestaEmpleado(RespuestaEmpleado* res){
    this->re.insert(res);
}

set<int> Huesped::getCodigosReservas() {
	set<int> res;
    map<int, Reserva*>::iterator it = r.begin();
	for (; it != r.end(); it++){
		if (it->second->getEstado() == Abierta) {
			res.insert(it->second->getCodigoReserva());
		}
	}
	return res;
}