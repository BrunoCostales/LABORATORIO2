#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct
{
    int id;
    char nombre [20];
    int edad;
    char sexo;
} stPersona;
typedef struct nodo
{
    stPersona dato;

    struct nodo*siguiente;
} nodo;



nodo * inicLista();
nodo * crearNodo(stPersona dato);
stPersona cargaPersona();
void mostrarPersona (stPersona p);
nodo * agregarAlPrincipio(nodo * lista, nodo * nuevo);
void muestraLista (nodo * lista);
nodo *agregarAlPrincipioPro(nodo* lista, nodo* nuevo);
nodo * buscandoUltimo (nodo* lista);
nodo * agregarAlFinal(nodo* lista, nodo* nuevo);
nodo* agregarOrdenadoxEdad (nodo* lista, nodo* nuevo);
nodo* intercalandoListas (nodo* lista1,nodo* lista2);
nodo* archivoAlista (char ruta[], nodo*lista);
nodo* archivoAlistaFiltrada (char ruta[], nodo*lista, int edad);
nodo* archivoAlistaFiltradaXnombre (char ruta[], nodo*lista, char nombre[]);


///COMO CARGO UNA LISTA?
// Cargo a la persona y cargo la lista en vez del arreglos es repetir la linea 40
int main()
{
    printf("Hello world!\n");


    nodo * lista ;
    lista= inicLista();
    for (int i=0; i<10; i++)
        lista = agregarAlPrincipioPro(lista,crearNodo(cargaPersona()));

    printf("\nLista:\n");
    muestraLista(lista);

    return 0;
}
nodo * inicLista()
{
    return NULL;

}
stPersona cargaPersona()
{
    static int id = 0;
    id++;

    stPersona p;
    p.id=id;
    strcpy(p.nombre,"Bruno");
    p.edad=21;
    p.sexo='M';


    return p;
}
void mostrarPersona (stPersona p)
{
    printf("\nID:%d",p.id);
    printf("\nNombre.....:%s",p.nombre);
    printf("\nEdad.......:%d",p.edad);
    printf("\nSexo.......:%c",p.sexo);
    printf("\n_______________________________\n");


}


nodo * crearNodo(stPersona dato)
{
    nodo * nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->dato=dato;
    nuevo ->siguiente=NULL;



    return nuevo;
}
nodo * agregarAlPrincipio(nodo * lista, nodo * nuevo)
{

    if (lista==NULL)
    {

        lista=nuevo;

    }
    else
    {

        nuevo->siguiente=lista;
        lista = nuevo;
    }



    return  lista;
}

void muestraLista (nodo * lista)
{
    nodo* seguidor =lista ;
    while(lista !=NULL)
    {

        mostrarPersona(seguidor->dato);
        seguidor=seguidor->siguiente;

    }


}
void muestraNodo(nodo* no){
    printf("\nNodo:%p",no);
    mostrarPersona(no->dato);
    printf("\nNodo->siguiente:%p",no->siguiente);

}
nodo *agregarAlPrincipioPro(nodo* lista, nodo* nuevo)
{

    nuevo->siguiente=lista;
    return nuevo;



}

nodo * buscandoUltimo (nodo* lista)
{
    nodo * seguidor = lista;
    while (seguidor->siguiente !=NULL)
    {

        seguidor=seguidor->siguiente;
    }


    return seguidor;
}
nodo * agregarAlFinal(nodo* lista, nodo* nuevo)
{
    if (lista == NULL)
    {
        lista = nuevo;

    }
    else
    {


        nodo * ultimo = buscandoUltimo(lista);

        ultimo ->siguiente=nuevo;


    }

    return lista;
}

nodo* agregarOrdenadoxEdad (nodo* lista, nodo* nuevo)
{

    if (!lista)  //Si la lista esta vacia, esta oredenada
    {
        lista = nuevo;
    }
    else
    {

        //Sie el nuevo nodo es menor a la lista

        if (nuevo->dato.edad <= lista->dato.edad)
        {

            lista=agregarAlPrincipioPro(lista,nuevo);
        }
        else
        {


            nodo* anterior = lista;
            nodo* seguidora = lista;

            while (seguidora&&(nuevo->dato.edad > seguidora->dato.edad))
            {
                anterior=seguidora;
                seguidora=seguidora->siguiente;

            }

            //Insertar el nuevo nodo en la lista de manera ordenada
            nuevo->siguiente=seguidora;
            anterior->siguiente=nuevo;
        }


    }

    return lista;

}


///Como intercalar dos listas que ambas estan ordenadas
//Tendria que agarrar ambas listas por parametro para luego retornar otra

