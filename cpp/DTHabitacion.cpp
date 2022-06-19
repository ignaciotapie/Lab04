#include "../h/DTHabitacion.h"

DTHabitacion::DTHabitacion(int num, int pre, int cap, map<string, DTCalificacion>* cals){
    numero = num;
    precio = pre;
    capacidad = cap;
    calificaciones = cals;
}
int DTHabitacion::getNumero(){
    return numero;
}
int DTHabitacion::getPrecio(){
    return precio;
}
int DTHabitacion::getCapacidad(){
    return capacidad;
}
map<string, DTCalificacion>* DTHabitacion::getCalificaciones(){
    return calificaciones;
}