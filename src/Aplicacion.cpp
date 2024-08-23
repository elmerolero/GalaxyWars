#include "Aplicacion.h"
#include "Fondo.h"

int Aplicacion::main( int argc, char* args[] )
{
    // Creamos el mundo
    Mundo mundo;
    Fondo fondo(&rocoso, 0, iAlto - rocoso.getAlto(), 6 * velocidadResX, 0, 10 );
    fondo.setColor(69, 50, 46);

    Jugador jugadorUno(&nave, 30 * velocidadResX, 0, 0, 0, 6);
    jugadorUno.setPosY((iAlto - jugadorUno.getAlto()) / 2);

    Estrella estrella(&estrellas, 100, 200, 0, 0, 200);
    Estrella estrella2(&estrellas, 300, 100, 0, 0, 200);

    mundo.add(&fondo);
    mundo.add(&estrella);
    mundo.add(&estrella2);
    mundo.add(&jugadorUno);

    SDL_ShowCursor(SDL_DISABLE);
    while(!iSalir)
    {
        while(SDL_PollEvent(&iEvento) != 0)
        {
            // ¿Quiere salir?
            if(iEvento.type == SDL_QUIT)
            {
                iSalir = true;
            }

            // ¿Presionó una tecla?
            if(iEvento.type == SDL_KEYDOWN)
            {
                if(iEvento.key.keysym.sym == SDLK_ESCAPE)
                {
                    iSalir = true;
                }
            }

            jugadorUno.entrada(mundo);
        }

        limpiar();
        mundo.mover();
        mundo.animar();
        mundo.dibujar();
        actualizar();
    }
    return 0;
}

/***
* Constructor de la Clase
***/
Aplicacion::Aplicacion( std::string titulo )
{
    iniciar(titulo.c_str());
    iSalir = false;
}

/***
* Destructor de la Clase
***/
Aplicacion::~Aplicacion()
{
    cerrar();
}

/***
* Iniciador del programa
***/
//Inicia el programa
bool Aplicacion::iniciar(std::string nombre)
{
    //Retornará falso si algo sale mal al iniciar
    bool listo = true;

    //Inicia SDL
    if( SDL_Init(SDL_INIT_VIDEO) < 0 )
    {
        printf("No se inicio SDL. Error: %s\n", SDL_GetError());
        listo = false;
    }
    else
    {
        //Inicializa SDL_image
        if( !( IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG ) )
        {
            printf("No se inicio SDL_image. Error: %s\n", IMG_GetError());
            listo = false;
        }
        else if(selecResolucion())
        {
            //Crea la ventana
            iVentana = SDL_CreateWindow(nombre.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, iLargo, iAlto, SDL_WINDOW_FULLSCREEN);
            if( iVentana == NULL )
            {
                printf("Ocurrio un problema al iniciar la ventana. Error: %s\n", SDL_GetError());
                listo = false;
            }
            else
            {
                iSuperficie = SDL_CreateRenderer(iVentana, -1, SDL_RENDERER_ACCELERATED);

                if( iSuperficie == NULL )
                {
                    printf("No pudo crearse el contexto de renderizado. Error: %s", SDL_GetError());
                }

                //Establece el color del área
                SDL_SetRenderDrawColor(iSuperficie, 0, 10, 50, 0xFF);
            }
        }
    }

    return listo;
}

/*** Carga lo que necesita para correr
*/
bool Aplicacion::cargarContenido()
{
    // Bandera que devolverá false en caso de error
    bool cargado = true;

    // Carga la nave
    if(nave.cargarImagen("Recursos/Imagenes/" + resolucion + "/nave.png") < 0)
    {
        printf("No se cargó la nave :(\n");
        cargado = false;
    }

    // Carga el misil
    if(misil.cargarImagen("Recursos/Imagenes/" + resolucion + "/misil.png") < 0)
    {
        printf("No se cargó el misil :O\n");
        cargado = false;
    }

    // Carga el misil
    if(estrellas.cargarImagen("Recursos/Imagenes/" + resolucion + "/Estrellas.png") < 0)
    {
        printf("No se cargó la estrella >:|\n");
        cargado = false;
    }

    // Carga la montaña
    if(rocoso.cargarImagen("Recursos/Imagenes/" + resolucion + "/rocoso.png") < 0)
    {
        printf("No se cargó la montaña >:|\n");
        cargado = false;
    }

    return cargado;
}

/***
* Libera de memoria el programa
***/
void Aplicacion::cerrar()
{
    // Destruye la nave
    nave.desalojar();

    // Desaloja el misil
    misil.desalojar();

    // Desaloja las estrellas
    estrellas.desalojar();

    // Elimina las montañas
    rocoso.desalojar();

    SDL_DestroyRenderer(iSuperficie);
    SDL_DestroyWindow(iVentana);

    iSuperficie = NULL;
    iVentana = NULL;

    IMG_Quit();
    SDL_Quit();
}

/***
* Limpia la superficie en juego
***/
void Aplicacion::limpiar()
{
    SDL_RenderClear(iSuperficie);
}


/***
* Actualiza la superficie en juego
***/
void Aplicacion::actualizar()
{
    SDL_RenderPresent(iSuperficie);
}
/***
* Selecciona la mejor resolucion para la pantalla
***/
bool Aplicacion::selecResolucion()
{
    // Devolverá falso en caso de error
    bool hecho = true;

    // Establece la descripcion del modo de la pantalla
    SDL_DisplayMode estadoPantalla;

    // Obtendrá la pantalla correcta
    int index = 0;

    // Obtiene los datos de la pantalla
    if(SDL_GetCurrentDisplayMode(index, &estadoPantalla) == 0)
    {
        // Resolución 1080p
        if(estadoPantalla.w >= RES_ALTA_ANCHO && estadoPantalla.h >= RES_ALTA_ALTO)
        {
            // Establece la resolución 1080 (la más alta)
            iLargo = RES_ALTA_ANCHO;
            iAlto = RES_ALTA_ALTO;

            // Lo indica en el string
            resolucion = OPC_ALTA;

            // Estbalece la resolucion
            resolucionPantalla = ALTA;

            // Velocidad en pixeles a la que se mueven las cosas
            velocidadResX = VELOCIDAD_ALTA;
        }
        // Resolucion 720p
        else if(estadoPantalla.w >= RES_NORMAL_ANCHO && estadoPantalla.h >= RES_NORMAL_ALTO)
        {
            // Estbalece la resolucion
            resolucionPantalla = ALTA;

            // Establece la resolución 720p (la más alta)
            iLargo = RES_NORMAL_ANCHO;
            iAlto = RES_NORMAL_ALTO;

            // Lo indica en el string
            resolucion = OPC_MEDIA;

            // Velocidad en pixeles a la que se mueven las cosas
            velocidadResX = VELOCIDAD_NORMAL;
        }
        else
        {
            printf("Error: Resolucion no disponible\n");
            hecho = false;
        }
    }

    return hecho;
}
