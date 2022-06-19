#ifndef DTRESERVA_
#define DTRESERVA_

#include <string>
#include "Fecha.h"
#include "Enum.h"
#include <set>

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
    DTReserva(int codigo, Fecha checkIn, Fecha checkOut, EstadoReserva estado, int costo, int numeroHabitacion);
};

class DTReservaGrupal : public DTReserva
{
private:
    set<string> nombreHuesped;
public:
    DTReservaGrupal(int, Fecha, Fecha, EstadoReserva, int, int, set<string>);
};

class DTReservaIndividual : public DTReserva
{
private:
    /* data */
public:
    DTReservaIndividual(int, Fecha, Fecha, EstadoReserva, int, int);
};

#endif