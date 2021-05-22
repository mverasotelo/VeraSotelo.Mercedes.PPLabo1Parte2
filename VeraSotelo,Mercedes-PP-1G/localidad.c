#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "localidad.h"

int cargarDescripcionLocalidad(int idLocalidad, eLocalidad localidades[], int tamLoc, char localidad[20]){
    int todoOk=0;
    if(localidades!=NULL && tamLoc>0 && localidad!=NULL){
        for(int i=0; i<tamLoc;i++){
            if(localidades[i].id==idLocalidad){
                strcpy(localidad,localidades[i].localidad);
                break;
                todoOk=1;
            }
        }
    }
    return todoOk;
}
