#include "../h/ControladorUsuarios.h"

ControladorUsuarios* ControladorUsuarios::instance = NULL;

ControladorUsuarios* ControladorUsuarios::getInstance()
{
    if (!instance)
    {
        instance = new ControladorUsuarios();
    }
    return instance;
}

void ControladorUsuarios::setUserInfo(string nombre, string email, string password)
{
    nombreUsuario = nombre;
    emailUsuario = email;
    passwordUsuario = password;
}

void ControladorUsuarios::esEmpleado(bool status)
{
    esEmpleadoUsuario = status;
}
void ControladorUsuarios::esFinger(bool status)
{
    esFingerUsuario = status;
}
void ControladorUsuarios::setCargoEmpleado(CargoEmpleado cargo)
{
    cargoUsuario = cargo;
}

bool ControladorUsuarios::esUsuarioRepetido()
{
    return (usuarios.find(emailUsuario) != usuarios.end());
}

void ControladorUsuarios::reingresarDatos()
{
}
void ControladorUsuarios::cancelarAltaUsuario()
{
}

void ControladorUsuarios::confirmarAltaUsuario()
{
    Usuario* user;
    if (esEmpleadoUsuario)
    {
        Empleado* empleado = new Empleado(nombreUsuario, emailUsuario, passwordUsuario, cargoUsuario);
        empleados.insert({emailUsuario, empleado});
        user = empleado;
    }
    else
    {
        Huesped* huesped = new Huesped(nombreUsuario, emailUsuario, passwordUsuario, esFingerUsuario);
        huespedes.insert({emailUsuario, huesped});
        user = huesped;
    }
    usuarios.insert({emailUsuario, user});
}

Empleado* ControladorUsuarios::getEmpleado(string nombreUsuario)
{
    return empleados.find(nombreUsuario)->second;
}


set<string> ControladorUsuarios::getUsuarios(){}

void ControladorUsuarios::seleccionarUsuario(string){}

//Registrar Estadia
set<string> ControladorUsuarios::getHostales(){
	set<string> res = ControladorHostales::getInstanciaHostales()->getHostales();
	return res;
}
void ControladorUsuarios::seleccionarHostal(string nombreHostal){
	this->nombreHostal = nombreHostal;
} 
set<int> ControladorUsuarios::getReservasDelHuesped(string emailHuesped) {
	this->emailHuesped = emailHuesped;
	auto it = usuarios.find(emailHuesped); 
	set <int> res = it->getCodigosReserva();
	return res;
}

void ControladorUsuarios::seleccionarReserva(int codigoReserva){
	this->codigoReserva = codigoReserva;
} 

void ControladorUsuarios::registrarEstadia(){
	auto it = usuarios.find(this->emailHuesped);
	Huesped* hues = &it->second;
    ControladorReservas* cr = ControladorReserva::getInstance();
	cr->registrarEstadia(this->codigoReserva, hues); //mandar la funcion de controldorReservas
}


DTUsuario ControladorUsuarios::listarDatos(){}
void ControladorUsuarios::finalizarConsultaUsuario(){}
void ControladorUsuarios::suscribirEmpleado(){}
void ControladorUsuarios::finalizarSuscripcion(){}
void ControladorUsuarios::eliminarEmpleado(){}
set<DTNotificacion> ControladorUsuarios::listaNotificaciones(){}
void ControladorUsuarios::finalizarConsultaNotis(){}
void ControladorUsuarios::finalizarEliminacion(){}

set<DTCalificacion> ControladorUsuarios::getCalificacionesSinResponder(string emailEmpleado){
    Empleado e = *empleados.find(emailEmpleado)->second;
    set<DTCalificacion> res = e.getCalificacionesSinResponder();
    return res;
}


map<string,Empleado*> ControladorUsuarios::getEmpleados()
{
    return empleados;
}


void ControladorUsuarios::notificarObservadores(Notificacion* n){
    
}