#ifndef ESTRELLA_H
#define ESTRELLA_H
#include "ObjetoAnimado.h" // Hereda de objeto

class Estrella : public ObjetoAnimado
{
    public:
        Estrella(Textura * textura, int px, int py, int vx = 0, int vy = 0, Uint32 lt = 200);
        ~Estrella();

        void animar();
        void mover();
        void mostrar();

    private:
        bool ida;
        int sizeFrameX;          // El tama�o a recorrer
        SDL_Rect seleccion;
};

#endif // ESTRELLA_H
