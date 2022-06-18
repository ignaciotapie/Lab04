#ifndef FECHA_
#define FECHA_

class Fecha{
    private:
        int anio;
        int mes;
        int dia;
        float hora;
    public:
        int getAnio();
        int getMes();
        int getDia();
        int getHora();
        Fecha();
        Fecha(float hora, int dia, int mes, int anio);
        ~Fecha();
};

#endif