#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ff fflush(stdin);
#include "tdaListaLibros.h"
#include "ArchivosLibros.h"
#include "tdaListaGenero.h"


nodoGeneros* pasarArchToListaGenero(nodoGeneros* lista,char nombreArch[]);
RegistroArchLibro copiarStLibroToregistroArch(stLibro aux);

int main()
{
    char ArchivoGeneros[]="generosyLi.dat";
    char ArchivoDeLista[]="archLista.dat";

    mostrarArchLibros(ArchivoGeneros);


    nodoGeneros* lista= inicListaGeneros();
    lista=pasarArchToListaGenero(lista,ArchivoGeneros);
    mostrarListaCopletaLibrosYgen(lista);


    /*pasarArchToListaGenero(lista,ArchivoGeneros);
    printf("\nLista: ");
    mostrarListaCopletaLibrosYgen(lista);*/

    return 0;
}


stLibro copiarRegitroArchToStLibros(RegistroArchLibro aux){

    stLibro copia;

    strcpy(copia.titulo,aux.titulo);
    strcpy(copia.autor,aux.autor);
    strcpy(copia.codigo,aux.codigo);
    copia.rango=aux.rango;
    copia.precioVenta=aux.precioVenta;
    copia.precioRenta=aux.precioRenta;
    copia.cantidad=aux.cantidad;

    return copia;
}


nodoGeneros* pasarArchToListaGenero(nodoGeneros* lista,char nombreArch[]){

    FILE * arch=fopen(nombreArch,"rb");
    RegistroArchLibro aux;

    if(arch!=NULL){
        while(fread(&aux,sizeof(RegistroArchLibro),1,arch)>0){

            stLibro copia=copiarRegitroArchToStLibros(aux);

            lista=altaGenero(lista,aux.genero,copia);

        }
    }
    fclose(arch);

    return lista;
}

RegistroArchLibro copiarStLibroToregistroArch(stLibro aux){

    RegistroArchLibro copia;

    strcpy(copia.titulo,aux.titulo);
    strcpy(copia.autor,aux.autor);
    strcpy(copia.codigo,aux.codigo);
    copia.rango=aux.rango;
    copia.precioVenta=aux.precioVenta;
    copia.precioRenta=aux.precioRenta;
    copia.cantidad=aux.cantidad;

    return copia;
}

void pasarListaToArch(nodoGeneros* lista,char nombreArch[]){

    FILE * arch=fopen(nombreArch,"wb");
    RegistroArchLibro aux;
    nodoLibro* libros=inicListaLibros();

    if(arch!=NULL){
        nodoGeneros* segG=lista;
        while(segG!=NULL){
            libros=segG->listaLibros;

            while(libros!=NULL){

                strcpy(aux.genero,segG->genero);
                aux=copiarStLibroToregistroArch(libros->dato);

                fwrite(&aux,sizeof(RegistroArchLibro),1,arch);

                libros=libros->siguiente;
            }
            segG=segG->siguiente;
        }
    }
    fclose(arch);

}

/*void pasarDeADLToArchivoDeAprobados(celda adl[],char nombreArch[],int validos,int cantMaterias){

    FILE * arch=fopen(nombreArch,"w+b");
    int i=0;
    int j=0;
    registroArchivo aux;
    nodo* listaC=inicLista();

    if(arch!=NULL){
        while(validos>j && cantMaterias>i){

            listaC=adl[i].listaDeNotas;

            while(listaC!=NULL){

                if(listaC->dato.nota >= 6){

                    strcpy(aux.materia,adl[i].materia);
                    aux.idMateria=adl[i].idMateria;

                    aux.legajo=listaC->dato.legajo;
                    strcpy(aux.nombreApe,listaC->dato.nombreApe);
                    aux.nota=listaC->dato.nota;

                    fwrite(&aux,sizeof(registroArchivo),1,arch);
                    j++;

                    listaC=listaC->siguiente;
                }else{
                    listaC=listaC->siguiente;
                }
            }

            i++;
        }
    }
    fclose(arch);
}*/



