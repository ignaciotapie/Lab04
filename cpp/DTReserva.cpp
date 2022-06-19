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