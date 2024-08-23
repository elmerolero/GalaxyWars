#include "Globales.h"

SDL_Renderer * iSuperficie;
int iLargo;
int iAlto;

// Porcentaje de velocidad según la resolucion
const double VELOCIDAD_ALTA = 1;
const double VELOCIDAD_NORMAL = 0.66;

const int RES_ALTA_ANCHO = 1920;
const int RES_ALTA_ALTO = 1080;
const int RES_NORMAL_ANCHO = 1260;
const int RES_NORMAL_ALTO = 720;

double velocidadResX;

Textura nave;
Textura misil;
Textura rocoso;
Textura estrellas;

/*const char * nave1 = "Recursos/Imagenes/nave.png";
const char * misil = "Recursos/Imagenes/misil.png";
const char * montanas = "Recursos/Imagenes/montana.png";
const char * fondo1 = "Recursos/Imagenes/fondo.png";
*/
