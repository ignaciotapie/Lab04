#ifndef IUSUARIOS_
#define IUSUARIOS_



#include "DTNotificacion.h"
#include "DTCalificacion.h"
#include "Usuario.h"
#include "DTUsuario.h"

#include <string>
#include <map>
#include <set>
#include <vector>


using namespace std;


class IUsuarios{
	public:
		// Caso de Uso: Alta de Usuario
		virtual void setUserInfo(string nombre, string email, string password);
		virtual void esEmpleado(bool esEmpleado);
		virtual void setCargoEmpleado(CargoEmpleado cargo);
		virtual void esFinger(bool esFinger);
		virtual bool esUsuarioRepetido();
		virtual void reingresarDatos();
		virtual void cancelarAltaUsuario();
		virtual void confirmarAltaUsuario();

		virtual set<string> getHuespedes();

		virtual set<string> getUsuarios();
		virtual void seleccionarUsuario(string);
		virtual set<int> getReservasDelHuesped(string); 
		virtual void seleccionarReserva(int);
		virtual void registrarEstadia();
		virtual DTUsuario listarDatos();
		virtual void finalizarConsultaUsuario();
		virtual void suscribirEmpleado();
		virtual void finalizarSuscripcion();
		virtual void eliminarEmpleado();
		virtual vector<DTNotificacion> listaNotificaciones();
		virtual void finalizarConsultaNotis();
		virtual void finalizarEliminacion();
		virtual vector<DTCalificacion> getCalificacionesSinResponder(string);
};

#endif