//
// Created by Jose on 3/29/2024.
//

#ifndef ESTERPG_GUERRERO_H
#define ESTERPG_GUERRERO_H
#include "Personaje.h"
#include "Weapon.h"
class Guerrero: public Personaje{
private:
    //Atributos
    int fuerza;
    weapon w;
public:
    Guerrero(const string &nombre, int hp);

    ~Guerrero() override;

    //Getters y Setters
    int getFuerza() const;
    void setFuerza(int fuerza);
    const weapon &getW() const;
    void setW(const weapon &w);

    //Metodos Heredados de la clase padre
    void getInfo();
    void dar_exp(int expn);
    int getDamage();
};


#endif //ESTERPG_GUERRERO_H
