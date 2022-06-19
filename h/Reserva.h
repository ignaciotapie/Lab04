#ifndef RESERVA_
#define RESERVA_


#include "Enum.h"
#include "DTEstadia.h"
#include "DTReserva.h"

#include <map>
#include <vector>
#include <set>

using namespace std;

class Estadia;
class Huesped;
class Habitacion;
class Fecha;

class Reserva{
    protected:
        int codigoReserva;
        Fecha checkIn;
        Fecha checkOut;
        EstadoReserva estado;
        int costo;
        Habitacion* habitacion;
        map<string, Estadia*> estadias;
        Huesped* huesped;
    public:
        Reserva(int codRes, Fecha checkIn, Fecha checkOut, EstadoReserva estado, int costo);
        virtual int getCodigoReserva();
        virtual Fecha getCheckIn();
        virtual Fecha getCheckOut();
        virtual EstadoReserva getEstado();
        virtual int getCosto();
        virtual Habitacion* getHabitacion();
        virtual map<string, Estadia*> getEstadias();
        virtual Huesped* getHuesped();
        void setCerradaReserva(Fecha, int, Reserva*, Huesped*);
        DTReserva getDTReserva();
        //CalificarEstadia
        vector<DTEstadia> getEstadiasFinalizadas(string);
        Estadia* getEstadia(string);
        //ConsultaEstadia
        vector<DTEstadia> getDTEstadias();


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
        ReservaGrupal(/* args */);
        void setCerradaReserva();
        int getCodigo();
        void agregarHuespedExtra(Huesped* huesped);
};

class ReservaIndividual : public Reserva{
    private:
    public:
        ReservaIndividual(/* args */);
        void setCerradaReserva();
        int getCodigo();
};

#endif