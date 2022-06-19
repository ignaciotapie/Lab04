#ifndef CONTROLADORRESERVAS_
#define CONTROLADORRESERVAS_

#include "IReservas.h"
#include "ControladorHostales.h"
#include "ControladorReloj.h"

#include <set>
#include <map>
#include <vector>

class Reserva;
class Empleado;
class DTReserva;

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
		vector<DTEstadia> getEstadiasFinalizadas(string);
		void seleccionarEstadia(int, string);
		//ComentarCalificacion
		vector<DTCalificacion> getCalificacionesSinResponder(string);
		void selectCalificacion(string, int);
		void setComentarioCalificacion(string);
		//ConsultaEstadia
		vector<DTEstadia> getEstadias();
		DTEstadiaPlus getEstadiaPlus();
		DTCalificacion getDTCalificacion();
		DTReserva getDTReserva();
		void finConsultaEstadia();
		set<string> getHostales();


		//Caso de uso: Realizar Reserva
		void addReserva(Reserva* r);
};

#endif