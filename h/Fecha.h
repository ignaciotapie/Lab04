#ifndef FECHA_
#define FECHA_

class Fecha{
    private:
        int anio;
        int mes;
        int dia;
        int hora;
    public:
        int getAnio();
        int getMes();
        int getDia();
        int getHora();
        Fecha();
        Fecha(int, int, int, int);
        ~Fecha();
};

#endif