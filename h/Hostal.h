#ifndef HOSTAL_
#define HOSTAL_

#include <string>
#include <map>
#include <set>

#include "Habitacion.h"
#include "Usuario.h"
#include "Calificacion.h"
#include "DTHostal.h"

using namespace std;

class Habitacion;
class Calificacion;
class Empleado;
class DTCalificacion;
class Reserva;
class DTEstadia;

class Hostal{
    private:
        string nombreHostal;
        string direccion;
        int telefono;
        map<int, Habitacion*> habitaciones;
        set<Calificacion*> calificaciones;
        map<string, Empleado*> empleados;
    public:
        Hostal();
        Hostal(string nombre, string direccion, int telefono);
        ~Hostal();

        //Caso de uso: Alta de Habitacion
        //string getNombreHostal();
        void nuevaHabitacion(int, int, int);
        DTHostal getDataHostal();


        string getNombreHostal();
        string getDireccion();
        int getTelefono();
        map<int, Habitacion*> getHabitaciones();
        set<Calificacion*> getCalificaciones();
        map<string, Empleado*> getEmpleados();
        void agregarCalificacion(Calificacion*);
        int getPromedioPuntaje();
        set<DTCalificacion> getDetalles();
        void asignarEmpleado(Empleado*);
        void reservarHabitacion(Reserva*, int);
        //CalificarEstadia
        set<DTEstadia> getEstadiasFinalizadas(string);
        //ComentarCalificacion
        set<DTCalificacion> getCalificacionesSinResponder();\
        //ConsultaEstadia
        set<DTEstadia> getDTEstadias();
};


#endif