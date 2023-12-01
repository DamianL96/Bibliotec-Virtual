#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "stCliente.h"
#include "../stFacturas/stFactura.h"


stCliente ingresarCliente(){
    printf("\n\n");
    stCliente nuevo;

    printf("\nDNI: ");
    fflush(stdin);
    scanf("%d",&nuevo.dni);

    printf("Nombre: ");
    fflush(stdin);
    scanf("%s",&nuevo.nombre);
    char c='s';
    int i=0;
    while( c=='s' && i< 50){
        nuevo.factura[i]= ingresarFactura();
        controlCliente(&c);
        i++;
    }
    nuevo.validosFacturasCliente=i;
    printf("\n\n");
    return nuevo;
}

void controlCliente(char *c){
    printf("\nAgregar Otra Factura? s/n: ");
    fflush(stdin);
    scanf("%c",c);
    while((c == 's')||(c =='n')){
        printf("\t¡Opcion Invalida!");
        printf("\nAgregar Otra Factura? s/n: ");
        fflush(stdin);
        scanf("%c",c);
    }
}

stCliente crearClienteNuevo(int dni,char nombre[],stFactura factura){
    stCliente nuevo;
    nuevo.dni= dni;
    strcpy(nuevo.nombre,nombre);

    nuevo.factura[0]= factura;
    nuevo.validosFacturasCliente=1;
    return nuevo;
}

stCliente agregarFacturaAlCliente(stCliente cliente,stFactura factura){///al llamar verificar que los validos sean menores a 10
    printf("\nfacturasValidas: %d",cliente.validosFacturasCliente);
    if(cliente.validosFacturasCliente <50){

        cliente.factura[cliente.validosFacturasCliente]= factura;

        cliente.validosFacturasCliente= cliente.validosFacturasCliente+1;
        imprimirCliente(cliente);
        //printf("\nfacturasValidas: %d",cliente.validosFacturasCliente);

    }else{
        printf("\nMaximo de Facturas Por Cliente Alcanzado!");
    }

    return cliente;
}

stCliente devolverLibroCliente(stCliente cliente,char titulo[]){
    int i=0;
    while(i < cliente.validosFacturasCliente){
        cliente.factura[i]=devolverLibroEnFactura(cliente.factura[i],titulo);
        i++;
    }
    return cliente;
}


void imprimirCliente(stCliente dato){
    printf("\n\n");
    printf("\nDNI: %d", dato.dni);
    printf("\nNombre: %s", dato.nombre);
    int i=0;
    while(i < dato.validosFacturasCliente){
        imprimirFactura(dato.factura[i]);
        i++;
    }
    printf("\n\n");
}

