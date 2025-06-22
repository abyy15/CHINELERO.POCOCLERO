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
void desactivarPelicula();
void activarPelicula();

/// MODIFICAR PELICULAS ///
void modificarPelicula();
int menuModificarPeli();
void modTodoPel();
void modNombrePel();
void modDirector();
void modGenero();
void modClasificacion();
void modFechaDeEstreno();

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
void crearSala();
void listarSala();
void desactivarSala();
void activarSala();

/// MODIFICAR SALAS ///
void modificarSala();
int menuModificarSala();
void modTodoSala();
void modNumSala();
void modNombreSala();
void modTipoSala();
void modCantButSala();

/// VENTAS ///
void ventas();
int menuVenta();
void crearVenta();
void listarVenta ();
void desactivarVenta ();
void activarVenta();

/// MODIFICAR VENTAS ///
void modificarVenta();
int menuModificarVenta();
void modTodoVenta();
void modidVenta();
void modidPeliculaVenta();
void modNumSalaVenta();
void modCantEntradaVenta();
void modMontoTotalVenta();
void modFechaVenta();
