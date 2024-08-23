#include "Estrella.h"

Estrella::Estrella(Textura * textura, int px, int py, int vx, int vy, Uint32 lt):
    ObjetoAnimado(textura, px, py, vx, vy, lt)
{
    // Inicializa la seleccion
    seleccion.x = 0;
    seleccion.y = 0;
    seleccion.w = getLargo() / 3;
    seleccion.h = getAlto();

    // Inicializa el tamaño de cada frame de la animacion de la estrella
    sizeFrameX = getLargo() / 3;
    ida = true;
}

Estrella::~Estrella()
{
    //dtor
    seleccion.x = 0;
    seleccion.y = 0;
    seleccion.w = 0;
    seleccion.h = 0;

    sizeFrameX = 0;
    destruir();
}

void Estrella::mostrar()
{
    dibujar(&seleccion);
}

void Estrella::mover()
{

}

void Estrella::animar()
{
    // Cambia de frame
    if(getTicks() > getLapso())
    {
        if(ida)
        {
            seleccion.x += sizeFrameX;
            if(seleccion.x >= sizeFrameX * 2)
                ida = false;
        }
        else
        {
            seleccion.x -= sizeFrameX;
            if(seleccion.x <= 0)
                ida = true;
        }
        reiniciar();
    }
}
