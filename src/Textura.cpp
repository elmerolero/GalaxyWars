#include "Aplicacion.h"
#include "Globales.h"
#include "Textura.h"

Textura::Textura()
{
    largo = 0;
    alto = 0;
    textura = NULL;
}

Textura::~Textura()
{
    desalojar();
}

int Textura::cargarImagen( std::string directorio )
{
    //Bandera de estado, devolverá -1 en caso de error
    int cargada = 0;

    //Se asegura que no tengan otras texturas
    desalojar();

    //Textura
    SDL_Texture * nuevaTextura = NULL;

    //Superficie donde se guardará la imagen
    SDL_Surface * imagenACargar = IMG_Load( directorio.c_str() );
    if( imagenACargar == NULL )
    {
        printf("No pudo cargarse la imagen. Error: %s", SDL_GetError());
        cargada = -1;
    }
    else
    {
        //Transforma la superficie en una textura
        nuevaTextura = SDL_CreateTextureFromSurface( iSuperficie, imagenACargar );
        if( nuevaTextura == NULL )
        {
            printf("Error al convertir la superficie. Error: %s", SDL_GetError());
            cargada = -1;
        }
        else
        {
            largo = imagenACargar -> w;
            alto = imagenACargar -> h;
        }

        //Libera memoria de la superficie
        SDL_FreeSurface(imagenACargar);
    }

    textura = nuevaTextura;
    if( textura == NULL )
        cargada = -1;

    return cargada;
}

#ifdef TTF_H
#define
int Textura::crearTexturaDeTexto( std::string textoAEscribir, SDL_Color colorFuente, TTF_Font * fuente)
{
    //En caso de error, retornará -1
    int cargado = 0;

    //Libera el espacio utilizado por texturas anteriores
    desalojar();

    //Renderiza la superficie de texto
    SDL_Surface * superficieTexto = TTF_RenderText_Solid( fuente, textoAEscribir.c_str(), colorFuente );
    if( superficieTexto != NULL )
    {
        //Convierte la superficie en una textura
        textura = SDL_CreateTextureFromSurface(tetris_areaPrincipal, superficieTexto);
        if( textura == NULL )
        {
            printf("Hubo un problema al convertir la textura. Error: %s", SDL_GetError() );
            cargado = -1;
        }
        else
        {
            largo = superficieTexto -> w;
            alto = superficieTexto -> h;
        }

        //Borra la superficie de memoria
        SDL_FreeSurface(superficieTexto);
    }
    else
    {
        printf("No se pudo crear la textura desde texto. Error: %s", TTF_GetError());
        cargado = -1;
    }

    return cargado;
}
#endif // TTF_H


void Textura::setBlend( SDL_BlendMode modo )
{
    SDL_SetTextureBlendMode( textura, modo );
}

void Textura::setColor(Uint8 rojo, Uint8 verde, Uint8 azul)
{
    SDL_SetTextureColorMod(textura, rojo, verde, azul);
}

void Textura::establecerAlpha( Uint8 transparencia )
{
    SDL_SetTextureAlphaMod( textura, transparencia );
}

//Copia la parte seleccionada de la imagen en el área de render
void Textura::renderizar( int x, int y, SDL_Rect *src )
{
    SDL_Rect cuadRender;

    if( src == NULL )
        cuadRender = {x, y, largo, alto};
    else
        cuadRender = {x, y, src->w, src->h};

    SDL_RenderCopy( iSuperficie, textura, src, &cuadRender );
}


void Textura::desalojar()
{
    if( textura != NULL )
    {
        //Destruye la textura de memoria
        SDL_DestroyTexture( textura );
        textura = NULL;
        largo = 0;
        alto = 0;
    }
}

int Textura::getAlto()
{
    return alto;
}

int Textura::getLargo()
{
    return largo;
}
