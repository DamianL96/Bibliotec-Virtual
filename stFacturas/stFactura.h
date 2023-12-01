#ifndef STFACTURA_H_INCLUDED
#define STFACTURA_H_INCLUDED
#include "../stLibros/tdaListaGenero.h"
#include "stProducto.h"

typedef struct{
    char fecha[50];
    stProducto libros[10];
    int total;
    int validosLibros;
}stFactura;

stFactura cargarFactura(int alquila);
stFactura ingresarFactura();
void controlFactura(char *c);
void imprimirFactura(stFactura factura);
float calcularTotal(stFactura factura);
int facturaAlquiler(stFactura factura);
void completarFactura(stFactura *factura,int i);
stFactura devolverLibroEnFactura(stFactura factura,char titulo[]);

#endif // STFACTURA_H_INCLUDED
