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


/// ////////////////////// MENU PRINCIPAL //////////////////////

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
                break;

            case 3: /// OPCIONES PARA VENTAS ///
                venta();
                break;

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


/// ////////////////////// PELICULAS //////////////////////


void pelicula (){
    system("cls");
    while (true){
        int eleccion = menuPelicula ();
        switch (eleccion){
            case 1: // CREAR PELICULA
                crearPelicula();
                break;
            case 2: // LISTAR PELICULAS
                system("cls");
                listarPeliculas();
                system("pause");
                system("cls");
                /// menuListarPelicula();
                break;
            case 3: // MODIFICAR PELICULAS
                /// modificarPelicula();
                break;
            case 4: // BORRAR PELICULA
                /// borrarPelicula();
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

void crearPelicula(){
    Pelicula objetoPelicula;
    ArchivoPelicula archivoPel("archivo/Peliculas.dat");
    if (objetoPelicula.cargarConValidacion()){archivoPel.guardar(objetoPelicula);}
    else {cout << "Se ha producido un error al grabar el registro. " << endl; system("pause");}
}

void listarPeliculas(){
    ArchivoPelicula archivoPel("archivo/Peliculas.dat");
    archivoPel.listarTodos();
}

void salas(){
    system("cls");
    while (true){
        int eleccion = menuSalas();
        switch (eleccion){
            case 1: // CREAR SALA
                //crearSala();
                break;
            case 2: // LISTAR SALA
                //listarSala();
                break;
            case 3: // MODIFICAR SALA
                //modificarSala();
                break;
            case 4: // BORRAR SALA
                //borrarSala();
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


/// ////////////////////// SALAS //////////////////////


int menuSalas(){
    int opcion;
    cout << "=========================================" << endl;
    cout << "                  SALAS                  " << endl;
    cout << "=========================================" << endl;
    cout << "1- Crear Sala" << endl;
    cout << "2- Listar Sala" << endl;
    cout << "3- Modificar Sala" << endl;
    cout << "4- Borrar Sala" << endl;
    cout << "=========================================" << endl;
    cout << "0- Salir" << endl;
    cout << "=========================================" << endl;
    cout << "Elija una opcion: ";
    cin >> opcion;
    return opcion;
}

void venta (){
    system("cls");
    while (true){
        int eleccion = menuSalas();
        switch (eleccion){
            case 1: // CREAR VENTA
                //crearVenta();
            case 2: // LISTAR VENTA
                break;
                //listarVenta();
                break;
            case 3: // MODIFICAR VENTA
                //modificarVenta();
                break;
            case 4: // BORRAR VENTA
                //borrarVenta();
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

int menuVenta(){
    int opcion;
    cout << "=========================================" << endl;
    cout << "                  VENTAS                 " << endl;
    cout << "=========================================" << endl;
    cout << "1- Crear Venta" << endl;
    cout << "2- Listar Ventas" << endl;
    cout << "3- Modificar Venta" << endl;
    cout << "4- Borrar Venta" << endl;
    cout << "=========================================" << endl;
    cout << "0- Salir" << endl;
    cout << "=========================================" << endl;
    cout << "Elija una opcion: ";
    cin >> opcion;
    return opcion;
}
