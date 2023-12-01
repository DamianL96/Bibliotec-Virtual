#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#define ff fflush(stdin);
#include "Manager.h"


#include "stFacturas/listaFactura.h"

#include "stLibros/tdaListaGenero.h"
#include "stLibros/tdaListaGenero.h"
#include "stLibros/ArchivosLibros.h"

#include "stCliente/ArchivosClientes.h"
#include "stCliente/arbol.h"

void comprar(){
    char nombreArchivoFacturas[20]= {"ArchivoFacturas"};
    stFactura factura;

    factura= cargarFactura(0);

    imprimirFactura(factura);
    cargarArchivoFactura(nombreArchivoFacturas,factura);
}

void alquilar(){
    char nombreArchivoFacturas[20]= {"ArchivoFacturas"};
    char nombreArchivoClientes[20]= {"ArchivoClientes"};
    nodoCliente* arbol=inicArbol();

    arbol=archivoClientesToArbolCLientes(arbol,nombreArchivoClientes);

    cargarNuevoClienteAlSistema(arbol,nombreArchivoClientes);/// se agregan los libros en una nueva factura

}

void devolucion(){
    char cod[10];
    char nombreArchivoClientes[20]={"ArchivoClientes"};
    nodoCliente*arbol = inicArbol();
    nodoCliente *cliente=inicArbol();
    arbol= archivoClientesToArbolCLientes(arbol,nombreArchivoClientes);

    char nombreArchivoLibros[20]= {"libros.dat"};
    nodoGeneros*listaGeneros= inicListaGeneros();
    listaGeneros= pasarArchToListaGenero(listaGeneros,nombreArchivoLibros);


    int dni=ingresarDNI();

    cliente= buscarClienteEnArbol(arbol,dni);
    if(cliente != NULL){
        imprimirCliente(cliente->dato);

        printf("INGRESAR CODIGO:");
        fflush(stdin);
        scanf("%s",&cod);

        nodoLibro* buscado= buscarNodoGeneroCodigo(listaGeneros,cod);

        arbol= devolverLibroEnArbol(arbol,dni,buscado->dato.titulo);
        sobreEscribirArchivoClientes(nombreArchivoClientes,arbol);

        listaGeneros= devolverLibroAListaGenero(listaGeneros,cod,1);///agrega 1 a la lista
        pasarListaToArch(listaGeneros,nombreArchivoLibros);

    }else{
        printf("\n El Cliente no existe...");
    }
}

void mostrarClientesExcentosMenu(){
    char nombreArchivoClientes[]={"ArchivoClientes"};
    nodoCliente*arbol=inicArbol();
    arbol= archivoClientesToArbolCLientes(arbol,nombreArchivoClientes);
    mostrarClientesExcentos(arbol);
}

void mostrarClientesConAlquilerMenu(){
    char nombreArchivoClientes[]={"ArchivoClientes"};
    nodoCliente*arbol=inicArbol();

    arbol= archivoClientesToArbolCLientes(arbol,nombreArchivoClientes);

    mostrarClientesConAlquiler(arbol);
}

void mostrarTodasLasFacturas(){
    char nombreArchivoFactura[]={"ArchivoFacturas"};
    nodoFactura* listaFactura= inicLista();
    listaFactura= archivoToLista(listaFactura,nombreArchivoFactura);
    mostrarListaFacturas(listaFactura);
}

void mostrarFacturasDelMesMenu(){
    char nombreArchivoFacturas[]={"archivoFacturas"};
    nodoFactura *listaFacturas=inicLista();
    listaFacturas=archivoToLista(listaFacturas,nombreArchivoFacturas);
    char mes[10];
    printf("\nMes a Buscar (nuemero del mes): ");
    fflush(stdin);
    scanf("%s",&mes);
    mostrarFacturasDelMes(listaFacturas,mes);
}

void mostrarFacturasDelDiaMenu(){
    char nombreArchivoFacturas[]={"archivoFacturas"};
    nodoFactura *listaFacturas=inicLista();
    listaFacturas=archivoToLista(listaFacturas,nombreArchivoFacturas);
    char dia[21];
    printf("\nDia a Buscar (dia/mes): ");
    fflush(stdin);
    scanf("%s",&dia);
    mostrarFacturasDelDia(listaFacturas,dia);
}

void agregarStockLibroMenu(){

    char ArchivoDeLista[]="libros.dat";
    char c='s';
    char cod[20];

    nodoGeneros* lista=inicListaGeneros();
    lista=pasarArchToListaGenero(lista,ArchivoDeLista);

    while(c=='s'){

        printf("\n\nIngrese el codigo del libro del que desea agregar stock\n ");
        ff
        gets(&cod);

        lista=agregarCantidadDeLibroEnLista(lista,cod);

        //printf("\n\n Se agrego correctamente\n ");

        printf("\nDesea seguir cargando stock? s/n \n");
        ff
        scanf("%c",&c);

       while(c!='s' && c!='n'){

            system("cls");

            printf("\nCaracter no valido ingrese: s/n (Si o NO)");
            ff
            scanf("%c",&c);
        }
    }

    pasarListaToArch(lista,ArchivoDeLista);
    system("pause");

}

