#ifndef DTUSUARIO_
#define DTUSUARIO_

#include <string>
#include "Enum.h"

using namespace std;

class DTUsuario
{
private:
    string nombre;
    string email;
public:
    DTUsuario(/* args */);
    ~DTUsuario();
};

class DTHuesped : public DTUsuario
{
private:
    bool esFinger;
public:
    DTHuesped(string, string, bool);
    ~DTHuesped();
};

class DTEmpleado : public DTUsuario
{
private:
    CargoEmpleado cargo;
    string nombreHostal;
public:
    DTEmpleado(string, string, CargoEmpleado, string);
    ~DTEmpleado();
};

#endif