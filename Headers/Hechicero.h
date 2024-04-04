//
// Created by Jose on 3/29/2024.
//

#ifndef ESTERPG_HECHICERO_H
#define ESTERPG_HECHICERO_H
#include "Personaje.h"
#include "Spell.h"
class Hechicero:public Personaje{
private:
    //Atributos
    int inteligencia;
    spell s;
public:
    Hechicero(const string &nombre,int hp);

    ~Hechicero() override;

    //Getters y Setters
    int getInteligencia() const;
    void setInteligencia(int inteligencia);
    const spell &getS() const;
    void setS(const spell &s);

    //Metodos Heredados de la clase padre
    void getInfo();
    void dar_exp(int expn);
    int getDamage();
};


#endif //ESTERPG_HECHICERO_H
