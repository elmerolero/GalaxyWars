#include "Mundo.h"

Mundo::Mundo()
{
    //ctor
}

Mundo::~Mundo()
{
    //dtor
    arreglo.erase( arreglo.begin(), arreglo.end() );
}

void Mundo::add(ObjetoAnimado * nObjeto)
{
    arreglo.push_back(nObjeto);
}

void Mundo::mover()
{
    for(unsigned int i = 0; i < arreglo.size(); i++ )
    {
        arreglo[i] -> mover();
        if(arreglo[i] -> getPosX() > iLargo)
        {
            delete arreglo[i];
            arreglo.erase( arreglo.begin() + i );
        }
    }
}

void Mundo::dibujar()
{
    for(unsigned int i = 0; i < arreglo.size(); i++ )
    {
        arreglo[i] -> mostrar();
    }
}

void Mundo::animar()
{
    for(unsigned int i = 0; i < arreglo.size(); i++ )
    {
        arreglo[i] -> animar();
    }
}
