#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int factorial (int x);
int potencia (int x, int p);
int potencia2 (int x, int p); //Analizando desde atras
void mostrarArreglo (int arreglo [], int validos, int i);
int capicua (int arreglo [], int validos, int i);
int sumandoArreglo (int arreglo [], int validos, int i);
int buscandoMenor (int arreglo [], int validos);
void creandoArchiv (char ruta [],int rta [], int dim);
int menorArchivo (FILE * archi);
int meta (char ruta[]);
void invertirArreglo (int array[], int dim, int i);
void leyendoParaInvertir(char ruta[], int array[],int dim, int i);

int main()
{
    char ruta []= {"archivodeEnteros.dat"};
    int rta [6]= {5,3,7,8,5,1};
    creandoArchiv(ruta,rta,6);
//    leyendoParaInvertir(ruta,rta,6,0);


//    invertirArreglo(rta,6,0);
//    for (int i=0;i<6;i++){
//
//
//        printf("%d|", rta[i]);
//
//    }

    return 0;
}
int factorial (int x)
{

    int rta;

    if (x== 0)
    {

        rta = 1;

    }
    else
    {

        rta = x *factorial (x-1);
    }
    return rta;
}
int potencia (int x, int p)
{
    int rta ;

    if (p == 0)
    {

        rta = 1;
    }
    else
    {

        rta = x*potencia(x,p-1);

    }


    return rta ;
}


int potencia2 (int x, int p)
{
    int rta =1;

    if (p>0)
    {
        rta = x * potencia2(x,p-1);
    }


    return rta;

}

void mostrarArreglo (int arreglo [], int validos, int i)
{

    if (i < validos)
    {

        printf(" |%d |", arreglo[i]);

        mostrarArreglo(arreglo,validos,i+1);

    }



}
int capicua (int arreglo [], int validos, int i)
{

    int rta=1 ;

    if (i< validos-1)
    {
        if (arreglo[i]== arreglo[validos-1])
        {

            rta =capicua (arreglo, validos-1,i+1);



        }
        else
        {
            rta = 0;
        }

    }



    return rta ;
}
int sumandoArreglo (int arreglo [], int validos, int i)
{
    int rta=0;
    //SIEMPRE RECORRE ESTO
    if(i<validos)
    {

        rta= arreglo[i] + sumandoArreglo(arreglo, validos, i+1);


    }


    return rta ;
}



int buscandoMenor (int arreglo [], int validos)
{

    int menor;
    if (validos >0)
    {

        menor = buscandoMenor(arreglo,validos-1);
        if (arreglo[validos-1]< menor)
            menor = arreglo[validos-1];
    }



    return menor;
}

void creandoArchiv (char ruta [],int rta [], int dim)
{


    FILE *archivo = NULL;
    archivo = fopen(ruta,"ab");



    if (archivo!=NULL)
    {

        printf("Se abrio con exito\n");

        for (int i = 0; i<dim; i++)
        {

            fwrite (&rta[i], sizeof(int),1,archivo);

        }



    }
    else
    {
        printf("ProblemAS\n");
    }
    printf("\nCerro\n");
    fclose(archivo);


}
int meta (char ruta[])
{

    FILE * archivo = fopen(ruta, "rb");
    int numero, menorNumero ;
    if (archivo!=NULL)
    {
        while (fread(&numero, sizeof(int),1,archivo) > 0)
        {

            printf("| %d |",numero);

        }

        menorNumero = menorArchivo(archivo);
    }
    else
    {

        printf("\bProblemas");
        fclose(archivo);
    }
    return menorNumero ;
}



int menorArchivo (FILE * archivo)
{

    int menor;
    int datoParaLeer;

    if (fread(&datoParaLeer,sizeof(int),1,archivo)== 0) ///con esto me posiciono en el final del archivo
    {
        fseek(archivo,sizeof(int)*(-1), SEEK_END); ///COMO ESTOY POR FUERA DEL ARCHIVO VOY A UNA POSIC ANTERIOR CON -1
        fread(&menor, sizeof(int), 1, archivo);
    }
    else
    {


        datoParaLeer =menorArchivo(archivo);
        if (datoParaLeer < menor )
        {


            menor = datoParaLeer;

        }

    }






    return menor ;
}




void invertirArreglo (int array[], int dim, int i)
{
    int aux=0;
    aux= array[i];

    if (i<dim)
    {

        array[i] = array[dim-1];
        array[dim-1]=aux;
        invertirArreglo(array, dim-1,i+1);
    }




}
//void leyendoParaInvertir(char ruta[], int array[],int dim, int i){
//
//    FILE * archivo = fopen(ruta, "r+b");
//    int numero;
//    if (archivo !=NULL){
//
//        printf("\nSe ABRIO\n");
//
//        while (fread(&numero,sizeof(int),1,archivo)>0){
//
//
//            printf("\n%d", numero);
//            if (i<=dim){
//            array[i]=numero;
//            i++;
//
//            }
//
//
//        }
//        invertirArreglo(array,dim,i);
//
//
//
//    }
//    fclose(archivo);


















//1. Calcular el factorial de un número en forma recursiva.
//2. Calcular la potencia de un número en forma recursiva.
//3. Recorrer un arreglo y mostrar sus elementos en forma recursiva.
//4. Recorrer un arreglo comenzando desde la posición 0 y mostrar sus elementos en
//forma invertida (recursivo).
//5. Determinar en forma recursiva si un arreglo es capicúa.
//6. Sumar en forma recursiva los elementos de un arreglo de enteros y retornar el total de la suma.
//7. Buscar el menor elemento de un arreglo en forma recursiva.
//8. Buscar el menor elemento de un archivo de números enteros de forma recursiva. (desde el mismo archivo)
//9. Invertir los elementos de un archivo de números enteros de forma recursiva.  (si no te sale, primero proba con invertir los elementos de un arreglo de int)
//10. Recorrer un archivo y mostrar sus elementos en forma invertida de forma recursiva.
//11. Ingresar valores a una variable de tipo char (por teclado) y mostrarlo en el orden inverso (hasta ingresar un ‘*’) de forma recursiva. NO usar arreglos.
//12. Determinar si un arreglo contiene un determinado elemento de forma recursiva. (Pueden intentarlo también con una función void)(Tener en cuenta para un arreglo desordenado y el caso para un arreglo ordenado)
