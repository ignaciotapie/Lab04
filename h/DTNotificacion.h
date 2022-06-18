#ifndef DTNOTIFICACION_
#define DTNOTIFICACION_

#include <string>

using namespace std;

class DTNotificacion{
    private:
        string autor;
        int puntaje;
        string comentario;
    public:
        DTNotificacion(string, int, string);
        string getAutor();
        int getPuntaje();
        string getComentario();
        ~DTNotificacion();
};

#endif