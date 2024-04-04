//
// Created by Jose on 3/29/2024.
//
#ifndef ESTERPG_EQUIPO_H
#define ESTERPG_EQUIPO_H
#include "Personaje.h"
#include <vector>

class Equipo {
private:
    //Atributos
    string nombre;
    vector<Personaje*> listPersonajes;
public:
    Equipo(const string &nombre);
    ~Equipo();
    //Sobrecarga del operador =
    Equipo operator=(Equipo e2);
    //Getters y Setters
    vector<Personaje *> &getListPersonajes();
    void setListPersonajes(const vector<Personaje *> &listPersonajes);
    string &getNombre();

    //Metodos Publicos
    void addPersonaje(Personaje* p);
    bool contains(string* n);
    int indexOf(string *nombre);
    void removePersonaje(string* nombre);
    void mostrarEquipo();
    int size(){
        return listPersonajes.size();
    }
};
#endif //ESTERPG_EQUIPO_H
