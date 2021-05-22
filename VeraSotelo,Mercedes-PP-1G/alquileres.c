#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alquileres.h"


int inicializarAlquileres(eAlquiler alquileres[], int tam){
    int retorno=0;
    if(alquileres!=NULL && tam>0){
        for(int i=0; i<tam;i++){
            alquileres[i].isEmpty=1;
        }
        retorno=1;
    }
    return retorno;
}

int buscarLugarAlq(eAlquiler alquileres[], int tam){
    int indice=-1;
    for(int i=0;i<tam;i++){
        if (alquileres[i].isEmpty==1){
            indice=i;
            break;
        }
    }
    return indice;
}

int altaAlquiler(eAlquiler alquileres[], int tam, int *pId, eCliente clientes[], int tamC, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat, int anioInicial, eLocalidad localidades[], int tamLoc){
    int todoOk=0;
    int indice=buscarLugarAlq(alquileres, tam);
    eAlquiler nuevoAlquiler;
    if(alquileres != NULL && tam>0 && pId != NULL && categorias != NULL && tamCat>0 && clientes != NULL && tamC>0 && juegos != NULL && tamJ>0){
        if(indice==-1){
            printf("No hay lugar disponible.\n");
        }else{
            nuevoAlquiler.codigoAlquiler=*pId;
            printf("    ALTA DE ALQUILERES\n");
            printf ("Codigo de alquiler: %d\n", nuevoAlquiler.codigoAlquiler);
            printf("\n");
            mostrarClientes(clientes, tamC, localidades, tamLoc);
            printf("\n");
            printf ("Ingrese codigo cliente: ");
            scanf("%d", &nuevoAlquiler.codigoCliente);
            if(buscarCliente(clientes, tamC, nuevoAlquiler.codigoCliente)==-1){
                printf ("El codigo del cliente no existe. Ingrese otro codigo: ");
                fflush(stdin);
                scanf("%d", &nuevoAlquiler.codigoCliente);
                printf("\n");
            }
            mostrarJuegos(juegos,  tamJ, categorias, tamCat);
            printf("\n");
            printf ("Ingrese codigo de juego: ");
            scanf("%d", &nuevoAlquiler.codigoJuego);
            printf("\n");
            while(buscarJuego(juegos, tamJ, nuevoAlquiler.codigoJuego)==-1){
                printf ("El codigo del juego no existe. Ingrese otro codigo: ");
                fflush(stdin);
                scanf("%d", &nuevoAlquiler.codigoJuego);
            }
            getFecha(&nuevoAlquiler.fecha, anioInicial);
            printf("\n");
            nuevoAlquiler.isEmpty=0;
            alquileres[indice]=nuevoAlquiler;
            todoOk=1;
            (*pId)++;
        }
    }
    return todoOk;
}

int contarAlquileres(eAlquiler alquileres[],int tam){
    int contador=0;
    if(alquileres != NULL && tam>0){
        for(int i=0;i<tam;i++){
            if (alquileres[i].isEmpty==0){
                contador++;
            }
        }
    }
    return contador;
}

int listarAlquileres(eAlquiler alquileres[], int tam, eCliente clientes[], int tamC, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat){
    int todoOk=0;
    printf(" CODIGO       CLIENTE             JUEGO            CATEGORIA            FECHA\n");
    if(alquileres != NULL && tam>0 && clientes != NULL && tamC>0 && juegos != NULL && tamJ>0 && categorias != NULL && tamCat>0){
        for(int i=0;i<tam;i++){
            if(!alquileres[i].isEmpty){
                mostrarAlquiler(alquileres[i], clientes, tamC, juegos, tamJ, categorias, tamCat);
            }
        }
    todoOk=1;
    }
    printf("\n");
    return todoOk;
}

void mostrarAlquiler(eAlquiler alquiler, eCliente clientes[], int tamC, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat){
    char descripcionJuego[20];
    char apellido[51];
    char categoria[20];
    int idCategoria;
    cargarApellido(alquiler.codigoCliente, clientes, tamC, apellido);
    cargarDescripcionJuego(alquiler.codigoJuego, juegos, tamJ, descripcionJuego);
    for(int i=0;i<tamJ;i++){
        if(alquiler.codigoJuego==juegos[i].codigo){
            idCategoria=juegos[i].idCategoria;
            break;
        }
    }
    cargarDescripcionCategoria(idCategoria, categorias, tamCat, categoria);
    printf(" %d      %10s         %10s          %10s          %02d/%02d/%d\n", alquiler.codigoAlquiler, apellido, descripcionJuego, categoria, alquiler.fecha.dia, alquiler.fecha.mes, alquiler.fecha.anio);
}

int bajaAlquileresCliente(eAlquiler alquileres[],int tam, int codEmpleado){
    int todoOk=0;
    if(alquileres != NULL && tam>0){
        for(int i=0;i<tam;i++){
            if(alquileres[i].codigoCliente==codEmpleado){
                alquileres[i].isEmpty=1;
            }
        }
        todoOk=1;
    }
    return todoOk;
}
