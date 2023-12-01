#ifndef ARCHIVOSLIBROS_H_INCLUDED
#define ARCHIVOSLIBROS_H_INCLUDED
#include "tdaListaGenero.h"

typedef struct{
    char genero[30];
    char titulo[30];
    char autor[30];
    char codigo[20];
    int rango;      //rango de edad
    int precioVenta;
    int precioRenta;        //precio de renta por semana
    int cantidad;
}RegistroArchLibro;


RegistroArchLibro cargarLibro();
void mostrarRegLibro(RegistroArchLibro libro);
void cargarArchivoLibro (char NombreArchi[]);
void mostrarArchLibros(char nombreArch[]);
void pasarListaToArch(nodoGeneros* lista,char nombreArch[]);
RegistroArchLibro copiarStLibroToregistroArch(stLibro aux,char genero[]);
nodoGeneros* pasarArchToListaGenero(nodoGeneros* lista,char nombreArch[]);
stLibro copiarRegitroArchToStLibros(RegistroArchLibro aux);

#endif // ARCHIVOSLIBROS_H_INCLUDED
