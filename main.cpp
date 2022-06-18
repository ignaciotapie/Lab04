#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

#include "h/ControladorUsuarios.h"
#include "h/Fabrica.h"
// #include "h/Habitacion.h"
// #include "h/Huesped.h"
// #include "h/reserva.h"
// #include "h/Sistema.h"
// #include "h/EstadoReserva.h"
// #include "h/DTReserva.h"
// #include "h/DTHabitacion.h"
// #include "h/DTFecha.h"
// #include "h/DTHuesped.h"

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
    int num;
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
        "14. Consulta Estadia\n";

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
                    interfazUsuario = ControladorUsuarios::getInstance();
                    interfazUsuario->setUserInfo(nombre, email, password);
                    interfazUsuario->esEmpleado(esEmpleado);

                    if (esEmpleado) 
                        interfazUsuario->setCargoEmpleado(cargo);
                    else 
                        interfazUsuario->esFinger(esFinger);

                    if (interfazUsuario->esUsuarioRepetido())
                    {
                        cout << "El usuario que ha ingresado ya existe en el sistema, desea ingresar otro usuario?" << endl << "(1) Si" << endl << "(2) No" << endl;
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

            case 3:
            {

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
                int i = 1;
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
                    bool incorrecto = true;
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
                IReservas* interfazReservas = fabrica->getIReservas();
                IHostales* interfazHostales = fabrica->getIHostales();
                set<DTHostal> listaHostales = interfazHostales->getHostalesPlus();
                set<DTHostal>::iterator auxiliarLista = listaHostales.begin();
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
                interfazHostales->seleccionarHabitacion(numHabitacion);

                IUsuarios* interfazUsuarios = fabrica->getIUsuarios();
                set<string> huespedesListados = interfazUsuarios->getHuespedes();
                set<string>::iterator aux = huespedesListados.begin();
                cout << "Lista de huespedes registrados: " << endl;
                int i = 1;
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
                interfazHostales->confirmarReserva();
                break;
            }
            case 9:
                {
                    loop = false;
                    break;
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

