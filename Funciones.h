#pragma once
#include <iostream>
#include <cstring>
#include <cstdio>

/// MENU ///
void menu ();
int mostrarMenuPrincipal();

/// CARGAR CADENA XD ///
void cargarCadena(char *palabra, int tamano);

/// PELICULA ///
void pelicula();
int menuPelicula ();
void crearPelicula();
void listarPeliculas(); ///Lista TODAS las peliculas sin filtrar
void modificarPelicula();
void borrarPelicula();
    /// MENU LISTAR PELICULAS ///
    void menuListarPelicula(); ///Muestra un menu para filtrar segun diferentes condiciones

/// SALAS ///
void salas();
int menuSalas();

/// VENTAS ///
void venta();
int menuVenta();
