#include "Objeto.h"

// Constructor
Objeto::Objeto(Textura * iTextura,int px, int py):
textura(iTextura), posX(px), posY(py)
{

}

// Destructor
Objeto::~Objeto()
{
    destruir();
}

// Dibuja el objeto
void Objeto::dibujar(SDL_Rect * src)
{
    textura -> renderizar(posX, posY, src);
}

// Establece la posición de la nave en X
void Objeto::setPosX(int px)
{
    this -> posX = px;
}

// Establece la posición de la nave en Y
void Objeto::setPosY(int py)
{
    this -> posY = py;
}

// Obtiene la posición de la nave en X
int Objeto::getPosX() const
{
    return this -> posX;
}

// Establece la posición de la nave en Y
int Objeto::getPosY() const
{
    return this -> posY;
}

// Obtiene el largo del objeto
int Objeto::getLargo()
{
    return textura -> getLargo();
}

// Obtiene la altura del objeto
int Objeto::getAlto()
{
    return textura -> getAlto();
}

//Establece el modo de combinación (necesario para usar establecerAlpha)
void Objeto::setBlend( SDL_BlendMode modo )
{
    textura -> setBlend(modo);
}

// Establece el color
void Objeto::setColor(Uint8 rojo, Uint8 verde, Uint8 azul)
{
    textura -> setColor(rojo, verde, azul);
}

//Establece el nivel de transparencia
void Objeto::establecerAlpha( Uint8 canal )
{
    textura -> establecerAlpha( canal );
}

// Destruye el objeto
void Objeto::destruir()
{
    posX = 0;
    posY = 0;
}
