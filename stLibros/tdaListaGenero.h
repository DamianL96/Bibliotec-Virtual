#ifndef TDALISTAGENERO_H_INCLUDED
#define TDALISTAGENERO_H_INCLUDED
#include "tdaListaLibros.h"


typedef struct{
    char genero[30];
    nodoLibro* listaLibros;
    struct nodoGeneros* siguiente;
}nodoGeneros;


nodoGeneros* inicListaGeneros();
nodoGeneros* crearNodoGenero(char gen[]);
nodoGeneros* agregarAlPpioGeneros(nodoGeneros* lista,nodoGeneros* nuevo);
nodoGeneros* buscarUltGenero(nodoGeneros* lista);
nodoGeneros* agregarAlFinalNodoGenero(nodoGeneros* lista, nodoGeneros* nuevo);
nodoGeneros* agregarEnOrdenGeneros(nodoGeneros* lista, nodoGeneros* nuevo);

nodoGeneros* ingresarListaGen(nodoGeneros* lista);
void mostrarListaGen(nodoGeneros* lista);

nodoLibro* buscarNodoGeneroCodigo(nodoGeneros* listaGenero,char cod[]);
nodoLibro* buscarNodoGeneroAutor(nodoGeneros* lista,char autor[]);
nodoLibro* buscarNodoGeneroTitulo(nodoGeneros* listaGenero,char titulo[]);
nodoLibro* buscarNodoGeneroMayoresEdad(nodoGeneros* lista,int edad);
nodoLibro* buscarNodoGeneroMenoresEdad(nodoGeneros* lista,int edad);
nodoGeneros* buscarNodoGenero(nodoGeneros* lista,char gen[]);
nodoGeneros* altaGenero(nodoGeneros* listaG,char genero[],stLibro libro);
nodoGeneros* agregarCantidadDeLibroEnLista(nodoGeneros* lista, char cod[]);
nodoGeneros* DiminuirCantidadDeLibroEnListaDeAuno(nodoGeneros* lista, char cod[],int cant);
nodoGeneros* DiminuirCantidadDeLibroEnLista(nodoGeneros* lista, char cod[]);
nodoGeneros* borrarBorrarLibroEnNodo(nodoGeneros* lista, char cod[]);

void mostrarListaSoloUnGenero(nodoGeneros* lista, char genero[]);
void mostrarListaCopletaLibrosYgen(nodoGeneros* lista);

nodoGeneros* ingresarGenerosYlibros(nodoGeneros* lista);

#endif // TDALISTAGENERO_H_INCLUDED
