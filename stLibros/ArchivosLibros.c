#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ff fflush(stdin);
#include "tdaListaLibros.h"
#include "ArchivosLibros.h"
#include "tdaListaGenero.h"

RegistroArchLibro cargarLibro(){

    RegistroArchLibro aux;

    printf("\nIngrese el genero del libro: ");
    ff
    gets(&aux.genero);

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

void mostrarRegLibro(RegistroArchLibro libro){

    printf("\n-----------------------------------------------------");
    printf("\nGenero: %s",libro.genero);
    printf("\nTitulo: %s",libro.titulo);
    printf("\nAutor: %s",libro.autor);
    printf("\nCodigo: %s",libro.codigo);
    printf("\nRango de edad: %d",libro.rango);
    printf("\nPrecio de venta: %d",libro.precioVenta);
    printf("\nPrecio de renta: %d",libro.precioRenta);
    printf("\nCantidad de copias: %d",libro.cantidad);

}

void cargarArchivoLibro (char NombreArchi[]){
    FILE * archi = fopen(NombreArchi,"ab");
    char control='s';

    if(archi != NULL){
        while(control=='s'){
            RegistroArchLibro aux=cargarLibro();
            fwrite(&aux,sizeof(RegistroArchLibro),1,archi);

            printf("\nDesea cargar otro? s/n \n");
            ff
            scanf("%c",&control);

            while(control!='s' && control!='n'){
            printf("\nCaracter no valido ingrese: s/n (Si o NO)");
            ff
            scanf("%c",&control);
        }
        }
    }
    fclose(archi);

}

void mostrarArchLibros(char nombreArch[]){

    FILE * arch=fopen(nombreArch,"rb");
    RegistroArchLibro aux;

    if(arch!=NULL){
        while(fread(&aux,sizeof(RegistroArchLibro),1,arch)>0){
            mostrarRegLibro(aux);
        }
    }
    fclose(arch);
}

nodoGeneros* pasarArchToListaGenero(nodoGeneros* lista,char nombreArch[]){

    FILE * arch=fopen(nombreArch,"rb");
    RegistroArchLibro aux;

    if(arch!=NULL){
        while(fread(&aux,sizeof(RegistroArchLibro),1,arch)>0){

            stLibro copia=copiarRegitroArchToStLibros(aux);

            lista=altaGenero(lista,aux.genero,copia);

        }
    }
    fclose(arch);

    return lista;
}

stLibro copiarRegitroArchToStLibros(RegistroArchLibro aux){

    stLibro copia;

    strcpy(copia.titulo,aux.titulo);
    strcpy(copia.autor,aux.autor);
    strcpy(copia.codigo,aux.codigo);
    copia.rango=aux.rango;
    copia.precioVenta=aux.precioVenta;
    copia.precioRenta=aux.precioRenta;
    copia.cantidad=aux.cantidad;

    return copia;
}
RegistroArchLibro copiarStLibroToregistroArch(stLibro aux,char genero[]){

    RegistroArchLibro copia;
    strcpy(copia.genero,genero);
    strcpy(copia.titulo,aux.titulo);
    strcpy(copia.autor,aux.autor);
    strcpy(copia.codigo,aux.codigo);
    copia.rango=aux.rango;
    copia.precioVenta=aux.precioVenta;
    copia.precioRenta=aux.precioRenta;
    copia.cantidad=aux.cantidad;

    return copia;
}

void pasarListaToArch(nodoGeneros* lista,char nombreArch[]){

    FILE * arch=fopen(nombreArch,"w+b");
    RegistroArchLibro aux;
    nodoLibro* libros=inicListaLibros();

    if(arch!=NULL){
        nodoGeneros* segG=lista;

        while(segG!=NULL){
            libros=segG->listaLibros;

            while(libros!=NULL){
                aux=copiarStLibroToregistroArch(libros->dato,segG->genero);
                fwrite(&aux,sizeof(RegistroArchLibro),1,arch);
                libros=libros->siguiente;
            }
            segG=segG->siguiente;
        }
        fclose(arch);
    }
}




