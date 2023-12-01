#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>
#include <windows.h>

#include "listaUsuario.h"

#define TECLA_BORRAR 8
#define TECLA_ENTER 13
#define TECLA_ESCAPE 27
#define ASTERISCO '*'


void PasardeListaToArchivoMenuUsuario(nodoUsuario * lista, char nombrearchivo[])
{
    Usuario unusuario;
    FILE * archivo= fopen(nombrearchivo, "w+b");

    if(archivo!=NULL)
    {
        while(lista!=NULL)
        {
            fwrite(&lista->usuario, sizeof(Usuario), 1, archivo);
            lista= lista->siguiente;
        }
    fclose(archivo);
    }
}



/// ESTA VA EN EL .C DE ARCHIVO
void mostrarArchivoMenuUsuario (char nombreArchivo[])
{
    FILE * archivoUsuario = fopen (nombreArchivo, "rb");
    Usuario unusuario;

    if(archivoUsuario!=NULL)
    {
        while(fread(&unusuario, sizeof(Usuario), 1, archivoUsuario)>0)
        {
            printf("%s \n", unusuario.nombreyapellido);
            printf("%d \n", unusuario.usuario);
            printf("%s \n", unusuario.contrasenia);
        }
    fclose(archivoUsuario);
    }
}


