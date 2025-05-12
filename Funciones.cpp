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
    while (true){
        system("cls");
        int eleccion = menuPelicula ();
        switch (eleccion){
            case 1: // CREAR PELICULA
                crearPelicula();
                break;
            case 2: // LISTAR PELICULAS
                listarPeliculas();
                /// menuListarPelicula();
                break;
            case 3: // MODIFICAR PELICULAS
                modificarPelicula();
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
    system("cls");
    if (objetoPelicula.cargarConValidacion()){
        archivoPel.guardar(objetoPelicula);
        cout << "SE GUARDO CON EXITO!" << endl;
        system ("cls");
    }
    else {cout << "Se ha producido un error al grabar el registro. " << endl; system("pause");}
}

void modificarPelicula(){
    system("cls");
    ArchivoPelicula archivo("archivo/Peliculas.dat");
    int idBuscado;
    cout << "Ingrese el ID de la pelicula a modificar: ";
    cin >> idBuscado;
    int pos = archivo.buscarPorID(idBuscado);
    if (pos == -1) {
        cout << "No se encontró ninguna pelicula con ese ID." << endl;
        return;
    }

    Pelicula peli = archivo.leerRegistro(pos);
    cout << "Pelicula encontrada: " << endl;
    peli.mostrar();
    cout << endl;
    cout << "Ingrese los nuevos datos: " << endl;
    peli.cargarConValidacion(); // asi o hacer una función específica que permita modificar campo por campo
    peli.setId(idBuscado); // Asegura que conserve el mismo ID
    if (archivo.modificar(peli, pos)) {
        cout << "Pelicula modificada con éxito. " << endl;
    } else { cout << "Error al modificar la pelicula. " << endl;}
    system ("pause");
    system ("cls");
}

void borrarPelicula(){

}

/// ////////////////////// LISTAR //////////////////////

void listarPeliculas() {
    system("cls");
    while (true) {
        int eleccion = menuListarPelicula();
        switch (eleccion) {
            case 1: // LISTA TODAS
                listarTodasLasPeliculas();
                break;
            case 2: // POR ID
                listarPeliculaPorID();
                break;
            case 3: // POR NOMBRE
                listarPeliculaPorNombre();
                break;
            case 4: // POR DIRECTOR
                listarPeliculaPorDirector();
                break;
            case 5: // POR GENERO
                listarPeliculaPorGenero();
                break;
            case 6: // POR CLASIFICACION
                listarPeliculaPorClasificacion();
                break;
            case 7: // POR FECHA DE ESTRENO
                listarPeliculaPorFechaDeEstreno();
                break;
            case 0: // SALIR
                return;
            default: // OPCION INCORRECTA
                cout << "Ingrese una opcion correcta. " << endl;
                system("pause");
                system("cls");
                break;
        }
        system("pause");
        system("cls");
    }
}

int menuListarPelicula (){
    int opcion;
    cout << "=========================================" << endl;
    cout << "             LISTAR PELICULAS            " << endl;
    cout << "=========================================" << endl;
    cout << "1- Listar Todas las Peliculas" << endl;
    cout << "2- Listar por ID" << endl;
    cout << "3- Listar por Nombre" << endl;
    cout << "4- Listar por Director" << endl;
    cout << "5- Listar por Genero" << endl;
    cout << "6- Listar por Clasificacion" << endl;
    cout << "7- Listar por Fecha de Estreno" << endl;
    cout << "=========================================" << endl;
    cout << "0- Salir" << endl;
    cout << "=========================================" << endl;
    cout << "Elija una opcion: ";
    cin >> opcion;
    return opcion;
}

void listarTodasLasPeliculas(){
    system("cls");
    ArchivoPelicula archivoPel("archivo/Peliculas.dat");
    archivoPel.listarTodos();
}

void listarPeliculaPorID() {
    // Implementar lógica para buscar y mostrar una película por ID
}

void listarPeliculaPorNombre() {
    // Implementar lógica para buscar y mostrar una película por nombre
}

void listarPeliculaPorDirector() {
    // Implementar lógica para buscar y mostrar películas por director
}

void listarPeliculaPorGenero() {
    // Implementar lógica para buscar y mostrar películas por género
}

void listarPeliculaPorClasificacion() {
    // Implementar lógica para buscar y mostrar películas por clasificación
}

void listarPeliculaPorFechaDeEstreno() {
    // Implementar lógica para buscar y mostrar películas por fecha de estreno
}

/// ////////////////////// SALAS //////////////////////

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

/// ////////////////////// VENTA //////////////////////

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
