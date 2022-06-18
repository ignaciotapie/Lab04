#ifndef ESTADIA_
#define ESTADIA_

#include "Fecha.h"
#include "Usuario.h"
#include "Reserva.h"
#include "Calificacion.h"
#include "DTEstadia.h"
#include "DTEstadiaPlus.h"
#include "DTReserva.h"

class DTReserva;

class Estadia
{
private:
    Fecha checkInReal;
    Fecha checkOutReal;
    int promo;
    Reserva* reserva;
    Huesped* huesped;
    Calificacion* calificacion;
public:
    Estadia(Fecha, Fecha, int, Reserva*, Huesped*, Calificacion*);
    ~Estadia();
    Reserva* getReserva();
    Huesped* getHuesped();
    Fecha getCheckOut();
    Fecha getCheckIn();
    int getPromo();
    void setCheckOut(Fecha);
    DTReserva getDTReserva();
    //calificarEstadia
    bool estaFinalizada();
    bool esHues(string);
    DTEstadia getDTEstadia();
    void setCalificacion(string, int, Hostal*);
    Calificacion* getCalificacion();
    //ConsultaEstadia
    DTEstadiaPlus getDTEstadiaPlus();
    DTCalificacion getDTCalificacion();
};

#endif