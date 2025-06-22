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
                ventas();
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
                desactivarPelicula();
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
    cout << "4- Desactivar Pelicula" << endl;
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

/// MODIFICAR PELICULAS

void modificarPelicula(){
   system("cls");
    while (true) {
        int eleccion = menuModificarPeli();
        switch (eleccion) {
            case 1: // MODIFICA TODO
                modTodoPel();
                break;
            case 2:
                modNombrePel();
                break;
            case 3:
                modDirector();
                break;
            case 4:
                modGenero();
                break;
            case 5:
                modClasificacion();
                break;
            case 6:
                modFechaDeEstreno();
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

int menuModificarPeli(){
    int opcion;
    cout << "=========================================" << endl;
    cout << "            MODIFICAR PELICULAS          " << endl;
    cout << "=========================================" << endl;
    cout << "1- Modificar todos los campos" << endl;
    cout << "2- Modificar Nombre" << endl;
    cout << "3- Modificar Director" << endl;
    cout << "4- Modificar Genero" << endl;
    cout << "5- Modificar Clasificacion" << endl;
    cout << "6- Modificar Fecha de Estreno" << endl;
    cout << "=========================================" << endl;
    cout << "0- Salir" << endl;
    cout << "=========================================" << endl;
    cout << "Elija una opcion: ";
    cin >> opcion;
    return opcion;
}

void modTodoPel (){
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
        cout << "Pelicula modificada con exito. " << endl;
    } else { cout << "Error al modificar la pelicula. " << endl;}
    system ("pause");
    system ("cls");
}

void modNombrePel() {
    system("cls");
    ArchivoPelicula archivo("archivo/Peliculas.dat");
    int idBuscado;
    cout << "Ingrese el ID de la pelicula a modificar: ";
    cin >> idBuscado;
    int pos = archivo.buscarPorID(idBuscado);
    if (pos == -1) {
        cout << "No se encontro ninguna pelicula con ese ID." << endl;
        return;
    }

    Pelicula peli = archivo.leerRegistro(pos);
    cout << "Nombre actual: " << peli.getNombre() << endl;

    char nuevoNombre[50];
    cout << "Ingrese el nuevo nombre: ";
    cargarCadena(nuevoNombre, 50);
    peli.setNombre(nuevoNombre);

    if (archivo.modificar(peli, pos)) {
        cout << "Nombre modificado con exito." << endl;
    } else {
        cout << "Error al modificar el nombre." << endl;
    }
}

void modDirector() {
    system("cls");
    ArchivoPelicula archivo("archivo/Peliculas.dat");
    int idBuscado;
    cout << "Ingrese el ID de la pelicula a modificar: ";
    cin >> idBuscado;
    int pos = archivo.buscarPorID(idBuscado);
    if (pos == -1) {
        cout << "No se encontro ninguna pelicula con ese ID." << endl;
        return;
    }

    Pelicula peli = archivo.leerRegistro(pos);
    cout << "Director actual: " << peli.getDirector() << endl;

    char nuevoDirector[50];
    cout << "Ingrese el nuevo director: ";
    cargarCadena(nuevoDirector, 50);
    peli.setDirector(nuevoDirector);

    if (archivo.modificar(peli, pos)) {
        cout << "Director modificado con exito." << endl;
    } else {
        cout << "Error al modificar el director." << endl;
    }
}

void modGenero() {
    system("cls");
    ArchivoPelicula archivo("archivo/Peliculas.dat");
    int idBuscado;
    cout << "Ingrese el ID de la pelicula a modificar: ";
    cin >> idBuscado;
    int pos = archivo.buscarPorID(idBuscado);
    if (pos == -1) {
        cout << "No se encontro ninguna pelicula con ese ID." << endl;
        return;
    }

    Pelicula peli = archivo.leerRegistro(pos);
    cout << "Genero actual: " << peli.getGenero() << endl;

    char nuevoGenero[30];
    cout << "Ingrese el nuevo genero: ";
    cargarCadena(nuevoGenero, 30);
    peli.setGenero(nuevoGenero);

    if (archivo.modificar(peli, pos)) {
        cout << "Genero modificado con exito." << endl;
    } else {
        cout << "Error al modificar el genero." << endl;
    }
}

void modClasificacion() {
    system("cls");
    ArchivoPelicula archivo("archivo/Peliculas.dat");
    int idBuscado;
    cout << "Ingrese el ID de la pelicula a modificar: ";
    cin >> idBuscado;
    int pos = archivo.buscarPorID(idBuscado);
    if (pos == -1) {
        cout << "No se encontro ninguna pelicula con ese ID." << endl;
        return;
    }

    Pelicula peli = archivo.leerRegistro(pos);
    cout << "Clasificacion actual: " << peli.getClasificacion() << endl;

    int nuevaClasificacion;
    cout << "Ingrese la nueva clasificacion (1: ATP, 2: +14, 3: +18): ";
    cin >> nuevaClasificacion;
    if (nuevaClasificacion >= 1 && nuevaClasificacion <= 3) {
        peli.setClasificacion(nuevaClasificacion);
    } else {
        cout << "Clasificacion invalida. No se modifico." << endl;
        return;
    }

    if (archivo.modificar(peli, pos)) {
        cout << "Clasificacion modificada con exito." << endl;
    } else {
        cout << "Error al modificar la clasificacion." << endl;
    }
}

void modFechaDeEstreno() {
    system("cls");
    ArchivoPelicula archivo("archivo/Peliculas.dat");
    int idBuscado;
    cout << "Ingrese el ID de la pelicula a modificar: ";
    cin >> idBuscado;
    int pos = archivo.buscarPorID(idBuscado);
    if (pos == -1) {
        cout << "No se encontro ninguna pelicula con ese ID." << endl;
        return;
    }

    Pelicula peli = archivo.leerRegistro(pos);
    cout << "Fecha actual de estreno: ";
    peli.getFechaEstreno().mostrar(); // o mostrarFecha() si lo tenes asi
    cout << "Ingrese la nueva fecha:" ;

    Fecha nuevaFecha;
    nuevaFecha.cargar(); // asumimos que Fecha tiene metodo cargar()

    peli.setFechaEstreno(nuevaFecha);

    if (archivo.modificar(peli, pos)) {
        cout << "Fecha de estreno modificada con exito." << endl;
    } else {
        cout << "Error al modificar la fecha." << endl;
    }
}

/// DESACTIVAR / ACTIVAR PELICULA

void desactivarPelicula(){
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
        cout << "No se encontro ninguna pelicula con ese ID." << endl;
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

/// LISTAR

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
        cout << "No se encontro ninguna pelicula con ese ID." << endl;
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
        cout << "No se encontro ninguna pelicula con ese nombre." << endl;
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
        cout << "No se encontro ninguna pelicula con ese director." << endl;
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
        cout << "No se encontro ninguna pelicula con ese genero." << endl;
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
        cout << "No se encontro ninguna pelicula con esa clasificación." << endl;
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
        cout << "No se encontro ninguna pelicula con esa fecha de estreno." << endl;
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
                crearSala();
                break;
            case 2: // LISTAR SALA
                listarSala();
                break;
            case 3: // MODIFICAR SALA
                modificarSala();
                break;
            case 4: // DESABILITAR/ELIMINAR SALA
                desactivarSala();
                break;
            case 5: // ACTIVAR SALA
                activarSala();
                break;
            case 0: // SALIR
                return;
            default: // OPCION INCORRECTA
                cout << "Ingrese una opcion correcta. " << endl ;
                system ("pause"); system ("cls");
                break;
        }
        system("cls");
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
    cout << "4- Desactivar Sala" << endl;
    cout << "5- Activar Sala" << endl;
    cout << "=========================================" << endl;
    cout << "0- Salir" << endl;
    cout << "=========================================" << endl;
    cout << "Elija una opcion: ";
    cin >> opcion;
    return opcion;
}

void crearSala(){
    Sala objSala;
    ArchivoSala archivoSala ("archivo/Salas.dat");
    system("cls");
    objSala.cargar();
    archivoSala.guardar(objSala);
    cout << "SE GUARDO CON EXITO!" << endl;
    system ("cls");
}

void listarSala(){
    system("cls");
    ArchivoSala archivoSala("archivo/Salas.dat");
    archivoSala.listarTodos();
    system ("pause");
    system ("cls");
}

/// MODIFICAR SALAS

void modificarSala(){
   system("cls");
    while (true) {
        int eleccion = menuModificarSala();
        switch (eleccion) {
            case 1: // MODIFICA TODO
                modTodoSala();
                break;
            case 2:
                modNumSala();
                break;
            case 3:
                modNombreSala();
                break;
            case 4:
                modTipoSala();
                break;
            case 5:
                modCantButSala();
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

int menuModificarSala(){
    int opcion;
    cout << "=========================================" << endl;
    cout << "              MODIFICAR SALAS            " << endl;
    cout << "=========================================" << endl;
    cout << "1- Modificar todos los campos" << endl;
    cout << "2- Modificar Numero" << endl;
    cout << "3- Modificar Nombre" << endl;
    cout << "4- Modificar Tipo" << endl;
    cout << "5- Modificar Cantidad de Butacas Disponibles" << endl;
    cout << "=========================================" << endl;
    cout << "0- Salir" << endl;
    cout << "=========================================" << endl;
    cout << "Elija una opcion: ";
    cin >> opcion;
    return opcion;
}

void modTodoSala(){
    system("cls");
    ArchivoSala archivoSala("archivo/Salas.dat");
    int numBuscado;
    cout << "Ingrese el numero de la sala a modificar: ";
    cin >> numBuscado;
    int pos = archivoSala.buscarPorNum(numBuscado);
    if (pos == -1) {
        cout << "No se encontro ninguna sala con ese numero." << endl;
        return;
    }

    Sala sala  = archivoSala.leerRegistro(pos);
    cout << "Sala encontrada: " << endl;
    sala.mostrar();
    cout << endl;
    cout << "Ingrese los nuevos datos: " << endl;
    sala.cargar();
    sala.setNumSala(numBuscado); // Asegura que conserve el mismo ID
    if (archivoSala.modificar(sala, pos)) {
        cout << "Sala modificada con exito. " << endl;
    } else { cout << "Error al modificar la sala. " << endl;}
    system ("pause");
    system ("cls");
}

void modNumSala(){
    system("cls");
    ArchivoSala archivo("archivo/Salas.dat");
    int numBuscado;
    cout << "Ingrese el numero de la sala a modificar: ";
    cin >> numBuscado;
    int pos = archivo.buscarPorNum(numBuscado);
    if (pos == -1) {
        cout << "No se encontro ninguna sala con ese numero." << endl;
        return;
    }

    Sala sala = archivo.leerRegistro(pos);
    cout << "Numero actual: " << sala.getNumSala() << endl;

    int nuevoNum;
    cout << "Ingrese el nuevo numero: ";
    cin >> nuevoNum;
    sala.setNumSala(nuevoNum);

    if (archivo.modificar(sala, pos)) {
        cout << "Numero modificado con exito." << endl;
    } else {
        cout << "Error al modificar el numero." << endl;
    }
}

void modNombreSala(){
    system("cls");
    ArchivoSala archivo("archivo/Salas.dat");
    int numBuscado;
    cout << "Ingrese el numero de la sala a modificar: ";
    cin >> numBuscado;
    int pos = archivo.buscarPorNum(numBuscado);
    if (pos == -1) {
        cout << "No se encontro ninguna sala con ese numero." << endl;
        return;
    }

    Sala sala = archivo.leerRegistro(pos);
    cout << "Nombre actual: " << sala.getNombreSala() << endl;

    char nuevoNombre[50];
    cout << "Ingrese el nuevo nombre: ";
    cargarCadena(nuevoNombre, 50);
    sala.setNombreSala(nuevoNombre);

    if (archivo.modificar(sala, pos)) {
        cout << "Nombre modificado con exito." << endl;
    } else {
        cout << "Error al modificar el nombre." << endl;
    }
}

void modTipoSala(){
    system("cls");
    ArchivoSala archivo("archivo/Salas.dat");
    int numBuscado;
    cout << "Ingrese el numero de la sala a modificar: ";
    cin >> numBuscado;
    int pos = archivo.buscarPorNum(numBuscado);
    if (pos == -1) {
        cout << "No se encontro ninguna sala con ese numero." << endl;
        return;
    }

    Sala sala = archivo.leerRegistro(pos);
    char ts [30];
    sala.tipoDeSala (sala.getTipoSala(), ts);
    cout << "Tipo actual: " << ts << endl;

    int nuevoTipo;
    cout << "Ingrese el nuevo Tipo de Sala (1-Estandar 2- Premium 3- Confort Plus): ";
    while (true){
            cin >> nuevoTipo;
            if (nuevoTipo > 3 || nuevoTipo < 1) {
                system("cls");
                cout << "Ingrese un numero valido. " << endl;
                sala.menuSala (); }
            else break;}
    sala.setTipoSala(nuevoTipo);
    if (archivo.modificar(sala, pos)) {
        cout << "Tipo modificado con exito." << endl;
    } else {
        cout << "Error al modificar el tipo de sala." << endl;
    }
    system("pause");
    system("cls");
}

void modCantButSala(){
    system("cls");
    ArchivoSala archivo("archivo/Salas.dat");
    int numBuscado;
    cout << "Ingrese el numero de la sala a modificar: ";
    cin >> numBuscado;
    int pos = archivo.buscarPorNum(numBuscado);
    if (pos == -1) {
        cout << "No se encontro ninguna sala con ese numero." << endl;
        return;
    }

    Sala sala = archivo.leerRegistro(pos);
    cout << "Cantidad actual de butacas disponibles: " << sala.getButacasDisponibles() << endl;

    int nuevoNum;
    cout << "Ingrese la nueva cantidad: ";
    cin >> nuevoNum;
    sala.setButacasDisponibles(nuevoNum);

    if (archivo.modificar(sala, pos)) {
        cout << "Cantidad modificada con exito." << endl;
    } else {
        cout << "Error al modificar la cantidad." << endl;
    }
}

/// DESABILITAR / ACTIVAR SALA /// SIN CREAR PROPIEDAD ESTADO EN LA CLASE SALA

void desactivarSala(){
    system("cls");
    ArchivoSala archivo("archivo/Salas.dat");
    int numBuscado;
    cout << "Ingrese el numero de la sala a desabilitar: ";
    cin >> numBuscado;
    int pos = archivo.buscarPorNum(numBuscado);
    if (pos == -1) {
        cout << "No se encontró ninguna sala con ese numero." << endl;
        return;
    }
    Sala sala = archivo.leerRegistro(pos);
    cout << "Sala encontrada: " << endl;
    sala.mostrar();
    if (sala.getEstado()){ /// SI LA SALA ESTA ACTIVA, SE PUEDE DESABILITAR.
        cout << endl;
        cout << "Esta seguro que desea eliminar/desactivar la sala? S/N: ";
        string seg;
        cin >> seg;

        if (seg == "S" || seg == "s") {
            sala.setEstado(false);  // Desactiva la película
            ArchivoSala archivo("archivo/Salas.dat");
            int pos = archivo.buscarPorNum(sala.getNumSala());
            if (pos != -1) {
                archivo.modificar(sala, pos);  // Guardar cambios en el archivo
            }
            cout << "!La sala se desactivo correctamente!" << endl;
        }
    } else cout << "La sala ya se encuentra desabilitada." << endl; /// CASO CONTRARIO, NO.
    system ("pause");
    system ("cls");
}

void activarSala(){
    system("cls");
    ArchivoSala archivo("archivo/Salas.dat");
    int numBuscado;
    cout << "Ingrese el numero de la sala a activar: ";
    cin >> numBuscado;
    int pos = archivo.buscarPorNum(numBuscado);
    if (pos == -1) {
        cout << "No se encontró ninguna sala con ese numero." << endl;
        return;
    }
    Sala sala = archivo.leerRegistro(pos);
    cout << "Sala encontrada: " << endl;
    sala.mostrar();
    if (sala.getEstado()) { /// SI LA SALA ESTA ACTIVA, NO SE PUEDE ACTIVAR.
        cout << "La sala ya se encuentra activa." << endl;
    } else {
        cout << "Esta seguro que desea activar la sala? S/N: ";
        string seg;
        cin >> seg;

        if (seg == "S" || seg == "s") {
            sala.setEstado(true);  // activa la sala
            ArchivoSala archivo("archivo/Salas.dat");
            int pos = archivo.buscarPorNum(sala.getNumSala());
            if (pos != -1) {
                archivo.modificar(sala, pos);  // Guardar cambios en el archivo
            }
            cout << "!La sala se activo correctamente!" << endl;
        }
    }
    system ("pause");
    system ("cls");
}

/// ////////////////////// VENTA //////////////////////

void ventas (){
    system("cls");
    while (true){
        int eleccion = menuVenta();
        switch (eleccion){
            case 1: // CREAR VENTA
                crearVenta();
                break;
            case 2: // LISTAR VENTA
                listarVenta();
                break;
            case 3: // MODIFICAR VENTA
                modificarVenta();
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

void crearVenta(){
    Venta objVenta;
    ArchivoVenta archivoVenta ("archivo/Ventas.dat");
    system("cls");
    objVenta.cargarConValidacion();
    archivoVenta.guardar(objVenta);
    cout << "SE GUARDO CON EXITO!" << endl;
    system ("cls");
}

void listarVenta(){
    system("cls");
    ArchivoVenta archivoventa("archivo/Ventas.dat");
    archivoventa.listarTodos();
    system ("pause");
    system ("cls");
}

void modificarVenta(){
    system("cls");
    while (true) {
        int eleccion = menuModificarVenta();
        switch (eleccion) {
            case 1: // MODIFICA TODO
                modTodoVenta();
                break;
            case 2:
                modidVenta();
                break;
            case 3:
                modidPeliculaVenta();
                break;
            case 4:
                //modNumSalaVenta();
                break;
            case 5:
                //modCantEntradaVenta();
                break;
            case 6:
                //modMontoTotalVenta();
                break;
            case 7:
                //modFechaVenta();
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

int menuModificarVenta(){
    int opcion;
    cout << "=========================================" << endl;
    cout << "             MODIFICAR VENTAS            " << endl;
    cout << "=========================================" << endl;
    cout << "1- Modificar todos los campos" << endl;
    cout << "2- Modificar ID Venta" << endl;
    cout << "3- Modificar ID Pelicula" << endl;
    cout << "4- Modificar Numero de sala" << endl;
    cout << "5- Modificar Cantidad de Entradas" << endl;
    cout << "6- Modificar Monto Total" << endl;
    cout << "7- Modificar Fecha de Venta" << endl;
    cout << "=========================================" << endl;
    cout << "0- Salir" << endl;
    cout << "=========================================" << endl;
    cout << "Elija una opcion: ";
    cin >> opcion;
    return opcion;
}

void modTodoVenta() {
    system ("cls");
    ArchivoVenta archivo("archivo/Ventas.dat");
    int idVenta;
    cout << "Ingrese el ID de la venta que desea modificar: ";
    cin >> idVenta;

    int total = archivo.contarRegistros();
    for (int i = 0; i < total; i++) {
        Venta venta = archivo.leerRegistro(i);
        if (venta.getIdVenta() == idVenta) {
            cout << "Registro encontrado: "<< endl;
            venta.mostrar();
            cout << endl;
            cout << "Ingrese los nuevos datos para la venta: " << endl;

            Venta nuevaVenta;
            nuevaVenta.setIdVenta(idVenta);  // mantenemos el mismo ID
            nuevaVenta.cargarConValidacion();  // tu método para cargar con validación

            archivo.modificar(nuevaVenta, i);
            cout << "=========================================" << endl;
            cout << "Venta modificada con éxito." << endl;
            return;
        }
    }

    cout << "No se encontró una venta con ese ID.\n";
}

void modidVenta() {
    ArchivoVenta archivo("archivo/Ventas.dat");
    int idVenta;
    cout << "Ingrese el ID actual de la venta a modificar: ";
    cin >> idVenta;

    int total = archivo.contarRegistros();
    for (int i = 0; i < total; i++) {
        Venta venta = archivo.leerRegistro(i);
        if (venta.getIdVenta() == idVenta) {
            int nuevoId;
            cout << "ID actual: " << venta.getIdVenta() << endl;
            cout << "Ingrese el nuevo ID: ";
            cin >> nuevoId;
            venta.setIdVenta(nuevoId);
            archivo.modificar(venta, i);
            cout << "ID de la venta modificado con éxito." << endl;
            return;
        }
    }

    cout << "No se encontró una venta con ese ID." << endl ;
}

void modidPeliculaVenta() {
    system("cls");
    ArchivoVenta archivoVenta("archivo/Ventas.dat");
    ArchivoPelicula archivoPelicula("archivo/Peliculas.dat");
    int idVenta;
    cout << "Ingrese el ID de la venta a modificar: ";
    cin >> idVenta;

    int total = archivoVenta.contarRegistros();
    for (int i = 0; i < total; i++) {
        Venta venta = archivoVenta.leerRegistro(i);
        if (venta.getIdVenta() == idVenta) {
            int idPeliculaActual = venta.getIdPelicula();
            int posPeli = archivoPelicula.buscarPorID(idPeliculaActual);

            cout << "=========================================" << endl;
            cout << "PELICULA ACTUAL DE LA VENTA: " << endl;
            cout << "=========================================" << endl;

            if (posPeli != -1) {
                Pelicula pelicula = archivoPelicula.leerRegistro(posPeli);
                pelicula.mostrar();
            } else {
                cout << "No se encontro la pelicula actual (ID: " << idPeliculaActual << ")" << endl;
            }

            cout << "=========================================" << endl;
            cout << "           LISTA DE PELICULAS            " << endl;
            cout << "=========================================" << endl;
            archivoPelicula.listarTodos();
            int nuevoIdPelicula;
            cout << "Ingrese el nuevo ID de pelicula: ";
            cin >> nuevoIdPelicula;

            venta.setIdPelicula(nuevoIdPelicula);
            archivoVenta.modificar(venta, i);

            cout << "=========================================" << endl;
            cout << "ID de pelicula modificado con éxito." << endl;
            return;
        }
    }

    cout << "No se encontro una venta con ese ID." << endl;
}
