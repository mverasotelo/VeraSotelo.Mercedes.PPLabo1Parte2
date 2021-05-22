#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "alquileres.h"
#include "cliente.h"
#include "juego.h"
#include "categoria.h"
#include "localidad.h"

/** \brief muestra los juegos de la categoria mesa
 *
 * \param juegos[] eJuego lista de juegos
 * \param tamJ int tamaño de la lista de juegos
 * \return int - Devuelve 0 si hay error y 1 si esta todo Ok
 *
 */
int mostrarJuegosCategMesa(eJuego juegos[], int tamJ);


/** \brief muestra los alquileres efectuados por un cliente ingresado
 *
 * \param alquileres[] eAlquiler - lista de alquileres
 * \param tam int - tamaño de la lista de alquileres
 * \param clientes[] eCliente - lista de clientes
 * \param tamC int - tamaño de la lista de clientes
 * \param juegos[] eJuego - lista de juegos
 * \param tamJ int - tamaño de la lista de juegos
 * \param categorias[] eCategoria - lista de categorias
 * \param tamCat int - tamaño de la lista de categorias
 * \return int - devuelve 0 si hay error 1 si esta todo Ok
 *
 */
int mostrarAlquileresCliente(eAlquiler alquileres[], int tam, eCliente clientes[], int tamC, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat, eLocalidad localidades[], int tamLoc);


/** \brief muestra el monto total a pagar/pagado por cliente
 *
 * \param alquileres[] eAlquiler - lista de alquileres
 * \param tam int - tamaño de la lista de alquileres
 * \param clientes[] eCliente - lista de clientes
 * \param tamC int - tamaño de la lista de clientes
 * \param juegos[] eJuego - lista de juegos
 * \param tamJ int - tamaño de la lista de juegos
 * \param localidades[] eLocalidad
 * \param tamLoc int
 * \return int - devuelve 0 si hay error 1 si esta todo Ok
 *
 */
int sumatoriaAlquileresXCliente(eAlquiler alquileres[], int tam, eCliente clientes[], int tamC, eJuego juegos[], int tamJ, eLocalidad localidades[], int tamLoc);


/** \brief muestra clientes que no han hecho ningun alquiler
 *
 * \param alquileres[] eAlquiler - lista de alquileres
 * \param tam int - tamaño de la lista de alquileres
 * \param clientes[] eCliente - lista de clientes
 * \param tamC int - tamaño de la lista de clientes
 * \param localidades[] eLocalidad - lista de localidades
 * \param tamLoc int tamaño - lista localidades
 * \return int - devuelve 0 si hay error 1 si esta todo Ok
 *
 */
int clientesSinAlquileres(eAlquiler alquileres[], int tam, eCliente clientes[], int tamC, eLocalidad localidades[], int tamLoc);


/** \brief Muestra los juegos no alquilados
 *
 * \param alquileres[] eAlquiler - lista de alquileres
 * \param tam int - tamaño de la lista de alquileres
 * \param juegos[] eJuego - lista de juegos
 * \param tamJ int - tamaño de la lista de juegos
 * \param categorias[] eCategoria - lista de categorias
 * \param tamCat int - tamaño de la lista de categorias
 * \return int - devuelve 0 si hay error 1 si esta todo Ok
 *
 */
