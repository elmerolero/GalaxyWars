#include "Fondo.h"

Fondo::Fondo(Textura * textura, int px, int py, int vx, int vy, Uint32 lt):
    ObjetoAnimado(textura, px, py, vx, vy, lt)
{
    //ctor
    seleccion.x = 0;
    seleccion.y = 0;
    seleccion.w = iLargo;
    seleccion.h = getAlto();
}

Fondo::~Fondo()
{
    //dtor
}

void Fondo::mover()
{
    if(getTicks() > getLapso())
    {
        seleccion.x += getVelX();
        if(seleccion.x + seleccion.w > getLargo())
        {
            seleccion.x = (((double)getLargo()) * .53) - seleccion.w;
        }
    }
}

void Fondo::animar()
{
}

void Fondo::mostrar()
{
    dibujar(&seleccion);
}
