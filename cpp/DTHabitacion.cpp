#include "../h/DTHabitacion.h"

DTHabitacion::DTHabitacion(int num, int pre, int cap, map<string, DTCalificacion>* cals){
    numero = num;
    precio = pre;
    capacidad = cap;
    calificaciones = cals;
}
 const int DTHabitacion::getNumero() const {
    return numero;
}
 const int DTHabitacion::getPrecio() const {
    return precio;
}
 const int DTHabitacion::getCapacidad() const {
    return capacidad;
}
 const map<string, DTCalificacion>* DTHabitacion::getCalificaciones() const {
    return calificaciones;
}