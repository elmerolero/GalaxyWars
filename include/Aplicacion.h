#ifndef APLICACION_H
#define APLICACION_H

#include <stdio.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "Globales.h"
#include "Mundo.h"
#include "Textura.h"
#include "Jugador.h"
#include "Misil.h"
#include "Estrella.h"

enum Estado { MENU,
              NIVEL,
              JUEGO };

enum Resolucion{ ALTA,
                 NORMAL };

const std::string OPC_ALTA = "Alto";
const std::string OPC_MEDIA = "Normal";

class Aplicacion
{
    public:
        // Constructores
        Aplicacion(std::string);
        virtual ~Aplicacion();

        // Funciones de la aplicacion
        bool iniciar(std::string);
        bool cargarContenido();
        void cerrar();
        void limpiar();
        void eventos();
        void actualizar();

        // El main principal
        int main(int argc, char* args[]);

    private:
        bool selecResolucion();
        Resolucion resolucionPantalla;
        std::string resolucion;
        static Estado estadoAplicacion; // En qué estado está la aplicacion
        bool iSalir;                    // Indica si se desea salir de la aplicacion
        SDL_Event iEvento;              // Obtiene los eventos recientes
        SDL_Window * iVentana = NULL;   // Ventana de la aplicación
};

#endif // APLICACION_H
