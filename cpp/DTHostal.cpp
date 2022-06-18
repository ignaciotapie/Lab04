#include <DTHostal.h>

DTHostal::DTHostal(string nom, string dir, int tel, float prom){
    nombre = nom;
    direccion = dir;
    telefono = tel;
    promCalif = prom;
}
string DTHostal::getNombre(){
    return nombre;
}
string DTHostal::getDireccion(){
    return direccion;
}
int DTHostal::getTelefono(){
    return telefono;
}
float DTHostal::getPromCalif(){
    return promCalif;
}