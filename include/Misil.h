#ifndef MISIL_H
#define MISIL_H
#include "ObjetoAnimado.h"  // Hereda de objeto animado

enum Bando { ALIADO,
             ENEMIGO };

class Misil : public ObjetoAnimado
{
    public:
        Misil(Textura *, int px, int py, int vx, int vy, Uint32 lt, Bando);
        virtual ~Misil();

        void mover();
        void detener();

    private:
        bool activo;
        int id;
        Bando bandoMisil;       // ¿El misil lo envía un aliado o un enemigo?
};

#endif // MISIL_H
