#ifndef ESPACIO_H
#define ESPACIO_H
#include "ObjetoAnimado.h"
#include "Misil.h"

struct Nodo
{
    Misil * item;
    Nodo * anterior;
    Nodo * siguiente;
};

class Espacio
{
    public:
        Espacio();
        virtual ~Espacio();

        void add(Misil *);
        void mover();
        void dibujar();
        void destroy(Nodo * );


    private:
        Nodo * primero;  // Primer elemento
        Nodo * ultimo;   // Ultimo elemento
};

#endif // ESPACIO_H
