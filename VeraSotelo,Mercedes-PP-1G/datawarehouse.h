#ifndef DATAWAREHOUSE_H_INCLUDED
#define DATAWAREHOUSE_H_INCLUDED
#include "fecha.h"
#include "juego.h"
#include "cliente.h"
#include "alquileres.h"

//base de juegos
static int codigos[10]={501,500,502,503,504,505,506,507,508,509};

static int idCategoriaJuego[10]={12,10,10,10,11,12,10,12,11,14};

static float importes[10]={1000,1500,200,1300,1250,1500,1250,1002,1250,1006};

static char descripcionJuego[10][10]={
    "TEG",
    "Monopoly",
    "UNO",
    "Trust",
    "Ludo",
    "Ajedrez",
    "Cartas",
    "Damas",
    "Generala",
    "MagicBox",
};

//base de clientes
static char nombres[10][51]={
    "Maria",
    "Belen",
    "Lucia",
    "Pedro",
    "Lucas",
    "Federico",
    "Marta",
    "Alicia",
    "Julian",
    "Horacio",
};

static char apellidos[10][51]={
    "Perez",
    "Sotelo",
    "Maciel",
    "Vera",
    "Ocampo",
    "Beskow",
    "Plozzer",
    "Quiroga",
    "Vera",
    "Mosquera",
};

static char sexos[10]={'f','f','f','m','m','m','f','f','m','m'};

static char telefonos[10][21]={
    "1135223256",
    "2215698323",
    "1135657356",
    "1165656586",
    "1189564463",
    "1198956565",
    "3514565656",
    "1198959597",
    "1189867455",
    "1186525325",
};

static int localidades[10]={50,51,54,53,54,52,50,51,54,53};

//base de alquileres

static int codigosJuego[10]={500,501,503,500,502,503,505,504,507,509};

static int codigosCliente[10]={1006,1001,1004,1001,1001,1003,1000,1002,1001,1005};

static eFecha fechasAlq[10]={{1,5,2021},{10,5,2021},{1,6,2021},{10,6,2021},{6,5,2021},{1,5,2021},{8,5,2021},{4,5,2021},{6,5,2021},{1,5,2021}};

//prototipos

/** \brief Harcodea juegos a una lista de eJuegos
 *
 * \param juegos[] eJuego lista a harcodear
 * \param tamJ int tamaño de la lista
 * \param cant int cantidd de juegos a harcodear
 * \return int devuelve cantidad de juegos harcodeados
 *
 */
int hardcodearJuegos(eJuego juegos[],int tamJ, int cant);


/** \brief Harcodea clientes a una lista de eClientes
 *
 * \param clientes[] eCliente lista a harcodear
 * \param tamC int tamaño de la lista
 * \param cant int cantidad de clientes a harcodear
* \param cant *int codigo para el cliente
 * \return int devuelve cantidad de clientes harcodeados
 *
 */
int hardcodearClientes(eCliente clientes[],int tamC, int cant, int* pId);


/** \brief Harcodea clientes a una lista de eAlquileres
 *
 * \param alquileres[] eAlquiler lista a harcodear
 * \param tamA int tamaño de la lista
 * \param cant int cantidad de alquileres a harcodear
 * \param pId int* codigo para el alquiler
 * \return int devuelve cantidad de alquileres harcodeados
 *
 */
int hardcodearAlquileres(eAlquiler alquileres[],int tamA, int cant, int* pId);

#endif // DATAWAREHOUSE_H_INCLUDED
