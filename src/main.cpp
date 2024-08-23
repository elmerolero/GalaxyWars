#include <SDL.h>
#include <SDL_image.h>
#include "Globales.h"
#include "Aplicacion.h"
#include "Textura.h"

int main( int argc, char* args[] )
{
    Aplicacion GalaxyWars("GalaxyWars");

    if(GalaxyWars.cargarContenido())
    {
        return GalaxyWars.main(argc, args);
    }
    else
    {
        printf("Error al cargar el contenido!\n");
        return -1;
    }
}
