#ifndef HOSTAL_
#define HOSTAL_

#include <string>
#include <map>
#include <set>
#include <vector>
#include "Fecha.h"

using namespace std;

class Habitacion;
class Calificacion;
class Empleado;
class DTCalificacion;
class Reserva;
class DTEstadia;
class DTHostal;

class Hostal{
    private:
        string nombreHostal;
        string direccion;
        string telefono;
        map<int, Habitacion*> habitaciones;
        set<Calificacion*> calificaciones;
        map<string, Empleado*> empleados;
    public:
        Hostal();
        Hostal(string nombre, string direccion, string telefono);
        Hostal(string nombreHostal, string direccion, string telefono, map<int, Habitacion*> habitaciones, set<Calificacion*> calificaciones, map<string, Empleado*> empleados);

        //Caso de uso: Alta de Habitacion
        //string getNombreHostal();
        void nuevaHabitacion(int, int, int, Hostal*);
        DTHostal getDataHostal();

        //Caso de uso: Realizar Reserva
        set<int> getHabitacionesLibres(Fecha CheckIn, Fecha CheckOut);
        
        const string getNombreHostal() const;
        const string getDireccion() const;
        const int getTelefono() const;
        map<int, Habitacion*> getHabitaciones();
        set<Calificacion*> getCalificaciones();
        map<string, Empleado*> getEmpleados();
        void agregarCalificacion(Calificacion*);
        const int getPromedioPuntaje() const;
        vector<DTCalificacion> getDetalles();
        void asignarEmpleado(Empleado*);
        void reservarHabitacion(Reserva*, int);
        //CalificarEstadia
        vector<DTEstadia> getEstadiasFinalizadas(string);
        //ComentarCalificacion
        vector<DTCalificacion> getCalificacionesSinResponder();\
        //ConsultaEstadia
        vector<DTEstadia> getDTEstadias();
};


#endif