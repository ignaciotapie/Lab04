#ifndef USUARIO_
#define USUARIO_

#include <string>
#include <map>
#include "Reserva.h"
#include "Estadia.h"
#include "RespuestaEmpleado.h"
#include "Notificacion.h"
#include "Hostal.h"
#include "DTUsuario.h"
#include "DTNotificacion.h"
#include "DTCalificacion.h"
#include "Calificacion.h"
#include "Enum.h"

class ReservaGrupal;

class Observer { 
private:
    ;
public:
    ~Observer();
    //CalificarEstadia
    virtual void notificarCalificacion(Notificacion*);
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
        ~Usuario();
};

class Huesped : public Usuario {

    private:
        bool esFinger;
        map<int,Reserva*> r;
        map<int,ReservaGrupal*> rg;
        map<int,Estadia*> e;
    public:
        Huesped(string nombre, string email, string password, bool esFinger);
        ~Huesped();
        DTUsuario getDTUsuario();
        set<int> getCodigosReservas();
        bool getEsFinger();

        
        void finalizarEstadia();
        void addReserva();

};

class Empleado : public Usuario, public Observer {
    
    private:
        CargoEmpleado cargo;
        set<Notificacion*> n;
        set<RespuestaEmpleado*> re;
        Hostal *hostal;

    public:
        Empleado(string nombre, string email, string password, CargoEmpleado cargo);
        ~Empleado();
        
        // GETTERS
        CargoEmpleado getCargoEmpleado();

        // SETTERS
        void setCargo(CargoEmpleado cargo) {this->cargo = cargo;}
        void setHostal(Hostal* hostal) {this->hostal = hostal;}


        DTUsuario getDTUsuario();
        void notificarCalificacion(Notificacion*);
        set<DTNotificacion> getNotificaciones();
        void setRespuestaEmpleado(RespuestaEmpleado*);
        //ComentarCalificacion
        set<DTCalificacion> getCalificacionesSinResponder();
};

#endif
