#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"

//1- Mostrar Juegos de categoría de mesa
int mostrarJuegosCategMesa(eJuego juegos[], int tamJ){
    int todoOk=0;
    int flag=1;
    int categMesa=10;
    if(juegos!=NULL && tamJ>0){
        printf("               JUEGOS DE CATEGORIA MESA\n");
        printf(" CODIGO          DESCRIPCION           IMPORTE\n");
        for(int j=0;j<tamJ;j++){
            if(categMesa==juegos[j].idCategoria){
                    printf("   %d           %10s            %7.2f\n", juegos[j].codigo, juegos[j].descripcion, juegos[j].importe);
                    flag=0;
                }
            }
            if(flag){
                printf("              No hay juegos de mesa\n");
        }
    todoOk=1;
    printf("\n\n");
    }
    return todoOk;
}

//2- Mostrar los alquileres efectuados por algún cliente seleccionado
int mostrarAlquileresCliente(eAlquiler alquileres[], int tam, eCliente clientes[], int tamC, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat, eLocalidad localidades[], int tamLoc){
    int todoOk=0;
    int idCliente;
    int flag=1;
    eCliente cliente;
    int indiceCliente;

    mostrarClientes(clientes, tamC, localidades, tamLoc);
    printf("\n");
    printf("Ingrese ID del cliente: ");
    scanf("%d", &idCliente);
    indiceCliente=buscarCliente(clientes, tamC, idCliente);
    if(indiceCliente!=-1){
        cliente=clientes[indiceCliente];
    }else{
        printf("Codigo de cliente inexistente.\n");
    }
    printf("\n");

    if(clientes!=NULL && tamC>0 && juegos!=NULL && tamJ>0&& alquileres!=NULL && tam>0 && categorias!=NULL && tamCat>0){
        printf("                        Alquileres de %s %s\n", cliente.nombre, cliente.apellido);
        printf(" CODIGO       CLIENTE             JUEGO            CATEGORIA            FECHA\n");
        for(int j=0;j<tam;j++){
            if(alquileres[j].codigoCliente==idCliente){
                mostrarAlquiler(alquileres[j],clientes, tamC, juegos, tamJ, categorias, tamCat);
                flag=0;
            }
        }
        if(flag){
            printf("              El cliente no ha alquilado ningun juego\n");
        }
    todoOk=1;
    printf("\n\n");
    }
    return todoOk;
}

//3- Mostrar el total de todos los importes pagados por el cliente seleccionado
int sumatoriaAlquileresXCliente(eAlquiler alquileres[], int tam, eCliente clientes[], int tamC, eJuego juegos[], int tamJ, eLocalidad localidades[], int tamLoc){
    int todoOk=0;
    int idCliente;
    int flag=1;
    eCliente cliente;
    int indiceCliente;
    float sumCliente=0;

    mostrarClientes(clientes, tamC, localidades, tamLoc);
    printf("\n");
    printf("Ingrese ID del cliente: ");
    scanf("%d", &idCliente);
    indiceCliente=buscarCliente(clientes, tamC, idCliente);
    if(indiceCliente!=-1){
        cliente=clientes[indiceCliente];
    }else{
        printf("Codigo de cliente inexistente.\n");
    }
    printf("\n");

    if(clientes!=NULL && tamC>0 && juegos!=NULL && tamJ>0&& alquileres!=NULL && tam>0){
        for(int i=0;i<tam;i++){
            if(alquileres[i].codigoCliente==clientes[indiceCliente].codigo){
                for(int j=0;j<tam;j++){
                    if(alquileres[i].codigoJuego==juegos[j].codigo){
                        sumCliente+=juegos[j].importe;
                        flag=0;
                    }
                }
            }
        }
    if(flag){
        printf("El cliente no ha alquilado ningun juego\n");
    }else{
        printf("Importe total de los alquileres %s %s: $%.2f\n", cliente.nombre, cliente.apellido, sumCliente);
    }
    todoOk=1;
    printf("\n\n");
    }
    return todoOk;
}

