#include <DTNotificacion.h>

DTNotificacion::DTNotificacion(string aut, int pun, string com){
    autor = aut;
    puntaje = pun;
    comentario = com;
}
string DTNotificacion::getAutor(){
    return autor;
}
int DTNotificacion::getPuntaje(){
    return puntaje;
}
string DTNotificacion::getComentario(){
    return comentario;
}