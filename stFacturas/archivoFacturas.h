#ifndef ARCHIVOFACTURAS_H_INCLUDED
#define ARCHIVOFACTURAS_H_INCLUDED
#include "listaFactura.h"

void cargarArchivoFactura(char nombreArchivo[],stFactura factura);
nodoFactura *archivoToLista(nodoFactura* listaFactura,char nombreArchivo[]);

#endif // ARCHIVOFACTURAS_H_INCLUDED
