#include "Headers/Batalla.h"
#include "Headers/Guerrero.h"
#include "Headers/Hechicero.h"
#include "Headers/GuerreroHechicero.h"
#include <iostream>
int main() {

    Equipo e1("My equipo");
    Equipo e2("Equipo Enemigo");
    vector<Personaje*> listaPersonajes;

    Guerrero p1("Artorias", 100);
    Guerrero p2("Dovaking", 150);
    Hechicero p3("Harry Potter", 60);
    Hechicero p4("Juan el Mago", 80);
    GuerreroHechicero p5("Arthas", 100);
    GuerreroHechicero p6("Uther", 90);

    while (true){
        cout<<"Bienvenido a MYFirstRPG"<<'\n';
        cout<<"1-Empezar Partida"<<'\n';
        cout<<"2-Salir"<<'\n';
        int option;
        cin>>option;
        int cant = 1;
        switch (option) {
            case 1:
                listaPersonajes = {&p1,&p2,&p3,&p4,&p5,&p6};
                while (cant <= 3) {
                    for (int i = 0; i < listaPersonajes.size(); i++) {
                        cout << "id:" << i + 1;
                        listaPersonajes[i]->getInfo();
                    }
                    int opcion;
                    cout << "Introduce el id del heroe que quiere elegir" << '\n';
                    cin >> opcion;
                    if (opcion > listaPersonajes.size()) cout << "Opcion fuera de rango, debe elegir entre 1 y " << listaPersonajes.size()<<'\n';
                    else {
                        e1.addPersonaje(listaPersonajes[opcion - 1]);
                        if (opcion>1){
                            listaPersonajes.erase(listaPersonajes.begin()+(opcion-1));
                        } else listaPersonajes.erase(listaPersonajes.begin());
                    }
                    cant++;
                }
                break;
            case 2:
                cout<<"Muchas Gracias por Probar esta Beta."<<'\n';
                break;
            default:
                cout<<"Introduce una opcion valida"<<'\n';
                continue;
        }
        if (option==1){
        cout<<"Empieza la Batalla"<<'\n';
        e2.setListPersonajes(listaPersonajes);
        Batalla batalla(e1,e2);
        batalla.Mostar_Arena();
        }
        break;
    }
    return 0;
}