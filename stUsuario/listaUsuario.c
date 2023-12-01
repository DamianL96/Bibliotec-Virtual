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


nodoUsuario * inicListaMenuGeneral()
{
    return NULL;
}

///CREAR NODO---------------------------------------------------------------------------
nodoUsuario * crearNodoUsuarioMenuGeneral(Usuario Nuevousuario)
{
    nodoUsuario * aux;
    aux= (nodoUsuario*)malloc(sizeof(nodoUsuario));
    aux->usuario.usuario = Nuevousuario.usuario;
    strcpy(aux->usuario.nombreyapellido, Nuevousuario.nombreyapellido);
    strcpy(aux->usuario.contrasenia, Nuevousuario.contrasenia);
    aux->siguiente= NULL;

    return aux;
}




nodoUsuario * crearUsuario(nodoUsuario * lista)
{
    Usuario nuevo;
    int valor=0;
    int existe=0;
    int validar=0;

    printf("-----------------------\n");
    printf("Ingrese DNI: ");
    fflush(stdin);

    do
    {
        gets(nuevo.usuario);
        valor = verificarCharNum(nuevo.usuario);
        existe = buscarNodoUsuarioMenuGeneral(lista, nuevo.usuario);

    }while(valor !=0 && existe!=1);


    printf("Ingrese contraseña (sin espacios): ");
    fflush(stdin);

    do
    {
        gets(nuevo.contrasenia);
        validar = verificarCharLetra(nuevo.contrasenia);

    }while(validar!=0);


    nodoUsuario * nuevoNodo = crearNodoUsuarioMenuGeneral(nuevo);

    return nuevoNodo;
}


int buscarNodoUsuarioMenuGeneral(nodoUsuario * lista, char dni[])
{
    nodoUsuario * seg;
    seg = lista;
    int existeono=0;

    while(seg!=NULL && existeono == 0)
    {
        if(strcmp(seg->usuario.usuario, dni)==0)
        {
            existeono=1;
        }
        seg=seg->siguiente;
    }

    return existeono;
}


nodoUsuario * agregarppiodeUsuario (nodoUsuario * lista, nodoUsuario * nuevo)
{
    if(lista==NULL)
    {
        lista= nuevo;
    }
    else
    {
        nuevo->siguiente= lista;
        lista = nuevo;
    }
    return lista;
}

void mostrarlistaDeUsuario (nodoUsuario * lista)
{
    nodoUsuario * seguidora= lista;
    while(seguidora!=NULL)
    {
        mostrarUsuario(seguidora->usuario);
        seguidora=seguidora->siguiente;
    }
}

void mostrarUsuario(Usuario unusuario)
{
    printf(" %s \n", unusuario.nombreyapellido);
    printf(" %d \n", unusuario.usuario);
    printf(" %s \n", unusuario.contrasenia);
}



int buscarNodoDNIdeUsuario (nodoUsuario * lista, int dni)
{
    nodoUsuario * seguidora = NULL;
    seguidora=lista;
    int rta=0;

        while(seguidora!=NULL && rta==0)
        {
            if(dni == seguidora->usuario.usuario)
            {
                rta= 1;
            }else
            {
                seguidora=seguidora->siguiente;
                rta= buscarNodoDNIdeUsuario(seguidora, dni);
            }
        }
    return rta;
}

nodoUsuario * buscarNodoDNIdeUsuarioParaLogin (nodoUsuario * lista, int dni)
{
    nodoUsuario * seguidora = NULL;
    nodoUsuario * aux=NULL;
    seguidora=lista;
    int rta=0;

        while(seguidora!=NULL && rta==0)
        {
            if(dni == seguidora->usuario.usuario)
            {
                aux = seguidora;
                rta=1;
            }
                seguidora=seguidora->siguiente;
        }
    return aux;
}


nodoUsuario * cargarListadeUsuariosDesdeCero(nodoUsuario * lista)
{
    char mander='s';
    int dni=0;

    while(mander=='s')
    {
        printf("Ingrese DNI\n");
        fflush(stdin);
        scanf("%d", &dni);
        nodoUsuario * nuevoNodo= cargarNodoUsuarioMenuGeneral(dni);
        lista= agregarppiodeUsuario(lista, nuevoNodo);

        printf("\nDesea seguir cargando usuarios?\n");
        fflush(stdin);
        scanf("%c", &mander);
    }
return lista;
}



nodoUsuario * cargarNodoUsuarioMenuGeneral(int dni)
{
    Usuario unusuario;

    printf("\nIngrese nombre y apellido del Usuario:\n");
    fflush(stdin);
    gets(&unusuario.nombreyapellido);

    unusuario.usuario= dni;

    printf("Ingrese contrasenia del Usuario:\n");
    fflush(stdin);
    scanf("%s", &unusuario.contrasenia);

    nodoUsuario * nuevoNodo = crearNodoUsuarioMenuGeneral(unusuario);
    return nuevoNodo;
}



nodoUsuario * ArchivoToListadeUsuario(nodoUsuario * lista, char arch[])
{
    Usuario unusuario;
    FILE * archivo = fopen(arch, "rb");

    if(archivo!=NULL)
    {
        while(fread(&unusuario, sizeof(Usuario), 1, archivo)>0)
        {
            nodoUsuario * nuevo= crearNodoUsuarioMenuGeneral(unusuario);
            lista= agregarppiodeUsuario(lista, nuevo);
        }
    fclose(archivo);
    }
    else
    {
        printf("\nNo se pudo abrir el archivo.\n");
    }

    return lista;
}




int iniciarSesion(nodoUsuario * lista)
{
    int dni;
    int validacion=0;
    char password[30];
    int rta=0;
    int logincorrecto=0;


    printf("\n - INICIAR SESION - \n");
    printf("\n - DNI: ");
    fflush(stdin);
    scanf("%d",&dni);

    validacion= buscarNodoDNIdeUsuario(lista, dni);

    if(validacion==1)
    {
        printf("\n - PASSWORD: ");
        fflush(stdin);
        scanf("%s", &password);

        nodoUsuario * aux = buscarNodoDNIdeUsuarioParaLogin(lista, dni);

        if(strcmpi(password, aux->usuario.contrasenia)==0)
        {
            rta=1;
            ///leerContrasenaSinMostrarla(password,dni);
            printf("\n");
        }
        else
        {
            printf("Contraseña incorrecta\n");
            /// go to login again.
        }
    }
    else
    {
        printf("El dni ingresado no existe \n  ");
    }

    if(rta==1 && validacion==1)
    {
        logincorrecto=1;
    }

return logincorrecto;
}


