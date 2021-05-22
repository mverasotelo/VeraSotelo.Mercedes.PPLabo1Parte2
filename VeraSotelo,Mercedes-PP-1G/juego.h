#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include "categoria.h"

//estructura juego
typedef struct {
    int codigo;
    char descripcion [20];
    float importe;
    int idCategoria;
}eJuego;

//prototipos

/** \brief Muestra juegos de una lista
 *
 * \param juegos[] eJuego - lista dejuegos
 * \param tam int - tamaño de la lista juegos
 * \param categorias[] eCategoria - lista de categorias
 * \param tamCat int - tamaño lista categorias
 * \return int - Devuelve 0 si hay error y 1 si esta todo Ok
 *
 */
int mostrarJuegos(eJuego juegos[], int tam, eCategoria categorias[], int tamCat);

/** \brief Imprime datos de un juego con la descripcion de su categoria
 *
 * \param juego eJuego - juego a mostrar
 * \param categorias[] eCategoria - lista de categorias
 * \param tamCat - int tamaño lista categorias
 * \return void
 *
 */
void mostrarJuego(eJuego juego, eCategoria categorias[], int tamCat);

/** \brief - Busca un juego por su codigo en una lista de juegos
 *
 * \param juegos[] eJuego - lista dejuegos
 * \param tam int - tamaño de la lista de juegos
 * \param codigo int - codigo del juego
 * \return int devuelve la posicion del juego en la lista, sino lo encuentra devuelve -1
 *
 */
int buscarJuego(eJuego juegos[], int tam, int codigo);


/** \brief Carga nombre del juego en la direccion de memoria indicada
 *
 * \param idJuego int id del juego
 * \param juegos[] eJuego array de juegos
 * \param tamJ int tamaño array
 * \param descripcion[20] char direccion de memoria
 * \return int - Devuelve 0 si hay error y 1 si esta todo Ok
 *
 */
int cargarDescripcionJuego(int idJuego, eJuego juegos[], int tamJ, char descripcion[20]);


#endif // JUEGO_H_INCLUDED
