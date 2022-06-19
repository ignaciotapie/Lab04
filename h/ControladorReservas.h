#ifndef CONTROLADORRESERVAS_
#define CONTROLADORRESERVAS_

#include "../h/IReservas.h"
#include "../h/ControladorHostales.h"
#include "../h/ControladorReloj.h"

#include <set>
#include <map>

class ControladorReservas : public IReservas
{
	private:
		static ControladorReservas* instance;
		map<int, Reserva*> reservas;
		int sigCodigoReserva = 0;

		string hostalSeleccionado;
		int codigoReservaEstadia;
		string emailHuespedEstadia;
		
		Empleado* empleadoGuardado;


    public:

		static ControladorReservas* getInstance();

		void registrarEstadia(int, Huesped*); 
		set<string> getAllHostales();
	    void finalizarEstadia();
		void setCalificacion(string, int);
		// CalificarEstadia 
		void seleccionarHostal(string);
		set<DTEstadia> getEstadiasFinalizadas(string);
		void seleccionarEstadia(int, string);
		//ComentarCalificacion
		set<DTCalificacion> getCalificacionesSinResponder(string);
		void selectCalificacion(string, int);
		void setComentarioCalificacion(string);
		//ConsultaEstadia
		set<DTEstadia> getEstadias();
		DTEstadiaPlus getEstadiaPlus();
		DTCalificacion getDTCalificacion();
		DTReserva getDTReserva();
		void finConsultaEstadia();
};

#endif