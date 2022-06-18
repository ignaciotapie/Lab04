#ifndef IHOSTALES_
#define IHOSTALES_

#include <string>
#include <map>
#include <set>
#include "DTReserva.h"
#include "DTCalificacion.h"
#include "DTHostal.h"

using namespace std;

class IHostales{
	public:
		virtual DTHostal getDTHostal();
		virtual set<string> getHostales();
		virtual void seleccionarHostal(string);
		virtual void altaHabitacion();
		virtual void confirmar();
		virtual set<string> getTop3Hostales();
		virtual set<DTCalificacion> getDetallesHostal(string);
		virtual void finalizarConsultaHostal();
		virtual void setHostalInfo(string, string, int);
		virtual void cancelarAltaHostal();
		virtual void confirmarAltaHostal();
		virtual void asignarEmpleado(string, CargoEmpleado);
		virtual void cancelarAsignacion();
		virtual void confirmarAsignacion();
		virtual set<string> getEmpleadosFueraDeHostal(string);
		virtual void cancelarReserva();
		virtual void confirmarReserva();
		virtual set<int> getHabitacionesLibres();
		virtual set<DTHostal> getHostalesPlus();
		virtual void seleccionarHabitacion(int numeroHabitacion);
		virtual void seleccionarHostalParaReserva(string nombreHostal, Fecha checkIn, Fecha checkOut, bool esReservaGrupal);
		virtual void getHuespedes();
		virtual void seleccionarHuesped(string nombreHuesped);
		virtual bool existeHostal(string nombreHostal);
		virtual ~IHostales ();
};

#endif