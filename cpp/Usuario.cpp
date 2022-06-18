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

string Usuario::getNombreUsuario(){ //getters
	return this->nombre;
}

string Usuario::getEmailUsuario(){ 
	return this->emil;
}

string Usuario::getPasswordUsuario(){ 
	return this->password;
}

CargoEmpleado Empleado::getCargoEmpleado(){
    this->cargoEmpleado
}

bool Huesped::getEsFinger(){
    this->esFinger;
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
	for (auto it = this->reservas->begin(); it != this->reservas->end(); it++){
		if (it->getEstado == Abierta) {
			res.insert(it->getCodigoReserva());
		}
	}
	return res;
}