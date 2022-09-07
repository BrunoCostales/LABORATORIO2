#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructura.h"


void mostrarEstructura (stEstructura E){

printf ("\n         ID : .......%d", E.id);
printf ("\n     NOMBRE : .......%s", E.nombre);
printf ("\n       EDAD : .......%s", E.edad);
printf ("\n         CP : .......%s", E.cp);


}
stEstructura cargaEstructura (){

stEstructura E ;
    static int id = 0 ;   //INCREMENTA DE MANERA HARDCORE y vive como una variable global y siempre vive
    id ++;
    E.id = id ;
    strcpy(E.nombre,"Bruno" );
    strcpy(E.edad,"21");
    strcpy(E.cp,"76");




return E ;
}
char * pasarDatoPuntero (stEstructura e){

    char * s = (char *) malloc (sizeof(char)*200);

    return s ;

}
