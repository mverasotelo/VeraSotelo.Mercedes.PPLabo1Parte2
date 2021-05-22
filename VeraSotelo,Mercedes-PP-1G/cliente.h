#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "inputs.h"
#include "localidad.h"


//estructura cliente
typedef struct {
    int codigo;
    char nombre [51];
    char apellido [51];
    char sexo;
    char telefono[21];
    int idLocalidad;
    int isEmpty;

}eCliente;


//funciones

/** \brief Inicializa el campo "isEmpty" de todos los valores de la lista de clientes en 1 (libre)
 *
 * \param clientes[] eCliente - Lista total de clientes
 * \param tam int - Tamaño de la lista de clientes
 * \return int devuelve 0 si hay error y 1 si salio todo OK
 *
 */
int inicializarClientes(eCliente clientes[], int tam);

/** \brief Busca si hay lugar libre en la lista de clientes
 *
 * \param clientes[] eCliente - Lista total de clientes
 * \param tam int - Tamaño de la lista de clientes
 * \return int - Devuelve el primer indice libre en la lista, sino hay lugar devuelve -1
 *
 */
int buscarLugar(eCliente clientes[], int tam);

/** \brief Indica si un cliente esta activo
 *
 * \param cliente eCliente - cliente a evaluar
 * \return int - Devuelve 1 si esta activo y 0 si esta inactivo
 *
 */
int clienteActivo(eCliente cliente);


/** \brief Cuenta la cantidad de clientes activos
 *
 * \param clientes[] eCliente - lista de clientes
 * \param tam int - tamaño de la lista
 * \return int - devuelve cantidad de clientes activos
 *
 */
int contarClientes(eCliente clientes[],int tam);


/** \brief Alta de un nuevo cliente
 *
 * \param clientes[] eCliente lista de clientes donde guardar el nuevo cliente
 * \param tam int tamaño de la lista de clientes
 * \param pId int* legajo a asignar
 * \return int devuelve 0 si hay error y 1 si salio todo OK
 *
 */
int altaCliente(eCliente clientes[], int tam, int *pId);


/** \brief Ordena clientes por apellido y nombre (2 criterios)
 *
 * \param clientes[] eCliente lista de clientes a ordenar
 * \param tam int tamaño de la lista
 * \return int devuelve 0 si hay error y 1 si salio todo OK
 *
 */
int ordenarClientes(eCliente clientes[], int tam);


/** \brief Muestra lista de clientes
 *
 * \param clientes[] eCliente lista de clientes a ordenar
 * \param tam int tamaño de la lista
 * \return int devuelve cantidad de clientes impresos
 *
 */
int mostrarClientes(eCliente clientes[], int tam, eLocalidad localidades[], int tamLoc);


/** \brief Muestra un cliente
 *
 * \param cliente eCliente - cliente a mostrar
 * \return void
 *
 */
void mostrarCliente(eCliente cliente, eLocalidad localidades[], int tamLoc);


/** \brief Busca la posicion de un cliente por su codigo
 *
 * \param clientes[] eCliente lista de clientes a ordenar
 * \param tam int tamaño de la lista
 * \param codigo int codigo a buscar
 * \return int devuelve la posicion del cliente en el array
 *
 */
int buscarCliente(eCliente clientes[], int tam, int codigo);


/** \brief Modifica los datos de un cliente, pidiendo su codigo y el dato a modificar
 *
 * \param clientes[] eCliente lista de clientes a ordenar
 * \param tam int tamaño de la lista
 * \return int devuelve 0 si hay error y 1 si salio todo OK
 *
 */
int modificarCliente(eCliente clientes[], int tam, eLocalidad localidades[], int tamLoc);


/** \brief modifica el dato de un cliente
 *
 * \param clientes[] eCliente lista de clientes a ordenar
 * \param tam int tamaño de la lista
 * \param legajo int codigo del cliente
 * \param datoModif int dato a modificar
 * \return int devuelve 0 si hay error y 1 si salio todo OK
 *
 */
int modificarDato(eCliente clientes[], int tam, int legajo, int datoModif);


/** \brief Hace la baja logica de un cliente, pidiendo su codigo y da de baja todos los alquileres de ese cliente
 *
 * \param clientes[] eCliente lista de clientes
 * \param tam int tamaño de la lista de clientes
 * \param alquileres[] eAlquiler lista de alquileres
 * \param tam int tamaño de la lista de aquileres
 * \return int devuelve -1 si hay error y el codigo del empleado dado de baja si salio todo Ok
 *
 */
int bajaCliente(eCliente clientes[], int tam, eLocalidad localidades[], int tamLoc);


/** \brief Carga apellido del cliente mediante su ID
 *
 * \param codCliente int codigo del cliente
 * \param clientes[] eCliente lista de clientes
 * \param tam int tamaño de la lista de clientes
 * \param descripcion[51] char direccion de memoria para guardar el apellido
 * \return int devuelve 0 si hay error y 1 si salio todo OK
 *
 */
int cargarApellido(int codCliente, eCliente clientes[], int tam, char descripcion[51]);


#endif // CLIENTE_H_INCLUDED
