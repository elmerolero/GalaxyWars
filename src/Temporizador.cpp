#include "Temporizador.h"

Temporizador::Temporizador()
{
    tiempoInicio = 0;
    tiempoTranscurrido = 0;
    enPausa = false;
}

Temporizador::~Temporizador()
{
    //dtor
}

void Temporizador::Iniciar()
{
    enPausa = false;
    tiempoInicio = SDL_GetTicks();
}

void Temporizador::Detener()
{
    if(!enPausa)
    {
        tiempoInicio = 0;
        tiempoTranscurrido = SDL_GetTicks() - tiempoInicio;
        enPausa = true;
    }
}

void Temporizador::Pausar()
{
    if(!enPausa)
    {
        tiempoTranscurrido = SDL_GetTicks() - tiempoInicio;
        enPausa = true;
    }
}

void Temporizador::Reanudar()
{
    if(enPausa)
    {
        tiempoInicio = SDL_GetTicks() - tiempoTranscurrido;
        enPausa = true;
    }
}

void Temporizador::Reiniciar()
{
    tiempoTranscurrido = 0;
    tiempoInicio = SDL_GetTicks();
}

Uint32 Temporizador::GetTicks()
{
    if(enPausa)
    {
        return tiempoTranscurrido;
    }
    else
    {
        return SDL_GetTicks() - tiempoInicio;
    }
}
