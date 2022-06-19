#include "../h/DTEstadia.h"

DTEstadia::DTEstadia(string em, int cod, Fecha in, Fecha out, int pro){
    emailHuesped = em;
    codigoReserva = cod;
    checkInReal = in;
    checkOutReal = out;
    promo = pro;
}
string DTEstadia::getEmailHuesped(){
    return emailHuesped;
}
int DTEstadia::getCodigoReserva(){
    return codigoReserva;
}
Fecha DTEstadia::getCheckInReal(){
    return checkInReal;
}
Fecha DTEstadia::getCheckOutReal(){
    return checkOutReal;
}
int DTEstadia::getPromo(){
    return promo;
}