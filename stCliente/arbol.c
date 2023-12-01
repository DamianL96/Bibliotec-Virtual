#include <stdlib.h>
#include <stdio.h>
#include "arbol.h"
#include "stCliente.h"
#include "../stLibros/tdaListaGenero.h"
#include "ArchivosClientes.h"

nodoCliente* inicArbol(){
    return NULL;
}

nodoCliente* crearNodoArbol(stCliente dato){
    nodoCliente *nuevo= (nodoCliente*)malloc(sizeof(nodoCliente));

    nuevo->izq= NULL;
    nuevo->der= NULL;
    nuevo->dato= dato;
    return nuevo;
}

int ingresarDNI(){
    int dni;
    printf("\n DNI: ");
    fflush(stdin);
    scanf("%d",&dni);
    return dni;
}

nodoCliente* buscarClienteEnArbol(nodoCliente* arbol, int dato){
    nodoCliente *buscado=NULL;

    if(arbol != NULL){

        if(dato == arbol->dato.dni){
            buscado = arbol;
        }
        else if(dato > arbol->dato.dni){
            buscado= buscarClienteEnArbol(arbol->der, dato);
        }
        else{
            buscado= buscarClienteEnArbol(arbol->izq, dato);
        }
    }
    return buscado;
}



nodoCliente* modificarFacturaClienteEnArbol(nodoCliente* arbol, int dato,stFactura factura){

    if(arbol != NULL){

        if(dato == arbol->dato.dni){

            arbol->dato= agregarFacturaAlCliente(arbol->dato,factura);
        }
        else if(dato > arbol->dato.dni){/// si e dato es mayor a la raiz

            arbol->der= modificarFacturaClienteEnArbol(arbol->der, dato, factura); ///va a la derecha
        }
        else{

            arbol->izq= modificarFacturaClienteEnArbol(arbol->izq, dato, factura);
        }
    }
    return arbol;
}

nodoCliente* devolverLibroEnArbol(nodoCliente* arbol, int dato,char titulo[]){

    if(arbol != NULL){

        if(dato == arbol->dato.dni){

            arbol->dato= devolverLibroCliente(arbol->dato,titulo);
        }
        else if(dato > arbol->dato.dni){/// si e dato es mayor a la raiz

            arbol->der= devolverLibroEnArbol(arbol->der, dato, titulo); ///va a la derecha
        }
        else{

            arbol->izq= devolverLibroEnArbol(arbol->izq, dato, titulo);
        }
    }
    return arbol;
}




nodoCliente *insertarArbol(nodoCliente *arbol, nodoCliente *nuevo){
    if(arbol == NULL){
        arbol = nuevo;
    }
    else{
        if(nuevo->dato.dni > arbol->dato.dni){/// nuevo es mayor a raiz
            arbol->der= insertarArbol(arbol->der, nuevo);///se va a la derecha
        }
        else{
            arbol->izq= insertarArbol(arbol->izq, nuevo);/// el nuevo es menor 0 igual, se ubica a la izquierda
        }
    }
    return arbol;
}

nodoCliente *cargarArbol(nodoCliente *arbol){
    nodoCliente *nuevo;
    char c= 's';
    stCliente dato;
    while(c == 's'){
        dato= ingresarCliente();
        nuevo= crearNodoArbol(dato);
        arbol= insertarArbol(arbol,nuevo);
        controlArbol(&c);
    }
    return arbol;
}

void controlArbol(char *c){
    printf("\nOtro? si='s'");
    fflush(stdin);
    scanf("%c",c);
}

int contarHojas(nodoCliente *arbol){
    int i=0;
    if(arbol != NULL){
        if((arbol->izq == NULL) && (arbol->der == NULL)){
            i++;
            printf("|%d",arbol->dato.dni);
        }
        i= i+contarHojas(arbol->izq);
        i= i+contarHojas(arbol->der);
    }
    return i;
}



void preOrden(nodoCliente *arbol){ ///Raiz / Izquierda / Derecha
    if(arbol != NULL){
        imprimirCliente(arbol->dato);
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

void inOrden(nodoCliente *arbol){/// Izquierda / Raiz / Derecha
    if(arbol != NULL){
        inOrden(arbol->izq);
        imprimirCliente(arbol->dato);
        inOrden(arbol->der);
    }
}

void postOrden(nodoCliente *arbol){/// Izquierda / Derecha / Raiz
    if(arbol != NULL){
        postOrden(arbol->izq);
        postOrden(arbol->der);
        imprimirCliente(arbol->dato);
    }
}


void mostrarClientesConAlquiler(nodoCliente *arbol){
    if(arbol != NULL){
        mostrarClientesConAlquiler(arbol->izq);
        if(clienteConAlquiler(arbol->dato) == 1){///si el cliente tiene alquiler
            imprimirCliente(arbol->dato);
        }
        mostrarClientesConAlquiler(arbol->der);
    }
}


int clienteConAlquiler(stCliente cliente){
    int rta=0;
    int i=0;
    while( rta== 0 && i <cliente.validosFacturasCliente ){
        rta= facturaAlquiler(cliente.factura[i]);
        i++;
    }
    return rta;
}



void mostrarClientesExcentos(nodoCliente *arbol){
    if(arbol != NULL){
        mostrarClientesExcentos(arbol->izq);
        if(clienteConAlquiler(arbol->dato) == 0){
            imprimirCliente(arbol->dato);
        }
        mostrarClientesExcentos(arbol->der);
    }
}




void cargarNuevoClienteAlSistema(nodoCliente *arbol,char nombreArchivoClientes[]){///se llama cuando se va a alquilar

    nodoCliente *nuevo;
    stCliente cliente;
    stFactura factura;
    char nombreArchivoFacturas[]={"ArchivoFacturas"};
    int dni;
    char nombre[30];
    char cod[20];

    dni= ingresarDNI();

    nodoCliente *buscado=buscarClienteEnArbol(arbol,dni);///con el dni se busca si el cliente existe
    if(buscado == NULL){///si el cliente no existe

        printf("\n Nombre Y Apellido: ");
        fflush(stdin);
        gets(nombre);

        factura= cargarFactura(1);///se carga la factura
        cargarArchivoFactura(nombreArchivoFacturas,factura);///se agrega al archivo de facturas

        cliente= crearClienteNuevo(dni,nombre,factura);///se crea la el cliente con la factura

        imprimirFactura(factura);///se muestra la factura del momento

        cargarNuevoClienteAlArchivo(nombreArchivoClientes,cliente);///

    }else

    if(buscado->dato.dni == dni){

        imprimirCliente(buscado->dato);
        printf("\n");
        factura= cargarFactura(1);
        cargarArchivoFactura(nombreArchivoFacturas,factura);///se carga la factura a su archivo

        arbol = modificarFacturaClienteEnArbol(arbol,dni,factura);

        sobreEscribirArchivoClientes(nombreArchivoClientes,arbol);

    }
    return 0;
}







