#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#define TAMSTR 51
#define TAMTEL 21

int inicializarClientes(eCliente clientes[], int tam){
    int retorno=0;
    if(clientes!=NULL && tam>0){
        for(int i=0; i<tam;i++){
            clientes[i].isEmpty=1;
        }
        retorno=1;
    }
    return retorno;
}

int buscarLugar(eCliente clientes[], int tam){
    int indice=-1;
    for(int i=0;i<tam;i++){
        if (!clienteActivo(clientes[i])){
            indice=i;
            break;
        }
    }
    return indice;
}

int clienteActivo(eCliente cliente){
    return !cliente.isEmpty;
}

int contarClientes(eCliente clientes[],int tam){
    int contadorClientes=0;
    if(clientes != NULL && tam>0){
        for(int i=0;i<tam;i++){
            if (clienteActivo(clientes[i])){
                contadorClientes++;
            }
        }
    }
    return contadorClientes;
}

int altaCliente(eCliente clientes[], int tam, int *pId){
    int todoOk=0;
    int indice=buscarLugar(clientes, tam);
    eCliente nuevoCliente;
    if(clientes != NULL && tam>0 && pId != NULL){
        if(indice==-1){
            printf("No hay lugar disponible.\n");
        }else{
            nuevoCliente.codigo=*pId;
            printf("    ALTA DE CLIENTES\n");
            printf ("Codigo de cliente: %d\n", nuevoCliente.codigo);
            printf ("Ingrese nombre: ");
            getString(nuevoCliente.nombre,TAMSTR);
            printf ("Ingrese apellido: ");
            getString(nuevoCliente.apellido,TAMSTR);
            getSexo(&nuevoCliente.sexo);
            printf ("Ingrese telefono: ");
            getString(nuevoCliente.telefono,21);
            getLocalidad(&nuevoCliente.idLocalidad);
            printf("\n");
            nuevoCliente.isEmpty=0;
            clientes[indice]=nuevoCliente;
            todoOk=1;
            (*pId)++;
        }
    }
    return todoOk;
}

int buscarCliente(eCliente clientes[], int tam, int codigo){
    int indiceCliente=-1;
    for(int i=0;i<tam;i++){
        if (clienteActivo(clientes[i]) && clientes[i].codigo==codigo){
            indiceCliente=i;
            break;
        }
    }
    return indiceCliente;
}

int ordenarClientes(eCliente clientes[], int tam){
    int todoOk=0;
    eCliente aux;
    if(clientes!=NULL && tam>0){
        for(int i=0; i<tam-1;i++){
            for(int j=i+1; j<tam; j++){
                if(clienteActivo(clientes[i])){
                    if(strcmp(clientes[i].apellido,clientes[j].apellido)>0||
                       ((strcmp(clientes[i].apellido,clientes[j].apellido)==0)&&(strcmp(clientes[i].nombre,clientes[j].nombre)>0))){
                        aux=clientes[i];
                        clientes[i]=clientes[j];
                        clientes[j]=aux;
                    }
                }
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int mostrarClientes(eCliente clientes[], int tam, eLocalidad localidades[], int tamLoc){
    int cantidadClientes=0;
    int flag=0;
    ordenarClientes(clientes,tam);
    if(clientes!=NULL && tam>0){
        printf(" CODIGO               NOMBRE              APELLIDO       SEXO     TELEFONO         LOCALIDAD\n");
        for(int i=0;i<tam;i++){
            if (clienteActivo(clientes[i])){
                mostrarCliente(clientes[i], localidades, tamLoc);
                flag=1;
                cantidadClientes++;
            }
        }
        if(!flag){
            printf("No hay clientes para mostrar\n");
        }
        printf("\n");
    }
    return cantidadClientes;
}

void mostrarCliente(eCliente cliente,eLocalidad localidades[], int tamLoc){
    char localidad[20];
    cargarDescripcionLocalidad(cliente.idLocalidad, localidades, tamLoc, localidad);
    printf("  %04d  %20s  %20s         %c     %10s      %11s\n",
        cliente.codigo,
        cliente.nombre,
        cliente.apellido,
        cliente.sexo,
        cliente.telefono,
        localidad);
}

int modificarCliente(eCliente clientes[], int tam, eLocalidad localidades[], int tamLoc){
    int todoOk=0;
    int codigo;
    int indice;
    if(clientes != NULL && tam>0){
        printf("    MODIFICAR CLIENTES\n");
        int contClientes=mostrarClientes(clientes,tam, localidades, tamLoc);
        if(contClientes>0){
            printf("Ingrese codigo del cliente a modificar: ");
            scanf("%d",&codigo);
            printf("\n");
            indice=buscarCliente(clientes,tam,codigo);
            if(indice!=-1){
                modificarDato(clientes,tam,codigo,submenuModificar());
            }else{
                printf("No existe el cliente con el codigo %d.\n\n", codigo);
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int modificarDato(eCliente clientes[], int tam, int codigo, int datoModif){
    int todoOk=0;
    if(clientes != NULL && tam>0){
        int indice=buscarCliente(clientes,tam,codigo);
        eCliente modifCliente=clientes[indice];
        switch (datoModif){
        case 1:
            printf("Ingrese nuevo nombre: ");
            getString(modifCliente.nombre, TAMSTR);
            break;
        case 2:
            printf("Ingrese nuevo apellido: ");
            getString(modifCliente.apellido, TAMSTR);
            break;
        case 3:
            printf ("Ingrese nuevo telefono: ");
            getString(modifCliente.telefono, TAMTEL);
            break;
        }
        clientes[indice]=modifCliente;
        todoOk=1;
    }
    return todoOk;
}

int bajaCliente(eCliente clientes[], int tam, eLocalidad localidades[], int tamLoc){
    int codigo=-1;
    int indice;
    char confirmar;
    if(clientes!=NULL && tam>0){
        printf("    BAJA DE CLIENTES\n");
        mostrarClientes(clientes,tam, localidades,tamLoc);
        printf("Codigo del cliente a dar de baja: ");
        scanf("%d", &codigo);
        printf("\n");
        indice=buscarCliente(clientes,tam,codigo);
        if(indice!=-1){
            printf("Seguro que desea dar de baja al cliente?\n");
            fflush (stdin);
            scanf("%c", &confirmar);
            if(confirmar=='s'){
                clientes[indice].isEmpty=1;
            }else{
                printf("Baja cancelada por el usuario.\n");
            }
        }else{
            printf("El codigo del cliente no existe.\n");
        }
    }
    return codigo;
}

int cargarApellido(int codCliente, eCliente clientes[], int tam, char descripcion[51]){
    int todoOk=0;
    if(clientes!=NULL && tam>0 && descripcion!=NULL){
        for(int i=0; i<tam;i++){
            if(clientes[i].codigo==codCliente){
                strcpy(descripcion,clientes[i].apellido);
                break;
                todoOk=1;
            }
        }
    }
    return todoOk;
}
