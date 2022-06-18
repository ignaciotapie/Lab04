#ifndef DTRESERVA_
#define DTRESERVA_

#include <string>
#include "Fecha.h"
#include "Reserva.h"

using namespace std;

class DTReserva
{
private:
    int codigo;
    Fecha checkIn;
    Fecha checkOut;
    EstadoReserva estado;
    int costo;
    int numeroHabitacion;
public:
    DTReserva(/* args */);
    ~DTReserva();
};

class DTReservaGrupal : public DTReserva
{
private:
    set<string> nombreHuesped;
public:
    DTReservaGrupal(int, Fecha, Fecha, EstadoReserva, int, int, set<string>);
    ~DTReservaGrupal();
};

class DTReservaIndividual : public DTReserva
{
private:
    /* data */
public:
    DTReservaIndividual(int, Fecha, Fecha, EstadoReserva, int, int);
    ~DTReservaIndividual();
};

#endif