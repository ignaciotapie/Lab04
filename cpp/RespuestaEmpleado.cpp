#include <RespuestaEmpleado.h>

RespuestaEmpleado::RespuestaEmpleado(string, Empleado*, Calificacion*){

}
RespuestaEmpleado::~RespuestaEmpleado(){

}
string RespuestaEmpleado::getMensaje(){
    return this->mensaje;
}
Empleado* RespuestaEmpleado::getEmpleado(){
    return this->empleado;
}
Calificacion* RespuestaEmpleado::getCalificacion(){
    return this->calificacion;
}