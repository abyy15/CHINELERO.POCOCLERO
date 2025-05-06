#include <iostream>
#include "funcion.h"

using namespace std;


int mostrarMenuPrincipal(){
    int eleccion;
    cout << "================================" << endl;
    cout << "======CHINELERO - POCOCLERO=====" << endl;
    cout << "================================" << endl;
    cout << "(1) Primer opcion jaja" << endl;
    cout << "(2) Segunda opcion jaja" << endl;
    cout << "(3) Tercera opcion jaja" << endl;
    cout << "================================" << endl;
    cout << "(0) SALIR." << endl;
    cout << "================================" << endl;
    cout << "Elija una opcion: ";
    cin >> eleccion;
    return eleccion;
}

void switchMenu(int eleccion){
    while (true){
        switch (eleccion)
        {
        case 1:
            /// PRIMERA OPCION ///
            system("cls");
            cout << "Eligio la primera opcion." << endl;
            system("pause");
            return;

        case 2:
            system("cls");
            /// SEGUNDA OPCION ///
            cout << "Eligio la segunda opcion." << endl;
            system("pause");
            return;

        case 3:
            system("cls");
            cout << "Eligio la tercera opcion." << endl;
            system("pause");
            /// TERCERA OPCION ///
            return;

        /// CASO PARA SALIR ///
        case 0:
            return;

///     ///////////////////////

        default:
            system("cls");
            cout << "Ingrese una opcion valida." << endl;
            system("pause");
            system("cls");
            eleccion = mostrarMenuPrincipal();
            break;
        }
    }
}
