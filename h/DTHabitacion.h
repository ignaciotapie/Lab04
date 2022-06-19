#ifndef DTHABITACION_
#define DTHABITACION_

#include <string>
#include <map>



using namespace std;

class DTCalificacion;

class DTHabitacion{
    private:
        int numero;
        int precio;
        int capacidad;
        map<string, DTCalificacion> *calificaciones;
    public:
        DTHabitacion(int, int, int, map<string, DTCalificacion> *);
        const int getNumero() const;
        const int getPrecio() const;
        const int getCapacidad() const;
        const map<string, DTCalificacion>* getCalificaciones() const;
};

#endif