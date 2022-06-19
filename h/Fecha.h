#ifndef FECHA_
#define FECHA_

class Fecha{
    private:
        int anio;
        int mes;
        int dia;
        float hora;
    public:
        Fecha();
        Fecha(float hora, int dia, int mes, int anio);
        int getAnio();
        int getMes();
        int getDia();
        int getHora();
        bool before(Fecha fecha);
        static bool areOverlapping(Fecha primerCheckIn, Fecha primerCheckOut, Fecha segundoCheckIn, Fecha segundoCheckOut);

};

#endif