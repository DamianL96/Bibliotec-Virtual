#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ff fflush(stdin);
#include "tdaListaLibros.h"
#include "ArchivosLibros.h"
#include "tdaListaGenero.h"

nodoLibro* inicListaLibros(){
    return NULL;
}

nodoLibro* crearNodoLibro(stLibro dato){

    nodoLibro* libros=(nodoLibro*)malloc(sizeof(stLibro));
    libros->dato=dato;
    libros->siguiente=NULL;

    return libros;
}

nodoLibro* agregarAlPpioLibro(nodoLibro* lista,nodoLibro* nuevo){

    if(lista!=NULL){
        nuevo->siguiente=lista;
        lista=nuevo;
    }else{
        lista=nuevo;
    }

    return lista;
}

nodoLibro* buscarUltLibro(nodoLibro* lista){

    nodoLibro* ult=lista;

    if(lista!=NULL){
        while(ult->siguiente!=NULL){
            ult=ult->siguiente;
        }
    }
    return ult;
}

nodoLibro* agregarAlFinalNodoLibro(nodoLibro* lista, nodoLibro* nuevo){

    if(lista!=NULL){
        nodoLibro* ult=buscarUltLibro(lista);
        ult->siguiente=nuevo;
    }else{
        lista=nuevo;
    }
    return lista;
}

nodoLibro* agregarEnOrdenLibros(nodoLibro* lista, nodoLibro* nuevo){

    if(lista==NULL){
        lista=nuevo;
    }else{

        if(strcmpi(nuevo->dato.titulo,lista->dato.titulo)<0){
            lista=agregarAlPpioLibro(lista,nuevo);
        }else{

            nodoLibro* ante=lista;
            nodoLibro* seg=lista->siguiente;
            while((seg!=NULL)&&(strcmpi(nuevo->dato.titulo,seg->dato.titulo))>0){
                ante=seg;
                seg=seg->siguiente;
            }
            nuevo->siguiente=seg;
            ante->siguiente=nuevo;

        }
    }
    return lista;
}

nodoLibro* buscarNodoLibroCheoRep(nodoLibro* lista, char titulo[]){         //busca y no borra lo siguiente

    nodoLibro* seguidora=lista;

    while(seguidora!=NULL && (strcmpi(titulo,seguidora->dato.titulo)!=0)){

        seguidora=seguidora->siguiente;
    }

    /*
    if(strcmpi(seguidora->dato.titulo,titulo)==0){          //eso si necesito retornalo
        seguidora->siguiente=NULL;
    }else{
        seguidora=NULL;
    }*/

    return seguidora;
}

nodoLibro* buscarNodoLibroPorTitulo(nodoLibro* lista, char titulo[]){

    nodoLibro* seguidora=lista;

    while(seguidora!=NULL && (strcmpi(titulo,seguidora->dato.titulo)!=0)){

        seguidora=seguidora->siguiente;
    }


    if(strcmpi(seguidora->dato.titulo,titulo)==0){          //eso si necesito retornalo
        seguidora->siguiente=NULL;
    }else{
        seguidora=NULL;
    }

    return seguidora;
}

nodoLibro* buscarNodoLibroPorCodigo(nodoLibro* lista, char cod[]){

    nodoLibro* seguidora=lista;

    while(seguidora!=NULL && (strcmpi(cod,seguidora->dato.codigo)!=0)){

        seguidora=seguidora->siguiente;
    }

    if(seguidora!=NULL){
        seguidora->siguiente=NULL;
    }


    return seguidora;
}

nodoLibro* buscarNodoLibroPorAutor(nodoLibro* lista, char autor[]){

    nodoLibro* CopiaL=inicListaLibros();
    nodoLibro* seg=lista;

    while(seg!=NULL){

        if(strcmpi(seg->dato.autor,autor)==0){
            nodoLibro* nuevo=crearNodoLibro(seg->dato);
            CopiaL=agregarAlPpioLibro(CopiaL,nuevo);
        }
            seg=seg->siguiente;

    }

    return CopiaL;
}

nodoLibro* buscarNodoLibroMayoresPorEdad(nodoLibro* lista, int edad){

    nodoLibro* CopiaL=inicListaLibros();
    nodoLibro* seg=lista;

    while(seg!=NULL){

        if(seg->dato.rango>=edad){
            nodoLibro* nuevo=crearNodoLibro(seg->dato);
            CopiaL=agregarAlPpioLibro(CopiaL,nuevo);
        }
            seg=seg->siguiente;

    }

    return CopiaL;
}

nodoLibro* buscarNodoLibroMenoresPorEdad(nodoLibro* lista, int edad){

    nodoLibro* CopiaL=inicListaLibros();
    nodoLibro* seg=lista;

    while(seg!=NULL){

        if(seg->dato.rango<=edad){
            nodoLibro* nuevo=crearNodoLibro(seg->dato);
            CopiaL=agregarAlPpioLibro(CopiaL,nuevo);
        }
            seg=seg->siguiente;

    }

    return CopiaL;
}



