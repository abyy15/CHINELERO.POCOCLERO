#pragma once
#include <iostream>
using namespace std;

class Fecha{
    private:
    int _dia, _mes, _anio;

    public:
    /// CONTRUCTOR Y DESTRUCTOR ///
    Fecha(){
        _dia = 0;
        _mes = 0;
        _anio = 0;
    }
    Fecha(int dia, int mes, int anio){
        _dia = dia;
        _mes = mes;
        _anio = anio;
    }

    /// CARGAR ///
    void cargar() {
        cout << "Ingrese el dia: ";
        cin >> _dia;
        cout << "Ingrese el mes: ";
        cin >> _mes;
        cout << "Ingrese el anio: ";
        cin >> _anio;
    }

    /// MOSTRAR ///
    void mostrar() {
        cout << "Fecha: " << _dia << "/" << _mes << "/" << _anio << endl;
    }

    /// GETERS ///
    int getDia(){ return _dia;}
    int getMes(){ return _mes;}
    int getAnio(){ return _anio;}

    /// SETTERS ///
    void setDia(int dia){ _dia = dia;}
    void setMes(int mes){ _mes = mes;}
    void setAnio(int anio){ _anio = anio;}

    /// TO STRING ///
    std::string toString(){ /// PASA EL OBJ FECHA A UN STRING
        return std::to_string(_dia) + "/" + std::to_string(_mes) + "/" + std::to_string(_anio);}
};
