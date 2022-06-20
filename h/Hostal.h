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
class DTReserva;

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
        Hostal(string nombreHostal, string direccion, int telefono, map<int, Habitacion*> habitaciones, set<Calificacion*> calificaciones, map<string, Empleado*> empleados);

        //Caso de uso: Alta de Habitacion
        //string getNombreHostal();
        void nuevaHabitacion(int, int, int);
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
        //consultar reserva
        vector<DTReserva> listarReservasDeHostal();
        //baja reserva
        set<int> listarCodigoReservasDeHostal();
        //CalificarEstadia
        vector<DTEstadia> getEstadiasFinalizadas(string);
        //ComentarCalificacion
        vector<DTCalificacion> getCalificacionesSinResponder();\
        //ConsultaEstadia
        vector<DTEstadia> getDTEstadias();
        //baja reserva
        void eliminarCalificacion(Calificacion*);
};


#endif