#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED

//estructura categoria

typedef struct {
    int id;
    char descripcion [20];
}eCategoria;

//prototipos

/** \brief Carga la descripcion de la catogoria, segun numero de ID, y lo guarda en una direccion de memoria
 *
 * \param idCategoria int - ID de la categoria
 * \param categorias[] eCategoria - lista de categorias
 * \param tamCat int - tamaño de la lista de categorias
 * \param descripcion[20] char - puntero a char donde se va a guardar la descripcion
 * \return int - Devuelve 0 si hay error y 1 si esta todo Ok
 *
 */
int cargarDescripcionCategoria(int idCategoria, eCategoria categorias[], int tamCat, char descripcion[20]);


/** \brief Muestra las categorias
 *
 * \param categorias[] eCategoria - lista de categorias
 * \param tamCat int - tamaño de la lista de categorias
 * \return int - Devuelve 0 si hay error y 1 si esta todo Ok
 *
 */
int mostrarCategorias(eCategoria categorias[], int tam);

#endif // CATEGORIA_H_INCLUDED
