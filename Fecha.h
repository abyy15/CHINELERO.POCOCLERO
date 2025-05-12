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

    /// CARGAR CON VALIDACION ///

    bool esBisiesto(int anio) { return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);}

    bool esFechaValida() {
        if (_anio < 1) return false;
        if (_mes < 1 || _mes > 12) return false;

        int diasPorMes[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

        if (_mes == 2 && esBisiesto(_anio)) {
            if (_dia < 1 || _dia > 29) return false;
        } else {
            if (_dia < 1 || _dia > diasPorMes[_mes]) return false;
        }
    return true;
    }

    void cargar() {
        do {
        cout << "Ingrese el dia: ";
        cin >> _dia;
        cout << "Ingrese el mes: ";
        cin >> _mes;
        cout << "Ingrese el anio: ";
        cin >> _anio;
        if (!esFechaValida()) { system ("cls"); cout << "Fecha invalida, intente de nuevo." << endl;}

        } while (!esFechaValida());
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
