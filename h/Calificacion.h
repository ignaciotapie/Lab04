#ifndef CALIFICACION_
#define CALIFICACION_

#include "Estadia.h"
#include "Hostal.h"
#include "Notificacion.h"
#include "RespuestaEmpleado.h"
#include "DTCalificacion.h"
#include "Usuario.h"

#include <string>
#include <map>

using namespace std;

class Estadia;
class RespuestaEmpleado;
class Hostal;
class Empleado;
class Notificacion;

class Calificacion{
    private:
        int puntaje;
        string comentario;
        Estadia* estadia;
        Hostal* hostal;
        RespuestaEmpleado* respuestaEmpleados;
    public:
        Calificacion(int, string, Estadia*, Hostal*, RespuestaEmpleado*);
        int getPuntaje();
        string getComentario();
        Estadia* getEstadia();
        Hostal* getHostal();
        RespuestaEmpleado* getRespuestaempleados();
        //CalificarEstadia
        Notificacion* crearNotificacion(string);
        //ComentarCalificacion
        bool noEstaRespuesta();
        DTCalificacion getDTCalificacion();
        void setComentarioCalificacion(string, Empleado*, Calificacion*);
};

#endif