void mostrarStLibro(stLibro libro){

    printf("\n-----------------------------------------------------");
    printf("\nTitulo: %s",libro.titulo);
    printf("\nAutor: %s",libro.autor);
    printf("\nCodigo: %s",libro.codigo);
    printf("\nRango de edad: %d",libro.rango);
    printf("\nPrecio de venta: %d",libro.precioVenta);
    printf("\nPrecio de renta: %d",libro.precioRenta);
    printf("\nCantidad de copias: %d",libro.cantidad);

}

void mostrarListaLibros(nodoLibro* libro){

    nodoLibro* seg=libro;

    if(libro!=NULL){
        while(seg!=NULL){
            mostrarStLibro(seg->dato);
            seg=seg->siguiente;
        }
    }
}

void mostrarListaLibrosSOLODisponibles(nodoLibro* libro){

    nodoLibro* seg=libro;

    if(libro!=NULL){
        while(seg!=NULL){

            if(seg->dato.cantidad > 0){
                mostrarStLibro(seg->dato);
            }

            seg=seg->siguiente;
        }
    }
}

stLibro ingresarDatosLibro(){

        stLibro aux;

        printf("\nA continuacion va a ingresar los datos del libro: ");

        printf("\nIngrese el titulo: ");
        ff
        gets(&aux.titulo);

        printf("\nIngrese el autor: ");
        ff
        gets(&aux.autor);

        printf("\nIngrese el codigo: ");
        ff
        gets(&aux.codigo);

        printf("\nIngrese el rango de edad: ");
        ff
        scanf("%d",&aux.rango);

        printf("\nIngrese el precio de venta: ");
        ff
        scanf("%d",&aux.precioVenta);

        printf("\nIngrese el precio de renta por semana: ");
        ff
        scanf("%d",&aux.precioRenta);

        printf("\nIngrese la cantidad de copias: ");
        ff
        scanf("%d",&aux.cantidad);

    return aux;
}

nodoLibro* ingresarLibroLista(nodoLibro* lista){            // se ordenan por titulo

    char c='s';

    while(c=='s'){

        stLibro aux=ingresarDatosLibro();

        nodoLibro* nuevo=crearNodoLibro(aux);

        nodoLibro* buscar=buscarNodoLibroCheoRep(lista,nuevo->dato.titulo);

        if(buscar!=NULL){
            printf("\nEl libro ingresado ya existe, se agrego 1 mas al inventario");
            buscar->dato.cantidad = 1+ buscar->dato.cantidad;
        }else{
            lista=agregarEnOrdenLibros(lista,nuevo);
        }

        printf("\nDesea continuar ingresando libros? s/n");
        ff
        scanf("%c",&c);

        while(c!='s' && c!='n'){
            printf("\nCaracter no valido ingrese: s/n (Si o NO)");
            ff
            scanf("%c",&c);
        }
    }

    return lista;
}

nodoLibro* borrarNodoLibroPorTitulo(char titulo[],nodoLibro* lista){

    if(lista!=NULL){

        if(strcmpi(titulo,lista->dato.titulo)==0){
            nodoLibro* aBorrar=lista;
            lista=lista->siguiente;
            free(aBorrar);

        }else{

            nodoLibro* ante=lista;
            nodoLibro* seg=lista->siguiente;

            while((seg!=NULL)&&(strcmpi(titulo,seg->dato.titulo)!=0)){
                ante=seg;
                seg=seg->siguiente;
            }
            if(seg!=NULL){
                ante->siguiente=seg->siguiente;
                free(seg);
            }
        }
    }
    return lista;
}

nodoLibro* borrarNodoLibroPorCodigo(char cod[],nodoLibro* lista){

    if(lista!=NULL){

        if(strcmpi(cod,lista->dato.codigo)==0){
            nodoLibro* aBorrar=lista;
            lista=lista->siguiente;
            free(aBorrar);

        }else{

            nodoLibro* ante=lista;
            nodoLibro* seg=lista->siguiente;

            while((seg!=NULL)&&(strcmpi(cod,seg->dato.codigo)!=0)){
                ante=seg;
                seg=seg->siguiente;
            }
            if(seg!=NULL){
                ante->siguiente=seg->siguiente;
                free(seg);
                printf("\n\nEl libro fue borrado correctamente\n");
            }
        }
    }
    return lista;
}

nodoLibro* buscarNodoLibroPorCodigoParaAgregarCantidad(nodoLibro* lista, char cod[]){

    nodoLibro* seguidora=lista;

    while(seguidora!=NULL && (strcmpi(cod,seguidora->dato.codigo)!=0)){

        seguidora=seguidora->siguiente;
    }
/*
    if(seguidora!=NULL){
        seguidora->siguiente=NULL;
    }
*/

    return seguidora;
}





