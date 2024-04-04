//
// Created by Jose on 3/29/2024.
//

#ifndef ESTERPG_BATALLA_H
#define ESTERPG_BATALLA_H
#include "Equipo.h"


class Batalla {
private:
    //Atributos
    Equipo ganador;
    Equipo caidos;
    Equipo equipo1;
    Equipo equipo2;
    //Metodos Privados
    void mostrarTeam();
    void turno_Jugador1();
    void turno_Jugador2();
public:
    Batalla(const Equipo &equipo1, const Equipo &equipo2);
    ~Batalla();
    //Metodos publicos
    void Mostar_Arena();

};
class Funciones{
public:
    Funciones();
    //Metodos Publicos auxiliares
    static bool atacar(Personaje* atacante, Personaje* defensor);
};


#endif //ESTERPG_BATALLA_H