void ModoCliente(){

    system("cls");

    char ArchivoDeLista[]="libros.dat";
    nodoGeneros* lista=inicListaGeneros();
    lista=pasarArchToListaGenero(lista,ArchivoDeLista);

    char c='s';

    do{
        int i=0;

        while((i<1)||(i>5)){
            printf("\nIngrese que funcion desea realizar: \n1. Buqueda de libro por codigo\n");
            printf("2. Buqueda de libro por Titulo\n");
            printf("3. Buqueda de libro por Autor\n");
            printf("4. Mostrar Por Genero\n");
            printf("5. Mostrar Por Rango Edad\n");
            ff
            scanf("%d",&i);
            system("cls");
        }

        switch(i){

            case 1:

                BusquedaDeLibroPorCodigo(lista);
                printf("\n\n");
                system("pause");

                break;

            case 2:

                BusquedaDeLibroPorTitulo(lista);
                printf("\n\n");
                system("pause");

                break;

            case 3:


                BusquedaDeLibrosPorAutor(lista);
                printf("\n\n");
                system("pause");

                break;

            case 4:

                BusquedaDeLibrosPorGenero(lista);
                printf("\n\n");
                system("pause");

                break;

            case 5:

                mostrarLibrosPorRangoMenu();
                printf("\n\n");
                system("pause");

                break;

        }

        printf("\n\nDesea seguir realizando alguna de estas funciones? s/n");
        ff
        scanf("%c",&c);

        system("cls");

        while(c!='s' && c!='n'){
            printf("\nCaracter no valido ingrese: s/n (Si o NO)");
            ff
            scanf("%c",&c);
        }

    }while(c=='s');
}

void BusquedaDeLibrosPorGenero(nodoGeneros* lista){

    char genero[30];
    system("cls");

    printf("\nIngrese el genero que desea buscar: \n");
    ff
    gets(&genero);

    nodoGeneros* libro=inicListaGeneros();
    libro=buscarNodoGenero(lista,genero);

    if(libro!=NULL){
        printf("\n\nLos libros que hay del genero %s son: ",genero);
        mostrarListaLibrosSOLODisponibles(libro->listaLibros);
    }else{
        printf("\n\nEl genero ingresado NO existe\n");
    }
}

void BusquedaDeLibrosPorAutor(nodoGeneros* lista){

    char autor[30];
    system("cls");

    printf("\nIngrese el autor: \n");
    ff
    gets(&autor);

    nodoLibro* libros=inicListaLibros();
    libros=buscarNodoGeneroAutor(lista,autor);

    if(libros!=NULL){

        if(libros->siguiente!=NULL){
            printf("\nLos libros del autor son:\n");
            mostrarListaLibrosSOLODisponibles(libros);
        }else{
            printf("\nEl libro del autor es:\n");
            mostrarListaLibrosSOLODisponibles(libros);
        }

    }else if(libros==NULL){
        printf("\n\nNo se encontro ningun libro del autor");
    }
}

void BusquedaDeLibroPorTitulo(nodoGeneros* lista){

    char titulo[30];

    system("cls");

    printf("\nIngrese el TITULO que desea buscar: \n");
    ff
    gets(&titulo);

    nodoLibro* libro=inicListaLibros();
    libro=buscarNodoGeneroTitulo(lista,titulo);

    if(libro!=NULL){
        printf("\nEl libro es:\n");
        mostrarListaLibrosSOLODisponibles(libro);
    }else{
        printf("\nEl libro con el titulo ingresado NO existe \n");
    }

}

void BusquedaDeLibroPorCodigo (nodoGeneros* lista){

    char cod[20];

    system("cls");

    printf("\nIngrese el codigo que desea buscar: ");
    ff
    gets(&cod);

    nodoLibro* libro=inicListaLibros();
    libro=buscarNodoGeneroCodigo(lista,cod);

    if(libro!=NULL){
        printf("\nEl libro es:\n");
        mostrarListaLibrosSOLODisponibles(libro);
        printf("\n\n");
    }else{
        printf("\nEl libro con el codigo ingresado NO existe \n");
    }

}

void borrarParaMenuUnLibro(){     /** da de baja un libro por codigo y sobreescribe el arch sin el */

    char ArchivoDeLista[]="libros.dat";

    nodoGeneros* lista=inicListaGeneros();
    lista=pasarArchToListaGenero(lista,ArchivoDeLista);

    char c='s';
    char cod[20];

    while(c=='s'){

       printf("\n\nIngrese el codigo del libro que desea borrar en la lista: \n");
       ff
       gets(&cod);

       lista=borrarBorrarLibroEnNodo(lista,cod);

        printf("\nDesea dar de baja otro? s/n \n");
        ff
        scanf("%c",&c);

       while(c!='s' && c!='n'){
            printf("\nCaracter no valido ingrese: s/n (Si o NO)");
            ff
            scanf("%c",&c);
        }

    }

    pasarListaToArch(lista,ArchivoDeLista);
}

void agregarLibroMenu(){

    char ArchivoDeLista[]="libros.dat";

    nodoGeneros* lista=inicListaGeneros();
    lista=pasarArchToListaGenero(lista,ArchivoDeLista);

    char c='s';

    while(c=='s'){

        lista=ingresarGenerosYlibros(lista);

        printf("\nDesea agregar otro? s/n \n");
        ff
        scanf("%c",&c);

       while(c!='s' && c!='n'){
            printf("\nCaracter no valido ingrese: s/n (Si o NO)");
            ff
            scanf("%c",&c);
        }
    }

    pasarListaToArch(lista,ArchivoDeLista);

}

void mostrarLibrosPorRangoMenu(){

    char ArchivoDeLista[]="libros.dat";

    nodoGeneros* lista=inicListaGeneros();
    lista=pasarArchToListaGenero(lista,ArchivoDeLista);
    int edad=0;
    printf("\n\nIngrese su edad para mostrarle los libros diponibles: \n");
    ff
    scanf("%d",&edad);

    nodoLibro* libros=inicListaLibros();

    if(edad < 18){

        libros=buscarNodoGeneroMenoresEdad(lista,edad);
        mostrarListaLibrosSOLODisponibles(libros);
    }else{

        libros=buscarNodoGeneroMayoresEdad(lista,edad);
        mostrarListaLibrosSOLODisponibles(libros);
    }

    system("pause");
}
