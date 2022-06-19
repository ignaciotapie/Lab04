#ifndef ESTADIA_
#define ESTADIA_

#include "Fecha.h"
#include "Calificacion.h"
#include "DTCalificacion.h"
#include "DTEstadia.h"
#include "DTEstadiaPlus.h"

class DTReserva;
class Huesped;
class Reserva;
class Calificacion;
class Hostal;

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