#ifndef NOTIFICACION_
#define NOTIFICACION_

#include <string>
#include "Usuario.h"
#include "Calificacion.h"
#include <map>
#include "DTNotificacion.h"

using namespace std;

class Notificacion{
    private:
        string autor;
        int empleadosLinkeados;
        Calificacion* calificacion;
    public:
        Notificacion(string, int, Calificacion*);
        ~Notificacion();

        //Caso de uso: Consulta de Notificaciones
        DTNotificacion getDTNotificacion();
        void disminuirNumero();
        int getEmpleadosLinkeados();

        string getAutor();
        Calificacion* getCalificacion();
        void aumentarNumero();
};


#endif