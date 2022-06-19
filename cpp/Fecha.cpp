#include "../h/Fecha.h"

int Fecha::getAnio(){
    return anio;
}
int Fecha::getMes(){
    return mes;
}
int Fecha::getDia(){
    return dia;
}
int Fecha::getHora(){
    return hora;
}
Fecha::Fecha(float hora, int dia, int mes, int anio){
    this->hora = hora;
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}
Fecha::~Fecha(){

}

bool Fecha::before(Fecha fechaAComparar)
{
    if (anio < fechaAComparar.anio) return true;
    else if (mes < fechaAComparar.mes) return true;
    else if (dia < fechaAComparar.dia) return true;
    else if (hora <= fechaAComparar.hora) return true;
}

bool Fecha::areOverlapping(Fecha primerCheckIn, Fecha primerCheckOut, Fecha segundoCheckIn, Fecha segundoCheckOut)
{
    return primerCheckIn.before(segundoCheckOut) && segundoCheckIn.before(primerCheckIn);
}