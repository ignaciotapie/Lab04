#ifndef DTESTADIA_
#define DTESTADIA_

#include <string>
#include "Fecha.h"

using namespace std;

class DTEstadia
{
private:
    string emailHuesped;
    int codigoReserva;
    Fecha checkInReal;
    Fecha checkOutReal;
    int promo;
public:
    DTEstadia(string, int, Fecha, Fecha, int);
    string getEmailHuesped();
    int getCodigoReserva();
    Fecha getCheckInReal();
    Fecha getCheckOutReal();
    int getPromo();
    ~DTEstadia();
};

#endif