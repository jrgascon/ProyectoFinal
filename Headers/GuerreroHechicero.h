//
// Created by Jose on 3/29/2024.
//

#ifndef ESTERPG_GUERREROHECHICERO_H
#define ESTERPG_GUERREROHECHICERO_H
#include "Personaje.h"
#include "Weapon.h"
#include "Spell.h"
class GuerreroHechicero: public Personaje{
private:
    //Atributos
    int inteligencia, fuerza;
    weapon w;
    spell s;
public:
    GuerreroHechicero(const string &nombre, int hp);

    ~GuerreroHechicero() override;

    //Getters y Setters
    int getInteligencia() const;
    void setInteligencia(int inteligencia);
    int getFuerza() const;
    void setFuerza(int fuerza);

    //Metodos heredados de la clase padre
    void getInfo();
    void dar_exp(int expn);
    int getDamage();
};


#endif //ESTERPG_GUERREROHECHICERO_H
