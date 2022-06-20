#include "../h/DTHostal.h"
#include "../h/Hostal.h"
#include "../h/DTHabitacion.h"

DTHostal::DTHostal(string nom, string dir, string tel, float prom){
    nombre = nom;
    direccion = dir;
    telefono = tel;
    promCalif = prom;
}

DTHostal::DTHostal(const Hostal& hostal)
{
    this->nombre = hostal.getNombreHostal();
    this->direccion = hostal.getDireccion();
    this->telefono = hostal.getTelefono();
    this->promCalif = hostal.getPromedioPuntaje();
}

const string DTHostal::getNombre() const{
    return nombre;
}
const string DTHostal::getDireccion() const{
    return direccion;
}
const string DTHostal::getTelefono() const{
    return telefono;
}
const float DTHostal::getPromCalif() const{
    return promCalif;
}

const vector<DTHabitacion> DTHostal::getDTHabs() const{
    return this->habs;
}