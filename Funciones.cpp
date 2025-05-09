#include <iostream>
#include "Funciones.h"

using namespace std;

void menu (){
    int eleccionUsuario = mostrarMenuPrincipal();
    switchMenu(eleccionUsuario);
}

int mostrarMenuPrincipal(){
    int eleccion;
    cout << "================================" << endl;
    cout << "======CHINELERO - POCOCLERO=====" << endl;
    cout << "================================" << endl;
    cout << "(1) Peliculas" << endl;
    cout << "(2) Salas" << endl;
    cout << "(3) Ventas" << endl;
    cout << "================================" << endl;
    cout << "(0) SALIR." << endl;
    cout << "================================" << endl;
    cout << "Elija una opcion: ";
    cin >> eleccion;
    return eleccion;
}

void switchMenu(int eleccion){
    system("cls");
    while (true){
        switch (eleccion){
            case 1: /// OPCIONES PAEA PELICULAS ///
                //peliculas();
                system("pause"); return;

            case 2: /// OPCIONES PARA SALAS ///
                //salas();
                system("pause"); return;

            case 3: /// OPCIONES PARA VENTAS ///
                //ventas();
                system("pause"); return;

            case 0: /// SALIR ///
                return;

            default:
                cout << "Ingrese una opcion valida." << endl;
                system("pause"); system("cls");
                eleccion = mostrarMenuPrincipal();
                break;
        }
    }
}
