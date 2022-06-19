#ifndef CALIFICACION_
#define CALIFICACION_

#include <string>
#include <map>

using namespace std;

class Estadia;
class RespuestaEmpleado;
class Hostal;
class Empleado;
class Notificacion;
class DTCalificacion;

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