#ifndef MUNDO_H
#define MUNDO_H
#include <vector>           // Se compone de un vector ObjetoAnimado
#include <stdio.h>
#include "ObjetoAnimado.h"  //Manipula objetos animados

class Mundo
{
    public:
        Mundo();
        ~Mundo();

        // Agrega elementos
        void add( ObjetoAnimado * );

        // Manipula los objetos en juego
        void mover();
        void dibujar();
        void animar();

    private:
        std::vector<ObjetoAnimado *>  arreglo;
};

#endif // MUNDO_H
