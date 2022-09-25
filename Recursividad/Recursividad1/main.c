#include <stdio.h>
#include <stdlib.h>


int factorial(int x);
int factorialConTernario (int x);
int sumarecursiva(int arreglo [], int validos, int i);
int impar(int x);
int par (int x);



///La recursividad es una tecnica utilizadaa en programacion que nos permite que un bloque de instrucciones se ejecute un
///un cierto numero de veces referenciandose
///Es similar a un bucle de iteracion
///Se denomina una funjcion recursisiva si durante su ejecucion se invoca directa o indirectamente a si misma
int main()
{
    //Se compone por dos partes la primera que es la solucion trivial--> lo que sea finito la recursividad
    ///SIEMPRE HAY UNA CONDICION DE CORTE AL MENOS(solucion Trivial)
    ///Y en cada llamada recursiva se acerca mas a esto
    //La otra parte es la autoreferencia

    //EJ:un factorial 5! 5x4x3x2x1 (n-1)
    //x! = x*(x-1)!

    int rta = impar(7020);
    printf("%d",rta);


    return 0;
}

//Ejemplo: RECURSIVIDAD DIRECTA
int factorial (int x)
{
    int rta = 0 ;
    //Condicion de Corte
    if (x==0)
        rta=1; //Solucion Trivial
    else
        ///Llamada recursiva
        rta = x*factorial(x-1); //Condicion de corte EXPLICITA
    return rta;
}
///Atencion a los datos pasados y la recursividad mantiene la memoria abierta
///se suspende la ejecucion de la funcion invocante hasta que la termine de resolver y GENERA UN NUEVO ESPACIO
//Cada llamada recursiva es una funcion diferente


int factorialConTernario (int x)
{
    return (x==0)?1:x*factorialConTernario(x-1);
}

int sumarecursiva(int arreglo [], int validos, int i)
{
    int rta =0 ;

    if (i == validos)//Aca llegaria al final de los elementos del arreglo
    {
        rta = 0 ;
    }
    else//Como no llego
    {
     //Aca va a llegar el dato             ///i+1 es un acercamiento y validos el maximo
        rta = arreglo [i]+sumarecursiva(arreglo, validos,i+1); //*Suma el elemento con el proximo y asi

    }

    return rta;
}
///LUEGO EXISTE LA RECURSIVIDAD INDIRECTA


int impar (int x){

int rta =0 ;
if (x==0){
    rta = 0;
}else{
    rta = par (x -1);

}

return rta;
}
int par (int x){
int rta ;
if (x ==0){


    rta =1;

}else{

    rta = impar (x-1);

}


return rta ;
}

///Relacion entre RECURSION E iteracion
//En la recursividad no hay ciclos, hay una estructura de seleccion
//En la la iteracion una de repeticion

///Repeticion
//En la recusividad es mas implicita

///Terminacion
//La iteracion termina cuando falla la condicion
//En la recursividad cuando la condicionde corte es verdadera

///Repeticion Infinita
//La iteracion se puede quedar en un bucle infinito si la condicion nunca es falsa
//La recursion se hace infinita si  no hay acercamiento

///PROBLEMA RECURSIVO
//La recursividad invoca de manera repetida y puede sobrecargar el procesador



///ITERACION VS RECURSIVIDAD

//La solucion recursiva controla las invocaciones por ende en el desarrollo de la misma
//puede consumir mucho espacio y tiempo de memoria

//Solucion recursiva solo cuando no puede ser facilmente expresada iterativamente
//La eficiencia de la solucion recursiva es satisfactoria
