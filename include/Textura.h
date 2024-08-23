#ifndef TEXTURA_H
#define TEXTURA_H
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <stdio.h>

class Textura
{
    public:
        //Inicializa las variables
        Textura();

        //Desaloja la textura de memoria
        virtual ~Textura();

        //Carga la imagen que se usará de textura
        int cargarImagen(std::string);

        #ifdef TTF_H
        #define
        //Crea una textura desde un texto definido
        int crearTexturaDeTexto( std::string, SDL_Color, TTF_Font * );
        #endif // TTF_H

        //Establece el modo de combinación (necesario para usar establecerAlpha)
        void setBlend( SDL_BlendMode );

        // Establece el color
        void setColor(Uint8, Uint8, Uint8);

        //Establece el nivel de transparencia
        void establecerAlpha( Uint8 );

        //Copia la parte seleccionada de la imagen en el área de render
        void renderizar( int, int, SDL_Rect * );

        //Desaloja de la memoria
        void desalojar();

        //Funciones obtener
        int getLargo();
        int getAlto();

    private:
        int largo;
        int alto;
        SDL_Texture * textura;
};

#endif // TEXTURA_H
