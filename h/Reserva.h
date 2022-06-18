#ifndef RESERVA_
#define RESERVA_

#include "Fecha.h"
#include <map>
#include "Estadia.h"
#include "Usuario.h"
#include "Habitacion.h"
#include "Enum.h"

using namespace std;

class Estadia;
class Huesped;
class DTReserva;

class Reserva{
    private:
        int codigoReserva;
        Fecha checkIn;
        Fecha checkOut;
        EstadoReserva estado;
        int costo;
        Habitacion* habitacion;
        map<string, Estadia*> estadias;
        Huesped* huesped;
    public:
        Reserva(/* args */);
        ~Reserva();
        int getCodigoReserva();
        Fecha getCheckIn();
        Fecha getCheckOut();
        EstadoReserva getEstado();
        int getCosto();
        Habitacion* getHabitacion();
        map<string, Estadia*> getEstadias();
        Huesped* getHuesped();
        void setCerradaReserva(Fecha, int, Reserva*, Huesped*);
        DTReserva getDTReserva();
        //CalificarEstadia
        set<DTEstadia> getEstadiasFinalizadas(string);
        Estadia* getEstadia(string);
        //ConsultaEstadia
        set<DTEstadia> getDTEstadias();
};

class ReservaGrupal : public Reserva{
    private:
        int cantHuesp;
        map<string, Huesped*> huespedesExtra;
    public:
        ReservaGrupal(/* args */);
        ~ReservaGrupal();
        void setCerradaReserva();
        int getCodigo();
};

class ReservaIndividual : public Reserva{
    private:
    public:
        ReservaIndividual(/* args */);
        ~ReservaIndividual();
        void setCerradaReserva();
        int getCodigo();
};

#endif