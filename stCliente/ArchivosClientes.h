#ifndef ARCHIVOSCLIENTES_H_INCLUDED
#define ARCHIVOSCLIENTES_H_INCLUDED

#include "arbol.h"

void cargarArchivoClientes(char nombreArchivo[]);
void mostrarArchivoClientes(char nombreArchivo[]);
void arbolToArchivo(nodoCliente *arbol,FILE *archivo);




#endif // ARCHIVOSCLIENTES_H_INCLUDED
