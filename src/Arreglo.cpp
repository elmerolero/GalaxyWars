#include "Arreglo.h"

Arreglo::Arreglo()
{
    arreglo = 0;
    tamanio = 0;
    rango = 0;
}


Arreglo::~Arreglo()
{
    delete [] arreglo;
    tamanio = 0;
    rango = 0;
}

// Añade elementos a por el inicio del arreglo
void Arreglo::agregarInicio( ObjetoAnimado * nElemento)
{
    // ¿El arreglo no está vacío?
    if( !estaVacio() )
    {
        // Crea un arreglo temporal donde se guardarán los nuevos datos
        ObjetoAnimado * arregloTemp[tamanio + 1];

        // Agrega el primer elemento al nuevo arreglo
        arregloTemp[0] = nElemento;

        // Añade el resto de los elementos al arreglo
        for(int i = 1; i < tamanio + 1; i++)
        {
            arregloTemp[i] = arreglo[i - 1];
        }

        // Elimina el arreglo antiguo
        delete [] arreglo;

        // Asigna el nuevo arreglo
        arreglo = arregloTemp;

        // Aumenta el número de elementos
        tamanio += 1;
        rango += 1;
    }
    else
    {
        // Crea un arreglo para un elemento
        arreglo = new ObjetoAnimado *[1];

        // Asigna el elemento dado
        arreglo[0] = nElemento;

        // Incrementa el tamaño del arreglo
        tamanio++;

        // Incrementa el tamaño del rango
        rango++;
    }
}


// Elimina el elemento del subíndice indicado
void Arreglo::eliminar(int subindice)
{
    // ¿El arreglo tiene un elemento?
    if( rango == 1 )
    {
        // Elimina el arreglo
        delete arreglo;
        arreglo = 0;

        // El rango es 0
        rango = 0;

        // El tamaño es 0
        tamanio = 0;
    }
    else if( !estaVacio() )
    {
        // Crea un arreglo temporal donde se guardarán los nuevos datos
        ObjetoAnimado * * arregloTemp = new ObjetoAnimado *[tamanio - 1];

        // Copia los elementos restantes del arreglo
        for( int i = 0; i < tamanio - 1; i++)
        {
            // ¿Es el subindice indicado?
            if( i != subindice )
            {
                // Asigna la cantidad
                arregloTemp[i] = arreglo[i];
            }
        }

        // Elimina el arreglo
        delete arreglo;

        // Asigna el arreglo
        arreglo = arregloTemp;
    }
}


ObjetoAnimado * Arreglo::operator[] (int subindice )
{
    if( subindice < rango )
    {
        return arreglo[subindice];
    }
}


// Indica si está vacío el arreglo
bool Arreglo::estaVacio()
{
    return arreglo == 0;
}
