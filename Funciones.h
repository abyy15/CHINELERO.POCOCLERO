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
void borrarPelicula();

/// LISTAR PELICULAS ///
void listarPeliculas(); ///Lista TODAS las peliculas sin filtrar
int menuListarPelicula();
void listarTodasLasPeliculas();
void listarPeliculaPorID();
void listarPeliculaPorNombre();
void listarPeliculaPorDirector();
void listarPeliculaPorGenero();
void listarPeliculaPorClasificacion();
void listarPeliculaPorFechaDeEstreno();

/// SALAS ///
void salas();
int menuSalas();

/// VENTAS ///
void venta();
int menuVenta();
