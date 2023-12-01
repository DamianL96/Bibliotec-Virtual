#ifndef STCLIENTE_H_INCLUDED
#define STCLIENTE_H_INCLUDED


#include "../stFacturas/stFactura.h"

typedef struct{
    int dni;
    char nombre[20];
    stFactura factura[50];///hasta 50 facturas por cliente
    int validosFacturasCliente;
}stCliente;


stCliente ingresarCliente();
stCliente crearClienteNuevo(int dni,char nombre[],stFactura factura);
stCliente agregarFacturaAlCliente(stCliente cliente,stFactura factura);
void imprimirCliente(stCliente dato);
stCliente devolverLibroCliente(stCliente cliente,char titulo[]);
int clienteConAlquiler(stCliente cliente);
#endif // STCLIENTE_H_INCLUDED
