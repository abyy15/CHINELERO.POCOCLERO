#include <iostream>
#include <cstring>
#include "Funciones.h"
#include "Fecha.h"
#include "Peliculas.h"
#include "Sala.h"
#include "Venta.h"

using namespace std;

void cargarCadena(char *palabra, int tamano){
    int i=0;
    fflush(stdin);
    for (i=0; i<tamano; i++){
        palabra[i]=cin.get();
        if (palabra[i]=='\n'){
            break;
        }
    }
    palabra[i]='\0';
    fflush(stdin);
}

void menu (){
    while (true){
        system("cls");
        int eleccionUsuario = mostrarMenuPrincipal();
        switch (eleccionUsuario){
            case 1: /// OPCIONES PAEA PELICULAS ///
                pelicula();
                break;

            case 2: /// OPCIONES PARA SALAS ///
                salas();
                system("pause"); return;

            case 3: /// OPCIONES PARA VENTAS ///
                //ventas();
                system("pause"); return;

            case 0: /// SALIR ///
                return;

            default:
                cout << "Ingrese una opcion valida." << endl;
                system("pause"); system("cls");
                eleccionUsuario = mostrarMenuPrincipal();
                break;
        }
    }
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

void pelicula (){
    system("cls");
    while (true){
        int eleccion = menuPelicula ();
        switch (eleccion){
            case 1: // CREAR PELICULA
                //crearPelicula();
                break;
            case 2: // LISTAR PELICULAS
                //listarPelicula();
                break;
            case 3: // MODIFICAR PELICULAS
                //modificarPelicula();
                break;
            case 4: // BORRAR PELICULA
                //borrarPelicula();
                break;
            case 0: // SALIR
                return;
            default: // OPCION INCORRECTA
                cout << "Ingrese una opcion correcta. " << endl ;
                system ("pause"); system ("cls");
                break;
        }
    }
}

int menuPelicula (){
    int opcion;
    cout << "=========================================" << endl;
    cout << "                PELICULAS                " << endl;
    cout << "=========================================" << endl;
    cout << "1- Crear Pelicula" << endl;
    cout << "2- Listar Peliculas" << endl;
    cout << "3- Modificar Pelicula" << endl;
    cout << "4- Borrar Pelicula" << endl;
    cout << "=========================================" << endl;
    cout << "0- Salir" << endl;
    cout << "=========================================" << endl;
    cout << "Elija una opcion: ";
    cin >> opcion;
    return opcion;
}

void salas(){

}
