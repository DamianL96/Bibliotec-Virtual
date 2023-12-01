#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ArchivosClientes.h"
#include "arbol.h"



int main()
{

    char nombreArchivoClientes[20]={"ArchivoClientes.dat"};
    cargarArchivoClientes(nombreArchivoClientes);
    //mostrarArchivoClientes(nombreArchivoClientes);
    nodoClientes *arbol= inicArbol();
    arbol= archivoClientesToArbolCLientes(arbol,nombreArchivoClientes);

    inOrden(arbol);
    printf("\n inOrden");
    nodoClientes *cliente= inicArbol();
    cliente= buscar(arbol,ingresarDNI());
    if(cliente == NULL){
        printf("\n Error: El Cliente no existe...");
    }else{
        imprimirCliente(cliente->dato);
    }


//    char letra;
//    printf("pon una letra: ");
//    fflush(stdin);
//    scanf("%c", &letra);
//
//    if (isalpha(letra) == 0)
//    {
//        printf("Eso no es una letra...");
//    }
//    else
//    {
//        printf("Bien hecho");
//    }





    return 0;
}


