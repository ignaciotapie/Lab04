#include "../h/DTCalificacion.h"

DTCalificacion::DTCalificacion(int pun, string com, Fecha fech, string em, int cod){
    puntaje = pun;
    comentario = com;
    fecha = fech;
    emailHuesp = em;
    codigoReserva = cod;
}

DTCalificacion::DTCalificacion(int pun, string com, string em, int cod){
    puntaje = pun;
    comentario = com;
    emailHuesp = em;
    codigoReserva = cod;
}

DTCalificacion::DTCalificacion(int punt, string com){
    this->puntaje = punt;
    this->comentario = com;
}

int DTCalificacion::getPuntaje(){
    return puntaje;
}
string DTCalificacion::getComentario(){
    return comentario;
}
Fecha DTCalificacion::getFecha(){
    return fecha;
}
string DTCalificacion::getEmailHuesp(){
    return emailHuesp;
}
int DTCalificacion::getCodigoReserva(){
    return codigoReserva;
}
void DTCalificacion::setPuntaje(int punt){
    this->puntaje = punt;
}

void DTCalificacion::setComentario(string com){
    this->comentario = com;
}

void DTCalificacion::setFecha(Fecha fecha){
    this->fecha = fecha;
}

void DTCalificacion::setEmailHuesp(string email){
    this->emailHuesp = email;
}

void DTCalificacion::setCodigoReserva(int cod){
    this->codigoReserva = cod;
}