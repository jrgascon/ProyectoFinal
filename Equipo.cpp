//
// Created by Jose on 3/29/2024.
//

#include "Headers/Equipo.h"

Equipo::Equipo(const string &nombre):nombre(nombre) {}
Equipo::~Equipo() {}

vector<Personaje *> &Equipo::getListPersonajes() {
    return this->listPersonajes;
}

void Equipo::setListPersonajes(const vector<Personaje *> &listPersonajes) {
    Equipo::listPersonajes = listPersonajes;
}

string &Equipo::getNombre(){
    return nombre;
}

void Equipo::addPersonaje(Personaje* p) {
    listPersonajes.push_back(p);
}

bool Equipo::contains(string* nombre){

    int i = 0;
    while (i < listPersonajes.size() && listPersonajes[i]->getNombre() != *nombre)
        ++i;
    return i < listPersonajes.size();

}
int Equipo::indexOf(string* nombre) {

    if (contains(nombre)) {
        int i = 0;
        while (i < listPersonajes.size() && listPersonajes[i]->getNombre() != *nombre)
            ++i;
        return i;
    }
    return  -1;

}
void Equipo::removePersonaje(string* nombre) {

    int index = indexOf(nombre);
    if (index != -1){
        listPersonajes.erase(listPersonajes.begin()+index);
    } else cout<<"Error"<<'\n';

}

void Equipo::mostrarEquipo() {

    for (Personaje* p: listPersonajes) {
        p->getInfo();
    }

}
//Metodo con el operador = sobrecargado
Equipo Equipo::operator=(Equipo e2) {

    nombre = e2.nombre;
    listPersonajes = e2.listPersonajes;
    return *this;

}








