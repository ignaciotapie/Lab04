#ifndef RESERVA_
#define RESERVA_

#include "Enum.h"
#include "Fecha.h"

#include <map>
#include <vector>
#include <set>
#include <string>

using namespace std;

class Estadia;
class Huesped;
class Habitacion;
class DTEstadia;
class DTReserva;

class Reserva{
    protected:
        int codigoReserva;
        Fecha checkIn;
        Fecha checkOut;
        EstadoReserva estado;
        int costo;
        Habitacion* habitacion;
        set<Estadia*> estadias;
        Huesped* huesped;
    public:
        int getCodigoReserva();
        Fecha getCheckIn();
        Fecha getCheckOut();
        EstadoReserva getEstado();
        int getCosto();
        Habitacion* getHabitacion();
        set<Estadia*> getEstadias();
        Huesped* getHuesped();
        void setCerradaReserva(Fecha, int, Reserva*, Huesped*);
        DTReserva getDTReserva();
        //CalificarEstadia
        vector<DTEstadia> getEstadiasFinalizadas(string);
        Estadia* getEstadia(string);
        //ConsultaEstadia
        vector<DTEstadia> getDTEstadias();
        void setCerradaReserva();
        
        virtual void calcularCosto() = 0;

        //SETTERS
        void setCheckIn(Fecha checkIn);
        void setCheckOut(Fecha checkOut);
        void setHuespedes(set<string> huespedes);

};

class ReservaGrupal : public Reserva{
    private:
        int cantHuesp;
        map<string, Huesped*> huespedesExtra;
    public:
        ReservaGrupal(int codRes, Fecha checkIn, Fecha checkOut, EstadoReserva estado, int costo);
        ReservaGrupal(int codRes, Fecha checkIn, Fecha checkOut, EstadoReserva estado, Habitacion* h);
        void agregarHuespedExtra(Huesped* huesped);
        void calcularCosto();
        DTReserva getDTReserva();
};

class ReservaIndividual : public Reserva{
    private:

    public:
        ReservaIndividual(int codRes, Fecha checkIn, Fecha checkOut, EstadoReserva estado, int costo);
        ReservaIndividual(int codRes, Fecha checkIn, Fecha checkOut, EstadoReserva estado, Habitacion* h);
        void calcularCosto();
        DTReserva getDTReserva();
};

#endif