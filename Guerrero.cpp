//
// Created by Jose on 3/29/2024.
//

#include "Headers/Guerrero.h"

Guerrero::Guerrero(const string &nombre, int hp) : Personaje(nombre, hp),fuerza(3),w() {}

Guerrero::~Guerrero() {}

int Guerrero::getFuerza() const {
    return fuerza;
}

void Guerrero::setFuerza(int fuerza) {
    Guerrero::fuerza = fuerza;
}

const weapon &Guerrero::getW() const {
    return w;
}

void Guerrero::setW(const weapon &w) {
    Guerrero::w = w;
}

void Guerrero::getInfo() {
    cout<<"Nombre: "<<getNombre()<<" Tipo: Guerrero Nivel:"<<getNivel()<< " HP: "<<getHp()<<" Damage: "<<getDamage()<<'\n';
}

void Guerrero::dar_exp(int expn) {

    if (exp+expn>=nivel*10){
        exp = exp - nivel*10;
        nivel++;
        setHp(hp+(getFuerza()*getNivel())+5);
        setFuerza(getFuerza()+2);
    } else exp += expn;

}

int Guerrero::getDamage() {
    return getW().damage+getFuerza();
}


