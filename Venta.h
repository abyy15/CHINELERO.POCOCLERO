#pragma once
#include <iostream>
#include "Fecha.h"

using namespace std;

class Venta {
    private:
        int idVenta;
        int idPelicula;
        int idSala;
        int cantidadEntradas;
        float montoTotal;
        Fecha fechaVenta;

    public:
        /// CONSTRUCTOR ///
        Venta() {
            idVenta = 0;
            idPelicula = 0;
            idSala = 0;
            cantidadEntradas = 0;
            montoTotal = 0.0;
        }

        /// SETTERS ///
        void setIdVenta(int id) { idVenta = id; }
        void setIdPelicula(int id) { idPelicula = id; }
        void setIdSala(int id) { idSala = id; }
        void setCantidadEntradas(int cant) { cantidadEntradas = cant; }
        void setMontoTotal(float monto) { montoTotal = monto; }
        void setFechaVenta(Fecha fecha) { fechaVenta = fecha; }

        /// GETTERS ///
        int getIdVenta() { return idVenta; }
        int getIdPelicula() { return idPelicula; }
        int getIdSala() { return idSala; }
        int getCantidadEntradas() { return cantidadEntradas; }
        float getMontoTotal() { return montoTotal; }
        Fecha getFechaVenta() { return fechaVenta; }

        /// MÉTODO CARGAR ///
        void cargar() {
            cout << "ID de la venta: ";
            cin >> idVenta;
            cout << "ID de la pelicula: ";
            cin >> idPelicula;
            cout << "ID de la sala: ";
            cin >> idSala;
            cout << "Cantidad de entradas: ";
            cin >> cantidadEntradas;
            cout << "Monto total ($): ";
            cin >> montoTotal;
            cout << "Fecha de la venta:\n";
            fechaVenta.cargar();
        }

        /// MÉTODO MOSTRAR ///
        void mostrar() {
            cout << "Venta #" << idVenta << endl;
            cout << "ID Pelicula: " << idPelicula << endl;
            cout << "ID Sala: " << idSala << endl;
            cout << "Cantidad de Entradas: " << cantidadEntradas << endl;
            cout << "Monto Total: $" << montoTotal << endl;
            cout << "Fecha de Venta: ";
            fechaVenta.mostrar();
            cout << endl;
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
                cout << endl << "----------------------------\n";
            }
            fclose(f);
        }
};
