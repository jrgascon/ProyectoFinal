//
// Created by Jose on 3/29/2024.
//

#include "Headers/Hechicero.h"

Hechicero::Hechicero(const string &nombre, int hp):
Personaje(nombre, hp), inteligencia(3), s() {}

Hechicero::~Hechicero() {}

int Hechicero::getInteligencia() const {
    return inteligencia;
}
void Hechicero::setInteligencia(int inteligencia) {
    Hechicero::inteligencia = inteligencia;
}
const spell &Hechicero::getS() const {
    return s;
}
void Hechicero::setS(const spell &s) {
    Hechicero::s = s;
}

void Hechicero::getInfo() {
    cout<<"Nombre: "<<getNombre()<<" Tipo: Hechicero Nivel:"<<getNivel()<< " HP: "<<getHp()<<" Damage: "<<getDamage()<<'\n';
}

void Hechicero::dar_exp(int expn) {
    if (exp+expn>=nivel*10){
        exp = exp - nivel*10;
        nivel++;
        setHp(hp+(getInteligencia()*getNivel())+5);
        setInteligencia(getInteligencia()+2);
    } else exp += expn;
}

int Hechicero::getDamage() {
    return getInteligencia()*getS().damage;
}