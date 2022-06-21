#ifndef IRESERVAS_
#define IRESERVAS_

#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

class DTReserva;
class DTCalificacion;
class DTEstadia;
class DTEstadiaPlus;
class Huesped;

class IReservas{
	public:
		virtual void registrarEstadia(int, Huesped*) = 0;
		virtual set<string> getHostales() = 0;
		virtual void seleccionarEstadia(int, string) = 0;
		virtual void finalizarEstadia() = 0;
		virtual void setCalificacion(string, int) = 0;
		virtual vector<DTCalificacion> getCalificacionesSinResponder(string) = 0;
		virtual void setComentarioCalificacion(string) = 0;
		virtual void selectCalificacion(string, int) = 0;
		virtual vector<DTEstadia> getEstadias() = 0;
		virtual DTEstadiaPlus getEstadiaPlus() = 0;
		virtual DTReserva getDTReserva() = 0;
		virtual DTCalificacion getDTCalificacion() = 0;
		virtual void finConsultaEstadia() = 0;
		virtual void seleccionarHostal(string) = 0;
		virtual vector<DTEstadia> getEstadiasFinalizadas(string) = 0;
		virtual bool existeCalificacion() = 0;
		virtual bool existeRespuestaEmpleado() = 0;
		virtual string getRespuestaEmpleado() = 0;
		virtual vector<DTReserva>listarReservasDeHostal(string) = 0;

		virtual void cargaDatos() = 0;
};

#endif