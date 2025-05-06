#include <iostream>
#include "funcion.h"

using namespace std;

int main()
{
    int eleccionUsuario = mostrarMenuPrincipal();
    switchMenu(eleccionUsuario);
    return 0;
}