int juegosNoAlquilados(eAlquiler alquileres[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat);


/** \brief Listar los teléfonos de los clientes que alquilaron juegos en una determinada fecha
 *
 * \param alquileres[] eAlquiler - lista de alquileres
 * \param tam int - tamaño de la lista de alquileres
 * \param anioInicial int
 * \param clientes[] eCliente - lista de clientes
 * \param tamC int - tamaño de la lista de clientes
 * \return int - devuelve 0 si hay error 1 si esta todo Ok
 *
 */
int telefonosAlquiladosXFecha(eAlquiler alquileres[], int tam, int anioInicial, eCliente clientes[], int tamC);


/** \brief Listar los juegos alquilados por mujeres
 *
 * \param alquileres[] eAlquiler - lista de alquileres
 * \param tam int - tamaño de la lista de alquileres
 * \param clientes[] eCliente - lista de clientes
 * \param tamC int - tamaño de la lista de clientes
 * \param juegos[] eJuego - lista de juegos
 * \param tamJ int - tamaño de la lista de juegos
 * \return int - devuelve 0 si hay error 1 si esta todo Ok
 *
 */
int juegosAlqMujeres(eAlquiler alquileres[], int tam, eCliente clientes[], int tamC, eJuego juegos[], int tamJ);


/** \brief Mostrar el o los juegos mas alquilados por hombres
 *
 * \param alquileres[] eAlquiler - lista de alquileres
 * \param tam int - tamaño de la lista de alquileres
 * \param clientes[] eCliente - lista de clientes
 * \param tamC int - tamaño de la lista de clientes
 * \param juegos[] eJuego - lista de juegos
 * \param tamJ int - tamaño de la lista de juegos
 * \return int - devuelve 0 si hay error 1 si esta todo Ok
 *
 */
int juegoPreferidoHombres(eAlquiler alquileres[], int tam, eCliente clientes[], int tamC, eJuego juegos[], int tamJ);


/** \brief
 *
 * \param alquileres[] eAlquiler - lista de alquileres
 * \param tam int - tamaño de la lista de alquileres
 * \param clientes[] eCliente - lista de clientes
 * \param tamC int - tamaño de la lista de clientes
 * \param localidades[] eLocalidad - lista de localidad
 * \param tamLoc int - tamaño lista localidad
 * \param juegos[] eJuego - lista de juegos
 * \param tamJ int - tamaño de la lista de juegos
 * \param categorias[] eCategoria - lista de categorias
 * \param tamCat int - tamaño de la lista de categorias
 * \return int - devuelve 0 si hay error 1 si esta todo Ok
 *
 */
int clientesXJuego(eAlquiler alquileres[], int tam, eCliente clientes[], int tamC, eLocalidad localidades[], int tamLoc, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat);


/** \brief muestra la recaudacion de una fecha ingresada
 *
 * \param alquileres[] eAlquiler - lista de alquileres
 * \param tam int - tamaño de la lista de alquileres
 * \param juegos[] eJuego - lista de juegos
 * \param tamJ int - tamaño de la lista de juegos
 * \param anioInicial int
 * \return int - devuelve 0 si hay error 1 si esta todo Ok
 *
 */
int recaudacionXFecha(eAlquiler alquileres[], int tam, eJuego juegos[], int tamJ, int anioInicial);


/** \brief Muestra categoria preferida clientes Avellaneda
 *
 * \param alquileres[] eAlquiler - lista de alquileres
 * \param tam int - tamaño de la lista de alquileres
 * \param clientes[] eCliente - lista de clientes
 * \param tamC int - tamaño de la lista de clientes
 * \param localidades[] eLocalidad - lista de localidad
 * \param tamLoc int - tamaño lista localidad
 * \param juegos[] eJuego - lista de juegos
 * \param tamJ int - tamaño de la lista de juegos
 * \param categorias[] eCategoria - lista de categorias
 * \param tamCat int - tamaño de la lista de categorias
 * \return int - devuelve 0 si hay error 1 si esta todo Ok
 *
 */
int categoriaPreferidaAvellaneda(eAlquiler alquileres[], int tam, eCliente clientes[], int tamC, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat);


/** \brief Lista total de alquileres por localidad
 *
 * \param alquileres[] eAlquiler - lista de alquileres
 * \param tam int - tamaño de la lista de alquileres
 * \param clientes[] eCliente - lista de clientes
 * \param tamC int - tamaño de la lista de clientes
 * \param localidades[] eLocalidad - lista de localidad
 * \param tamLoc int - tamaño lista localidad
 * \param juegos[] eJuego - lista de juegos
 * \param tamJ int - tamaño de la lista de juegos
 * \param categorias[] eCategoria - lista de categorias
 * \param tamCat int - tamaño de la lista de categorias
 * \return int - devuelve 0 si hay error 1 si esta todo Ok
 *
 */
int mostrarAlquileresLocalidad(eAlquiler alquileres[], int tam, eCliente clientes[], int tamC, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat, eLocalidad localidades[], int tamLoc);


#endif // INFORMES_H_INCLUDED
