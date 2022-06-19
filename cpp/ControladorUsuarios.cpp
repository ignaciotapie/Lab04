#include "../h/ControladorUsuarios.h"
#include "../h/ControladorHostales.h"
#include "../h/Usuario.h"
#include "../h/ControladorReservas.h"
#include "../h/DTUsuario.h"
#include "../h/DTNotificacion.h"

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
	empleados.insert(pair<string,Empleado*>(emailUsuario, empleado));
        user = empleado;
    }
    else
    {
        Huesped* huesped = new Huesped(nombreUsuario, emailUsuario, passwordUsuario, esFingerUsuario);
	huespedes.insert(pair<string,Huesped*>(emailUsuario, huesped));
        user = huesped;
    }
	usuarios.insert(pair<string,Usuario*>(emailUsuario, user));
}

Empleado* ControladorUsuarios::getEmpleado(string emailUsuario)
{
    return empleados.find(emailUsuario)->second;
}

set<string> ControladorUsuarios::getHuespedes()
{
    set<string> listaHuespedes;
    map<string, Huesped*>::iterator it = huespedes.begin();
    for (; it != huespedes.end(); it++)
    {
        listaHuespedes.insert(it->second->getNombre());
    }
    return listaHuespedes;
}

Huesped* ControladorUsuarios::getHuesped(string emailUsuario)
{
    return huespedes.find(emailUsuario)->second;
}

set<string> ControladorUsuarios::getUsuarios()
{
    map<string,Usuario*>::iterator it = usuarios.begin();
    set<string> nombres;
    for (; it != usuarios.end(); it++)
    {
        nombres.insert(it->second->getNombre());
    }
    return nombres;
}

void ControladorUsuarios::seleccionarUsuario(string){}

//Registrar Estadia
set<string> ControladorUsuarios::getHostales(){
	set<string> res = ControladorHostales::getInstance()->getHostales();
	return res;
}
void ControladorUsuarios::seleccionarHostal(string nombreHostal){
	this->nombreHostal = nombreHostal;
} 
set<int> ControladorUsuarios::getReservasDelHuesped(string emailHuesped) {
	this->emailHuesped = emailHuesped;
	map<string,Huesped*>::iterator it = huespedes.find(emailHuesped); 
	set<int> res = it->second->getCodigosReservas();
	return res;
}

void ControladorUsuarios::seleccionarReserva(int codigoReserva){
	this->codigoReserva = codigoReserva;
} 

void ControladorUsuarios::registrarEstadia(){
	Huesped* hues = huespedes.find(this->emailHuesped)->second;
    ControladorReservas* cr = ControladorReservas::getInstance();
	cr->registrarEstadia(this->codigoReserva, hues); //mandar la funcion de controldorReservas
}


DTUsuario ControladorUsuarios::listarDatos(){
    map<string,Usuario*>::iterator ite = this->usuarios.find(this->usuarioSeleccionado);
    return (*ite).second.getDTUsuario();
}

void ControladorUsuarios::finalizarConsultaUsuario(){}
void ControladorUsuarios::eliminarEmpleado(){}
vector<DTNotificacion> ControladorUsuarios::listaNotificaciones()
{
    return vector<DTNotificacion>();
}
void ControladorUsuarios::finalizarConsultaNotis(){}
void ControladorUsuarios::finalizarEliminacion(){}

vector<DTCalificacion> ControladorUsuarios::getCalificacionesSinResponder(string emailEmpleado){
    Empleado e = *empleados.find(emailEmpleado)->second;
    vector<DTCalificacion> res = e.getCalificacionesSinResponder();
    return res;
}


map<string,Empleado*> ControladorUsuarios::getEmpleados()
{
    return empleados;
}


void ControladorUsuarios::notificarObservadores(Notificacion* n)
{
    set<Empleado*>::iterator it = observers.begin();
    for (; it != observers.end(); it++)
    {
        (*it)->notificarCalificacion(n);
    }
}

set<string> ControladorUsuarios::getListaEmpleados()
{
    set<string> listaEmpleados;
    map<string, Empleado*>::iterator it = empleados.begin();
    for (; it != empleados.end(); it++)
    {
        listaEmpleados.insert(it->second->getNombre());
    }
    return listaEmpleados;
}

void ControladorUsuarios::seleccionarEmpleado(string nombre)
{
    nombreEmpleadoASuscribir = nombre;
}
void ControladorUsuarios::suscribirEmpleado()
{
    observers.insert(empleados.find(nombreEmpleadoASuscribir)->second);
}
void ControladorUsuarios::finalizarSuscripcion()
{

}
