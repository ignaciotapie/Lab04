#ifndef DTESTADIAPLUS_
#define DTESTADIAPLUS_

#include <string>
#include "../h/Fecha.h"

using namespace std;


class DTEstadiaPlus
{
private:
    string nombreHostal;
    string nombreHuesped;
    int numeroHabitacion;
    int codigoReserva;
    Fecha checkInReal;
    Fecha checkOutReal;
    int promo;
public:
    DTEstadiaPlus(string, string, int, int, Fecha, Fecha, int);
    string getNombreHostal();
    string getNombreHuesped();
    int getNumeroHabitacion();
    int getCodigoReserva();
    Fecha getCheckInReal();
    Fecha getCheckOutReal();
    int getPromo();
};

#endif