//
// Created by Jose on 3/29/2024.
//

#include <random>
#include "Headers/Batalla.h"
//Clase Batalla
void Batalla::mostrarTeam(){

    cout<<"\t Arena "<<'\n';
    cout<<equipo1.getNombre()<<'\t'<<'\t'<<'\t'<<equipo2.getNombre()<<'\n';
    int i = 0;
    while (i < 3){
        if (equipo1.size()>i){
            cout<<(i+1)<<" "<<equipo1.getListPersonajes()[i]->getNombre()<<" HP "<<equipo1.getListPersonajes()[i]->getHp()<<'\t'<<'\t';
            if (equipo2.size()>i){
                cout<<(i+1)<<" "<<equipo2.getListPersonajes()[i]->getNombre()<<" HP "<<equipo2.getListPersonajes()[i]->getHp()<<'\n';
            }else cout<<'\n';
        } else if(equipo2.size()>i)
            cout<<(i+1)<<" "<<equipo2.getListPersonajes()[i]->getNombre()<<" HP "<<equipo2.getListPersonajes()[i]->getHp()<<'\n';
        i++;
    }

}

void Batalla::turno_Jugador1() {

    int i = 0;
    while(i<equipo1.size()){
        mostrarTeam();
        cout<<"Turno de: "<<equipo1.getListPersonajes()[i]->getNombre()<<'\n';
        int resividorId;
        cout<<"Introduce el id del Heroe que vas a atacar: "<<'\n';
        cin>>resividorId;
        if (resividorId <= 0 or resividorId > equipo2.size()){
            cout<<"Ingrese un id valido"<<'\n';
            continue;
        }
        if (Funciones().atacar(equipo1.getListPersonajes()[i],equipo2.getListPersonajes()[resividorId-1])){
            caidos.addPersonaje(equipo2.getListPersonajes()[resividorId-1]);
            string* nombreP = const_cast<string *>(&equipo2.getListPersonajes()[resividorId-1]->getNombre());
            equipo2.removePersonaje(nombreP);
            if (equipo2.getListPersonajes().empty()) break;
        }
        i++;
    }

}

void Batalla::turno_Jugador2() {

    int i = 0;
    while(i<equipo2.size()){
        cout<<"Turno de: "<<equipo2.getListPersonajes()[i]->getNombre()<<'\n';
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> distribucion(1, 3);
        int resividorId = distribucion(gen);
        if (Funciones().atacar(equipo2.getListPersonajes()[i],equipo1.getListPersonajes()[resividorId-1])){
            caidos.addPersonaje(equipo1.getListPersonajes()[resividorId-1]);
            string* nombreP = const_cast<string *>(&equipo1.getListPersonajes()[resividorId-1]->getNombre());
            equipo1.removePersonaje(nombreP);
            if (equipo1.getListPersonajes().empty()) break;
        }
        i++;
    }

}

Batalla::Batalla(const Equipo &equipo1, const Equipo &equipo2) : equipo1(equipo1), equipo2(equipo2), caidos("Lista caidos"),
ganador(" "){}

Batalla::~Batalla() {}

void Batalla::Mostar_Arena() {

    while (equipo1.size()>0 && equipo2.size()>0){
        turno_Jugador1();
        if (equipo2.getListPersonajes().empty()){
            break;
        }
        cout<<"Turno del otro Jugador:"<<'\n';
        turno_Jugador2();
    }
    if (equipo2.getListPersonajes().empty()){
        ganador=equipo1;
        cout<<"Felicidades tu equipo ha resultado ganador, bien echo"<<'\n'<<ganador.getNombre()<<'\n';
        ganador.mostrarEquipo();
    } else {
        ganador=equipo2;
        cout<<"Derrota, mejor suerte la proxima"<<'\n'<<ganador.getNombre()<<'\n';
        ganador.mostrarEquipo();
    }
    cout<<"Heroes caidos"<<'\n';
    caidos.mostrarEquipo();

}

//Clase Funciones
Funciones::Funciones(){}

bool Funciones::atacar(Personaje *atacante, Personaje *defensor) {

    if(defensor->getHp() - atacante->getDamage() <= 0){
        cout<<defensor->getNombre()<<" ha sido derrotado"<<'\n';
        defensor->setHp(0);
        atacante->dar_exp(defensor->getNivel()*2);
        return true;
    } else{
        cout<<atacante->getNombre()<<" hizo un ataque de "<<atacante->getDamage()<<" puntos de damage a "<< defensor->getNombre()<<'\n';
        defensor->setHp(defensor->getHp()-atacante->getDamage());
        atacante->dar_exp((int)(defensor->getNivel()*0.5));
        return false;
    }

}