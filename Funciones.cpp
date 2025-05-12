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
                desabilitarPelicula();
                break;
            case 5: // ACTIVAR PELICULA
                activarPelicula();
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
    cout << "4- Desabilitar Pelicula" << endl;
    cout << "5- Activar Pelicula" << endl;
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

void desabilitarPelicula(){
    system("cls");
    ArchivoPelicula archivo("archivo/Peliculas.dat");
    int idBuscado;
    cout << "Ingrese el ID de la pelicula a desabilitar: ";
    cin >> idBuscado;
    int pos = archivo.buscarPorID(idBuscado);
    if (pos == -1) {
        cout << "No se encontró ninguna pelicula con ese ID." << endl;
        return;
    }
    Pelicula peli = archivo.leerRegistro(pos);
    cout << "Pelicula encontrada: " << endl;
    peli.mostrar();
    if (peli.getEstado()){ /// SI LA PELICULA ESTA ACTIVA, SE PUEDE DESABILITAR.
        cout << endl;
        cout << "Esta seguro que desea eliminar/desactivar la pelicula? S/N: ";
        string seg;
        cin >> seg;

        if (seg == "S" || seg == "s") {
            peli.setEstado(false);  // Desactiva la película
            ArchivoPelicula archivo("archivo/Peliculas.dat");
            int pos = archivo.buscarPorID(peli.getId());
            if (pos != -1) {
                archivo.modificar(peli, pos);  // Guardar cambios en el archivo
            }
            cout << "!La pelicula se desactivo correctamente!" << endl;
        }
    } else cout << "La pelicula ya se encuentra desabilitada." << endl; /// CASO CONTRARIO, NO.
    system ("pause");
    system ("cls");
}

