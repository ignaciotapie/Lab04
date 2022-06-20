#include "../h/DTUsuario.h"

using namespace std;

DTHuesped::DTHuesped(string nombre, string email, bool esFinger)
{
    this->nombre = nombre;
    this->email = email;
    this->esFinger = esFinger;
}

DTEmpleado::DTEmpleado(string nombre, string email, CargoEmpleado cargo, string nombreHostal)
{
    this->nombre = nombre;
    this->email = email;
    this->cargo = cargo;
    this->nombreHostal = nombreHostal;
}