#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED
#include "fecha.h"
#include "juego.h"
#include "cliente.h"
#include "categoria.h"

//estructura alquiler

typedef struct {
    int codigoAlquiler;
    int codigoJuego;
    int codigoCliente;
    int isEmpty;
    eFecha fecha;

}eAlquiler;

//prototipos

/** \brief Inicializa todos los elementos de alquileres a isEmpty=1
 *
 * \param alquileres[] eAlquiler lista de alquileres
 * \param tam int tamaño de la lista
 * \return int devuelve 0 si hay error 1 si esta todo Ok
 *
 */
int inicializarAlquileres(eAlquiler alquileres[], int tam);

/** \brief Busca lugar libre para alquiler
 *
 * \param alquileres[] eAlquiler lista de alquileres
 * \param tam int tamaño de la lista
 * \return int devuelve primer indice libre
 *
 */
int buscarLugarAlq(eAlquiler alquileres[], int tam);

/** \brief Da de alta un nuevo alquiler y lo guarda en el primer lugar disponible de la lista indicada
 *
 * \param alquileres[] eAlquiler - lista de alquileres donde guardar el nuevo elemento
 * \param tam int - tamaño de la lista de alquileres
 * \param pId int* - proximo ID a utilizar
 * \param clientes[] eCliente - lista de clientes
 * \param tamC int - tamaño de la lista de clientes
 * \param juegos[] eJuego - lista de juegos
 * \param tamJ int - tamaño de la lista de juegos
 * \param categorias[] eCategoria - lista de categorias
 * \param tamCat int - tamaño de la lista de categorias
 * \param localidades[] eLocalidad - lista de localidades
 * \param tamLoc int - tamaño de la lista de localidades

 * \return int - devuelve 0 si hay error 1 si esta todo Ok
 *
 */
int altaAlquiler(eAlquiler alquileres[], int tam, int *pId, eCliente clientes[], int tamC, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat, int anioInicial, eLocalidad localidades[], int tamLoc);

/** \brief Imprime todos los alquileres de una lista, detallando nombre, juego, categoria y fecha
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
int listarAlquileres(eAlquiler alquileres[], int tam, eCliente clientes[], int tamC, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat);


/** \brief Recibe un alquiler y lo imprime, detallando nombre, juego, categoria y fecha
 *
 * \param alquiler eAlquiler alquiler a imprimir
 * \param clientes[] eCliente - lista de clientes
 * \param tamC int - tamaño de la lista de clientes
 * \param juegos[] eJuego - lista de juegos
 * \param tamJ int - tamaño de la lista de juegos
 * \param tamJ int - tamaño de la lista de juegos
 * \param categorias[] eCategoria - lista de categorias
 * \return void
 *
 */
void mostrarAlquiler(eAlquiler alquiler, eCliente clientes[], int tamC, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat);

/** \brief cuenta los alquileres activos
 *
 * \param alquileres[] eAlquiler lista de alquileres
 * \param tam int tamaño lista de alquileres

 * \return int devuelve numero de alquileres activos
 *
 */
int contarAlquileres(eAlquiler alquileres[],int tam);


/** \brief Da de baja los alquileres de un cliente que se dio de baja
 *
 * \param alquileres[] eAlquiler lista de alquileres
 * \param tam int tamaño lista de alquileres
 * \param codEmpleado int codigo empleado dado de baja
 * \return int - devuelve 0 si hay error 1 si esta todo Ok
 *
 */
int bajaAlquileresCliente(eAlquiler alquileres[],int tam, int codEmpleado);

#endif // ALQUILERES_H_INCLUDED
