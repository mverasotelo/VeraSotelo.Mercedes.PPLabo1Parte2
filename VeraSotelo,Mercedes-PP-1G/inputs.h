#ifndef INPUTS_H_INCLUDED
#define INPUTS_H_INCLUDED
#include "fecha.h"

//funciones menu de opciones y validacion datos

/** \brief menu de opciones
 *
 * \return int devuelve opcion seleccionada por el usuario
 *
 */
int menuOpciones();

/** \brief submenu de datos a modificar
 *
 * \return int devuelve opcion seleccionada por el usuario
 *
 */
int submenuModificar();


/** \brief submenu de informes
 *
 * \return int devuelve opcion seleccionada por el usuario
 *
 */
int submenuInformes();


/** \brief pide y valida una opcion
 *
 * \param min int opcion minima
 * \param max int opcion maxima
 *
 */
int getOption(int min, int max);

/** \brief pide y valida extension de un string
 *
 * \param string char* string
 * \param maxLen int extension maxima
 * \return int devuelve 0 si esta todo OK y -1 si hay algun error
 *
 */
int getString(char string[], int maxLen);


/** \brief pide el sexo, lo valida y lo guarda en la direccion de memoria indicada
 *
 * \param telefono char* puntero al sexo
 * \return int devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int getSexo(char* sexo);


/** \brief pide una fecha, la valida, valdia que sea posterior a la fecha inicial y la guarda en una direccion de memoria
 *
 * \param fecha eFecha* direccion de memoria donde se va a guardar la fecha
 * \param anioInicial int año a partir del cual se pueden ingresar fechas
 * \return int devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int getFecha(eFecha * fecha, int anioInicial);


/** \brief pide ID de localidad y lo valida
 *
 * \param idLocalidad int* direccion de memoria donde se va a guardad la localidad
 * \return int devuelve 1 si salio todo bien, 0 si hubo algun error
 *
 */
int getLocalidad(int* idLocalidad);


#endif // INPUTS_H_INCLUDED
