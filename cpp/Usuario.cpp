#include "../h/Usuario.h"

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

string Usuario::getNombre()
{
    return this->nombre;
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

string Usuario::getEmail()
{
    return email;
}

void Empleado::notificarCalificacion(Notificacion* noti){
    n.insert(noti);
}

vector<DTCalificacion> Empleado::getCalificacionesSinResponder(){
    return this->hostal->getCalificacionesSinResponder();
}

void Empleado::setRespuestaEmpleado(RespuestaEmpleado* res){
    this->re.insert(res);
}

set<int> Huesped::getCodigosReservas() {
	set<int> res;
    map<int, ReservaIndividual*>::iterator it = r.begin();
	for (; it != r.end(); it++){
		if (it->second->getEstado() == Abierta) {
			res.insert(it->second->getCodigoReserva());
		}
	}

    map<int, ReservaGrupal*>::iterator iter = rg.begin();
    for (; iter != rg.end(); iter++)
    {
        if (iter->second->getEstado() == Abierta) {
			res.insert(it->second->getCodigoReserva());
		}
    }
	return res;
}

void Huesped::addReserva(Reserva* r)
{
    ReservaIndividual* ri = dynamic_cast<ReservaIndividual*>(r);
    if (ri)
    {
	this->r.insert(pair<int, ReservaIndividual*>(ri->getCodigoReserva(), ri));
    }
    else
    {
        ReservaGrupal* rg = dynamic_cast<ReservaGrupal*>(r);
        this->rg.insert(pair<int, ReservaGrupal*>(rg->getCodigoReserva(), rg));
    }
}
