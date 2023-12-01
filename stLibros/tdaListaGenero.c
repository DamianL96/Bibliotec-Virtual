#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ff fflush(stdin);
#include "tdaListaLibros.h"
#include "ArchivosLibros.h"
#include "tdaListaGenero.h"


nodoGeneros* inicListaGeneros()
{
    return NULL;
}

nodoGeneros* crearNodoGenero(char gen[])
{

    nodoGeneros* nuevo=inicListaGeneros();

    nuevo=(nodoGeneros*)malloc(sizeof(nodoGeneros));

    strcpy(nuevo->genero,gen);
    nuevo->listaLibros=inicListaLibros();
    nuevo->siguiente=NULL;


    return nuevo;
}

nodoGeneros* agregarAlPpioGeneros(nodoGeneros* lista,nodoGeneros* nuevo)
{

    if(lista!=NULL)
    {
        nuevo->siguiente=lista;
        lista=nuevo;
    }
    else
    {
        lista=nuevo;
    }

    return lista;
}

nodoGeneros* buscarUltGenero(nodoGeneros* lista)
{

    nodoGeneros* ult=lista;

    if(lista!=NULL)
    {
        while(ult->siguiente!=NULL)
        {
            ult=ult->siguiente;
        }
    }
    return ult;
}

nodoGeneros* agregarAlFinalNodoGenero(nodoGeneros* lista, nodoGeneros* nuevo)
{

    if(lista!=NULL)
    {
        nodoGeneros* ult=buscarUltGenero(lista);
        ult->siguiente=nuevo;
    }
    else
    {
        lista=nuevo;
    }
    return lista;
}

nodoGeneros* buscarNodoGenero(nodoGeneros* lista,char gen[])
{

    nodoGeneros* buscado=lista;

    while((buscado!=NULL)&&(strcmpi(buscado->genero,gen)!=0))
    {
        buscado=buscado->siguiente;
    }


    return buscado;
}


nodoLibro* buscarNodoGeneroCodigo(nodoGeneros* listaGenero,char cod[])
{

    nodoGeneros* segG=listaGenero;

    nodoLibro* segL=inicListaLibros();

    if(segG!=NULL)
    {
        segL=buscarNodoLibroPorCodigo(segG->listaLibros,cod);

        while(segG !=NULL && (segL==NULL))
        {
            segL=buscarNodoLibroPorCodigo(segG->listaLibros,cod);

            segG=segG->siguiente;

        }
    }

    return segL;
}

nodoLibro* buscarNodoGeneroTitulo(nodoGeneros* listaGenero,char titulo[])
{

    nodoGeneros* segG=listaGenero;

    nodoLibro* segL=inicListaLibros();

    if(segG!=NULL)
    {
        segL=buscarNodoLibroPorTitulo(segG->listaLibros,titulo);

        while(segG !=NULL && (segL==NULL))
        {
            segL=buscarNodoLibroPorTitulo(segG->listaLibros,titulo);

            segG=segG->siguiente;

        }
    }

    return segL;
}

nodoLibro* buscarNodoGeneroAutor(nodoGeneros* lista,char autor[]){

    nodoGeneros* segG=lista;
    nodoLibro* copiaL=inicListaLibros();
    nodoLibro* libros=inicListaLibros();


    while(segG!=NULL){

        copiaL=buscarNodoLibroPorAutor(segG->listaLibros,autor);

        if(copiaL!=NULL){
            libros=agregarAlFinalNodoLibro(libros,copiaL);
        }

        segG=segG->siguiente;
    }


    return libros;
}

nodoLibro* buscarNodoGeneroMayoresEdad(nodoGeneros* lista,int edad){

    nodoGeneros* segG=lista;
    nodoLibro* copiaL=inicListaLibros();
    nodoLibro* libros=inicListaLibros();


    while(segG!=NULL){

        copiaL=buscarNodoLibroMayoresPorEdad(segG->listaLibros,edad);

        if(copiaL!=NULL){
            libros=agregarAlFinalNodoLibro(libros,copiaL);
        }

        segG=segG->siguiente;
    }


    return libros;
}