//4- Listar los clientes que no alquilaron juegos
int clientesSinAlquileres(eAlquiler alquileres[], int tam, eCliente clientes[], int tamC, eLocalidad localidades[], int tamLoc){
    int contClientes[tamC];
    int flag=1;
    for(int i=0;i<tamC;i++){
        contClientes[i]=0;
    }
    int todoOk=0;

    if(alquileres!=NULL && tam>0 && clientes!=NULL && tamC>0 && localidades!=NULL && tamLoc>0){
        for(int j=0;j<tamC;j++){
            if(clienteActivo(clientes[j])){
                for(int i=0;i<tam;i++){
                    if(alquileres[i].isEmpty==0 && alquileres[i].codigoCliente==clientes[j].codigo){
                        contClientes[j]++;
                        flag=0;
                    }
                }
            }
        }
        printf("Clientes que no alquilaron juegos:\n");
        for(int m=0;m<tamC;m++){
            if(clienteActivo(clientes[m]) && contClientes[m]<1){
                mostrarCliente(clientes[m], localidades, tamLoc);
            }
        }
        if(flag){
            printf("Todos los clientes alquilaron al menos un juego\n");
        }
    printf("\n\n");
    todoOk=1;
    }
    return todoOk;
}

//5- Listar los juegos que no han sido alquilados
int juegosNoAlquilados(eAlquiler alquileres[], int tam, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat){
    int contJuegos[tamJ];
    int flag=1;
    for(int i=0;i<tamJ;i++){
        contJuegos[i]=0;
    }
    int todoOk=0;

    if(alquileres!=NULL && tam>0 && juegos!=NULL && tamJ>0 && categorias!=NULL && tamCat>0){
        for(int j=0;j<tamJ;j++){
            for(int i=0;i<tam;i++){
                if(alquileres[i].isEmpty==0 && alquileres[i].codigoJuego==juegos[j].codigo){
                    contJuegos[j]++;
                    flag=0;
                }
            }
        }
        printf("Juegos que no han sido alquilados:\n");
        printf(" CODIGO         DESCRIPCION             CATEGORIA            IMPORTE\n");
        for(int m=0;m<tamJ;m++){
            if(contJuegos[m]<1){
                mostrarJuego(juegos[m], categorias, tamCat);
            }
        }
        if(flag){
            printf("No hay juegos que no hayan sido alquilados\n");
        }
    printf("\n\n");
    todoOk=1;
    }
    return todoOk;
}


//6- Listar los teléfonos de los clientes que alquilaron juegos en una determinada fecha
int telefonosAlquiladosXFecha(eAlquiler alquileres[], int tam, int anioInicial, eCliente clientes[], int tamC){
    int todoOk;
    int flag=1;
    eFecha fecha;
    if(alquileres!=NULL && tam>0 && clientes!=NULL && tamC>0){
        getFecha(&fecha, anioInicial);
        printf("   TELEFONOS DE LOS CLIENTES QUE ALQUILARON EL %02d/%02d/%d\n", fecha.dia,fecha.mes,fecha.anio);
        for(int i=0;i<tam;i++){
            if(alquileres[i].fecha.dia==fecha.dia&&alquileres[i].fecha.mes==fecha.mes&&alquileres[i].fecha.anio==fecha.anio){
                for(int j=0;j<tamC;j++){
                    if(alquileres[i].codigoCliente==clientes[j].codigo){
                        printf("%20s %20s\n",clientes[j].apellido, clientes[j].telefono);
                        flag=0;
                    }
                }
            }
        }
        if(flag){
            printf("No se ha alquilado ningun juego\n");
        }
        printf("\n");
        todoOk=1;
    }
    return todoOk;
}

//7 - Listar los juegos alquilados por mujeres
int juegosAlqMujeres(eAlquiler alquileres[], int tam, eCliente clientes[], int tamC, eJuego juegos[], int tamJ){
    int todoOk=0;
    int contJuegos[tamJ];
    int flag=1;
    for(int i=0;i<tamJ;i++){
        contJuegos[i]=0;
    }
    if(alquileres!=NULL && tam>0 && clientes!=NULL && tamC>0 && juegos!=NULL && tamJ>0){
        for(int j=0;j<tamJ;j++){
            for(int k=0; k<tam; k++){
                if(alquileres[k].codigoJuego==juegos[j].codigo&&!alquileres[k].isEmpty){
                    for(int l=0;l<tamC;l++){
                            if(alquileres[k].codigoCliente==clientes[l].codigo&&clientes[l].sexo=='m'){
                                contJuegos[j]++;
                                flag=0;
                            }
                        }
                    }
                }
                printf("Juego %s: %d\n", juegos[j].descripcion, contJuegos[j]);
            }
        printf("\n");
        printf("Juego/s alquilados/s por mujeres:\n");
        for(int m=0;m<tamJ;m++){
                if(contJuegos[m]>0){
                    printf("- %s\n", juegos[m].descripcion);
            }
        }
        if(flag){
            printf("No hay juegos alquilados por mujeres.\n");
        }
        todoOk=1;
        printf("\n\n");
    }
    return todoOk;
}

