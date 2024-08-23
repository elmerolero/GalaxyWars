#include "Espacio.h"

Espacio::Espacio()
{
    primero = NULL;
    ultimo = NULL;
}

Espacio::~Espacio()
{
    //dtor
}

void Espacio::add(Misil * item)
{
    // Crea un nuevo nodo
    Nodo * nuevo = new Nodo;

    // Asigna el objeto animado pasado en los argumentos
    nuevo -> item = item;
    nuevo -> anterior = NULL;
    nuevo -> siguiente = NULL;

    // ¿Es el primer elemento de la lista?
    if( primero == NULL )
    {
        // Es tanto el primero como el último elemento de la lista
        primero = ultimo = nuevo;
    }
    else
    {
        // El nuevo ahora es el ultimo
        ultimo -> siguiente = nuevo;
        nuevo -> anterior = ultimo;
        ultimo = nuevo;
    }
}

void Espacio::destroy(Nodo * nodo )
{
    // Elimina el nodo
    delete nodo;
}

void Espacio::mover()
{
    // Requerimos un puntero auxiliar
    Nodo * aux = primero;
    Nodo * temp = NULL;

    // Para cada uno de los nodos
    while( aux != NULL )
    {
        aux -> item -> mover();

        // ¿Está fuera de la pantalla?
        if( aux -> item -> getPosX() > iLargo )
        {
            // Asigna el nodo actual
            temp = aux;

            // Se saca de la pila
            if( aux -> anterior != NULL )
                aux -> anterior -> siguiente = aux -> siguiente;
            aux = aux -> siguiente;
            destroy(temp);
        }
        else
        {
            aux = aux -> siguiente;
        }
    }
}

void Espacio::dibujar()
{
    // Requerimos un puntero auxiliar
    Nodo * aux = primero;

    // Para cada uno de los nodos
    while( aux != NULL )
    {
        aux -> item -> dibujar();
        aux = aux -> siguiente;
    }
}
