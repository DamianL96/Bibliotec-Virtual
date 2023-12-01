#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stProducto.h"


stProducto ingresarProducto(){
    stProducto dato;

    printf("\nTitulo: ");
    fflush(stdin);
    gets(dato.titulo);

    printf("\nPrecio: ");
    fflush(stdin);
    scanf("%d",&dato.precio);

    printf("\nAlquila si=1 no=0: ");
    fflush(stdin);
    scanf("%d",&dato.alquila);

    return dato;
}

stProducto cargarProducto(char titulo[],int precio,int alquila){
    stProducto libro;
    strcpy(libro.titulo,titulo);
    libro.precio=precio;
    libro.alquila= alquila;
    return libro;
}

int libroAlquilado(stProducto libro){
    int rta=0;
    if(libro.alquila == 1){
        rta=1;
    }
    printf("\nlibro alquilado:%d",rta);
    return rta;
}


void imprimirProducto(stProducto libro){
    char no[3]= {"No"};
    char si[3]= {"Si"};

    if(libro.alquila == 1){
        printf("\n  %s  |  $ %d  |  Alquila: %s ", libro.titulo, libro.precio, si);
    }else if(libro.alquila == 0){
        printf("\n  %s  |  $ %d  |  Alquila: %s ", libro.titulo, libro.precio, no);
    }
}
