#ifndef OBJETO_H
#define OBJETO_H
#include "Textura.h"    // Se compone de textura

class Objeto
{
    public:
        Objeto(Textura *, int, int);
        virtual ~Objeto();

        // Dibuja el objeto
        void dibujar(SDL_Rect *);

        // Establece la posición del objeto
        void setPosX(int);
        void setPosY(int);

        // Obtiene la posición del objeto
        int getPosX() const;
        int getPosY() const;

        //Funciones obtener
        int getLargo();
        int getAlto();

        //Establece el modo de combinación (necesario para usar establecerAlpha)
        void setBlend( SDL_BlendMode );

        // Establece el color
        void setColor(Uint8, Uint8, Uint8);

        //Establece el nivel de transparencia
        void establecerAlpha( Uint8 );

        // Destruye el objeto
        void destruir();

    private:
        Textura * textura;
        int posX;                        // Posición de la pantalla en X
        int posY;                        // Posición de la pantalla en Y
};

#endif // OBJETO_H
