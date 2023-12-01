#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../stLibros/tdaListaGenero.h"
#include "stFactura.h"
#include "stProducto.h"

stFactura devolverLibroEnFactura(stFactura factura,char titulo[]){
    int i=0;
    while(i<factura.validosLibros){
        if(strcmp( factura.libros[i].titulo, titulo) == 0){
            factura.libros[i].alquila = 0;
        }
        i++;
    }
    return factura;
}


stFactura cargarFactura(int alquila){

    char nombreArchivoLibros[]={"libros.dat"};
    nodoGeneros *listaGeneros=inicListaGeneros();
    listaGeneros= pasarArchToListaGenero(listaGeneros,nombreArchivoLibros);

    printf("\nCARGAR FACTURA:\n");

    char cod[20];
    stFactura factura;
    nodoLibro *aComprar;
    char c = 's';
    int i=0;



    while (c == 's' && i<10){/// i < 10 es la cantidad de libros por factura

        ingresarCodigo(&cod);
        aComprar= buscarNodoGeneroCodigo(listaGeneros,cod);

        if(aComprar != NULL){
            if(aComprar->dato.cantidad > 0){
                if(alquila == 0){

                    factura.libros[i]= cargarProducto(aComprar->dato.titulo,aComprar->dato.precioVenta,alquila);///carga el libro del listado a la factura
                }
                else if(alquila == 1){

                    factura.libros[i]= cargarProducto(aComprar->dato.titulo,aComprar->dato.precioRenta,alquila);///carga el libro del listado a la factura
                }
                i++;

                listaGeneros=DiminuirCantidadDeLibroEnListaDeAuno(listaGeneros,cod,1);///disminuir la cantidad del libro

            }else{
                printf("\nLIBRO NO DISPONIBLE..");
            }
        }else{
            printf("\nPOR EL MOMENTO NO TENEMOS ESE LIBRO :(");
        }
        controlFactura(&c);
    }

    pasarListaToArch(listaGeneros,nombreArchivoLibros);
    factura.validosLibros= i;
    factura.total= calcularTotal(factura);

    time_t hora = time(NULL); ///toma el valor del timepo en el momento
    struct tm *fechaActual= localtime(&hora);
    strftime(factura.fecha,50,"%d/%m/%Y %X",fechaActual);

    return factura;
}

stFactura ingresarFactura(){
    stFactura factura;
    int i=0; ///<10
    char c='s';
    while(i<10 && c == 's'){

        factura.libros[i]=ingresarProducto();
        i++;
        controlFactura(&c);
    }
    factura.validosLibros= i;
    factura.total= calcularTotal(factura);


    time_t hora = time(NULL); ///toma el valor del timepo en el momento
    struct tm *fechaActual= localtime(&hora);
    strftime(factura.fecha,50,"%d/%m/%Y %X",fechaActual);
    return factura;
}


int facturaAlquiler(stFactura factura){
    int flag=0;
    int i=0;
    while(flag == 0 && i<factura.validosLibros){
        if(factura.libros[i].alquila == 1){
            flag = 1;
        }
        i++;
    }
    return flag;
}

void ingresarCodigo(char *cod[]){
    printf("\n Codigo: ");
    fflush(stdin);
    gets(cod);
}


void controlFactura(char *c){


    printf("\nAgregar Otro Libro? s/n: ");
    fflush(stdin);
    scanf("%c",c);
    while((c == 's')||(c =='n')){
        printf("\t¡Opcion Invalida!");
        printf("\nAgregar Otro Libro? s/n: ");
        fflush(stdin);
        scanf("%c",c);
    }
}

    //mostrarFecha(fechaAhora);

void imprimirFactura(stFactura factura){
    int i=0;
    printf("\n\n -FACTURA-  %s",factura.fecha);
    while(i< factura.validosLibros){
        imprimirProducto(factura.libros[i]);
        i++;
    }
    printf("\n PRECIO FINAL: $ %d",factura.total);
    printf("\n");
}


float calcularTotal(stFactura factura){
    int i=0;
    float rta=0;
    while(i < factura.validosLibros){
        rta= rta+ factura.libros[i].precio;
        i++;
    }
    return rta;
}

