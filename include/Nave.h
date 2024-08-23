#ifndef NAVE_H
#define NAVE_H
#include "ObjetoAnimado.h" // Hereda de "ObjetoAnimado"

class Nave : public ObjetoAnimado
{
    public:
        Nave(Textura *, int, int, int, int, Uint32);
        ~Nave();

        // La nave opcionalmente puede atacar
        virtual void Atacar();

    private:
};

#endif // NAVE_H
