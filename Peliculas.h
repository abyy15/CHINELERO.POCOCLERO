#pragma once
#include <iostream>
#include "Fecha.h"
using namespace std;

class Pelicula {
    private:
        int id;
        char nombre [100];
        char director [100];
        char genero [100];
        int clasificacion; // 1: ATP, 2: +14, 3: +18
        Fecha fechaEstreno; // Objeto Fecha
        bool estado = true;
    public:
        /* void cargar() {
            cout << "ID de la pelicula: ";
            cin >> id;
            cin.ignore();
            cout << "Nombre de la pelicula: ";
            cargarCadena(nombre, 99);
            cout << "Director (Apellido y Nombre): ";
            cargarCadena(director, 99);
            cout << "Genero: ";
            cargarCadena(genero, 99);
            cout << "Clasificacion (1: ATP, 2: +14, 3: +18): ";
            cin >> clasificacion;
            cout << "Fecha de estreno:\n";
            fechaEstreno.cargar();
        }*/

        bool cargarConValidacion();

        void mostrar(){
            cout << "ID: " << id << endl;
            cout << "Nombre: " << nombre << endl;
            cout << "Director: " << director << endl;
            cout << "Genero: " << genero << endl;
            cout << "Clasificacion: ";
            switch (clasificacion) {
                case 1: cout << "ATP"; break;
                case 2: cout << "Mayores de 14"; break;
                case 3: cout << "Mayores de 18"; break;
                default: cout << "Desconocida"; break;
            }
            cout << endl;
            cout << "Fecha de estreno: ";
            fechaEstreno.mostrar();
            cout << endl;
            cout << "Estado: " << (estado ? "Activo" : "Desactivado") << endl;
        }

        // GETTERS
        int getId() { return id; }
        char* getNombre() { return nombre; }
        char* getDirector() { return director; }
        char* getGenero() { return genero; }
        int getClasificacion() { return clasificacion; }
        Fecha getFechaEstreno() { return fechaEstreno; }
        bool getEstado() { return estado; }

        //SETTERS
        void setId(int _id) { id = _id; }
        void setNombre(const char* _nombre) { strncpy(nombre, _nombre, sizeof(nombre)-1); }
        void setDirector(const char* _director) { strncpy(director, _director, sizeof(director)-1); }
        void setGenero(const char* _genero) { strncpy(genero, _genero, sizeof(genero)-1); }
        void setClasificacion(int _clasificacion) { clasificacion = _clasificacion; }
        void setFechaEstreno(const Fecha& _fechaEstreno) { fechaEstreno = _fechaEstreno; }
        void setEstado(bool e) { estado = e; }
};

class ArchivoPelicula {
    private:
        char nombreArchivo[100];
    public:
        ArchivoPelicula(const char* nombre) {
            strncpy(nombreArchivo, nombre, 99);
            nombreArchivo[49] = '\0';
        }

        bool guardar(const Pelicula& p) {
            FILE* f = fopen(nombreArchivo, "ab");
            if (f == nullptr) return false;
            bool ok = fwrite(&p, sizeof(Pelicula), 1, f);
            fclose(f);
            return ok;
        }

        Pelicula leerRegistro(int pos) {
        Pelicula reg;
        FILE* p = fopen(nombreArchivo, "rb");
        if (p == nullptr) return reg;
        fseek(p, pos * sizeof(Pelicula), SEEK_SET);
        fread(&reg, sizeof(Pelicula), 1, p);
        fclose(p);
        return reg;
        }

        bool modificar(const Pelicula& p, int pos) {
            FILE* f = fopen(nombreArchivo, "rb+");
            if (f == nullptr) return false;
            fseek(f, pos * sizeof(Pelicula), SEEK_SET);
            bool ok = fwrite(&p, sizeof(Pelicula), 1, f);
            fclose(f);
            return ok;
        }

        int contarRegistros() {
            FILE* f = fopen(nombreArchivo, "rb");
            if (f == nullptr) {/*cout << "SE ABRIO MAL EL ARCHIVO EN CONTAR REGISTROS" << endl;*/ return 0;}
            fseek(f, 0, SEEK_END);
            int tam = ftell(f);
            fclose(f);
            int cantidad = 0;
            cantidad = tam / (sizeof (Pelicula));
            return cantidad; /// PARECE ESTAR RETORNANDO 0. Testear despues.
        }

        void listarTodos() {
            Pelicula p;
            FILE* f = fopen(nombreArchivo, "rb");
            if (f == nullptr) {
                cout << "No se pudo abrir el archivo.\n";
                return;
            }
            while (fread(&p, sizeof(Pelicula), 1, f) == 1) {
                p.mostrar();
                cout << "----------------------------\n";
            }
            fclose(f);
        }

        int buscarPorID(int idBuscado) { //imprimir bitcoin
            Pelicula p;
            FILE* f = fopen(nombreArchivo, "rb");
            if (f == nullptr) return -1;

            int pos = 0;
            while (fread(&p, sizeof(Pelicula), 1, f) == 1) {
                if (p.getId() == idBuscado) {
                    fclose(f);
                    return pos;
                }
                pos++;
            }
            fclose(f);
            return -1; // no encontrado
        }
};

bool Pelicula :: cargarConValidacion(){
    ArchivoPelicula archivoPel("archivo/Peliculas.dat");
    int cantidadRegistros = 0;
    cantidadRegistros = archivoPel.contarRegistros();
    //cout << "Los registros contados son: " << cantidadRegistros << endl;
    id = cantidadRegistros + 1;
    //cout << "La ID sera: " << id << endl;
    cout << "NOMBRE DE LA PELICULA: ";
    cargarCadena(nombre, 100);
    while (strlen(nombre) == 0){
        system("cls");
        cout << "La pelicula debe contener un nombre. " << endl;
        system("pause");
        system("cls");
        cout << "NOMBRE DE LA PELICULA: ";
        cargarCadena(nombre, 100);
    }
    cout << "DIRECTOR: ";
    cargarCadena(director, 100);
    while (strlen(director) == 0){
        system("cls");
        cout << "La pelicula debe tener un director. " << endl;
        system("pause");
        system("cls");
        cout << "DIRECTOR: ";
        cargarCadena(director, 100);
    }
    cout << "GENERO: ";
    cargarCadena(genero, 100);
    while (director == ""){
        system("cls");
        cout << "La pelicula debe tener un genero. " << endl;
        system("pause");
        system("cls");
        cout << "GENERO: ";
        cargarCadena(genero, 100);
    }
    cout << "CLASIFICACION (1: ATP, 2: +14, 3: +18): ";
    cin >> clasificacion;
    while (clasificacion < 1 || clasificacion > 3){
        system("cls");
        cout << "Ingrese una clasificacion valida. " << endl;
        system("pause");
        system("cls");
        cout << "CLASIFICACION (1: ATP, 2: +14, 3: +18):";
        cin >> clasificacion;
    }
    cout << "FECHA DE ESTRENO: ";
    fechaEstreno.cargar();
    return true;
}
