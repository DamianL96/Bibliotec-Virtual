#ifndef FUNC_ARCHIVO_H_INCLUDED
#define FUNC_ARCHIVO_H_INCLUDED


                                /// PROTOTIPADO funciones archivo
void PrimerMenu(char nombrearchivousuario[]);
void RegistrarUsuario(char nombreArchivo [30], nodoUsuario * lista);
void mostrarArchivoMenuUsuario (char nombreArchivo[30]);
void PasardeListaToArchivoMenuUsuario (nodoUsuario * lista, char nombrearchivo[30]);

#endif // FUNC_ARCHIVO_H_INCLUDED
