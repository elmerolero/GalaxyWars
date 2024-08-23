#include "Quad.h"

// Constructor predeeterminado
Quad::Quad():
    nivel(1)
{
    // Establece el límite en 0's
    limite.x = 0;
    limite.y = 0;
    limite.w = iLargo;
    limite.h = iAlto;

    // Inicia los hijos del arbol
    arribaIzquierda = NULL;
    arribaDerecha = NULL;
    abajoIzquierda = NULL;
    abajoDerecha = NULL;

    dividir();
}

// Constructor de nodo
Quad::Quad(int nivel, SDL_Rect & rect):
    limite(rect), nivel(nivel)
{
    // Inicializa los hijos del arbol
    arribaIzquierda = NULL;
    arribaDerecha = NULL;
    abajoIzquierda  = NULL;
    abajoDerecha = NULL;
}

Quad::~Quad()
{
    this->limpiar();
}

void Quad::insertar(Objeto * nodo)
{

}

void Quad::limpiar()
{
    // Elimina todos los elementos almacenados
    elementos.clear();

    /* Elimina todos sus nodos */
    // Arriba izquierda
    if(arribaIzquierda != NULL)
    {
        delete arribaIzquierda;
        arribaIzquierda = NULL;
    }

    // Arriba derecha
    if(arribaDerecha != NULL)
    {
        delete arribaDerecha;
        arribaDerecha = NULL;
    }

    // Abajo izquierda
    if(abajoIzquierda != NULL)
    {
        delete abajoIzquierda;
        abajoIzquierda = NULL;
    }

    // Abajo derecha
    if(abajoDerecha != NULL)
    {
        delete abajoDerecha;
        abajoDerecha = NULL;
    }

    // Establece el límite en 0's
    limite.x = 0;
    limite.y = 0;
    limite.w = 0;
    limite.h = 0;
}

void Quad::dividir()
{
    SDL_Rect rectAux;
    int subLargo = limite.w / 2;
    int subAlto = limite.h / 2;
    int x = limite.x;
    int y = limite.y;

    // Establecemos los límites del nodo arribaIzquierda
    rectAux = {x + subLargo, y, subLargo, subAlto};
    arribaIzquierda = new Quad(nivel + 1, rectAux);

    // Establecemos los límites del nodo arribaDerecha
    rectAux = {x, y, subLargo, subAlto};
    arribaDerecha = new Quad(nivel + 1, rectAux);

    // Establecemos los límites del nodo abajoIzquierda
    rectAux = {x + subLargo, y + subAlto, subLargo, subAlto};
    abajoIzquierda = new Quad(nivel + 1, rectAux);

    // Establecemos los límites del nodo abajoDerecha
    rectAux = {x, y + subAlto, subLargo, subAlto};
    abajoDerecha = new Quad(nivel + 1, rectAux);
}
