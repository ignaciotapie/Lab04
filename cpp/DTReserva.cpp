#include "../h/DTReserva.h"

DTReserva::DTReserva(int codigo, Fecha checkIn, Fecha checkOut, EstadoReserva estado, int costo, int numeroHabitacion)
{
    this->codigo = codigo;
    this->checkIn = checkIn;
    this->checkOut = checkOut;
    this->estado = estado;
    this->costo = costo;
    this->numeroHabitacion = numeroHabitacion;
}

int DTReserva::getCodigo(){
return codigo;
}
Fecha DTReserva::getCheckIn(){
return checkIn;
}
Fecha DTReserva::getCheckOut(){
return checkOut;
}
EstadoReserva DTReserva::getEstado(){
return estado;
}
int DTReserva::getCosto(){
return costo;
}
int DTReserva::getNumeroHabitacion(){
return numeroHabitacion;
}

// void DTReservaGrupal::imprimir(){
//     cout << "Codigo Reserva " << getCodigo() << endl
//     << "CheckIn: " << getCheckIn().getDia() << "/" << getCheckIn().getMes() << "/" << getCheckIn().getAnio() << ":" << getCheckIn().getHora() << "hs." << endl
//     << "CheckOut: " << getCheckOut().getDia() << "/" << getCheckOut().getMes() << "/" << getCheckOut().getAnio() << ":" << getCheckOut().getHora() << "hs." << endl
//     << "Estado Reserva " << getEstado() << endl
//     << "Costo: " << getCosto() << endl
//     << "Numero Habitacion: " << endl
//     << "Huespedes: " << endl;
//     set<string>::iterator itr;
//     for (itr = nombreHuesped.begin(); itr != nombreHuesped.end(); itr++){
//         cout << *itr << endl;
//     }
// }

// void DTReservaIndividual::imprimir(){
//     cout << "Codigo Reserva " << getCodigo() << endl
//     << "CheckIn: " << getCheckIn().getDia() << "/" << getCheckIn().getMes() << "/" << getCheckIn().getAnio() << ":" << getCheckIn().getHora() << "hs." << endl
//     << "CheckOut: " << getCheckOut().getDia() << "/" << getCheckOut().getMes() << "/" << getCheckOut().getAnio() << ":" << getCheckOut().getHora() << "hs." << endl
//     << "Estado Reserva " << getEstado() << endl
//     << "Costo: " << getCosto() << endl
//     << "Numero Habitacion: " << endl;
// }