//8- Mostrar el o los juegos más alquilados por hombres
int juegoPreferidoHombres(eAlquiler alquileres[], int tam, eCliente clientes[], int tamC, eJuego juegos[], int tamJ){
    int todoOk=0;
    int contJuegos[tamJ];
    for(int i=0;i<tamJ;i++){
        contJuegos[i]=0;
    }
    int juegoPreferido=0;
    char juego[10];
    if(alquileres!=NULL && tam>0 && clientes!=NULL && tamC>0 && juegos!=NULL && tamJ>0){
        for(int j=0;j<tamJ;j++){
            for(int k=0; k<tam; k++){
                if(alquileres[k].codigoJuego==juegos[j].codigo&&!alquileres[k].isEmpty){
                    for(int l=0;l<tamC;l++){
                            if(alquileres[k].codigoCliente==clientes[l].codigo&&clientes[l].sexo=='m'){
                                contJuegos[j]++;
                            }
                        }
                    }
                }
            }
        //comparo los contadores de categorias para ver cual es el mayor
        for(int l=0;l<tamJ;l++){
            if(juegoPreferido<contJuegos[l]){
                juegoPreferido=contJuegos[l];
                strcpy(juego,juegos[l].descripcion);
            }
        }
        //imprimo la categoria favorita si hay empate de categorias, informo todas
        printf("Juego/s favorito/s de los hombres: ");
            for(int m=0;m<tamJ;m++){
                if(juegoPreferido==contJuegos[m]){
                    printf("%s ", juegos[m].descripcion);
            }
        }
        todoOk=1;
        printf("\n\n");
    }
    return todoOk;
}

//9- Listar los clientes que alquilaron un determinado juego
int clientesXJuego(eAlquiler alquileres[], int tam, eCliente clientes[], int tamC, eLocalidad localidades[], int tamLoc, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat){
    int idJuego;
    int flag=1;
    int indiceJ;
    int todoOk=0;
    mostrarJuegos(juegos,tamJ,categorias,tamCat);
    printf("\n");
    printf("Ingrese codigo del juego: ");
    scanf("%d", &idJuego);
    indiceJ=buscarJuego(juegos, tamJ, idJuego);
    while(indiceJ==-1){
        printf("Codigo de juego inexistente. Ingrese nuevamente: \n");
        scanf("%d", &idJuego);
    }
    printf("\n");
    if(alquileres!=NULL && tam>0 && clientes!=NULL && tamC>0 && juegos!=NULL && tamJ>0 && categorias!=NULL && tamCat>0){
        printf("              CLIENTES QUE ALQUILARON EL JUEGO %s\n", strupr(juegos[indiceJ].descripcion));
        printf(" CODIGO               NOMBRE              APELLIDO       SEXO     TELEFONO     LOCALIDAD\n");
        for(int k=0; k<tam; k++){
            if(idJuego==alquileres[k].codigoJuego){
                for(int l=0; l<tamC; l++){
                    if(clienteActivo(clientes[l]) && alquileres[k].isEmpty==0 && alquileres[k].codigoCliente==clientes[l].codigo){
                        mostrarCliente(clientes[l], localidades,tamLoc);
                        flag=0;
                    }
                }
            }
        }
        if(flag){
            printf("El juego no ha sido alquilado.");
        }
        todoOk=1;
        printf("\n\n");
    }
    return todoOk;
}


