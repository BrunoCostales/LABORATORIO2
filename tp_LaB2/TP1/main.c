#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Estructuras.h"




int main()
{
  int array [4];
////    int arreglo [5];
////    printf("El promedio es %.2f!\n", punto1(arreglo,5));

//    int x = 4;
//    int y =292;
//    intercambio(&x,&y);
//    intercambio(&x,&y);
//
//    printf ("%d  y =%d\n",x,y);

    persona p [4];
    cargaEstructura(p,4);
    mostrandoTodas(p,4);
    int g =capturandoGenero(p,4,'F');
    printf("%d",g);
    return 0;
}

