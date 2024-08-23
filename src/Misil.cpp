#include "Misil.h"

Misil::Misil(Textura * textura, int px, int py, int vx, int vy, Uint32 lt, Bando bando):
    ObjetoAnimado(textura, px, py, vx, vy, lt), bandoMisil(bando)
{
    //ctor
    activo = true;
}

Misil::~Misil()
{
    //dtor
    destruir();
}

void Misil::mover()
{
    if(activo)
    {
        setPosX(getPosX() + getVelX());
    }
}

void Misil::detener()
{
    activo = false;
}
