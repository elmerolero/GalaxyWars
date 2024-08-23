#include "Jugador.h"

// Constructor
Jugador::Jugador(Textura * textura, int px, int py, int vx, int vy, Uint32 lt):
    Nave(textura, px, py, vx, vy, lt), id(0)
{

}

// Destructor
Jugador::~Jugador()
{

}

// Gestiona la entrada del jugador
void Jugador::entrada(Mundo & mundo)
{
    // Obtiene el estado del teclado
    estadoTeclado = SDL_GetKeyboardState( NULL );

    // ¿Presiono arriba?
    if( estadoTeclado[ SDL_SCANCODE_UP ] )
    {
        // Establecemos la velocidad de movimiento en Y
        setVelY(-4);
    }
    // ¿Presiono abajo?
    else if( estadoTeclado[ SDL_SCANCODE_DOWN ] )
    {
        // Establecemos la velocidad de movimiento en Y
        setVelY(4);
    }
    else
    {
        setVelY(0);
    }
    // ¿Presionó izquierda?
    if( estadoTeclado[ SDL_SCANCODE_LEFT ] )
    {
        // Establecemos la velocidad de movimiento en X
        setVelX(-4);
    }
    // ¿Presionó derecha?
    else if( estadoTeclado[ SDL_SCANCODE_RIGHT ] )
    {
        // Establecemos la velocidad de movimiento en X
        setVelX(4);
    }
    else
    {
        setVelX(0);
    }

    // ¿Presionó espacio?
    if( estadoTeclado[SDL_SCANCODE_SPACE] && !teclaAbajo )
    {
        atacar(mundo);
        // Indica que ya fue preionada la tecla
        teclaAbajo = true;
    }
    else if( !estadoTeclado[SDL_SCANCODE_SPACE] )
    {
        teclaAbajo = false;
    }

}

void Jugador::atacar(Mundo & mundo)
{
    Misil * nMisil = new Misil(&misil, getPosX() + 40, getPosY() + ((getAlto() - misil.getAlto()) / 2), 4 * velocidadResX, 0, 4, ALIADO);
    mundo.add(nMisil);
}

void Jugador::mover()
{
    // ¿Cumple con el tiempo acordado?
    if( getTicks() > getLapso() )
    {
        setPosX(getPosX() + getVelX());
        if(getPosX() < 0 || getPosX() + getLargo() > iLargo)
        {
            setPosX(getPosX() - getVelX());
        }

        setPosY(getPosY() + getVelY());
        if(getPosY() < 0 || getPosY() + getAlto() > iAlto)
        {
            setPosY(getPosY() - getVelY());
        }
        reiniciar();
    }
}
