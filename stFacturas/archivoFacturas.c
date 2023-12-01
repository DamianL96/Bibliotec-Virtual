
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "archivoFacturas.h"
#include "listaFactura.h"

///-------------------------------------------------stFactura
void cargarArchivoFactura(char nombreArchivo[],stFactura factura){
    FILE *archivo= fopen(nombreArchivo, "ab");
    if(archivo != NULL){
        fwrite(&factura,sizeof(stFactura),1,archivo);
        fclose(archivo);
    }
}

nodoFactura *archivoToLista(nodoFactura* listaFactura,char nombreArchivo[]){
    stFactura factura;
    nodoFactura *nuevo= inicLista();
    FILE *archivo= fopen(nombreArchivo, "rb");
    if(archivo != NULL){

        while( fread(&factura,sizeof(stFactura),1,archivo) > 0){
            factura.total=calcularTotal(factura);
            nuevo= crearNodo(factura);
            listaFactura= agregarAlPrincipio(nuevo,listaFactura);
        }
        fclose(archivo);
    }
    return listaFactura;
}///-------------------------------------------stFactura