nodoLibro* buscarNodoGeneroMenoresEdad(nodoGeneros* lista,int edad){

    nodoGeneros* segG=lista;
    nodoLibro* copiaL=inicListaLibros();
    nodoLibro* libros=inicListaLibros();


    while(segG!=NULL){

        copiaL=buscarNodoLibroMenoresPorEdad(segG->listaLibros,edad);

        if(copiaL!=NULL){
            libros=agregarAlFinalNodoLibro(libros,copiaL);
        }

        segG=segG->siguiente;
    }


    return libros;
}

nodoGeneros* agregarEnOrdenGeneros(nodoGeneros* lista, nodoGeneros* nuevo)
{

    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {

        if(strcmpi(nuevo->genero,lista->genero)<0)
        {
            lista=agregarAlPpioGeneros(lista,nuevo);
        }
        else
        {
            nodoGeneros* ante=lista;
            nodoGeneros* seg=lista->siguiente;
            while((seg!=NULL)&&(strcmpi(nuevo->genero,seg->genero))>0)
            {
                ante=seg;
                seg=seg->siguiente;
            }
            nuevo->siguiente=seg;
            ante->siguiente=nuevo;

        }
    }
    return lista;
}


nodoGeneros* ingresarListaGen(nodoGeneros* lista)
{

    char c='s';
    char gen[30];

    while(c=='s')
    {
        printf("\nIngrese un Genero: ");
        ff
        gets(&gen);

        nodoGeneros* nuevo=crearNodoGenero(gen);
        lista=agregarEnOrdenGeneros(lista,nuevo);

        printf("\nDesea continuar ingresando libros? s/n");
        ff
        scanf("%c",&c);

        while(c!='s' && c!='n')
        {
            printf("\nCaracter no valido ingrese: s/n (Si o NO)");
            ff
            scanf("%c",&c);
        }
    }

    return lista;
}

void mostrarListaGen(nodoGeneros* lista)
{

    nodoGeneros* seg=lista;

    if(lista!=NULL)
    {
        while(seg!=NULL)
        {

            printf("\nGenero : %s",seg->genero);

            seg=seg->siguiente;
        }
    }
}

nodoGeneros* altaGenero(nodoGeneros* listaG,char genero[],stLibro libro)
{

    nodoLibro* nuevoLibro=crearNodoLibro(libro);
    nodoGeneros* generoEncontrado=buscarNodoGenero(listaG,genero);


    if(generoEncontrado==NULL)
    {

        nodoGeneros* nuevoGenero=crearNodoGenero(genero);

        listaG=agregarAlPpioGeneros(listaG,nuevoGenero);

        generoEncontrado=listaG;

    }
    generoEncontrado->listaLibros=agregarEnOrdenLibros(generoEncontrado->listaLibros,nuevoLibro);

    return listaG;
}

void mostrarListaSoloUnGenero(nodoGeneros* lista, char genero[])
{

    nodoGeneros* seg=lista;

    if(lista!=NULL)
    {
        while(seg!=NULL && (strcmp(seg->genero,genero)!=0))
        {
            seg=seg->siguiente;
        }
        if(seg!=NULL)
        {
            mostrarListaLibros(seg->listaLibros);
        }
        else
        {
            printf("\nError, el genero ingresado no existe.");
        }
    }
}

void mostrarListaCopletaLibrosYgen(nodoGeneros* lista)
{

    nodoGeneros* segGen=lista;

    if(lista!=NULL)
    {
        while(segGen!=NULL)
        {
            printf("\n\n GENERO: %s\n",segGen->genero);
            mostrarListaLibros(segGen->listaLibros);

            segGen=segGen->siguiente;
        }
    }
}

