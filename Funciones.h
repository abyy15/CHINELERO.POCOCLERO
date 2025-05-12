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
void modificarPelicula();
void desabilitarPelicula();
void activarPelicula();

/// LISTAR PELICULAS ///
void listarPeliculas(); ///Lista TODAS las peliculas sin filtrar
int menuListarPelicula();
void listarTodasLasPeliculas();
void listarID();
void listarNombre();
void listarDirector();
void listarGenero();
void listarClasificacion();
void listarFechaDeEstreno();

/// SALAS ///
void salas();
int menuSalas();

/// VENTAS ///
void venta();
int menuVenta();
