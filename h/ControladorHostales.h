#ifndef CONTROLADORHOSTALES_
#define CONTROLADORHOSTALES_

#include "IHostales.h"
#include "Hostal.h"
#include "Reserva.h"

class ControladorHostales : public IHostales{
	
	private:
		static ControladorHostales* instance;

		//Caso de Uso: Alta de Hostal
		string nombreHostal, direccionHostal;
		int telefonoHostal;

		//Caso de Uso: Asignar Empleado a Hostal
		string nombreEmpleadoAAsignar, nombreHostalAAsignar;
		CargoEmpleado cargoEmpleadoAAsignar;

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


		set<string> getTop3Hostales();
		set<DTCalificacion> getDetallesHostal(string);
		void asignarEmpleado(string nombreEmpleado, CargoEmpleado cargo);
		void cancelarAsignacion();
		void confirmarAsignacion();
		set<string> getEmpleadosFueraDeHostal(string);
		void cancelarReserva();
		void confirmarReserva();
		set<int> getHabitacionesLibres();
		set<DTHostal> getHostalesPlus();
		void seleccionarHabitacion();
		void seleccionarHostalParaReserva(string, Fecha, bool);
		void seleccionarHuesped();
		//CalificarEstadia
		Hostal* getHostal(string);
};

#endif