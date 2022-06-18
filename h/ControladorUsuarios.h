#ifndef CONTROLADORUSUARIOS_
#define CONTROLADORUSUARIOS_

#include "IUsuarios.h"
#include "ControladorReservas.h"

class ControladorUsuarios : public IUsuarios{
	private:
		static ControladorUsuarios* instance;

		set<Empleado*> observers;
		
		map<string, Huesped*> huespedes;
		map<string, Empleado*> empleados;
		map<string, Usuario*> usuarios;

		// Caso de Uso: Alta de Usuario
		string nombreUsuario, emailUsuario, passwordUsuario;
		bool esEmpleadoUsuario, esFingerUsuario;
		CargoEmpleado cargoUsuario;
		
		//Registrar Estadia
		string nombreHostal;

	public: 

		static ControladorUsuarios* getInstance();

		// Caso de Uso: Alta de Usuario
		void setUserInfo(string nombre, string email, string password);
		void esEmpleado(bool esEmpleado);
		void setCargoEmpleado(CargoEmpleado cargo);
		void esFinger(bool esFinger);
		bool esUsuarioRepetido();
		void reingresarDatos();
		void cancelarAltaUsuario();
		void confirmarAltaUsuario();

		//Caso de uso: Consulta de Usuario
		//set<string> getUsuarios();
		//void seleccionarUsuario(string);
		DTUsuario listarDatos();
		void finalizarConsultaUsuario();
		
		// Caso de Uso: Asignar Empleado a Hostal
		Empleado* getEmpleado(string nombreUsuario);

		set<string> getUsuarios();
		void seleccionarUsuario(string);

		//Caso de uso: Suscribirse a Notificacion
		//Empleado* getEmpleado(string nombreUsuario);
		void seleccionarEmpleado(string);
		void suscribirEmpleado();
		void finalizarSuscripcion();

		//Caso de uso: Consulta de Notificaciones
		set<DTNotificacion> listaNotificaciones();
		void finalizarConsultaNotis();
		
		//Caso de uso: Eliminar Suscripcion
		void eliminarEmpleado();
		void finalizarEliminacion();

		//Registrar Estadia
		set<string> getHostales();
		void seleccionarHostal(string);
		set<int> getReservasDelHuesped(string); 
		void seleccionarReserva(int);
		void registrarEstadia();

		map<string,Empleado*>  getEmpleados();
		//CalificarEstadia
		void notificarObservadores(Notificacion*);
		//ComentarCalificacion
		set<DTCalificacion> getCalificacionesSinResponder(string);
	    
};

#endif