nodo* intercalandoListas (nodo* lista1,nodo* lista2)
{
    nodo*lista3=NULL;
    nodo*aux=NULL;

    while (lista1&&lista2)
    {
        if(lista1->dato.edad < lista2->dato.edad)
        {
            aux=lista1;
            lista1=lista1->siguiente;



        }
        else
        {
            aux=lista2;
            lista2=lista2->siguiente;


        }
        aux->siguiente=NULL;
        lista3=agregarAlFinal(lista3, aux);

    }
    if (lista1)
    {

        lista3=agregarAlFinal(lista3,lista1);
    }
    else if(lista2)
    {
        lista3=agregarAlFinal(lista3,lista2);
    }

//    lista1=NULL;
//    lista2=NULL;

    return lista3;
}
nodo* archivoAlista (char ruta[], nodo*lista)
{
    FILE *archivo = fopen(ruta,"rb");//TENGAMOS EN CUENTA QUE ESTA CREADOOO
    stPersona persona;
    if (archivo)
    {
        ///PREGUNTA :COMO CUENTO LOS ARCHIVOS??

        while (fread(&persona, sizeof(stPersona),1, archivo)>0)
        {

            lista=agregarAlFinal(lista,crearNodo(persona));


        }

    }
    fclose(archivo);
    return lista;
}
nodo* archivoAlistaFiltrada (char ruta[], nodo*lista, int edad)  ///IMAGINEMOSNO QUE NOS DICE MAYORES A UNA EDAD
{
    FILE *archivo = fopen(ruta,"rb");
    stPersona persona;
    if (archivo)
    {

        while (fread(&persona, sizeof(stPersona),1, archivo)>0)
        {
            if (persona.edad >=edad)
                lista=agregarAlFinal(lista,crearNodo(persona));


        }

    }
    fclose(archivo);
    return lista;
}
nodo* archivoAlistaFiltradaXnombre (char ruta[], nodo*lista, char nombre[])  ///Que solo sean los Bruno q entren en la lista
{
    FILE* archivo = fopen(ruta,"rb");
    stPersona persona;
    if (archivo)
    {

        while (fread(&persona, sizeof(stPersona),1, archivo)>0)
        {
            if (strcmp(persona.nombre, nombre)==0)
                lista=agregarAlFinal(lista,crearNodo(persona));


        }

    }
    fclose(archivo);
    return lista;
}

int cuentaNodosPorEdad (nodo* lista, int edad)
{
    int contador =0;
    nodo * seguidora= lista;
    while (seguidora)
    {

        if (seguidora->dato.edad>edad)
            contador ++;
        seguidora=seguidora->siguiente;
    }
    return contador ;


}

int cuentaNodosPorEdadRecursiva(nodo*lista, int edad){///RECURSIVA
    int contador=0;

    if (lista){//RECURSIVIDAD IMPLICITA
        if (lista->dato.edad>edad){

            contador=1+cuentaNodosPorEdadRecursiva(lista->siguiente,edad);

        }else{

            contador=cuentaNodosPorEdadRecursiva(lista->siguiente,edad);
        }

    }

    return contador;
}



int sumaNodosXedad(nodo* lista, int edad)
{


    int contador =0;
    nodo * seguidora= lista;
    while (seguidora)
    {

        if (seguidora->dato.edad>edad)
            contador+=seguidora->dato.edad;
        seguidora=seguidora->siguiente;
    }
    return contador ;


}
int sumaNodosXedadTernarioRecursivo(nodo* lista, int edad){



return (lista)?(lista->dato.edad>edad)?lista->dato.edad+sumaNodosXedadTernarioRecursivo(lista->siguiente,edad):sumaNodosXedadTernarioRecursivo(lista->siguiente,edad):0;
}

void listaToArchivo(nodo*lista, char ruta[]){
    FILE* archivo = fopen (ruta,"ab");
    stPersona p=lista->dato;///VAMOS A TENER QUE PASAR EL PUNTERO DE ESTO DESPUES
    if (archivo){
        while (lista){
                    //Por eso que le pasamos &
            fwrite(&p,sizeof(stPersona),1,archivo);
            lista=lista->siguiente;
        }
    }
    fclose(archivo);


}

nodo* invirtiendoLista (nodo*lista){


    while (lista){
            ///MIRAR DE NUEVO EVITAR ARMAR NODOS

    nodo* actual = lista->siguiente;
    actual->siguiente=lista;
    lista=lista->siguiente;




    }
    lista=auxiliar;
    return auxiliar;



}


