#ifndef ESTRUCTURA_H_INCLUDED
#define ESTRUCTURA_H_INCLUDED

typedef struct {
    int id;
    char nombre [14];
    char edad [5];
    char cp [2];

}stEstructura;

stEstructura cargaEstructura ();
void mostrarEstructura (stEstructura E);
char * pasarDatoPuntero (stEstructura e) ;



#endif // ESTRUCTURA_H_INCLUDED
