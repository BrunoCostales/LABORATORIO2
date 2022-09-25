#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int edad;
    char sexo ;
    char nombre [20];



}stPersona;

typedef struct nodo {
    stPersona dato;
   struct  nodo * siguiente ;

}nodo;


typedef struct nodoDoble{

    stPersona dato;
    struct nodoDoble * aiguiente;
    struct nodoDoble * anterior;

} nodoDoble;
nodo * crearNodoDoble (stPersona dato);
int main()
{
    printf("Hello world!\n");
    return 0;
}
nodoDoble * crearNodoDoble (stPersona dato){

    nodo * nuevo = (nodoDoble*) malloc (sizeof(nodoDoble));
    nuevo ->dato = dato;
    nuevo->siguiente = NULL;
    nuevo->anterior =NULL;

    return nuevo;
}
