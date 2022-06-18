#include "../h/DTHostal.h"

DTHostal::DTHostal(string nom, string dir, int tel, float prom){
    nombre = nom;
    direccion = dir;
    telefono = tel;
    promCalif = prom;
}
string DTHostal::getNombre() const{
    return nombre;
}
string DTHostal::getDireccion() const{
    return direccion;
}
int DTHostal::getTelefono() const{
    return telefono;
}
float DTHostal::getPromCalif() const{
    return promCalif;
}