#ifndef RESPUESTAEMPLEADO_
#define RESPUESTAEMPLEADO_

#include <string>
#include "Calificacion.h"
#include "Usuario.h"

using namespace std;

class Calificacion;

class RespuestaEmpleado
{
private:
    string mensaje;
    Empleado* empleado;
    Calificacion* calificacion;
public:
    RespuestaEmpleado(string, Empleado*, Calificacion*);
    ~RespuestaEmpleado();
    string getMensaje();
    Empleado* getEmpleado();
    Calificacion* getCalificacion();
};


#endif