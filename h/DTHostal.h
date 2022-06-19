#ifndef DTHOSTAL_
#define DTHOSTAL_

#include "Hostal.h"
#include <string>


using namespace std;

class DTHostal
{
    private:
        string nombre;
        string direccion;
        int telefono;
        float promCalif;
    public:
        DTHostal(string nombre, string direccion, int telefono, float promCalif);
        DTHostal(const Hostal& hostal);
        const string getNombre() const;
        const string getDireccion() const;
        const int getTelefono() const;
        const float getPromCalif() const;
};

#endif