#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stFactura.h"

typedef struct nodoFactura{
    stFactura factura;
    struct nodoFactura *sig;
}nodoFactura;


nodoFactura* inicLista();
nodoFactura* crearNodo(stFactura dato);
nodoFactura* cargarLista(nodoFactura *lista);
nodoFactura* cargarListaAlFinal(nodoFactura *lista);
nodoFactura* cargarListaOrdenanda(nodoFactura *lista);

nodoFactura* agregarAlPrincipio(nodoFactura *nuevo,nodoFactura *lista);
nodoFactura* agregarAlFinal(nodoFactura *nuevo,nodoFactura *lista);
nodoFactura *agregarEnOrden(nodoFactura *nuevo, nodoFactura *lista);

nodoFactura* buscarUltimo(nodoFactura *lista);
nodoFactura* buscarXNombre(nodoFactura *lista,char nombreBuscado[]);

nodoFactura *borrarNodo(int edad,nodoFactura *lista);
nodoFactura *borrarListaCompleta(nodoFactura *lista);

void buscarXFecha(nodoFactura *listaFactura,char limite[]);
void mostrarListaFacturas(nodoFactura *lista);
void imprimirNodo(nodoFactura *a);

int semaforoInferior(nodoFactura* listaFactura,char limiteInferior[],int semaforo);
int semaforoSuperior(nodoFactura* listaFactura,char limiteSuperior[],int semaforo);
int compararFecha(nodoFactura *listaFactura,char fecha[]);
void mostrarEntreFechas(nodoFactura*listaFactura,char limiteInferior[],char limiteSuperior[]);

#endif // LISTAS_H_INCLUDED
