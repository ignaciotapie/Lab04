#include "../h/ControladorHostales.h"
#include "../h/ControladorUsuarios.h"

ControladorHostales* ControladorHostales::instance = NULL;

ControladorHostales* ControladorHostales::getInstance(){
    if (!instance)
    {
        instance = new ControladorHostales();
    }
    return instance;
}

void ControladorHostales::setHostalInfo(string nombre, string direccion, int telefono)
{
    nombreHostal = nombre;
    direccionHostal = direccion;
    telefonoHostal = telefono;
}

void ControladorHostales::confirmarAltaHostal()
{
    Hostal* h = new Hostal(nombreHostal, direccionHostal, telefonoHostal);
    hostales.insert(pair<string,Hostal*>(nombreHostal, h));
}
void ControladorHostales::cancelarAltaHostal()
{
}


//Caso de Uso: Asignar Empleado a Hostal
set<string> ControladorHostales::getEmpleadosFueraDeHostal(string nombreHostal)
{
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    map<string,Empleado*> empleados = cu->getEmpleados();
    Hostal* hostalElegido = hostales.find(nombreHostal)->second;
    map<string, Empleado*> empleadosAEliminar = hostalElegido->getEmpleados();

    map<string, Empleado*>::iterator iter = empleadosAEliminar.begin();
    for (;iter != empleadosAEliminar.end(); iter++)
    {
        empleados.erase(iter->first);
    }
    set<string> empleadosSinHostalSeleccionado;


    map<string, Empleado*>::iterator aux = empleados.begin();
    for (; aux != empleados.end(); aux++)
    {
        empleadosSinHostalSeleccionado.insert(aux->first);
    }
    nombreHostalAAsignar = nombreHostal;

    return empleadosSinHostalSeleccionado;
}

void ControladorHostales::asignarEmpleado(string nombre, CargoEmpleado cargo)
{
    nombreEmpleadoAAsignar = nombre;
    cargoEmpleadoAAsignar = cargo;
}
void ControladorHostales::confirmarAsignacion()
{
    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
    Empleado* empleado = cu->getEmpleado(nombreEmpleadoAAsignar);

    Hostal* hostal = hostales.find(nombreHostalAAsignar)->second;

    empleado->setCargo(cargoEmpleadoAAsignar);
    empleado->setHostal(hostal);

    hostal->asignarEmpleado(empleado);

}
void ControladorHostales::cancelarAsignacion()
{
}


//Caso de uso: Realizar Reserva
bool ControladorHostales::existeHostal(string nombreHostal)
{
    return (hostales.find(nombreHostal) != hostales.end());
}


DTHostal ControladorHostales::getDTHostal(){
    return DTHostal("nombre","nombre",1,1); //TEMPORAL.
}
set<string> ControladorHostales::getHostales(){
    return set<string>(); //TEMPORAL.
}
void ControladorHostales::seleccionarHostal(string){

}
void ControladorHostales::altaHabitacion(){

}
void ControladorHostales::confirmar(){

}
//Consulta Top 3 Hostales
set<string> ControladorHostales::getTop3Hostales(){
    set<string> res;
	int prom = 0;
	int prom1 = 0;
	int prom2 = 0;
	int prom3 = 0;
	Hostal* h1 = NULL;
	Hostal* h2 = NULL;
	Hostal* h3 = NULL;
	for (map<string,Hostal*>::iterator it =  hostales.begin(); it != hostales.end(); it++){
		prom = it->second->getPromedioPuntaje();
		if (prom > prom1){
			prom3 = prom2;
			prom2 = prom1;
			prom1 = prom;
			h3 = h2;
			h2 = h1;
			h1 = it->second;
		}else if (prom > prom2){
			prom3 = prom2;
			prom2 = prom;
			h3 = h2;
			h2 = it->second;
		}else if (prom > prom3){
			prom3 = prom;
			h3 = it->second;
		}
	}	
	res.insert(h1->getNombreHostal());
	res.insert(h2->getNombreHostal());
	res.insert(h3->getNombreHostal());
	return res;

}
set<DTCalificacion> ControladorHostales::getDetallesHostal(string){
    map<string,Hostal*>::iterator it = hostales.find(nombreHostal);
	set<DTCalificacion> res = it->second->getDetalles();
	return res;
}


void ControladorHostales::finalizarConsultaHostal(){}


void ControladorHostales::cancelarReserva(){}
void ControladorHostales::confirmarReserva(){}
set<int> ControladorHostales::getHabitacionesLibres()
{
    Hostal* hostal = hostales.find(nombreHostalAReservar)->second;
    return hostal->getHabitacionesLibres(checkInReserva, checkOutReserva);
}
set<DTHostal> ControladorHostales::getHostalesPlus()
{
    map<string, Hostal*>::iterator it = hostales.begin();
    set<DTHostal> listaDTs;
    for (; it != hostales.end(); it++)
    {
        listaDTs.insert(it->second->getDataHostal());
    }
    return listaDTs;
}
void ControladorHostales::seleccionarHabitacion(int habitacion)
{
    habitacionAReservar = habitacion;
}
void ControladorHostales::seleccionarHostalParaReserva(string nombreHostal, Fecha checkIn, Fecha checkOut, bool esReservaGrupal)
{
    nombreHostalAReservar = nombreHostal;
    checkInReserva = checkIn;
    checkOutReserva = checkOut;
    esReservaGrupalReserva = esReservaGrupal;
}
void ControladorHostales::seleccionarHuesped(string nombreHuesped)
{
    huespedesAElegir.insert(nombreHuesped);
}


Hostal* ControladorHostales::getHostal(string nombreHostal){
    return hostales.find(nombreHostal)->second;
}