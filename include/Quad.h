#ifndef QUAD_H
#define QUAD_H
#include <SDL.h>
#include <cmath>
#include <vector>
#include "Globales.h"
#include "Objeto.h"

const int MAX_OBJETOS = 5;  // La cantidad de objetos máximos que puedes agregar al árbol
const int NIVEL_MAXIMO = 4; // La cantidad de niveles que puede haber

class Quad
{
    public:
        Quad();
        Quad(int nivel, SDL_Rect &);
        ~Quad();

        void insertar(Objeto * nodo);
        void limpiar();
        void dividir();

    private:
        const int nivel;                          // Se asegura que no sobrepaso el nivel más profundo
        SDL_Rect limite;                    // Delimita el espacio que tienen los objetos
        std::vector<Objeto *> elementos;    // Accesa a los objetos que contiene
        Quad * arribaIzquierda;             // Nodos siguientes
        Quad * arribaDerecha;
        Quad * abajoIzquierda;
        Quad * abajoDerecha;
};

#endif // QUAD_H
