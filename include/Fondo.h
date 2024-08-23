#ifndef FONDO_H
#define FONDO_H
#include <SDL.h>
#include "ObjetoAnimado.h"

class Fondo : public ObjetoAnimado
{
    public:
        Fondo(Textura * textura, int, int, int, int, Uint32);
        ~Fondo();

        void animar();
        void mostrar();
        void mover();

    private:
        SDL_Rect seleccion;
};

#endif // FONDO_H
