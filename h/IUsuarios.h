#ifndef IUSUARIOS_
#define IUSUARIOS_


#include "Usuario.h"
#include "DTUsuario.h"
#include "DTNotificacion.h"
#include "DTCalificacion.h"

#include <string>
#include <map>
#include <set>


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
		virtual set<DTNotificacion> listaNotificaciones();
		virtual void finalizarConsultaNotis();
		virtual void finalizarEliminacion();
		virtual set<DTCalificacion> getCalificacionesSinResponder(string);
		virtual ~IUsuarios(){};
};

#endif