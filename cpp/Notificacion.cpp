#include "../h/Notificacion.h"

Notificacion::Notificacion(string s, int i, Calificacion* c){
    this->autor = s;
    this->empleadosLinkeados = i;
    this->calificacion = c;
}
Notificacion::~Notificacion(){

}
string Notificacion::getAutor(){
    return this->autor;
}
int Notificacion::getEmpleadosLinkeados(){
    return this->empleadosLinkeados;
}
Calificacion* Notificacion::getCalificacion(){
    return this->calificacion;
}
DTNotificacion Notificacion::getDTNotificacion(){

}
void Notificacion::aumentarNumero(){

}
void Notificacion::disminuirNumero(){
    
}