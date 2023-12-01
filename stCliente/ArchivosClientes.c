#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "ArchivosClientes.h"
#include "stCliente.h"
#include "arbol.h"

#include "../stFacturas/stFactura.h"
#include "../stLibros/tdaListaGenero.h"


void cargarArchivoClientes(char nombreArchivo[]){

    FILE *archivoClientes=fopen(nombreArchivo,"ab");
    stCliente dato;
    char c='s';

    if(archivoClientes != NULL){
        while(c== 's'){

            dato= ingresarCliente();
            fwrite(&dato,sizeof(stCliente),1,archivoClientes);
            controlArbol(&c);

        }
        fclose(archivoClientes);
    }else{
        printf("\nError al abrir archivo");
    }

}

void cargarNuevoClienteAlArchivo(char nombreArchivo[],stCliente cliente){

    FILE *archivoClientes=fopen(nombreArchivo,"ab");

    if(archivoClientes != NULL){
        fwrite(&cliente,sizeof(stCliente),1,archivoClientes);
        fclose(archivoClientes);
    }else{
        printf("\nError al abrir archivo");
    }
}


void mostrarArchivoClientes(char nombreArchivo[]){

    FILE *archivoClientes= fopen(nombreArchivo,"rb");
    stCliente dato;

    if(archivoClientes != NULL){

        while(fread(&dato,sizeof(stCliente),1,archivoClientes) > 0){

            imprimirCliente(dato);
        }
        fclose(archivoClientes);
    }
}

void mostrarArchivoClienteSeleccionado(char nombreArchivo[],int dni){
    FILE *archivoClientes= fopen(nombreArchivo,"rb");
    stCliente dato;

    if(archivoClientes != NULL){

        while(fread(&dato,sizeof(stCliente),1,archivoClientes) > 0){
            if(dni == dato.dni){
                imprimirCliente(dato);
            }

        }
        fclose(archivoClientes);
    }
}

nodoCliente *archivoClientesToArbolCLientes(nodoCliente *arbol,char nombreArchivo[]){

    FILE *archivoClientes= fopen(nombreArchivo,"rb");
    stCliente dato;
    nodoCliente *nuevo= NULL;

    if(archivoClientes != NULL){
        while(fread(&dato,sizeof(stCliente),1,archivoClientes) > 0){

            nuevo= crearNodoArbol(dato);
            arbol= insertarArbol(arbol,nuevo);

        }
        fclose(archivoClientes);
    }
    return arbol;
}

void sobreEscribirArchivoClientes(char nombreArchivoClientes[],nodoCliente *arbol){
    FILE* archivo= fopen(nombreArchivoClientes,"w+b");
    if(archivo != NULL){
        arbolToArchivo(arbol,archivo);
        fclose(archivo);
    }
}

void arbolToArchivo(nodoCliente *arbol,FILE *archivo){
    if(arbol != NULL){
        arbolToArchivo(arbol->izq,archivo);
        fwrite(&arbol->dato,sizeof(stCliente),1,archivo);
        arbolToArchivo(arbol->der,archivo);
    }
}

