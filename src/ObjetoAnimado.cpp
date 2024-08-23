#include "ObjetoAnimado.h"

// Constructor
ObjetoAnimado::ObjetoAnimado(Textura * textura, int px, int py, int vx, int vy, Uint32 lt):
    Objeto(textura, px, py), lapso(lt), velX(vx), velY(vy)
{
    tiempo = new Temporizador();
    tiempo -> Iniciar();
}

//Destructor
ObjetoAnimado::~ObjetoAnimado()
{
    tiempo -> Detener();
    delete tiempo;

    destruir();
}

// Mueve el objeto
void ObjetoAnimado::mover()
{
    if(tiempo->GetTicks() > lapso)
    {
        setPosX(getPosX() - velX);
        if(getPosX() + getLargo() < 0)
            setPosX(iLargo);
        tiempo -> Reiniciar();
    }
}

// Anima el objeto
void ObjetoAnimado::animar()
{
    // Vacío
}

// Mostrar
void ObjetoAnimado::mostrar()
{
    dibujar(NULL);
}

// Establece la velocidad a la que se mueve el objeto en X
void ObjetoAnimado::setVelX(int vx)
{
    this->velX = vx;
}

// Establece la velocidad a la que se mueve el objeto en Y
void ObjetoAnimado::setVelY(int vy)
{
    this->velY = vy;
}

// Retorna la velocidad a la que se mueve el objeto en X
int ObjetoAnimado::getVelX() const
{
    return velX;
}

// Retorna la velocidad a la que se mueve el objeto en Y
int ObjetoAnimado::getVelY() const
{
    return velY;
}

/*/ Establece la seleccion
void ObjetoAnimado::setSeleccion(int x, int y, int w, int h)
{
    seleccion.x = x;
    seleccion.y = y;
    sleccion.w = w;
    seleccion.h = h;
}*/

// Obtiene el lapso de referencia
Uint32 ObjetoAnimado::getLapso()
{
    return lapso;
}

// Obtiene el tiempo transcurrido en milisegundos
Uint32 ObjetoAnimado::getTicks()
{
    return tiempo -> GetTicks();
}

// Pausa el tiempo transcurrido del objeto
void ObjetoAnimado::pausar()
{
    tiempo -> Pausar();
}

void ObjetoAnimado::reanudar()
{
    tiempo -> Reanudar();
}

void ObjetoAnimado::reiniciar()
{
    tiempo -> Reiniciar();
}
