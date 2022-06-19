#ifndef NOTIFICACION_
#define NOTIFICACION_

#include "Usuario.h"
#include "DTNotificacion.h"
#include "Calificacion.h"
#include <map>
#include <string>


using namespace std;

class Calificacion;

class Notificacion{
    private:
        string autor;
        int empleadosLinkeados;
        Calificacion* calificacion;
    public:
        Notificacion(string, int, Calificacion*);
        string getAutor();
        int getEmpleadosLinkeados();
        Calificacion* getCalificacion();
        DTNotificacion getDTNotificacion();
        void aumentarNumero();
        void disminuirNumero();
};


#endif