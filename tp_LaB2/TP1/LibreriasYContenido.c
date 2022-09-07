#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Estructuras.h"





void crear (int array [], int dim)
{

    for (int i = 0 ; i< dim ; i++)
    {

        array [i] = -1;
    }
}



void mostrar (int array [], int dim)
{

    for  (int i = 0 ; i < dim ; i++)
    {

        printf("%d |", array [i]);


    }
}

int cargaArray (int array
                [], int dim)
{
    char opt ;
    int validos = 0 ;
    while (validos <dim && opt!=27)
    {

        printf ("\n Ingrese valores :");
        scanf ("%d",&array[validos]);
        validos++;
        (validos == dim )? printf ("\nYa se lleno el arreglo\n"):printf ("\nDesea seguir ingresando?De lo contrario PULSE ESC PARA SALIR\n");
        opt = getch ();
    }
    return validos;
}
int sumar (int array [], int dim)
{
    int suma = 0 ;
    for(int i = 0 ; i <dim ; i++)
    {

        (array[i] == -1 )? array [i] = 0:"";

        suma+=array[i];
    }

    return suma ;
}
float promedio (int suma, int validos)
{
    float promedio = (float) suma / validos;
    return promedio ;
}
float punto1 (int arreglo[], int dim)
{
    crear (arreglo, dim);
    mostrar (arreglo,dim);
    int validos = cargaArray (arreglo,dim);
    int suma = sumar (arreglo,dim);
    float pro = promedio (suma,validos);

    return pro ;
}

int potencia (int a)
{
    int val = 1 ;
    int i ;
    if (a == 0 )
    {
        val = 1;
    }
    else
    {
        for (i =1 ; i < a; i++)
        {

            val = val * 10;
        }
    }

    return val ;
}


int conjuncion (int array[], int dim)
{
    int conjunto = 0 ;
    for (int i = 0 ; i <dim ; i++)
    {

        conjunto +=array[i] * potencia (dim-i);

    }


    return conjunto;

}
void intercambio (int * a, int * b)
{

    int x = *a;
    *a = *b;
    *b= x;


}
void cargaEstructura (persona P[], int dim )
{

    for(int i = 0 ; i<dim; i++)
    {

        printf("\nIngrese la edad de la persona:");
        scanf("%d",&P[i].edad);
        printf ("\nIngrese el genero : [M][F]:");
        P[i].genero = getch();
        printf("\nIngrese el nombre:");
        fflush(stdin);
        gets(P[i].nombre);
        printf("\n\nLos datos fueron cargados con exito!\n");

    }



}
void MostrandoEstructura (persona P)
{

    printf("\nEDAD:%d",P.edad);
    printf("\nGenero :%c",P.genero);
    printf("\nNombre:%s",P.nombre);



}
void mostrandoTodas (persona P [], int dim)
{

    for(int i = 0 ; i < dim; i++)
    {


        MostrandoEstructura(P[i]);
        printf("\n_____________________________________________________\n");

    }

}
int capturandoGenero (persona P [], int dim, char g)
{

    int sexo=0;

    for (int i= 0 ; i<dim; i++)
    {
        P[i].genero == g ? sexo++:"";

    }




    return sexo ;
}
int pasarlasGenero (persona o [], int validosO, char g, persona d[], int validosD)
{
    for (int i= 0 ;i<validosO;i++){
        if (o[i].genero== g ){

            d[validosD]= o [i];
            validosD++;

        }
    }


    return validosD;
}





//Al momento de crear un arreglo dinamico es decir que cambien con el transcurso de la info
//  Recolectada lo que se tiene que hacer es un funcion en la que sea de tipo ESTRUCTURA QUE LLKEVA
persona * capturandoGeneroArray (persona P[],int dim,char g)
{


    persona * p =(persona*) malloc (sizeof(persona)* capturandoGenero(P,dim,g));
    //Al momento de crear un arreglo redimensionado lo que tenemos que hacer es declarrar un puntero de tipo la estructura
//Que luego lo instancia  y utilizo malloc
    int generos = capturandoGenero(P,dim,g);

    return p;



}

