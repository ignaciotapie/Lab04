#ifndef CONTROLADORHOSTALES_
#define CONTROLADORHOSTALES_

#include "IHostales.h"
#include "Hostal.h"
#include "Reserva.h"
#include "Fecha.h"

class ControladorHostales : public IHostales{
	
	private:
		static ControladorHostales* instance;

		//Caso de Uso: Alta de Hostal
		string nombreHostal, direccionHostal;
		int telefonoHostal;

		//Caso de Uso: Asignar Empleado a Hostal
		string nombreEmpleadoAAsignar, nombreHostalAAsignar;
		CargoEmpleado cargoEmpleadoAAsignar;

		//Caso de Uso: Realizar Reserva
		string nombreHostalAReservar;
		Fecha checkInReserva, checkOutReserva;
		bool esReservaGrupalReserva;
		int habitacionAReservar;
		set<string> huespedesAElegir;
	
		map<string, Hostal*> hostales;

	public: 
		static ControladorHostales* getInstance();


		//Caso de uso: Alta de Hostal
		void setHostalInfo(string nombre, string direccion, int telefono);
		void confirmarAltaHostal();
		void cancelarAltaHostal();

		//Caso de uso: Alta de Habitacion
		set<string> getHostales();
		void seleccionarHostal(string);
		void altaHabitacion(int, int, int);
		void confirmarHabitacion();
		void cancelarHabitacion();

		//Caso de uso: Consulta de Hostal
		DTHostal getDTHostal();
		void finalizarConsultaHostal();

		//Caso de uso: Realizar Reserva
		bool existeHostal(string nombreHostal);
		set<DTHostal> getHostalesPlus();
		void seleccionarHostalParaReserva(string nombreHostal, Fecha checkIn, Fecha checkOut, bool esReservaGrupal);
		void seleccionarHabitacion(int habitacion);
		void seleccionarHuesped(string nombreHuesped);

		set<string> getTop3Hostales();
		set<DTCalificacion> getDetallesHostal(string);
		void asignarEmpleado(string nombreEmpleado, CargoEmpleado cargo);
		void cancelarAsignacion();
		void confirmarAsignacion();
		set<string> getEmpleadosFueraDeHostal(string);
		void cancelarReserva();
		void confirmarReserva();
		set<int> getHabitacionesLibres();

		//CalificarEstadia
		Hostal* getHostal(string);
};

#endif