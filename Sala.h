#pragma once
#include <iostream>
using namespace std;

class Sala {
    private:
        int numSala;
        char nombreSala [30];
        int tipoSala; // 1- Estandar 2- Premium 3-Confort Plus
        int butacasDisponibles;

    public:
        /// GETTERS ///
        int getNumSala() { return numSala; }
        char* getNombreSala()  { return nombreSala; }
        int getTipoSala() { return tipoSala; }
        int getButacasDisponibles() { return butacasDisponibles; }

        /// SETTERS ///
        void setNumSala(int num) { numSala = num; }
        void setNombreSala(const char* nombre) { strcpy(nombreSala, nombre); }
        void setTipoSala(int tipo) { tipoSala = tipo; }
        void setButacasDisponibles(int butacas) { butacasDisponibles = butacas; }

        /// METODOS ///
        void cargar(){
            cout << "Numero de Sala: ";
            cin >> numSala;
            cout << "Nombre de la Sala: ";
            cargarCadena (nombreSala,30);
            menuSala();
            while (true){
            cin >> tipoSala;
            if (tipoSala > 3 || tipoSala < 1) {
                system("cls");
                cout << "Ingrese un numero valido. " << endl;
                menuSala (); }
            else break;}
            cout << "Cantidad de Butacas Disponibles: ";
            cin >> butacasDisponibles;
        }

        void mostrar (){
            cout << "Numero de Sala: " << numSala << endl;
            cout << "Nombre de la Sala: " << nombreSala << endl;
            char ts [30];
            tipoDeSala (tipoSala, ts);
            cout << "Tipo de Sala: " << ts << endl ;
            cout << "Cantidad de Butacas Disponibles: " << butacasDisponibles ;
            cout << endl;

        }

        void tipoDeSala (int tipoSala, char* ts){
            if (tipoSala == 1){ strcpy (ts, "Estandar");}
            else if (tipoSala == 2) { strcpy (ts,"Premium");}
            else if (tipoSala == 3) {strcpy (ts,"Confort Plus");}
            else strcpy (ts,"--------");
            return;
        }

        void menuSala (){
            cout << "Tipo de sala: " << endl;
            cout << "1- Estandar " << endl;
            cout << "2- Premium " << endl;
            cout << "3- Confort Plus " << endl;
        }
};

class ArchivoSala {
    private:
        char nombreArchivo[50];
    public:
        ArchivoSala(const char* nombre) {
            strncpy(nombreArchivo, nombre, 49);
            nombreArchivo[49] = '\0';
        }

        bool guardar(const Sala& p) {
            FILE* f = fopen(nombreArchivo, "ab");
            if (f == nullptr) return false;
            bool ok = fwrite(&p, sizeof(Sala), 1, f);
            fclose(f);
            return ok;
        }

        Sala leerRegistro(int pos) {
            Sala reg;
            FILE* p = fopen(nombreArchivo, "rb");
            if (p == nullptr) return reg;
            fseek(p, pos * sizeof(Sala), SEEK_SET);
            fread(&reg, sizeof(Sala), 1, p);
            fclose(p);
            return reg;
        }

        bool modificar(const Sala& p, int pos) {
            FILE* f = fopen(nombreArchivo, "rb+");
            if (f == nullptr) return false;
            fseek(f, pos * sizeof(Sala), SEEK_SET);
            bool ok = fwrite(&p, sizeof(Sala), 1, f);
            fclose(f);
            return ok;
        }

        int contarRegistros() {
            FILE* f = fopen(nombreArchivo, "rb");
            if (f == nullptr) return 0;
            fseek(f, 0, SEEK_END);
            int tam = ftell(f);
            fclose(f);
            return tam / sizeof(Sala);
        }

        void listarTodos() {
            Sala p;
            FILE* f = fopen(nombreArchivo, "rb");
            if (f == nullptr) {
                cout << "No se pudo abrir el archivo.\n";
                return;
            }
            while (fread(&p, sizeof(Sala), 1, f) == 1) {
                p.mostrar();
                cout << endl;
                cout << "----------------------------\n";
            }
            fclose(f);
        }

        int buscarPorNum(int numBuscado) { //imprimir bitcoin 2.0
            Sala s;
            FILE* f = fopen(nombreArchivo, "rb");
            if (f == nullptr) return -1;

            int pos = 0;
            while (fread(&s, sizeof(Sala), 1, f) == 1) {
                if (s.getNumSala() == numBuscado) {
                    fclose(f);
                    return pos;
                }
                pos++;
            }
            fclose(f);
            return -1; // no encontrado
        }
};
