esta todo dentro del mismo .h, asi mira #pragma once
\#include <iostream>
\#include <cstring>
\#include <cstdio>

using namespace std;

class Pelicula {
    private:
        int id;
        char nombre\[50];
        char director\[50];
        char genero\[30];
        int clasificacion; // 1: ATP, 2: +14, 3: +18
        Fecha fechaEstreno; // Objeto Fecha
    public:
        void cargar() {
            cout << "ID de la película: ";
            cin >> id;
            cin.ignore();

            cout << "Nombre de la película: ";
            cin.getline(nombre, 50);

            cout << "Director (Apellido y Nombre): ";
            cin.getline(director, 50);

            cout << "Género: ";
            cin.getline(genero, 30);

            cout << "Clasificación (1: ATP, 2: +14, 3: +18): ";
            cin >> clasificacion;

            cout << "Fecha de estreno:\n";
            fechaEstreno.cargar();
        }

        void mostrar() const {
            cout << "ID: " << id << endl;
            cout << "Nombre: " << nombre << endl;
            cout << "Director: " << director << endl;
            cout << "Género: " << genero << endl;
            cout << "Clasificación: ";
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
        }

        // GETTERS
        int getId() const { return id; }
        const char* getNombre() const { return nombre; }
        const char* getDirector() const { return director; }
        const char* getGenero() const { return genero; }
        int getClasificacion() const { return clasificacion; }
        Fecha getFechaEstreno() const { return fechaEstreno; }

        //SETTERS
        void setId(int _id) { id = _id; }
        void setNombre(const char* _nombre) { strncpy(nombre, _nombre, sizeof(nombre)-1); }
        void setDirector(const char* _director) { strncpy(director, _director, sizeof(director)-1); }
        void setGenero(const char* _genero) { strncpy(genero, _genero, sizeof(genero)-1); }
        void setClasificacion(int _clasificacion) { clasificacion = _clasificacion; }
        void setFechaEstreno(const Fecha& _fechaEstreno) { fechaEstreno = _fechaEstreno; }

};

class ArchivoPelicula {
    private:
        char nombreArchivo[50];
    public:
        ArchivoPelicula(const char* nombre) {
            strncpy(nombreArchivo, nombre, 49);
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
            if (f == nullptr) return 0;
            fseek(f, 0, SEEK_END);
            int tam = ftell(f);
            fclose(f);
            return tam / sizeof(Pelicula);
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

        int buscarPorID(int idBuscado) { //INVERCION A FUTURO
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
