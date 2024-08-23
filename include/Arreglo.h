#ifndef ARREGLO_H
#define ARREGLO_H
#include "ObjetoAnimado.h"

class Arreglo
{
    public:
        Arreglo();
        ~Arreglo();

        // Permite agregar elementos
        void agregarInicio( ObjetoAnimado *);
        /*void agregarFin(const ObjetoAnimado * &);

        // Permite eliminar elementos del arreglo
        void eliminar_incio();
        void eliminar_fin();*/
        void eliminar(int);

        // Devuelve una referencia al elemento del sub�ndice dado
        ObjetoAnimado * & operator [] (int);

        // Indica si est� vac�o el arreglo
        bool estaVacio();

    private:
        ObjetoAnimado * arreglo;     // Sobre �ste se crea el arreglo
        unsigned int tamanio;   // Tama�o del arreglo
        unsigned int rango;     // La cantidad de elementos usados en el arrglo
};

#endif // ARREGLO_H
