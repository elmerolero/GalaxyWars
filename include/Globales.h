#ifndef GLOBALES_H
#define GLOBALES_H
#include <SDL.h>
#include <string>
#include "Textura.h"

// Área de renderizado
extern SDL_Renderer * iSuperficie;

// Dimensiones de la pantalla
extern int iLargo;
extern int iAlto;

extern const int RES_ALTA_ANCHO;
extern const int RES_ALTA_ALTO;
extern const int RES_NORMAL_ANCHO;
extern const int RES_NORMAL_ALTO;

// Porcentaje de velocidad según la resolucion
extern const double VELOCIDAD_ALTA;
extern const double VELOCIDAD_NORMAL;

extern double velocidadResX;

// Textura del misil
extern Textura nave;
extern Textura misil;
extern Textura rocoso;
extern Textura estrellas;
#endif // GLOGALES_H
