#ifndef LOCALIDAD_H_INCLUDED
#define LOCALIDAD_H_INCLUDED

//estructura localidad

typedef struct {
    int id;
    char localidad [20];
}eLocalidad;

/** \brief carga descripcion de una localidad
 *
 * \param idLocalidad int ID localidad a cargar
 * \param localidades[] eLocalidad lista de localidades
 * \param tamLoc int tamaño de la lista
 * \param localidad[20] char puntero a char donde guardar la localidad
 * \return int - Devuelve 0 si hay error y 1 si esta todo Ok
 *
 */
int cargarDescripcionLocalidad(int idLocalidad, eLocalidad localidades[], int tamLoc, char localidad[20]);

#endif // LOCALIDAD_H_INCLUDED
