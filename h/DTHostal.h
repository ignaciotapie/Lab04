#ifndef DTHOSTAL_
#define DTHOSTAL_

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
    string getNombre() const;
    string getDireccion() const;
    int getTelefono() const;
    float getPromCalif() const;
    ~DTHostal();
};

#endif