#include "../h/DTEstadiaPlus.h>

DTEstadiaPlus::DTEstadiaPlus(string nomHos, string nomHues, int numHab, int codRes, Fecha in, Fecha out, int prom){
    nombreHostal = nomHos;
    nombreHuesped = nomHues;
    numeroHabitacion = numHab;
    codigoReserva = codRes;
    checkInReal = in;
    checkOutReal = out;
    promo = prom;
}
string DTEstadiaPlus::getNombreHostal(){
    return nombreHostal;
}
string DTEstadiaPlus::getNombreHuesped(){
    return nombreHuesped;
}
int DTEstadiaPlus::getNumeroHabitacion(){
    return numeroHabitacion;
}
int DTEstadiaPlus::getCodigoReserva(){
    return codigoReserva;
}
Fecha DTEstadiaPlus::getCheckInReal(){
    return checkInReal;
}
Fecha DTEstadiaPlus::getCheckOutReal(){
    return checkOutReal;
}
int DTEstadiaPlus::getPromo(){
    return promo;
}