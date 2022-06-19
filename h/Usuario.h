#ifndef USUARIO_
#define USUARIO_

#include <string>
#include <map>
#include <vector>
#include <set>
#include "Enum.h"

class Reserva;
class ReservaGrupal;
class ReservaIndividual;
class RespuestaEmpleado;
class Estadia;
class Calificacion;
class Notificacion;
class Hostal;
class DTUsuario;
class DTNotificacion;
class DTCalificacion;


using namespace std;

class Observer { 
    protected:
        set<Notificacion*> n;
    public:
        //CalificarEstadia
        virtual void notificarCalificacion(Notificacion*) = 0;
};


class Usuario {
    protected:
        string nombre;
        string email;
        string password;
    public:
        string getEmail();
        string getNombre();
        string getPassword();
        virtual DTUsuario getDTUsuario();
};

class Huesped : public Usuario {

    private:
        bool esFinger;
        map<int,ReservaIndividual*> r;
        map<int,ReservaGrupal*> rg;
        map<int,Estadia*> e;
    public:
        Huesped(string nombre, string email, string password, bool esFinger);
        DTUsuario getDTUsuario();
        set<int> getCodigosReservas();
        bool getEsFinger();

        
        void finalizarEstadia();
        void addReserva(Reserva* reserva);
};

class Empleado : public Usuario, public Observer {
    
    private:
        CargoEmpleado cargo;
        set<RespuestaEmpleado*> re;
        Hostal *hostal;

    public:
        Empleado(string nombre, string email, string password, CargoEmpleado cargo);
        
        // GETTERS
        CargoEmpleado getCargoEmpleado();

        // SETTERS
        void setCargo(CargoEmpleado cargo) {this->cargo = cargo;}
        void setHostal(Hostal* hostal) {this->hostal = hostal;}


        DTUsuario getDTUsuario();
        void notificarCalificacion(Notificacion*);
        vector<DTNotificacion> getNotificaciones();
        void setRespuestaEmpleado(RespuestaEmpleado*);

        //Consulta de Usuario
        string getHostalDeEmpleado();

        //ComentarCalificacion
        vector<DTCalificacion> getCalificacionesSinResponder();
};

#endif
