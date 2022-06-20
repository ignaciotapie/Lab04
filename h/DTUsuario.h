#ifndef DTUSUARIO_
#define DTUSUARIO_

#include <string>
#include "Enum.h"

using namespace std;

class DTUsuario
{
    protected:
        string nombre;
        string email;
    public:

};

class DTHuesped : public DTUsuario
{
    private:
        bool esFinger;
    public:
        DTHuesped(string nombre, string email, bool esFinger);
};

class DTEmpleado : public DTUsuario
{
    private:
        CargoEmpleado cargo;
        string nombreHostal;
    public:
        DTEmpleado(string nombre, string email, CargoEmpleado cargo, string nombreHostal);
};

#endif