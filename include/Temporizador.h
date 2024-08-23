#ifndef TEMPORIZADOR_H
#define TEMPORIZADOR_H
#include <SDL.h>

class Temporizador
{
    public:
        Temporizador();
        virtual ~Temporizador();

        void Iniciar();
        void Detener();
        void Pausar();
        void Reanudar();
        void Reiniciar();

        Uint32 GetTicks();

    private:
        Uint32 tiempoInicio;            // Guarda los milisegundos donde empieza la cuenta
        Uint32 tiempoTranscurrido;      // Obtiene el tiempo transcurrido

        bool enPausa;                   //Indica si está detenido
};

#endif // TEMPORIZADOR_H
