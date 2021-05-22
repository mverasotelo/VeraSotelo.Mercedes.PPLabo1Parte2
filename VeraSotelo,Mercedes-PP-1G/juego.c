#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "juego.h"

int mostrarJuegos(eJuego juegos[], int tam, eCategoria categorias[], int tamCat){
    int todoOk=0;
    if(juegos!=NULL && tam>0){
        printf(" CODIGO         DESCRIPCION             CATEGORIA            IMPORTE\n");
        for(int i=0;i<tam;i++){
            mostrarJuego(juegos[i], categorias, tamCat);
        }
        todoOk=1;
    }
    printf("\n");
    return todoOk;
}

void mostrarJuego(eJuego juego, eCategoria categorias[], int tamCat){
    char descripcion[20];
    cargarDescripcionCategoria(juego.idCategoria, categorias, tamCat, descripcion);
    printf(" %4d          %10s             %10s            $%7.2f\n",juego.codigo, juego.descripcion, descripcion, juego.importe);
}

int buscarJuego(eJuego juegos[], int tam, int codigo){
    int indice=-1;
    for(int i=0;i<tam;i++){
        if (juegos[i].codigo==codigo){
            indice=i;
            break;
        }
    }
    return indice;
}

int cargarDescripcionJuego(int idJuego, eJuego juegos[], int tamJ, char descripcion[20]){
    int todoOk=0;
    if(juegos!=NULL && tamJ>0 && descripcion!=NULL){
        for(int i=0; i<tamJ;i++){
            if(juegos[i].codigo==idJuego){
                strcpy(descripcion,juegos[i].descripcion);
                break;
                todoOk=1;
            }
        }
    }
    return todoOk;
}
