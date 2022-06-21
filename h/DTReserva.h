#ifndef DTRESERVA_
#define DTRESERVA_

#include <string>
#include "Fecha.h"
#include "Enum.h"
#include <set>
#include <iostream>

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
    int getCodigo();
    Fecha getCheckIn();
    Fecha getCheckOut();
    EstadoReserva getEstado();
    int getCosto();
    int getNumeroHabitacion();
    DTReserva(int codigo, Fecha checkIn, Fecha checkOut, EstadoReserva estado, int costo, int numeroHabitacion);
    // virtual void imprimir() = 0;
};

class DTReservaGrupal : public DTReserva
{
private:
    set<string> nombreHuesped;
public:
    DTReservaGrupal(int, Fecha, Fecha, EstadoReserva, int, int, set<string>);
    void imprimir();
};

class DTReservaIndividual : public DTReserva
{
private:
    /* data */
public:
    DTReservaIndividual(int, Fecha, Fecha, EstadoReserva, int, int);
    void imprimir();
};

#endif