//10-Mostrar la recaudación de una fecha en particular
int recaudacionXFecha(eAlquiler alquileres[], int tam, eJuego juegos[], int tamJ, int anioInicial){
    int todoOk;
    float recaudacion=0;
    eFecha fecha;
    if(alquileres!=NULL && tam>0 && juegos!=NULL && tamJ>0){
        getFecha(&fecha, anioInicial);
        printf("   RECAUDACION DEL %02d/%02d/%d\n", fecha.dia,fecha.mes,fecha.anio);
        for(int i=0;i<tam;i++){
            if(alquileres[i].fecha.dia==fecha.dia&&alquileres[i].fecha.mes==fecha.mes&&alquileres[i].fecha.anio==fecha.anio){
                for(int j=0;j<tamJ;j++){
                    if(alquileres[i].codigoJuego==juegos[j].codigo){
                        recaudacion+=juegos[j].importe;
                    }
                }
            }
        }
        printf("La recaudacion fue de $%.2f\n\n",recaudacion);
        todoOk=1;
    }
    return todoOk;
}

//11- Categoria preferida Avellaneda
int categoriaPreferidaAvellaneda(eAlquiler alquileres[], int tam, eCliente clientes[], int tamC, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat){
    int todoOk=0;
    int contCateg[tamCat];
    for(int i=0;i<tamCat;i++){
        contCateg[i]=0;
    }
    int categPreferida = 0;
    char categoria[10];
    if(alquileres!=NULL && tam>0 && categorias!=NULL && tamCat>0 && juegos!=NULL && tamJ>0 && clientes!=NULL && tamC>0 ){
        printf("     CATEGORIA PREFERIDA DE AVELLANEDA\n");
        for(int i=0; i<tamCat;i++){
            for(int j=0;j<tamJ;j++){
                if(juegos[j].idCategoria==categorias[i].id){
                    for(int k=0; k<tam; k++){
                        if(alquileres[k].codigoJuego==juegos[j].codigo&&!alquileres[k].isEmpty){
                            for(int l=0;l<tamC;l++){
                                if(clienteActivo(clientes[l]) && alquileres[k].codigoCliente==clientes[l].codigo && clientes[l].idLocalidad==51){
                                    contCateg[i]++;
                                }
                            }
                        }
                    }
                }
            }
        }
        //comparo los contadores de categorias para ver cual es el mayor
        for(int l=0;l<tamCat;l++){
            if(categPreferida<contCateg[l]){
                categPreferida=contCateg[l];
                strcpy(categoria,categorias[l].descripcion);
            }
        }
        //imprimo la categoria preferida si hay empate de categorias, informo todas
        printf("Categoria/s preferida/s de los clientes de Avellaneda: ");
            for(int m=0;m<tamCat;m++){
                if(categPreferida==contCateg[m]){
                    printf("%s ", categorias[m].descripcion);
            }
        }
        todoOk=1;
        printf("\n\n");
        }
    return todoOk;
}

//12- Mostrar los alquileres efectuados por los clientes de una localidad
int mostrarAlquileresLocalidad(eAlquiler alquileres[], int tam, eCliente clientes[], int tamC, eJuego juegos[], int tamJ, eCategoria categorias[], int tamCat, eLocalidad localidades[], int tamLoc){
    int todoOk=0;
    int idLocalidad;
    int flag=1;
    for(int i=0; i<tamLoc; i++){
        printf("%d - %s\n", localidades[i].id, localidades[i].localidad);
    }
    printf("\n");
    getLocalidad(&idLocalidad);
    printf("\n");
    if(clientes!=NULL && tamC>0 && alquileres!=NULL && tam>0 && localidades!=NULL && tamLoc>0){
        printf("                        ALQUILERES DE LA LOCALIDAD\n");
        printf(" CODIGO       CLIENTE             JUEGO            CATEGORIA            FECHA\n");
        for(int j=0;j<tam;j++){
            for(int k=0;k<tamC;k++){
                if(clienteActivo(clientes[k]) && !alquileres[j].isEmpty && alquileres[j].codigoCliente==clientes[k].codigo && clientes[k].idLocalidad==idLocalidad){
                    mostrarAlquiler(alquileres[j],clientes, tamC, juegos, tamJ, categorias, tamCat);
                    flag=0;
                }
            }
        }
        if(flag){
            printf(" No han habido alquileres en la localidad\n");
        }
    todoOk=1;
    printf("\n\n");
    }
    return todoOk;
}
