#ifndef DTCALIFICACION_
#define DTCALIFICACION_

#include <string>
#include "Fecha.h"

using namespace std;

class DTCalificacion{
    private:
        int puntaje;
        string comentario;
        Fecha fecha;
        string emailHuesp;
        int codigoReserva;
    public:
        DTCalificacion(int, string, Fecha, string, int);
        DTCalificacion(int, string, string, int);
        DTCalificacion(int, string);
        int getPuntaje();
        string getComentario();
        Fecha getFecha();
        string getEmailHuesp();
        int getCodigoReserva();
        void setPuntaje(int);
        void setComentario(string);
        void setFecha(Fecha);
        void setEmailHuesp(string);
        void setCodigoReserva(int);
};

#endif