nodoGeneros* ingresarGenerosYlibros(nodoGeneros* lista)
{

    char c='s';
    stLibro libro;
    char genero[30];

    while(c=='s')
    {

        libro=ingresarDatosLibro();

        printf("\nIngrese el GENERO del libro: ");
        ff
        gets(&genero);

        lista=altaGenero(lista,genero,libro);

        printf("\nDesea continuar ingresando libros? s/n");
        ff
        scanf("%c",&c);

        while(c!='s' && c!='n')
        {
            printf("\nCaracter no valido ingrese: s/n (Si o NO)");
            ff
            scanf("%c",&c);
        }

    }
    return lista;
}

nodoGeneros* agregarCantidadDeLibroEnLista(nodoGeneros* lista, char cod[]){

    nodoGeneros* segG=lista;

    nodoLibro* segL=inicListaLibros();

    if(segG!=NULL)
    {
        segL=buscarNodoLibroPorCodigo(segG->listaLibros,cod);

        while(segG !=NULL && (segL==NULL))
        {
            segL=buscarNodoLibroPorCodigoParaAgregarCantidad(segG->listaLibros,cod);

            segG=segG->siguiente;

        }
    }

    if(segL!=NULL){
        int cant=0;
        printf("\n\nIngrese cuantos copias desea agregar: ");
        ff
        scanf("%d",&cant);

        segL->dato.cantidad=cant +segL->dato.cantidad;

        printf("\n\nSe agrego correctamente\n");

    }else{

        printf("\n\nEl libro NO existe\n");

    }

    return lista;
}

nodoGeneros* devolverLibroAListaGenero(nodoGeneros* lista, char cod[],int cant){

    nodoGeneros* segG=lista;

    nodoLibro* segL=inicListaLibros();

    if(segG!=NULL)
    {
        segL=buscarNodoLibroPorCodigo(segG->listaLibros,cod);

        while(segG !=NULL && (segL==NULL))
        {
            segL=buscarNodoLibroPorCodigoParaAgregarCantidad(segG->listaLibros,cod);

            segG=segG->siguiente;

        }
    }

    if(segL!=NULL){
        segL->dato.cantidad= segL->dato.cantidad + cant;

    }else{
        printf("\n\nEl libro NO existe\n");
    }

    return lista;
}


nodoGeneros* DiminuirCantidadDeLibroEnListaDeAuno(nodoGeneros* lista, char cod[],int cant){

    nodoGeneros* segG=lista;

    nodoLibro* segL=inicListaLibros();

    if(segG!=NULL)
    {
        segL=buscarNodoLibroPorCodigo(segG->listaLibros,cod);

        while(segG !=NULL && (segL==NULL))
        {
            segL=buscarNodoLibroPorCodigoParaAgregarCantidad(segG->listaLibros,cod);

            segG=segG->siguiente;

        }
    }

    if(segL!=NULL){

        segL->dato.cantidad=segL->dato.cantidad-cant;

    }

    return lista;
}

nodoGeneros* DiminuirCantidadDeLibroEnLista(nodoGeneros* lista, char cod[]){

    nodoGeneros* segG=lista;

    nodoLibro* segL=inicListaLibros();

    if(segG!=NULL)
    {
        segL=buscarNodoLibroPorCodigo(segG->listaLibros,cod);

        while(segG !=NULL && (segL==NULL))
        {
            segL=buscarNodoLibroPorCodigoParaAgregarCantidad(segG->listaLibros,cod);

            segG=segG->siguiente;

        }
    }

    if(segL!=NULL){
        int cant=0;
        printf("\n\nIngrese la cantidad de copias que tomara del inventario : ");
        ff
        scanf("%d",&cant);

        segL->dato.cantidad=segL->dato.cantidad-cant;

    }else{

        printf("\n\n El codigo no existe\n");

    }

    return lista;
}

nodoGeneros* borrarBorrarLibroEnNodo(nodoGeneros* lista, char cod[]){

    nodoGeneros* segG=lista;
    nodoGeneros* copia=inicListaGeneros();


    while(segG!=NULL){

        segG->listaLibros=borrarNodoLibroPorCodigo(cod,segG->listaLibros);

        segG=segG->siguiente;

    }

    return lista;

}







