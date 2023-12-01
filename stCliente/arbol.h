#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include "stCliente.h"


typedef struct{
    stCliente dato;
    struct nodoCliente *izq;
    struct nodoCliente *der;
}nodoCliente;

nodoCliente* inicArbol();
nodoCliente* crearNodoArbol(stCliente dato);
nodoCliente* insertarArbol(nodoCliente *arbol, nodoCliente *nuevo);
nodoCliente* cargarArbol(nodoCliente *arbol);

nodoCliente* buscarClienteEnArbol(nodoCliente* arbol, int dato);
nodoCliente* modificarFacturaClienteEnArbol(nodoCliente* arbol, int dato,stFactura factura);

void preOrden(nodoCliente *arbol);
void inOrden(nodoCliente *arbol);
void postOrden(nodoCliente *arbol);

void controlArbol(char *c);
int contarHojas(nodoCliente *arbol);
void cargarNuevoClienteAlSistema(nodoCliente *arbol,char nombreArchivoClientes[]);
nodoCliente* devolverLibroEnArbol(nodoCliente* arbol, int dato,char titulo[]);


#endif // ARBOL_H_INCLUDED
