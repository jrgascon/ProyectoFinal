//
// Created by Jose on 3/29/2024.
//

#ifndef ESTERPG_PERSONAJE_H
#define ESTERPG_PERSONAJE_H
#include <string>
#include <iostream>
using namespace std;

class Personaje{
protected:
    //Atributos
    string nombre;
    int nivel,hp,exp;
public:
                        //Constructor y Destructor
    Personaje(const string &nombre, int hp);
    virtual ~Personaje();

                        //Getters and Setters
    const string &getNombre() const;
    void setNombre(const string &nombre);
    int getNivel() const;
    void setNivel(int nivel);
    int getHp();
    void setHp(int hp);
    int getExp() const;
    void setExp(int exp);

    //Metodos virtuales puros
    virtual void getInfo()=0;
    virtual void dar_exp(int expn)=0;
    virtual int getDamage()=0;

};


#endif //ESTERPG_PERSONAJE_H
