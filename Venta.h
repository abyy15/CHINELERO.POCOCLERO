#pragma once
#include <iostream>
#include "Fecha.h"

using namespace std;

class Venta {
    private:
        int idVenta;
        int idPelicula;
        int numSala;
        int cantidadEntradas;
        float montoTotal;
        Fecha fechaVenta;
        bool estado = true;

    public:

        bool cargarConValidacion();

        /// CONSTRUCTOR ///
        Venta() {
            idVenta = 0;
            idPelicula = 0;
            numSala = 0;
            cantidadEntradas = 0;
            montoTotal = 0.0;
        }

        /// SETTERS ///
        void setIdVenta(int id) { idVenta = id; }
        void setIdPelicula(int id) { idPelicula = id; }
        void setNumSala(int id) { numSala = id; }
        void setCantidadEntradas(int cant) { cantidadEntradas = cant; }
        void setMontoTotal(float monto) { montoTotal = monto; }
        void setFechaVenta(Fecha fecha) { fechaVenta = fecha; }
        void setEstado(bool e) { estado = e; }

        /// GETTERS ///
        int getIdVenta() { return idVenta; }
        int getIdPelicula() { return idPelicula; }
        int getNumSala() { return numSala; }
        int getCantidadEntradas() { return cantidadEntradas; }
        float getMontoTotal() { return montoTotal; }
        Fecha getFechaVenta() { return fechaVenta; }
        bool getEstado() { return estado; }


        /// MÉTODO MOSTRAR ///
        void mostrar() {
            cout << "Venta #" << idVenta << endl;
            cout << "ID Pelicula: " << idPelicula << endl;
            cout << "Numero de Sala: " << numSala << endl;
            cout << "Cantidad de Entradas: " << cantidadEntradas << endl;
            cout << "Monto Total: $" << montoTotal << endl;
            cout << "Fecha de Venta: ";
            fechaVenta.mostrar();
        }
};

class ArchivoVenta {
    private:
        char nombreArchivo[50];
    public:
        ArchivoVenta(const char* nombre) {
            strncpy(nombreArchivo, nombre, 49);
            nombreArchivo[49] = '\0';
        }

        bool guardar(Venta& v) {
            FILE* f = fopen(nombreArchivo, "ab");
            if (f == nullptr) return false;
            bool ok = fwrite(&v, sizeof(Venta), 1, f);
            fclose(f);
            return ok;
        }

        Venta leerRegistro(int pos) {
            Venta v;
            FILE* f = fopen(nombreArchivo, "rb");
            if (f == nullptr) return v;
            fseek(f, pos * sizeof(Venta), SEEK_SET);
            fread(&v, sizeof(Venta), 1, f);
            fclose(f);
            return v;
        }

        bool modificar(Venta& v, int pos) {
            FILE* f = fopen(nombreArchivo, "rb+");
            if (f == nullptr) return false;
            fseek(f, pos * sizeof(Venta), SEEK_SET);
            bool ok = fwrite(&v, sizeof(Venta), 1, f);
            fclose(f);
            return ok;
        }

        int contarRegistros() {
            FILE* f = fopen(nombreArchivo, "rb");
            if (f == nullptr) return 0;
            fseek(f, 0, SEEK_END);
            int tam = ftell(f);
            fclose(f);
            return tam / sizeof(Venta);
        }

        void listarTodos() {
            Venta v;
            FILE* f = fopen(nombreArchivo, "rb");
            if (f == nullptr) {
                cout << "No se pudo abrir el archivo.\n";
                return;
            }
            while (fread(&v, sizeof(Venta), 1, f) == 1) {
                v.mostrar();
                cout << "----------------------------" << endl;
            }
            fclose(f);
        }

        int buscarPorID(int idBuscado) {
            Venta v;
            FILE* f = fopen(nombreArchivo, "rb");
            if (f == nullptr) return -1;

            int pos = 0;
            while (fread(&v, sizeof(Venta), 1, f) == 1) {
                if (v.getIdVenta() == idBuscado) {
                    fclose(f);
                    return pos;
                }
                pos++;
            }
            fclose(f);
            return -1; // no encontrado
        }

};

/// MÉTODO CARGAR ///

bool Venta :: cargarConValidacion(){
    ArchivoPelicula archivoPelicula ("archivo/Peliculas.dat");
    ArchivoSala archivoSala ("archivo/Salas.dat");
    Sala objSala;
    ArchivoVenta archivoVenta("archivo/Ventas.dat");
    int cantidadRegistros = 0;
    cantidadRegistros = archivoVenta.contarRegistros();
    idVenta = cantidadRegistros + 1;
    cout << "=========================================" << endl;
    cout << "         PELICULAS DISPONIBLES           " << endl;
    cout << "=========================================" << endl;
    archivoPelicula.listarTodos();
    cout << "=========================================" << endl;
    cout << "La ID de la venta sera: " << idVenta << endl;
    cout << "=========================================" << endl;
    cout << "ID de la pelicula: " ;
    cin >> idPelicula;
    cout << "=========================================" << endl;
    while (idPelicula == 0){
        system("cls");
        cout << "Debe ingresar un id de Pelicula. " << endl;
        system("pause");
        system("cls");
        cout << "ID de la pelicula: ";
        cin >> idPelicula;
    }
    //system ("cls");
    archivoSala.listarTodos();
    cout << endl;
    cout << "=========================================" << endl;
    cout << "Ingrese el numero de sala: " ;
    cin >> numSala;
    cout << "Cantidad de entradas: " ;
    cin >> cantidadEntradas;
    int pos = archivoSala.buscarPorNum(numSala);
    objSala = archivoSala.leerRegistro(pos);
    montoTotal = objSala.getPrecio()* cantidadEntradas;
    cout << "=========================================" << endl;
    cout << "TOTAL: " << montoTotal << endl;
    cout << "Porfavor ingrese fecha de la venta : ";
    fechaVenta.cargar();
    return true;
}
