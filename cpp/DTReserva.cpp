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

DTReservaIndividual::DTReservaIndividual(int codigo, Fecha checkIn, Fecha checkOut, EstadoReserva estado, int costo, int numeroHabitacion) : DTReserva(codigo, checkIn, checkOut, estado, costo, numeroHabitacion){

}

DTReservaGrupal::DTReservaGrupal(int codigo, Fecha checkIn, Fecha checkOut, EstadoReserva estado, int costo, int numeroHabitacion, set<string> nombreHuesped) : DTReserva(codigo, checkIn, checkOut, estado, costo, numeroHabitacion){
    this->nombreHuesped = nombreHuesped;
}