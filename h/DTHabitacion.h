#ifndef DTHABITACION_
#define DTHABITACION_

#include <string>
#include <map>

#include "DTCalificacion.h"

using namespace std;

class DTHabitacion{
    private:
        int numero;
        int precio;
        int capacidad;
        map<string, DTCalificacion> *calificaciones;
    public:
        DTHabitacion(int, int, int, map<string, DTCalificacion> *);
        int getNumero();
        int getPrecio();
        int getCapacidad();
        map<string, DTCalificacion>* getCalificaciones();
        ~DTHabitacion();
};

#endif