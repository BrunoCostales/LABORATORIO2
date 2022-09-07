#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED
//ESTRUCTURAS Y PROTOTIPADO


typedef struct {
      char nombre[30];
      char genero;
      int edad;
}persona;



void crear (int array [] ,int dim);
void mostrar (int array [] , int dim);
int cargaArray (int array [], int dim);
int sumar (int array [], int dim);
float promedio (int suma,int  validos);
float punto1 (int arreglo[], int dim );
int potencia (int a);
int conjuncion (int array[] , int dim);
///Ejercicio7
void intercambio (int *a, int *b);
void cargaEstructura (persona P [],int dim );
void MostrandoEstructura (persona P);
void mostrandoTodas (persona P [], int dim);
int capturandoGenero (persona P [], int dim, char g);
int pasarlasGenero (persona o [], int validosO, char g, persona d[], int validosD);
persona * capturandoGeneroArray(persona P [],int dim, char g);
#endif // ESTRUCTURAS_H_INCLUDED
