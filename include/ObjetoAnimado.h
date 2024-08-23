#ifndef OBJETOANIMADO_H
#define OBJETOANIMADO_H
#include "Globales.h"       // Necesario para las dimensiones de la pantalla
#include "Objeto.h"         // Hereda de "Objeto"
#include "Temporizador.h"   // Se compone de un "Temporizador"

class ObjetoAnimado : public Objeto
{
    public:
        ObjetoAnimado(Textura *, int, int, int, int, Uint32);
        virtual ~ObjetoAnimado();

        // Esto forma parte de objeto animado
        virtual void mover();

        // Anima al objeto
        virtual void animar();

        // Muestra la textura
        virtual void mostrar();

        // Establece la velocidad a la que se mueve el objeto
        void setVelX(int);
        void setVelY(int);

        // Obtiene la velocidad a la que se mueve el objeto
        int getVelX() const;
        int getVelY() const;

        // Obtiene el lapso de avance
        Uint32 getLapso();

        // Obtiene los ticks
        Uint32 getTicks();

        // Opciones permitidas con el tiempo
        void pausar();
        void reanudar();
        void reiniciar();

    private:
        Temporizador * tiempo;            // Cuenta el tiempo del objeto
        Uint32 lapso;                     // Cada cuántos segundos...
        int velX;                        // Velocidad que se mueve en X
        int velY;                        // Velocidad que se mueve en Y
};

#endif // OBJETOANIMADO_H
