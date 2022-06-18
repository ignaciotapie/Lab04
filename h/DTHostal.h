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
    DTHostal(string, string, int, float);
    string getNombre();
    string getDireccion();
    int getTelefono();
    float getPromCalif();
    ~DTHostal();
};

#endif