//
// Created by Jose on 3/29/2024.
//
#include "Headers/Personaje.h"

Personaje::Personaje(const string &nombre,int hp) : nombre(nombre), nivel(1), hp(hp) {}

Personaje::~Personaje() {}

const string &Personaje::getNombre() const {
    return nombre;
}

void Personaje::setNombre(const string &nombre) {
    Personaje::nombre = nombre;
}

int Personaje::getNivel() const {
    return nivel;
}

void Personaje::setNivel(int nivel) {
    Personaje::nivel = nivel;
}

int Personaje::getHp() {
    return hp;
}

void Personaje::setHp(int hp) {
    Personaje::hp = hp;
}

int Personaje::getExp() const {
    return exp;
}

void Personaje::setExp(int exp) {
    Personaje::exp = exp;
}