void activarPelicula(){
    system("cls");
    ArchivoPelicula archivo("archivo/Peliculas.dat");
    int idBuscado;
    cout << "Ingrese el ID de la pelicula a activar: ";
    cin >> idBuscado;
    int pos = archivo.buscarPorID(idBuscado);
    if (pos == -1) {
        cout << "No se encontró ninguna pelicula con ese ID." << endl;
        return;
    }
    Pelicula peli = archivo.leerRegistro(pos);
    cout << "Pelicula encontrada: " << endl;
    peli.mostrar();
    if (peli.getEstado()) { /// SI LA PELICULA ESTA ACTIVA, NO SE PUEDE ACTIVAR.
        cout << "La pelicula ya se encuentra activa." << endl;
    } else {
        cout << "Esta seguro que desea activar la pelicula? S/N: ";
        string seg;
        cin >> seg;

        if (seg == "S" || seg == "s") {
            peli.setEstado(true);  // activa la película
            ArchivoPelicula archivo("archivo/Peliculas.dat");
            int pos = archivo.buscarPorID(peli.getId());
            if (pos != -1) {
                archivo.modificar(peli, pos);  // Guardar cambios en el archivo
            }
            cout << "!La pelicula se activo correctamente!" << endl;
        }
    }
    system ("pause");
    system ("cls");
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
                listarID();
                break;
            case 3: // POR NOMBRE
                listarNombre();
                break;
            case 4: // POR DIRECTOR
                listarDirector();
                break;
            case 5: // POR GENERO
                listarGenero();
                break;
            case 6: // POR CLASIFICACION
                listarClasificacion();
                break;
            case 7: // POR FECHA DE ESTRENO
                listarFechaDeEstreno();
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

void listarID() {
    system ("cls");
    ArchivoPelicula archivo("archivo/Peliculas.dat");
    int idBuscado;
    cout << "=========================================" << endl;
    cout << "               LISTAR POR ID             " << endl;
    cout << "=========================================" << endl;
    cout << "Ingrese la id a listar: " ;
    cin >> idBuscado;

    int pos = archivo.buscarPorID(idBuscado);
    if (pos == -1) {
        cout << "No se encontró ninguna pelicula con ese ID." << endl;
        return;
    }

    Pelicula peli = archivo.leerRegistro(pos);
    cout << "Pelicula encontrada: " << endl;
    peli.mostrar();

}

void listarNombre() {
    system("cls");
    ArchivoPelicula archivo("archivo/Peliculas.dat");
    char nombre[100];
    cout << "=========================================" << endl;
    cout << "           LISTAR POR NOMBRE             " << endl;
    cout << "=========================================" << endl;
    cout << "Ingrese el nombre de la pelicula a buscar: ";
    cargarCadena(nombre, 100);

    int pos = archivo.buscarPorNombre(nombre);
    if (pos == -1) {
        cout << "No se encontró ninguna pelicula con ese nombre." << endl;
        return;
    }

    Pelicula peli = archivo.leerRegistro(pos);
    cout << "Pelicula encontrada:" << endl;
    peli.mostrar();
}

void listarDirector() {
    system("cls");
    ArchivoPelicula archivo("archivo/Peliculas.dat");
    char director[100];

    cout << "=========================================" << endl;
    cout << "         LISTAR POR DIRECTOR             " << endl;
    cout << "=========================================" << endl;
    cout << "Ingrese el nombre del director: ";
    cargarCadena(director, 100);

    int pos = archivo.buscarPorDirector(director);
    if (pos == -1) {
        cout << "No se encontró ninguna película con ese director." << endl;
        return;
    }

    Pelicula peli = archivo.leerRegistro(pos);
    cout << "Pelicula encontrada:" << endl;
    peli.mostrar();
}

void listarGenero() {
    system("cls");
    ArchivoPelicula archivo("archivo/Peliculas.dat");
    char genero[100];

    cout << "=========================================" << endl;
    cout << "           LISTAR POR GENERO             " << endl;
    cout << "=========================================" << endl;
    cout << "Ingrese el genero: ";
    cargarCadena(genero, 100);

    int pos = archivo.buscarPorGenero(genero);
    if (pos == -1) {
        cout << "No se encontró ninguna película con ese género." << endl;
        return;
    }

    Pelicula peli = archivo.leerRegistro(pos);
    cout << "Pelicula encontrada:" << endl;
    peli.mostrar();
}

void listarClasificacion() {
    system("cls");
    ArchivoPelicula archivo("archivo/Peliculas.dat");
    int clasificacionBuscada;

    cout << "=========================================" << endl;
    cout << "           LISTAR POR CLASIFICACION      " << endl;
    cout << "=========================================" << endl;
    cout << "Ingrese la clasificación (1: ATP, 2: +14, 3: +18): ";
    cin >> clasificacionBuscada;

    // Validar que la clasificación sea válida
    while (clasificacionBuscada < 1 || clasificacionBuscada > 3) {
        cout << "Clasificación inválida, ingrese nuevamente: ";
        cin >> clasificacionBuscada;
    }

    int pos = archivo.buscarPorClasificacion(clasificacionBuscada);
    if (pos == -1) {
        cout << "No se encontró ninguna película con esa clasificación." << endl;
        return;
    }

    Pelicula peli = archivo.leerRegistro(pos);
    cout << "Pelicula encontrada:" << endl;
    peli.mostrar();
}

void listarFechaDeEstreno() {
    system("cls");
    ArchivoPelicula archivo("archivo/Peliculas.dat");
    Fecha fechaBuscada;

    cout << "=========================================" << endl;
    cout << "           LISTAR POR FECHA DE ESTRENO  " << endl;
    cout << "=========================================" << endl;
    cout << "Ingrese la fecha de estreno (dd/mm/yyyy): ";
    fechaBuscada.cargar();

    int pos = archivo.buscarPorFechaEstreno(fechaBuscada);
    if (pos == -1) {
        cout << "No se encontró ninguna película con esa fecha de estreno." << endl;
        return;
    }

    Pelicula peli = archivo.leerRegistro(pos);
    cout << "Pelicula encontrada:" << endl;
    peli.mostrar();
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
