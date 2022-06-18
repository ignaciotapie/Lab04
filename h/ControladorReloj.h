#ifndef Controlador_Reloj
#define Controlador_Reloj

#include "IReloj.h"

using namespace std;

class ControladorReloj: public IReloj {
	private:
		//singleton
		static ControladorReloj *instance;
		Fecha fechaActual;
	
	public: 
		static ControladorReloj* getInstance();
		//operaciones
		
		Fecha getFechaActual();
		void modificarFecha(int, int, int, int);
};

#endif
