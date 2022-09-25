#include <stdio.h>
#include <stdlib.h>



//     Un TDA, es un tipo de dato definido por el programador
//       que se puede manipular de un modo similiar a los definidos por el sistema.
//        El TDA tiene una identidad y un comportamiento con el cual permite la interaccion
//         ES INDEPENDIENTE AL LENGUAJE QUE SE QUIERA IMPLEMENTA
//          La lista enlazada es algo completamente dinamico es un puntero a dirreccion enlazada
//          ESTRUCTURA--> Dato enlazada a otro DATO

// Una pila es una lista LIFO y es una lista de elementos UNA TDA



//LA ESTRUCTURA DE UN DATO DINAMICO SE trata de un conjunto de variables determinadas
//Orgabnizadas de alguna manera para representar un comportamiento
///estan las Estructuras ESTATICAS--> Su tamaño de memoria es fijo
///DINAMICAS su tamaño en memoria es variable ej listas enlazadas
typedef struct
{
    char nombre [20];
    int edad;
    char sexo;
} stPersona;


typedef struct
{
    stPersona dato;  //Estos son los datos que contiene el nodo


    struct nodo*siguiente; ///ACA esta la direccion al otro nodo(recursividad)
    } nodo;
    ///Cada uno de los elementos de la lista se llama NODO
///CADA NODO CONTIENE INFORMACION Y SU ACCESO ES SECUENCIAL--> Entro por el primero, para llegar al ultimo





nodo * inicLista();
nodo * crearNodo(stPersona dato);///CREAR NODO VA A RETORNAR UN PUNTERO HACIA EL NUEVO NODO Y VAMOS A RECIBIR
                                    ///COMO PARAMETRO EL DATO DE ESTRUCTURA



int main()
{

    //POR EJEMPLO
    //Antes definiamos estaticas los arreglos
    int array [10];
    ///RESERVABAMOS UNA DIMENSION Y USABAMOS VALIDOS
    //Sin embargo esto cambia cuando es dinamico

    //REALLOC MALLOC CALLOC
    int * arregloDinamico = malloc(10*sizeof(int));
    //Esto tranquilamente se puede redimensionar y hasta liberarlo
    free(arregloDinamico);
    ///000OJO FREE elimina el arreglo PERO NO ELIMINA LOS DATOS DEL ARREGLO
    /// LIBERA EL ESPACIO DE LA MEMORIA Y PARA UTILIZAR EN EL FUTURO
    arregloDinamico=NULL;


    //Una LISTA Enlazada es una estructura lineal conformada por nodos

    /// NODOS--> TDA
    // no tiene limite de elementos para almacenar
    //Solo podemos acceder a sus elementos por el inicio de la lista
    //Para acceder al 2do tengo que ir al 1ro
    //ASI SUCCESIVAMENTE


    ///LISTA CONTIENE un puntero de la siguiente lista



    //Ejemplo en linea 29
    nodo * lista ;

    //El acceso al primer nodo de la lista se hace atraves de una variable de tipo puntero


    lista= inicLista();



    return 0;
}
///DEFINIENDO EL COMPORTAMIENTO
nodo * inicLista()
{
    return NULL;
//Es por ello que para llegar al ultimo se contempla el puntero al  que apunta (NULLL)

}

nodo * crearNodo(stPersona dato) //CREA AL NODO
{
    nodo * nuevo = (nodo*)malloc(sizeof(nodo));//Reserva un espacio de memoria y retorna la direc de memoria
    nuevo->dato=dato;
    nuevo ->siguiente=NULL;//como no hay siguiente es NULL



    return nuevo;
}
nodo * agregarAlPrincipio(nodo * lista, nodo * nuevo){

    if (lista==NULL){

        lista=nuevo;

    }else{

        nuevo->siguiente=lista;
        lista = nuevo;
    }



    return  lista;
}
