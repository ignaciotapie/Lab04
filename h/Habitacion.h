#ifndef HABITACION_
#define HABITACION_

#include "Reserva.h"
#include "Hostal.h"
#include "Estadia.h"
#include "DTEstadia.h"
#include <map>
#include <set>

using namespace std;

class Hostal;
class Reserva;

class Habitacion{
    private:
        int numero;
        int precio;
        int capacidad;
        Hostal* hostal;
        map<int, Reserva*> reservas;
    public:
        Habitacion();
        Habitacion(int, int, int, Hostal*, map<int, Reserva*>);
        int getNumero();
        int getCapacidad();
        int getPrecio();
        Hostal* getHostal();
        map<int, Reserva*> getReservas();
        void addReserva(Reserva*);
        bool isReservado(Fecha);
        //CalificarEstadia
        set<DTEstadia> getEstadiasFinalizadas(string);
        //ConsultaEstadia
        set<DTEstadia> getDTEstadias();
};

#endif