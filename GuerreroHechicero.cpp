//
// Created by Jose on 3/29/2024.
//

#include "Headers/GuerreroHechicero.h"

GuerreroHechicero::GuerreroHechicero(const string &nombre, int hp):
Personaje(nombre, hp),inteligencia(3), fuerza(3),w(), s() {}

GuerreroHechicero::~GuerreroHechicero() {}

int GuerreroHechicero::getInteligencia() const {
    return inteligencia;
}

void GuerreroHechicero::setInteligencia(int inteligencia) {
    GuerreroHechicero::inteligencia = inteligencia;
}

int GuerreroHechicero::getFuerza() const {
    return fuerza;
}

void GuerreroHechicero::setFuerza(int fuerza) {
    GuerreroHechicero::fuerza = fuerza;
}

void GuerreroHechicero::getInfo() {
    cout<<"Nombre: "<<getNombre()<<" Tipo: GuerreroHechicero Nivel:"<<getNivel()<< " HP: "<<getHp()<<" Damage: "<<getDamage()<<'\n';
}

void GuerreroHechicero::dar_exp(int expn) {

    if (exp+expn>=nivel*10){
        exp = exp - nivel*10;
        nivel++;
        setHp(hp+(getFuerza()*nivel)+5);
        setInteligencia(getInteligencia()+1);
        setFuerza(getFuerza()+1);
    } else exp += expn;

}

int GuerreroHechicero::getDamage() {
    return (getInteligencia()+getFuerza()+s.damage+w.damage);
}