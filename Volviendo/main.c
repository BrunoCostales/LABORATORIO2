#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructura.h"



int main()
{
    printf("Hello world!\n");
    stEstructura e = cargaEstructura();
    stEstructura f = cargaEstructura();
    mostrarEstructura(e);
    mostrarEstructura(f);



    return 0;
}

//Al momento de crear librerias podes optar para una mejor organizacion en creas en FILE new File  un .h donde van
//LAS DECLARACIONES DE TODOOO ESTRUCTURA Y PROTOTIPADO


///LUEGO EN EL .C  va el contenido de las funciones y se agregan todas las librerias


///Dejando asi el main totalmente libre para unicamente llamar


//Para guardar todo lo que contenga el printf se utiliza sprintF por lo que se almacena todo en la variable que pongamos delant
// por ejemplo sprintf (s, "ACANESTA TODO EL STRING"))
