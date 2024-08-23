#ifndef JUGADOR_H
#define JUGADOR_H
#include <SDL.h>         // Se compone de un "Uint8"
#include <stdio.h>
#include "Mundo.h"
#include "Nave.h"        // Hereda de "Nave"
#include "Misil.h"

class Jugador : public Nave
{
    public:
        Jugador(Textura *, int px, int py, int vx, int vy, Uint32 lt);
        ~Jugador();

        // Gestiona lo que presiona el jugador
        void entrada(Mundo &);

        // Mover
        void mover();

        // Ataca
        void atacar(Mundo &);

    private:
        bool teclaAbajo;                // Indica si ya presionó la tecla
        const Uint8 * estadoTeclado;    // Almacena el estado del teclado
        int id;
};

#endif // JUGADOR_H
