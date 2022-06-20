#ifndef DTHOSTAL_
#define DTHOSTAL_

#include <string>

using namespace std;
class Hostal;

class DTHostal
{
    private:
        string nombre;
        string direccion;
        string telefono;
        float promCalif;
    public:
        DTHostal(string nombre, string direccion, string telefono, float promCalif);
        DTHostal(const Hostal& hostal);
        const string getNombre() const;
        const string getDireccion() const;
        const string getTelefono() const;
        const float getPromCalif() const;
};

#endif