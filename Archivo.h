#pragma once
#include <cstdio>
#include <cstring>

template <class T>
class Archivo {
private:
    char nombreArchivo[50];

public:
    Archivo(const char* nombre) {
        strncpy(nombreArchivo, nombre, 49);
        nombreArchivo[49] = '\0';
    }

    bool guardar(const T& obj) {
        FILE* p = fopen(nombreArchivo, "ab");
        if (p == nullptr) return false;
        bool ok = fwrite(&obj, sizeof(T), 1, p);
        fclose(p);
        return ok;
    }

    bool leer(T& obj, int pos) {
        FILE* p = fopen(nombreArchivo, "rb");
        if (p == nullptr) return false;
        fseek(p, pos * sizeof(T), SEEK_SET);
        bool ok = fread(&obj, sizeof(T), 1, p);
        fclose(p);
        return ok;
    }

    bool modificar(const T& obj, int pos) {
        FILE* p = fopen(nombreArchivo, "rb+");
        if (p == nullptr) return false;
        fseek(p, pos * sizeof(T), SEEK_SET);
        bool ok = fwrite(&obj, sizeof(T), 1, p);
        fclose(p);
        return ok;
    }

    int contarRegistros() {
        FILE* p = fopen(nombreArchivo, "rb");
        if (p == nullptr) return 0;
        fseek(p, 0, SEEK_END);
        int tam = ftell(p);
        fclose(p);
        return tam / sizeof(T);
    }

    void listarTodos() {
        T obj;
        FILE* p = fopen(nombreArchivo, "rb");
        if (p == nullptr) {
            printf("No se pudo abrir el archivo.\n");
            return;
        }
        while (fread(&obj, sizeof(T), 1, p) == 1) {
            obj.mostrar();  // La clase T debe tener este método
            printf("----------------------------\n");
        }
        fclose(p);
    }
};
