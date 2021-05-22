#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datawarehouse.h"

int hardcodearJuegos(eJuego juegos[],int tamJ, int cant){
    int total=0;
    if(juegos!=NULL && tamJ>0 && cant>=0 && cant<=tamJ){
        for(int i=0; i<cant;i++){
            strcpy(juegos[i].descripcion,descripcionJuego[i]);
            juegos[i].codigo=codigos[i];
            juegos[i].idCategoria=idCategoriaJuego[i];
            juegos[i].importe=importes[i];
            total++;
        }
    }
    return total;
}

int hardcodearClientes(eCliente clientes[],int tamC, int cant, int* pId){
    int total=0;
    if(clientes!=NULL && tamC>0 && cant>=0 && cant<=tamC){
        for(int i=0; i<cant;i++){
            clientes[i].codigo=*pId;
            clientes[i].isEmpty=0;
            strcpy(clientes[i].nombre,nombres[i]);
            strcpy(clientes[i].apellido,apellidos[i]);
            strcpy(clientes[i].telefono,telefonos[i]);
            clientes[i].idLocalidad=localidades[i];
            clientes[i].sexo=sexos[i];
            (*pId)++;
            total++;
        }
    }
    return total;
}

int hardcodearAlquileres(eAlquiler alquileres[],int tamA, int cant, int* pId){
    int total=0;
    if(alquileres!=NULL && tamA>0 && cant>=0 && cant<=tamA){
        for(int i=0; i<cant;i++){
            alquileres[i].codigoAlquiler=*pId;
            alquileres[i].isEmpty=0;
            alquileres[i].codigoCliente=codigosCliente[i];
            alquileres[i].codigoJuego=codigosJuego[i];
            alquileres[i].fecha.dia=fechasAlq[i].dia;
            alquileres[i].fecha.mes=fechasAlq[i].mes;
            alquileres[i].fecha.anio=fechasAlq[i].anio;
            (*pId)++;
            total++;
        }
    }
    return total;
}
