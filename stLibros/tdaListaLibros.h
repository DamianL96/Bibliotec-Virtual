#ifndef TDALISTALIBROS_H_INCLUDED
#define TDALISTALIBROS_H_INCLUDED



typedef struct{
    char titulo[30];
    char autor[30];
    char codigo[20];
    int rango;          //rango de edad
    int precioVenta;
    int precioRenta;    //precio de renta por semana
    int cantidad;
}stLibro;

typedef struct{
    stLibro dato;
    struct nodo* siguiente;
}nodoLibro;

nodoLibro* inicListaLibros();
nodoLibro* crearNodoLibro(stLibro dato);
nodoLibro* agregarAlPpioLibro(nodoLibro* lista,nodoLibro* nuevo);
nodoLibro* buscarUltLibro(nodoLibro* lista);
nodoLibro* agregarAlFinalNodoLibro(nodoLibro* lista, nodoLibro* nuevo);
nodoLibro* agregarEnOrdenLibros(nodoLibro* lista, nodoLibro* nuevo);
nodoLibro* buscarNodoLibroCheoRep(nodoLibro* lista, char titulo[]);
nodoLibro* buscarNodoLibroPorTitulo(nodoLibro* lista, char titulo[]);
nodoLibro* buscarNodoLibroPorCodigo(nodoLibro* lista, char cod[]);
nodoLibro* buscarNodoLibroPorAutor(nodoLibro* lista, char autor[]);
nodoLibro* buscarNodoLibroMayoresPorEdad(nodoLibro* lista, int edad);
nodoLibro* buscarNodoLibroMenoresPorEdad(nodoLibro* lista, int edad);
nodoLibro* ingresarLibroLista(nodoLibro* lista);
nodoLibro* borrarNodoLibroPorTitulo(char titulo[],nodoLibro* lista);
nodoLibro* borrarNodoLibroPorCodigo(char cod[],nodoLibro* lista);
int codigoLibroIncremental(nodoLibro* lista);
nodoLibro* buscarNodoLibroPorCodigoParaAgregarCantidad(nodoLibro* lista, char cod[]);

stLibro ingresarDatosLibro();
void mostrarStLibro(stLibro libro);
void mostrarListaLibros(nodoLibro* libro);
void mostrarListaLibrosSOLODisponibles(nodoLibro* libro);


#endif // TDALISTALIBROS_H_INCLUDED
