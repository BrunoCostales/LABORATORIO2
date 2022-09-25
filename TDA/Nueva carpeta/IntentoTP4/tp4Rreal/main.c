#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{

    int id;
    int edad;
    char nombre[20];


} stPersona;

typedef struct nodo
{

    stPersona dato;

    struct nodo* siguiente;

} nodo;

nodo* inicLista ();
void crearArchivo (char ruta []);
stPersona crearDato();
nodo* crearNodoConDato(stPersona dato);
nodo* agregarAlprincipio (nodo* lista, nodo* nuevo);
void mostrarLista (nodo* lista);
void mostrarTodaLista (nodo* lista);
void cargaArchivo (char ruta [], stPersona P);
void lecturaArchivo (char ruta []);
void archivoFuncion (char ruta[]);
nodo* archivoToLista (char ruta [], nodo* lista);
nodo* ordenarListaxEdad(nodo* lista, nodo* nuevo);
int analizandoEdad(nodo*lista,int edad);
nodo* agregarAlfinal(nodo*lista,nodo* nuevo);
nodo* intercalandoListas (nodo* lista1, nodo* lista2);
nodo* invertirLista(nodo* lista);
int main()
{
    printf("Hello world!\n");

    char ruta []= {"PrimerArchivo.dat"};


    nodo* lista =inicLista();
//    lista= crearNodoConDato(crearDato());
//    for(int i = 0 ; i<2; i++)
//    {
//        lista = agregarAlprincipio(lista,crearNodoConDato(crearDato()));
//    }





    lista =archivoToLista(ruta,lista);

    mostrarTodaLista(lista);



    return 0;
}
nodo* inicLista ()
{

    return NULL;
}

stPersona crearDato ()
{


    stPersona P;
    printf("\nCREACION DE DATO:\n");
    printf("\nIngrese edad ");
    scanf("%d", &P.edad);
    printf("\nIngrese NOMBRE: ");
    fflush(stdin);
    gets(P.nombre);


    return P;
}
nodo* crearNodoConDato(stPersona dato)
{

    nodo* nuevo = (nodo*) malloc(sizeof(nodo));//Arreglo dinamico
    nuevo->dato=dato;//Asignamos el dato
    nuevo->siguiente=NULL;//No hay siguiente TODAVIA

    return nuevo;
}
nodo* agregarAlprincipio (nodo* lista, nodo* nuevo)
{

    nuevo->siguiente=lista;
    return nuevo;
}
void mostrarLista (nodo* lista)
{


    printf("\nID:%d",0);
    printf("\nEdad:%d",lista->dato.edad);
    printf("\nNombre:%s",lista->dato.nombre);
    printf("\n_______________________\n");
    printf("\nDireccion:%p",lista);
    printf("\nDireccion SIGUIENTE:%p",lista->siguiente);



}
void mostrarTodaLista (nodo* lista)
{

    nodo* seguidor=lista;
    while (seguidor)
    {

        mostrarLista(seguidor);

        seguidor=seguidor->siguiente;
    }


}
void crearArchivo(char ruta[])
{
    FILE * archivo = fopen(ruta,"ab");
    if (archivo)
    {

        printf("Se Creo Con exito\n");

    }
    fclose(archivo);


}

void cargaArchivo(char ruta[], stPersona P)
{

    FILE* archivo = fopen(ruta, "ab");

    if(archivo)
    {

        fwrite(&P,sizeof(stPersona),1,archivo);

    }
    fclose(archivo);



}
void lecturaArchivo (char ruta [])
{

    FILE* archivo = fopen (ruta, "rb");
    stPersona P;
    if (archivo)
    {

        while (fread(&P,sizeof(stPersona),1,archivo)>0)
        {
            static int id=0;
            id++;

            P.id=id;
            printf("Estructura N %d", P.id);
            printf("\n_____________\nEDAD:%d", P.edad);
            printf("\nNombre: %s",P.nombre);
            printf("\n____________________________________________\n");



        }

    }
    fclose(archivo);


}

void archivoFuncion (char ruta[])
{

    crearArchivo(ruta);
    cargaArchivo(ruta,crearDato());
    lecturaArchivo(ruta);





}
nodo* archivoToLista (char ruta [], nodo* lista)
{

    FILE* archivo = fopen (ruta,"rb");
    stPersona dato ;
    int p=0;
    if (archivo)
    {

        while (fread(&dato,sizeof(stPersona),1,archivo)>0)
        {

            lista =agregarAlprincipio(lista,crearNodoConDato(dato));
            p++;

        }

    }
    fclose(archivo);





    return lista;
}
nodo* ordenarListaxEdad(nodo* lista, nodo* nuevo)
{

    nodo* seguidor=NULL;
    nodo*anterior= NULL;
    seguidor=lista;


    if (lista) //Si la lista no es null
    {
        lista = nuevo;

    }
    else
    {

        if (nuevo->dato.edad<=lista->dato.edad)
        {

            lista=agregarAlprincipio(lista,nuevo);
        }
        else
        {

            anterior=lista;
            seguidor=lista;

            while (seguidor&&nuevo->dato.edad >seguidor->dato.edad)
            {

                anterior=seguidor;

                seguidor=seguidor->siguiente;

            }
            nuevo->siguiente=seguidor;
            anterior->siguiente=nuevo;

        }


    }





    return lista;
}
int analizandoEdad(nodo*lista, int edad)
{
    int verdad=0;
    nodo* seguidora= lista;
    while (seguidora && verdad==0)
    {
        if (seguidora->dato.edad==edad)
        {

            verdad=1;
        }


        seguidora=seguidora->siguiente;

    }

    return verdad;
}

nodo* agregarAlfinal(nodo*lista,nodo* nuevo)
{

    if (lista)
    {
        while (lista->siguiente!=NULL)
        {

            lista=lista->siguiente;
        }
        lista->siguiente=nuevo;

    }
    else
    {
        lista=nuevo;
    }


    return lista;
}

nodo* intercalandoListas (nodo* lista1, nodo* lista2)
{

    nodo* listaDefinitiva=NULL;
    nodo* auxiliar=NULL;


    while (lista1&&lista2)
    {

        if(lista1->dato.edad<lista2->dato.edad)
        {

            auxiliar=lista1;
            lista1=lista1->siguiente;


        }
        else
        {

            auxiliar=lista2;
            lista2=lista2->siguiente;

        }
    }

    if(lista1)
    {


        listaDefinitiva=agregarAlfinal(listaDefinitiva,lista1);
    }
    else if (lista2)
    {

        listaDefinitiva=agregarAlfinal(listaDefinitiva,lista2);
    }



    return listaDefinitiva;

}
nodo* invertirLista(nodo* lista){
    nodo* listaInvertida=NULL;
    nodo* aux=NULL;
    while(lista){
        aux=lista;
        lista=lista->siguiente;
        aux->siguiente=NULL;
        listaInvertida=agregarAlPpio(listaInvertida, aux);
    }
    return listaInvertida;
}

