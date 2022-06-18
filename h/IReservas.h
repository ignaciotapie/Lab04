#ifndef IRESERVAS_
#define IRESERVAS_

#include <string>
#include <map>
#include <set>
#include "Usuario.h"
#include "DTCalificacion.h"
#include "DTEstadia.h"
#include "DTEstadiaPlus.h"
#include "DTReserva.h"
#include "ControladorUsuarios.h"

using namespace std;

class IReservas{
	public:
		virtual void registrarEstadia(int, Huesped*); 
		virtual set<string> getHostales();
		virtual void seleccionarEstadia(int, string);
		virtual void finalizarEstadia();
		virtual void setCalificacion(string, int);
		virtual set<DTCalificacion> getCalificacionesSinResponder(string);
		virtual void setComentarioCalificacion(string);
		virtual void selectCalificacion(string, int);
		virtual set<DTEstadia> getEstadias();
		virtual DTEstadiaPlus getEstadiaPlus();
		virtual DTReserva getDTReserva();
		virtual DTCalificacion getDTCalificacion();
		virtual void finConsultaEstadia();
		virtual void seleccionarHostal(string);
		virtual set<DTEstadia> getEstadiasFinalizadas(string);
		virtual ~IReservas();
};

#endif