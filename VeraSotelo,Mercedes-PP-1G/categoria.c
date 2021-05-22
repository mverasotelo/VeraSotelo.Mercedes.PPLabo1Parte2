#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "categoria.h"

int cargarDescripcionCategoria(int idCategoria, eCategoria categorias[], int tamCat, char descripcion[20]){
    int todoOk=0;
    if(categorias!=NULL && tamCat>0 && descripcion!=NULL){
        for(int i=0; i<tamCat;i++){
            if(categorias[i].id==idCategoria){
                strcpy(descripcion,categorias[i].descripcion);
                break;
                todoOk=1;
            }
        }
    }
    return todoOk;
}

int mostrarCategorias(eCategoria categorias[], int tam){
    int todoOk=0;
    if(categorias!=NULL && tam>0){
        printf("     CATEGORIAS\n");
        printf("  ID     DESCRIPCION\n");
        for(int i=0;i<tam;i++){
            printf(" %3d     %10s \n", categorias[i].id, categorias[i].descripcion);
        }
        todoOk=1;
    }
    printf("\n");
    return todoOk;
}
