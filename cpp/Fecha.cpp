#include "../h/Fecha.h"

const int Fecha::getAnio() const{
    return anio;
}
const int Fecha::getMes() const{
    return mes;
}
const int Fecha::getDia() const{
    return dia;
}
const int Fecha::getHora() const{
    return hora;
}
Fecha::Fecha()
{
    this->hora = 0;
    dia = 0;
    mes = 0;
    anio = 0;
}

Fecha::Fecha(float hora, int dia, int mes, int anio){
    this->hora = hora;
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

bool Fecha::before(Fecha fechaAComparar)
{
    if (anio < fechaAComparar.anio) return true;
    else if (mes < fechaAComparar.mes) return true;
    else if (dia < fechaAComparar.dia) return true;
    else if (hora <= fechaAComparar.hora) return true;
    
    return false;
}

bool Fecha::areOverlapping(Fecha primerCheckIn, Fecha primerCheckOut, Fecha segundoCheckIn, Fecha segundoCheckOut)
{
    return primerCheckIn.before(segundoCheckOut) && segundoCheckIn.before(primerCheckIn);
}