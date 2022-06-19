#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

#include "h/Fabrica.h"
#include "h/Reserva.h"
#include "h/Usuario.h"
#include "h/Enum.h"
#include "h/Fecha.h"
#include "h/DTHostal.h"
#include "h/DTEstadia.h"
#include "h/DTEstadiaPlus.h"
#include "h/DTReserva.h"
#include "h/DTUsuario.h"

int CheckIntCin() // Usado en lugar de cin >> (int) para asegurarse que es un int correcto y no ocurra el Cin Infinite Loop
{
    int newNum;
    std::cin >> newNum;
    bool invalido = cin.fail();
    while (invalido)
    {
        if (std::cin.fail())
        {
            std::cout << "Por favor ingrese un numero valido" << endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> newNum;
        }
        else 
        {
            invalido = false;
        }
    }
    return newNum;
}

using namespace std;

int main()
{
    bool loop = true;
    Fabrica* fabrica = new Fabrica();
    while (loop)
    {
        std::cout << 
        "Ingrese un numero:\n" <<
        "1. Agregar Usuario\n" << 
        "2. Agregar Hostal\n" << 
        "3. Agregar Habitacion\n" <<
        "4. Asignar Empleado a Hostal\n" <<
        "5. Obtener Huespedes\n" << 
        "6. Obtener Habitaciones\n" <<
        "7. Registrar Reserva\n" << 
        "8. Obtener Reservas\n" << 
        "9. Salir\n" <<
        endl <<
        "DEBUG:\n"
        "10. Cargar Datos de Prueba\n" << 
        "11. Ajustar Fecha\n" <<
        "12. Calificar Estadia\n" <<
        "13. Comentar Calificacion\n" <<
        "14. Consulta Estadia\n" <<
        "15. Consulta top 3 de Hostales\n" <<
        "16. Registrar Estadia\n" <<
        "17. Finalizar Estadia\n" <<
        "18. Consulta Hostal\n" <<
        "19. Consulta Usuario\n" <<
        "20. Subscribirse a notificaciones \n" <<
        "21. Consultar notificaciones\n" <<
        "22. Eliminar suscripcion\n";

        int num = CheckIntCin();
        switch (num)
        {
            case 1: 
            {
                IUsuarios* interfazUsuario = fabrica->getIUsuarios();
                bool usuarioRepetido = true;
                bool terminarCasoDeUso = false;
                while (usuarioRepetido)
                {
                    string email, nombre, password;
                    bool esEmpleado, esFinger;
                    cout << "Ingrese nombre\n";
                    cin.ignore();
                    getline(cin, nombre);
                    cout << "Ingrese email\n";
                    cin.ignore();
                    getline(cin, email);
                    cout << "Ingrese password\n";
                    cin.ignore();
                    getline(cin, password);
                    cout << "Es empleado?\n" << "(1) Si\n" << "(2) No\n";
                    bool incorrecto = true;
                    while (incorrecto)
                    {
                        string fin;
                        cin >> fin;
                        if (fin == "1" || fin == "2")
                        {
                            incorrecto = false;
                            if (fin == "1")
                                esEmpleado = true;
                            else
                                esEmpleado = false;
                        }
                        else
                        {
                            cout << "Por favor, elija una opcion correcta" << endl;
                        }
                    }
                    CargoEmpleado cargo;   
                    if (esEmpleado)
                    {
                        cout << "Elija el cargo del empleado\n" << "(1) Administracion\n" << "(2) Limpieza\n" << "(3) Recepcion\n" << "(4) Infraestructura\n";
                        bool repetir = true;
                        while (repetir)
                        {
                            int option = CheckIntCin();
                            repetir = false;
                            switch (option)
                            {
                                case 1:
                                    cargo = CargoEmpleado::Administracion;
                                break;
                                case 2:
                                    cargo = CargoEmpleado::Limpieza;
                                break;
                                case 3:
                                    cargo = CargoEmpleado::Recepcion;
                                break;
                                case 4:
                                    cargo = CargoEmpleado::Infraestructura;
                                break;
                                default:
                                    repetir = true;
                                    cout << "Por favor, elija una opcion correcta" << endl;
                                break;
                            }
                        }
                    }
                    else
                    {
                        cout << "Es finger?\n" << "(1) Si\n" << "(2) No\n";
                        bool incorrecto = true;
                        while (incorrecto)
                        {
                            string fin;
                            cin >> fin;
                            if (fin == "1" || fin == "2")
                            {
                                incorrecto = false;
                                if (fin == "1")
                                    esFinger = true;
                                else
                                    esFinger = false;
                            }
                            else
                            {
                                cout << "Por favor, elija una opcion correcta" << endl;
                            }
                        }
                    }
                    interfazUsuario = fabrica->getIUsuarios();
                    interfazUsuario->setUserInfo(nombre, email, password);
                    interfazUsuario->esEmpleado(esEmpleado);

                    if (esEmpleado) 
                        interfazUsuario->setCargoEmpleado(cargo);
                    else 
                        interfazUsuario->esFinger(esFinger);

                    if (interfazUsuario->esUsuarioRepetido())
                    {
                        cout << "El usuario que ha ingresado ya existe en el sistema, desea ingresar otro usuario?" << endl << "(1) Si" << endl << "(2) No" << endl;
                        incorrecto = true;
                        while (incorrecto)
                        {
                            string fin;
                            cin >> fin;
                            if (fin == "1" || fin == "2")
                            {
                                incorrecto = false;
                                if (fin == "1")
                                    interfazUsuario->reingresarDatos();
                                else
                                {
                                    terminarCasoDeUso = true;
                                    interfazUsuario->cancelarAltaUsuario();
                                }
                            }
                            else
                            {
                                cout << "Por favor, elija una opcion correcta" << endl;
                            }
                        }

                    }
                    else 
                        usuarioRepetido = false;
                    
                }
                if (!terminarCasoDeUso)
                {
                    cout << "Desea confirmar la creacion del usuario?\n" << "(1) Si\n" << "(2) No\n";
                    bool incorrecto = true;
                    while (incorrecto)
                    {
                        string fin;
                        cin >> fin;
                        if (fin == "1" || fin == "2")
                        {
                            incorrecto = false;
                            if (fin == "1")
                                interfazUsuario->confirmarAltaUsuario();
                            else
                                interfazUsuario->cancelarAltaUsuario();
                        }
                        else
                        {
                            cout << "Por favor, elija una opcion correcta" << endl;
                        }
                    }
                }
                break;
            }  

            case 2: 
            { 
                string nombre, email;
                int telefono;

                cout << "Ingrese nombre del Hostal: \n";
                cin.ignore();
                getline(cin, nombre);
                cout << "Ingrese direccion del Hostal: \n";
                cin.ignore();
                getline(cin, email);
                cout << "Ingrese telefono del Hostal: \n";
                telefono = CheckIntCin();

                IHostales* interfazHostales = fabrica->getIHostales();
                interfazHostales->setHostalInfo(nombre, email, telefono);
                cout << "Desea confirmar la creacion del hostal?\n" << "(1) Si\n" << "(2) No\n";
                bool incorrecto = true;
                while (incorrecto)
                {
                    string fin;
                    cin >> fin;
                    if (fin == "1" || fin == "2")
                    {
                        incorrecto = false;
                        if (fin == "1")
                            interfazHostales->confirmarAltaHostal();
                        else
                            interfazHostales->cancelarAltaHostal();
                    }
                    else
                    {
                        cout << "Por favor, elija una opcion correcta" << endl;
                    }
                }
                break;
            }

            case 3:{
                //getHostales
                IHostales* interfazHostales = fabrica->getIHostales();

                set<string> allHostales = interfazHostales->getHostales();
                int i = 1;
                for(set<string>::iterator it = allHostales.begin(); it != allHostales.end(); ++it)
                {
                    cout << i << ". " << *it << endl;
                    ++i;
                }
                string nombreHostal;
                bool nombreHostalValido = false;
                cout << "Ingrese nombre del hostal\n";
                while (!nombreHostalValido)
                {
                    cin.ignore();
                    getline(cin, nombreHostal);

                    if (allHostales.find(nombreHostal) != allHostales.end())
                    {
                        nombreHostalValido = true;
                    }
                    else
                    {
                        cout << "Por favor, escriba un hostal que esta en la lista." << endl;
                    }
                }

                //altaHabitacion
                int numero, precio, capacidad;
                cout << "Ingrese numero" << endl;
                numero = CheckIntCin();
                cout << "Ingrese precio" << endl;
                precio = CheckIntCin();
                cout << "Ingrese capacidad" << endl;
                capacidad = CheckIntCin();
                interfazHostales->altaHabitacion(numero, precio, capacidad);

                //Confirmar/Cancelar
                cout << "Desea confirmar la creacion de la habitacion?\n" << "(1) Si\n" << "(2) No\n";
                bool incorrecto = true;
                while (incorrecto)
                {
                    string fin;
                    cin >> fin;
                    if (fin == "1" || fin == "2")
                    {
                        incorrecto = false;
                        if (fin == "1")
                            interfazHostales->confirmarAltaHabitacion();
                        else
                            interfazHostales->cancelarAltaHabitacion();
                    }
                    else
                    {
                        cout << "Por favor, elija una opcion correcta" << endl;
                    }
                }
                break;


            }

            case 4: 
            {   
                IHostales* interfazHostales = fabrica->getIHostales();

                set<string> allHostales = interfazHostales->getHostales();
                int i = 1;
                for(set<string>::iterator it = allHostales.begin(); it != allHostales.end(); ++it)
                {
                    cout << i << ". " << *it << endl;
                    ++i;
                }
                string nombreHostal;
                bool nombreHostalValido = false;
                cout << "Ingrese nombre del hostal\n";
                while (!nombreHostalValido)
                {
                    cin.ignore();
                    getline(cin, nombreHostal);

                    if (allHostales.find(nombreHostal) != allHostales.end())
                    {
                        nombreHostalValido = true;
                    }
                    else
                    {
                        cout << "Por favor, escriba un hostal que esta en la lista." << endl;
                    }
                }


                set<string> EmpleadosFueraHostal = interfazHostales->getEmpleadosFueraDeHostal(nombreHostal);
                i = 1;
                for(set<string>::iterator it = EmpleadosFueraHostal.begin(); it != EmpleadosFueraHostal.end(); ++it)
                {
                    cout << i << ". " << *it << endl;
                    ++i;
                }


                bool nombreEmpleadoValido = false;
                string nombreEmpleado;
                cout << "Ingrese nombre del empleado a asignar:" << endl;
                while (!nombreEmpleadoValido)
                {
                    cin.ignore();
                    getline(cin, nombreEmpleado);

                    if (EmpleadosFueraHostal.find(nombreEmpleado) != EmpleadosFueraHostal.end())
                    {
                        nombreEmpleadoValido = true;
                    }
                    else
                    {
                        cout << "Por favor, escriba un empleado que este en la lista." << endl;
                    }
                }

                CargoEmpleado cargo;
                cout << "Elija el cargo del empleado\n" << "(1) Administracion\n" << "(2) Limpieza\n" << "(3) Recepcion\n" << "(4) Infraestructura\n";
                bool repetir = true;
                while (repetir)
                {
                    int option = CheckIntCin();
                    repetir = false;
                    switch (option)
                    {
                        case 1:
                            cargo = CargoEmpleado::Administracion;
                        break;
                        case 2:
                            cargo = CargoEmpleado::Limpieza;
                        break;
                        case 3:
                            cargo = CargoEmpleado::Recepcion;
                        break;
                        case 4:
                            cargo = CargoEmpleado::Infraestructura;
                        break;
                        default:
                        {
                            repetir = true;
                            cout << "Por favor, elija una opcion correcta" << endl;
                            break;
                        }
                    }
                }
                bool masEmpleados = true;
                while (masEmpleados)
                {
                    interfazHostales->asignarEmpleado(nombreEmpleado, cargo);
                    cout << "Desea confirmar la asignacion del empleado?\n" << "(1) Si\n" << "(2) No\n";
                    bool incorrecto = true;
                    while (incorrecto)
                    {
                        string fin;
                        cin >> fin;
                        if (fin == "1" || fin == "2")
                        {
                            incorrecto = false;
                            if (fin == "1")
                                interfazHostales->confirmarAsignacion();
                            else
                                interfazHostales->cancelarAsignacion();
                        }
                        else
                        {
                            cout << "Por favor, elija una opcion correcta" << endl;
                        }
                    }
                    cout << "Desea confirmar agregar mas empleado al mismo hostal?\n" << "(1) Si\n" << "(2) No\n";
                    incorrecto = true;
                    while (incorrecto)
                    {
                        string fin;
                        cin >> fin;
                        if (fin == "1" || fin == "2")
                        {
                            incorrecto = false;
                            if (fin == "2")
                                masEmpleados = false;
                        }
                        else
                        {
                            cout << "Por favor, elija una opcion correcta" << endl;
                        }
                    }
                }
                break;
            }
            case 7:
            {
                IHostales* interfazHostales = fabrica->getIHostales();
                vector<DTHostal> listaHostales = interfazHostales->getHostalesPlus();
                vector<DTHostal>::iterator auxiliarLista = listaHostales.begin();
                int i = 1;
                for(; auxiliarLista != listaHostales.end(); auxiliarLista++ )
                {
                    cout << i << ". " << auxiliarLista->getNombre() << " - " << auxiliarLista->getDireccion() << " - " << auxiliarLista->getPromCalif();
                }
                string nombreHostal;
                cout << "Ingrese nombre del Hostal que desea reservar: \n";
                cin.ignore();
                getline(cin, nombreHostal);

                bool existeHostal = interfazHostales->existeHostal(nombreHostal);

                if (!existeHostal)
                {
                    cout << "El hostal que ha ingresado no existe." << endl;
                    break;
                }
                cout << "Ingrese fecha para check-in: " << endl;
                cout << "Hora (Formato H.HH/HH.HH): ";
                float horaCheckIn;
                cin >> horaCheckIn;
                cout << endl;
                cout << "Dia: ";
                int diaCheckIn = CheckIntCin();
                cout << endl;
                cout << "Mes: ";
                int mesCheckIn = CheckIntCin();
                cout << endl;
                cout << "Anio: ";
                int anioCheckIn = CheckIntCin();
                cout << endl;

                cout << "Ingrese fecha para check-out: " << endl;
                cout << "Hora (Formato H.HH/HH.HH): ";
                float horaCheckOut;
                cin >> horaCheckOut;
                cout << endl;
                cout << "Dia: ";
                int diaCheckOut = CheckIntCin();
                cout << endl;
                cout << "Mes: ";
                int mesCheckOut = CheckIntCin();
                cout << endl;
                cout << "Anio: ";
                int anioCheckOut = CheckIntCin();
                cout << endl;

                bool esReservaGrupal = false;
                cout << "Es Reserva Grupal?\n" << "(1) Si\n" << "(2) No\n";
                bool incorrecto = true;
                while (incorrecto)
                {
                    string fin;
                    cin >> fin;
                    if (fin == "1" || fin == "2")
                    {
                        incorrecto = false;
                        if (fin == "1")
                            esReservaGrupal = true;
                    }
                    else
                    {
                        cout << "Por favor, elija una opcion correcta" << endl;
                    }
                }
                interfazHostales->seleccionarHostalParaReserva(nombreHostal, Fecha(horaCheckIn,diaCheckIn,mesCheckIn,anioCheckIn), Fecha(horaCheckOut, diaCheckOut, mesCheckOut, anioCheckOut), esReservaGrupal);
                set<int> habitacionesLibres = interfazHostales->getHabitacionesLibres();
                if (habitacionesLibres.empty())
                {
                    cout << "No hay habitaciones libres." << endl;
                    break;
                }
                set<int>::iterator it = habitacionesLibres.begin();
                for (; it != habitacionesLibres.end(); it++)
                {
                    cout << "Habitacion " << (*it) << endl;
                }
                cout << "Escriba el numero de la habitacion a elegir: ";
                int numHabitacion;
                bool habitacionValida = false;
                while (!habitacionValida)
                {
                    numHabitacion = CheckIntCin();
                    if (habitacionesLibres.find(numHabitacion) != habitacionesLibres.end())
                    {
                        habitacionValida = true;
                    }
                    else
                    {
                        cout << "Por favor, escriba una habitacion de la lista." << endl;
                    }
                }

                //seleccionarHabitacion
                interfazHostales->seleccionarHabitacion(numHabitacion);

                IUsuarios* interfazUsuarios = fabrica->getIUsuarios();
                set<string> huespedesListados = interfazUsuarios->getHuespedes();
                set<string>::iterator aux = huespedesListados.begin();
                cout << "Lista de huespedes registrados: " << endl;
                i = 1;
                for (; aux != huespedesListados.end(); aux++)
                {
                    cout << i << ". " << *aux << endl;
                }
                cout << "Ingrese el nombre del huesped a registrar: " ;
                cin.ignore();
                string nombreHuesped;
                getline(cin, nombreHuesped);
                interfazHostales->seleccionarHuesped(nombreHuesped);
                set<string> nombreHuespedes;
                nombreHuespedes.insert(nombreHuesped);
                if (esReservaGrupal)
                {
                    bool quiereAgregar = true;
                    while (quiereAgregar)
                    {
                        cout << "Ingrese el nombre de otro huesped a agregar a la reserva grupal: "; 
                        cin.ignore();
                        getline(cin, nombreHuesped);
                        interfazHostales->seleccionarHuesped(nombreHuesped);
                        nombreHuespedes.insert(nombreHuesped);
                        cout << "Desea agregar mas huespedes?\n" << "(1) Si\n" << "(2) No\n";
                        bool incorrecto = true;
                        while (incorrecto)
                        {
                            string fin;
                            cin >> fin;
                            if (fin == "1" || fin == "2")
                            {
                                incorrecto = false;
                                if (fin == "2")
                                    quiereAgregar = false;
                            }
                            else
                            {
                                cout << "Por favor, elija una opcion correcta" << endl;
                            }
                        }
                    }
                }
                cout << "Datos de la reserva:" << endl;
                cout << "Hostal: " << nombreHostal << endl;
                cout << "Es reserva grupal: " << (esReservaGrupal ? "Si" : "No") << endl;
                cout << "Huespedes: " << endl;
                for (set<string>::iterator huespedIt = nombreHuespedes.begin(); huespedIt != nombreHuespedes.end(); huespedIt++)
                {
                    cout << *huespedIt << endl;
                }
                cout << "Desea confirmar la reserva?\n" << "(1) Si\n" << "(2) No\n";
                incorrecto = true;
                string fin;
                while (incorrecto)
                {
                    string fin;
                    cin >> fin;
                    if (fin == "1" || fin == "2")
                    {
                        incorrecto = false;
                    }
                    else
                    {
                        cout << "Por favor, elija una opcion correcta" << endl;
                    }
                }
                if (fin == "2") break;
                interfazHostales->confirmarReserva();
                break;
            }
            case 9:
                {
                    loop = false;
                    break;
                }
            case 11:
            {
                IReloj* interfazReloj = ControladorReloj::getInstance();
                cout << "Ingrese la nueva fecha: " << endl;
                cout << "Hora (Formato H.HH/HH.HH): ";
                float hora;
                cin >> hora;
                cout << endl;
                cout << "Dia: ";
                int dia = CheckIntCin();
                cout << endl;
                cout << "Mes: ";
                int mes = CheckIntCin();
                cout << endl;
                cout << "Anio: ";
                int anio = CheckIntCin();
                cout << endl;

                interfazReloj->modificarFecha(hora,dia,mes,anio);
                break;
            }
            case 12:
            {
                IHostales* ihostales = fabrica->getIHostales();
                set<string> nombresHostales = ihostales->getHostales();
                cout << "Nombres Hostales:" << endl;
                set<string>::iterator itr;
                for (itr = nombresHostales.begin(); itr != nombresHostales.end(); itr++){
                    cout << *itr << endl;
                }
                IReservas* ireservas = fabrica->getIReservas();
                cout << "Seleccione Hostal(Nombre Hostal):" << endl;
                string hostalSeleccionado;
                cin >> hostalSeleccionado;
                ireservas->seleccionarHostal(hostalSeleccionado);
                string emailEmpleado;
                cout << "Ingresar Email Empleado:" << endl;
                cin >> emailEmpleado;
                vector<DTEstadia> estadiasFinalizadas = ireservas->getEstadiasFinalizadas(emailEmpleado);
                vector<DTEstadia>::iterator itrEstadias;
                for (itrEstadias = estadiasFinalizadas.begin(); itrEstadias != estadiasFinalizadas.end(); itrEstadias++){
                    DTEstadia DTEst = *itrEstadias;
                    cout << "Email Huesped: " << DTEst.getEmailHuesped() << endl;
                    cout << "Codigo Reserva: " << DTEst.getCodigoReserva() << endl;
                    cout << "CheckIn: " << DTEst.getCheckInReal().getDia() << "/" << DTEst.getCheckInReal().getMes() << "/" << DTEst.getCheckInReal().getAnio() << ":" << DTEst.getCheckInReal().getHora() << "hs." << endl;
                    cout << "CheckOut: " << DTEst.getCheckOutReal().getDia() << "/" << DTEst.getCheckOutReal().getMes() << "/" << DTEst.getCheckOutReal().getAnio() << ":" << DTEst.getCheckOutReal().getHora() << "hs." << endl;
                    cout << "Codigo Promo: " << DTEst.getPromo() << endl;
                }
                cout << "Seleccione Estadia(Codigo Reserva y luego Email Huesped):" << endl;
                int codigoRes;
                string emailHues;
                cin >> codigoRes;
                cin >> emailHues;
                ireservas->seleccionarEstadia(codigoRes, emailHues);
                cout << "Ingresar Comentario: " << endl;
                string comentario;
                cin >> comentario;
                cout << "Ingresar Calificacion (1-5):" << endl;
                int cal;
                cin >> cal;
                ireservas->setCalificacion(comentario, cal);
                break;
            }
            case 13:
            {
                IReservas* ireservas = fabrica->getIReservas();
                cout << "Ingrese Email Empleado:" << endl;
                string emailEmpleado;
                cin >> emailEmpleado;
                vector<DTCalificacion> calificacionesSinResponder = ireservas->getCalificacionesSinResponder(emailEmpleado);
                vector<DTCalificacion>::iterator itr;
                cout << "Calificaciones" << endl;
                for (itr = calificacionesSinResponder.begin(); itr != calificacionesSinResponder.end(); itr++){
                    cout << "Codigo Reserva: " << itr->getCodigoReserva() << endl;
                    cout << "Email Hueped: " << itr->getEmailHuesp() << endl;
                    cout << "Puntaje: " << itr->getPuntaje() << endl;
                    cout << "Comentario: " << itr->getComentario() << endl;
                    cout << "Fecha: " << itr->getFecha().getDia() << "/" << itr->getFecha().getMes() << "/" << itr->getFecha().getAnio() << ":" << itr->getFecha().getHora() << "hs" << endl;
                }
                cout << "Seleccionar Calificacion (Codigo Reserva y Email Huesped):" << endl;
                int codigoReserva;
                string emailHuesped;
                cin >> codigoReserva;
                cin >> emailHuesped;
                ireservas->setCalificacion(emailHuesped, codigoReserva);
                break;
            }
            case 14:
            {
                IHostales* ihostales = fabrica->getIHostales();
                IReservas* ireservas = fabrica->getIReservas();
                set<string> nombresHostales = ihostales->getHostales();
                set<string>::iterator itrHostales;
                cout << "Hostales" << endl; 
                for (itrHostales = nombresHostales.begin(); itrHostales != nombresHostales.end(); itrHostales++){
                    cout << *itrHostales << endl;
                }
                cout << "Seleccione Hostal: " << endl;
                string nombreHostal;
                cin >> nombreHostal;
                ireservas->seleccionarHostal(nombreHostal);
                vector<DTEstadia> estadias = ireservas->getEstadias();
                vector<DTEstadia>::iterator itrEstadias;
                for (itrEstadias = estadias.begin(); itrEstadias != estadias.end(); itrEstadias++){
                    DTEstadia DTEst = *itrEstadias;
                    cout << "Email Huesped: " << DTEst.getEmailHuesped() << endl;
                    cout << "Codigo Reserva: " << DTEst.getCodigoReserva() << endl;
                    cout << "CheckIn: " << DTEst.getCheckInReal().getDia() << "/" << DTEst.getCheckInReal().getMes() << "/" << DTEst.getCheckInReal().getAnio() << ":" << DTEst.getCheckInReal().getHora() << "hs." << endl;
                    cout << "CheckOut: " << DTEst.getCheckOutReal().getDia() << "/" << DTEst.getCheckOutReal().getMes() << "/" << DTEst.getCheckOutReal().getAnio() << ":" << DTEst.getCheckOutReal().getHora() << "hs." << endl;
                    cout << "Codigo Promo: " << DTEst.getPromo() << endl;
                }
                cout << "Seleccione Estadia(Codigo Reserva y luego Email Huesped):" << endl;
                int codigoRes;
                string emailHues;
                cin >> codigoRes;
                cin >> emailHues;
                DTEstadiaPlus estadiaSeleccionada = ireservas->getEstadiaPlus();
                cout << "Nombre Hostal: " << estadiaSeleccionada.getNombreHostal() << endl;
                cout << "Nombre Huesped: " << estadiaSeleccionada.getNombreHuesped() << endl;
                cout << "Numero Habitacion: " << estadiaSeleccionada.getNumeroHabitacion() << endl;
                cout << "Codigo Reserva: " << estadiaSeleccionada.getCodigoReserva() << endl;
                cout << "CheckIn: " << estadiaSeleccionada.getCheckInReal().getDia() << "/" << estadiaSeleccionada.getCheckInReal().getMes() << "/" << estadiaSeleccionada.getCheckInReal().getAnio() << ":" << estadiaSeleccionada.getCheckInReal().getHora() << "hs." << endl;
                cout << "CheckOut: " << estadiaSeleccionada.getCheckOutReal().getDia() << "/" << estadiaSeleccionada.getCheckOutReal().getMes() << "/" << estadiaSeleccionada.getCheckOutReal().getAnio() << ":" << estadiaSeleccionada.getCheckOutReal().getHora() << "hs." << endl;
                cout << "Codigo Promo: " << estadiaSeleccionada.getPromo() << endl;
                if (ireservas->existeCalificacion()){
                    cout << "Desea ver la Info de la Calificacion (1/0)(Si/No): " << endl;
                    bool verCal;
                    cin >> verCal;
                    if (verCal){
                        DTCalificacion cal = ireservas->getDTCalificacion();
                        cout << "Puntaje: " << cal.getPuntaje() << endl;
                        cout << "Comentario: " << cal.getComentario() << endl;
                        cout << "Fecha: " << cal.getFecha().getDia() << "/" << cal.getFecha().getMes() << "/" << cal.getFecha().getAnio() << ":" << cal.getFecha().getHora() << "hs" << endl;
                    }
                }else{
                    cout << "No hay Calificacion." << endl;
                }
                cout << "Desea ver la Info de la Reserva (1/0)(Si/No): " << endl;
                bool verRes;
                cin >> verRes;
                if (verRes){
                    DTReserva res = ireservas->getDTReserva();
                    cout << "Info Reserva: " << endl;
                    // Info Res
                }
                break;
            }

            case 15:
            {
                IHostales* interfazHostales = fabrica->getIHostales();
                set<string> top3Hostales = interfazHostales->getTop3Hostales();
                int i = 1;
                set<string>::iterator it;
                for(it = top3Hostales.begin(); it != top3Hostales.end(); ++it)
                {
                    cout << i << ". " << (*it) << endl;
                    ++i;
                }
                string nombreHostal;
                bool nombreHostalValido = false;
                cout << "Ingrese nombre del hostal\n";
                while (!nombreHostalValido)
                {
                    cin.ignore();
                    getline(cin, nombreHostal);

                    if (top3Hostales.find(nombreHostal) != top3Hostales.end())
                    {
                        nombreHostalValido = true;
                    }
                    else
                    {
                        cout << "Por favor, escriba un hostal que esta en la lista." << endl;
                    }
                }

                cout << "Desea ver detalles de algun hostal?\n" << "(1) Si\n" << "(2) No\n";
                bool incorrecto = true;
                string fin;
                while (incorrecto)
                {
                    string fin;
                    cin >> fin;
                    if (fin == "1" || fin == "2")
                    {
                        incorrecto = false;
                    }
                    else
                    {
                        cout << "Por favor, elija una opcion correcta" << endl;
                    }
                }
                if (fin == "2") break;

                cout << "De cual?\n" << "(1) Primero\n" << "(2) Segundo\n"<< "(3) Tercero\n";
                    bool repetir = true;
                    string nomHost;
                    while (repetir)
                    {
                       int option = CheckIntCin();
                        repetir = false;
                        switch (option)
                        {
                            
                            case 1:{
                                it = top3Hostales.begin();
                                nomHost = (*it);
                            break;
                            }
                            case 2:{
                                it = top3Hostales.begin();
                                it++;
                                nomHost = (*it);
                            break;
                            }
                            case 3:{
                                it = top3Hostales.end();
                                nomHost = (*it);
                            break;                                
                            }
                            default:
                                repetir = true;
                                cout << "Por favor, elija una opcion correcta" << endl;
                            break;
                        }
                    }
                    vector<DTCalificacion> calif = interfazHostales->getDetallesHostal(nomHost);
					i = 1;
                    for(vector<DTCalificacion>::iterator it = calif.begin(); it != calif.end(); ++it)
                    {
                        DTCalificacion DTCalif = *it;
                        cout << i << ".Puntaje: " << DTCalif.getPuntaje()<< ".Comentario: " << DTCalif.getComentario() << endl;
                        ++i;
                    }
                break;
            }
            case 16:{
                IHostales* interfazHostales = fabrica->getIHostales();
                IUsuarios* interfazUsuarios = fabrica->getIUsuarios();
                set<string> allHostales = interfazHostales->getHostales();
                int i = 1;
                for(set<string>::iterator it = allHostales.begin(); it != allHostales.end(); ++it)
                {
                    cout << i << ". " << (*it) << endl;
                    ++i;
                }
                string nombreHostal;
                bool nombreHostalValido = false;
                cout << "Ingrese nombre del hostal\n";
                while (!nombreHostalValido)
                {
                    cin.ignore();
                    getline(cin, nombreHostal);

                    if (allHostales.find(nombreHostal) != allHostales.end())
                    {
                        nombreHostalValido = true;
                    }
                    else
                    {
                        cout << "Por favor, escriba un hostal que esta en la lista." << endl;
                    }
                }

                set<string> UsuariosRegistrados = interfazUsuarios->getUsuarios();

                bool emailHuespedValido = false;
                string emailHuesped;
                cout << "Ingrese el email del huesped a registrar su estadia:" << endl;
                while (!emailHuespedValido)
                {
                    cin.ignore();
                    getline(cin, emailHuesped);

                    if (UsuariosRegistrados.find(emailHuesped) != UsuariosRegistrados.end())
                    {
                        emailHuespedValido = true;
                    }
                    else
                    {
                        cout << "Por favor, escriba un email de un huesped." << endl;
                    }
                }

                set<int> ReservasNoCanceladasDelHuesped = interfazUsuarios->getReservasDelHuesped(emailHuesped);
                i = 1;
                for(set<int>::iterator it = ReservasNoCanceladasDelHuesped.begin(); it != ReservasNoCanceladasDelHuesped.end(); ++it)
                {
                    cout << i << ". " << (*it) << endl;
                    ++i;
                }

                bool codResValido = false;
                int codRes;
                cout << "Ingrese el codigo de la reserva para registrar la estadia:" << endl;
                while (!codResValido)
                {
                    cin >> codRes;

                    if (ReservasNoCanceladasDelHuesped.find(codRes) != ReservasNoCanceladasDelHuesped.end())
                    {
                        codResValido = true;
                    }
                    else
                    {
                        cout << "Por favor, escriba un codigo de reserva que este en la lista." << endl;
                    }
                }
                interfazUsuarios->registrarEstadia();

                break;
            }
            case 17:{
                IHostales* interfazHostales = fabrica->getIHostales();
                IUsuarios* interfazUsuarios = fabrica->getIUsuarios();
                IReservas* interfazReservas = fabrica->getIReservas();
                set<string> allHostales = interfazHostales->getHostales();
                int i = 1;
                for(set<string>::iterator it = allHostales.begin(); it != allHostales.end(); ++it)
                {
                    cout << i << ". " << (*it) << endl;
                    ++i;
                }
                string nombreHostal;
                bool nombreHostalValido = false;
                cout << "Ingrese nombre del hostal" << endl;
                while (!nombreHostalValido)
                {
                    cin.ignore();
                    getline(cin, nombreHostal);

                    if (allHostales.find(nombreHostal) != allHostales.end())
                    {
                        nombreHostalValido = true;
                    }
                    else
                    {
                        cout << "Por favor, escriba un hostal que esta en la lista." << endl;
                    }
                }
                set<string> UsuariosRegistrados = interfazUsuarios->getUsuarios();
                bool emailHuespedValido = false;
                string emailHuesped;
                cout << "Ingrese el email del huesped a finalizar su estadia:" << endl;
                while (!emailHuespedValido)
                {
                    cin.ignore();
                    getline(cin, emailHuesped);

                    if (UsuariosRegistrados.find(emailHuesped) != UsuariosRegistrados.end())
                    {
                        emailHuespedValido = true;
                    }
                    else
                    {
                        cout << "Por favor, escriba un email de un huesped." << endl;
                    }
                }
                
                interfazReservas->finalizarEstadia();
                cout << "Se ha finalizado la estadia." << endl;
                break;
            }

            case 18:{
                //getHostales
                IHostales* interfazHostales = fabrica->getIHostales();

                set<string> allHostales = interfazHostales->getHostales();
                int i = 1;
                for(set<string>::iterator it = allHostales.begin(); it != allHostales.end(); ++it)
                {
                    cout << i << ". " << *it << endl;
                    ++i;
                }
                string nombreHostal;
                bool nombreHostalValido = false;
                cout << "Ingrese nombre del hostal\n";
                while (!nombreHostalValido)
                {
                    cin.ignore();
                    getline(cin, nombreHostal);

                    if (allHostales.find(nombreHostal) != allHostales.end())
                    {
                        nombreHostalValido = true;
                    }
                    else 
                    {
                        cout << "Por favor, escriba un hostal que esta en la lista." << endl;
                    }
                }

                //seleccionarHostal
                interfazHostales->seleccionarHostal(nombreHostal);

                //getDTHostal
                DTHostal h = interfazHostales->getDTHostal();
                cout << "Nombre:" << h.getNombre() << endl;
                cout << "Direccion:" << h.getDireccion() << endl;
                cout << "Telefono:" << h.getTelefono() << endl;

                //finalizarConsultaHostal
                interfazHostales->finalizarConsultaHostal();

                break;
            }
            case 19:{
                //getUsuarios
                IUsuarios* interfazUsuarios = fabrica->getIUsuarios();

                set<string> allUsers = interfazUsuarios->getUsuarios();
                int i = 1;
                for(set<string>::iterator it = allUsers.begin(); it != allUsers.end(); ++it)
                {
                    cout << i << ". " << *it << endl;
                    ++i;
                }
                string nombreUsuario;
                bool nombreUsuarioValido = false;
                cout << "Ingrese nombre del usuario\n";
                while (!nombreUsuarioValido)
                {
                    cin.ignore();
                    getline(cin, nombreUsuario);

                    if (allUsers.find(nombreUsuario) != allUsers.end())
                    {
                        nombreUsuarioValido = true;
                    }
                    else
                    {
                        cout << "Por favor, escriba un usuario que este en la lista." << endl;
                    }
                }

                //listarDatos
                DTUsuario u = interfazUsuarios->listarDatos();
                

                break;
            }
            case 20:
            {
                IUsuarios* interfazUsuarios = fabrica->getIUsuarios();
                set<string> lista = interfazUsuarios->getListaEmpleados();
                if (lista.size() == 0)
                {
                    cout << "No hay empleados registrados." << endl;
                    break;
                }
                set<string>::iterator it = lista.begin();
                cout << "Lista de Empleados" << endl;
                int i = 1;
                for (; it != lista.end(); it++)
                {
                    cout << i << ". " << *it << endl;
                    i++;
                }
                cout << "Escriba el nombre del empleado a suscribir: ";
                string nombreEmpleado;

                bool nombreExiste = false;
                while (!nombreExiste)
                {
                    cin.ignore();
                    getline(cin, nombreEmpleado);
                    if (lista.find(nombreEmpleado) != lista.end())
                    {
                        nombreExiste = true;
                    }
                    else 
                    {
                        cout << "Empleado no existe, por favor elija un empleado de la lista: ";
                    }
                }

                interfazUsuarios->seleccionarEmpleado(nombreEmpleado);

                cout << "Desea confirmar la suscripcion?" << endl << "(1) Si" << endl << "(2) No" << endl;
                bool incorrecto = true;
                while (incorrecto)
                {
                    string fin;
                    cin >> fin;
                    if (fin == "1" || fin == "2")
                    {
                        incorrecto = false;
                        if (fin == "1")
                            interfazUsuarios->suscribirEmpleado();
                    }
                    else
                    {
                        cout << "Por favor, elija una opcion correcta" << endl;
                    }
                }
            }
            case 21:
            {
                
            }


            default:
                {
                    cout << "Por favor ingrese un numero valido" << endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
        }
    }
    return 0;
}

