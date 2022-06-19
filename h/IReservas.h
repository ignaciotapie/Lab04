#ifndef IRESERVAS_
#define IRESERVAS_

#include "Usuario.h"
#include "DTCalificacion.h"
#include "DTEstadia.h"
#include "DTEstadiaPlus.h"

#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;
class DTReserva;

class IReservas{
	public:
		virtual void registrarEstadia(int, Huesped*); 
		virtual set<string> getHostales();
		virtual void seleccionarEstadia(int, string);
		virtual void finalizarEstadia();
		virtual void setCalificacion(string, int);
		virtual vector<DTCalificacion> getCalificacionesSinResponder(string);
		virtual void setComentarioCalificacion(string);
		virtual void selectCalificacion(string, int);
		virtual vector<DTEstadia> getEstadias();
		virtual DTEstadiaPlus getEstadiaPlus();
		virtual DTReserva getDTReserva();
		virtual DTCalificacion getDTCalificacion();
		virtual void finConsultaEstadia();
		virtual void seleccionarHostal(string);
		virtual vector<DTEstadia> getEstadiasFinalizadas(string);
};

#endif