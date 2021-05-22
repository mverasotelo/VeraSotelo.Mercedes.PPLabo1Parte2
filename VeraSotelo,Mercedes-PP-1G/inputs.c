#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"

int menuOpciones(){
    int opcion;
    printf("     GESTION DE JUEGOS\n");
    printf("1) Alta Cliente\n");
    printf("2) Modificar Cliente\n");
    printf("3) Baja Cliente\n");
    printf("4) Listar Clientes\n");
    printf("5) Alta alquiler\n");
    printf("6) Listar alquileres\n");
    printf("7) Informes\n");
    printf("8) Salir\n\n");
    opcion=getOption(1,7);
    return opcion;
}

int submenuModificar(){
    int opcion;
    printf("Que dato desea modificar?\n1. Nombre\n2. Apellido\n3. Sexo\n\n");
	opcion=getOption(1,3);
    return opcion;
}

int submenuInformes(){
    int opcion;
    printf("     INFORMES\n");
    printf("1. Mostrar juegos de categoria mesa\n");
    printf("2. Mostrar alquileres de un cliente\n");
    printf("3. Mostrar el total de todos los importes pagados por el cliente seleccionado\n");
    printf("4. Listar los clientes que no alquilaron juegos\n");
    printf("5. Listar los juegos que no han sido alquilados\n");
    printf("6. Listar los teléfonos de los clientes que alquilaron juegos en una determinada fecha\n");
    printf("7. Listar los juegos alquilados por mujeres\n");
    printf("8. Mostrar el o los juegos más alquilados por hombres\n");
    printf("9. Listar los clientes que alquilaron un determinado juego\n");
    printf("10. Mostrar la recaudacion de una fecha en particular\n");
    printf("11. Mostrar categoria favorita de los clientes de Avellaneda\n");
    printf("12. Mostrar alquileres por localidad\n");
    printf("13. Volver al menu anterior\n\n");
	opcion=getOption(1,13);
    return opcion;
}

int getOption(int min, int max){
	int opcion;
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    while(opcion<min||opcion>max){
        printf("Opcion invalida. Ingrese nuevamente: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }
    printf("\n");
    return opcion;
}

int getString(char *string, int maxLen){
    int retorno=0;
    char aux[100];
    if(string!=NULL && maxLen>0 && maxLen<99){
        fflush(stdin);
        fgets(aux,100,stdin);
        while(strlen(aux)>maxLen){
            printf("El maximo numero de caracteres permitidos es %d. Reingrese dato: ",maxLen);
            fflush(stdin);
            fgets(aux,100,stdin);
        }
        aux[strlen(aux)-1]='\0';
        strcpy(string, aux);
        retorno=1;
    }
    return retorno;
}

int getSexo(char* sexo){
    int retorno=0;
    printf ("Ingrese sexo (m/f): ");
    if(sexo!=NULL){
        scanf ("%c", sexo);
        while(*sexo!='f'&&*sexo!='m'){
            printf ("Error. Ingrese m/f: ");
            fflush(stdin);
            scanf ("%c", sexo);
        }
        retorno=1;
    }
    return retorno;
}

int getLocalidad(int* idLocalidad){
    int retorno=0;
    printf ("Ingrese ID localidad: ");
    if(idLocalidad!=NULL){
        scanf ("%d", idLocalidad);
        while(*idLocalidad<50||*idLocalidad>54){
            printf ("Error. Ingrese una ID valido: ");
            fflush(stdin);
            scanf ("%d", idLocalidad);
        }
        retorno=1;
    }
    return retorno;
}

int getFecha(eFecha * fecha, int anioInicial){
    int retorno=0;
    eFecha aux;
    if(fecha!=NULL){
        printf ("Ingrese fecha (dd/mm/aaaa): ");
        scanf ("%d/%d/%d",&aux.dia, &aux.mes, &aux.anio);
        while((aux.mes>12||aux.mes<1)||(aux.dia<1||aux.dia>31)||aux.anio<anioInicial){
            printf ("Error. Ingrese fecha (dd/mm/aaaa):");
            fflush(stdin);
            scanf ("%d/%d/%d",&aux.dia, &aux.mes, &aux.anio);
        }
        printf("\n");
        *fecha=aux;
        retorno=1;
    }
    return retorno;
}
