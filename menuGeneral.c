#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>
#include <windows.h>


#include "stUsuario/listaUsuario.h"
#include "Manager.h"





#define TECLA_BORRAR 8
#define TECLA_ENTER 13
#define TECLA_ESCAPE 27
#define ASTERISCO '*'


/// *******************************FUNCIONES******************

int verificarCharNum (char palabra[])
{
    int dimension=0;
    int flag = 1;
    dimension = strlen(palabra);

    for(int i=0; i<dimension; i++)
    {
        if(!isdigit(palabra[i]))
        {
            flag = 0;
        }
    }

    return flag;
}



int verificarCharLetra (char palabra[]) /// sin espacios
{
    int dimension=0;
    int flag = 1;
    dimension = strlen(palabra);

    for(int i=0; i<dimension; i++)
    {
        if(isspace(palabra[i]))
        {
            flag = 0;
        }
    }

    return flag;
}



/// ESTA VA EN EL .C DE MENU
void PrimerMenu()
{
    char nombrearchivousuario[]={"Archivo.dat"};
    int opcion=0;
    do
    {
        int login=0;
        int eleccion=0;
        int dniabuscar=0;


        int trueorfalse=0;
        nodoUsuario * lista= inicListaMenuGeneral();


        printf("\n-----Elija su modo de Ingreso----\n");
        printf("\n---1---Modo Usuario-----\n");
        printf("---2---Modo Cliente-----\n");
        printf("---3---SALIR-----");

        printf("\nOpcion: \n");
        fflush(stdin);
        scanf("%d", &opcion);
        system("cls");
        switch(opcion)
        {
        case 1:

            printf("\n--1---INICIAR SESION-----\n");
            printf("\n--2---REGISTRARSE-----\n");
            fflush(stdin);
            scanf("%d", &eleccion);
            system("cls");

            if(eleccion==2)  /// SI SE QUIERE REGISTRAR
            {
                lista = ArchivoToListadeUsuario(lista, nombrearchivousuario);  /// PASO DEL ARCHIVO A LA LISTA
                printf("\nIngrese su DNI\n\n");
                fflush(stdin);
                scanf("%d", &dniabuscar);
                int trueorfalse = buscarNodoDNIdeUsuario(lista, dniabuscar); /// BUSCO SI ESTA O NO EL DNI EN LA LISTA
                if(trueorfalse==1)
                {
                    printf("\nEl DNI ingresado ya esta registrado\n");
                    ///vuelve a menu de elegir como iniciar sesion
                    system("pause");
                    system("cls");
                }else
                {
                    nodoUsuario * nuevouser = NULL;
                    nuevouser = cargarNodoUsuarioMenuGeneral(dniabuscar);                        /// CARGO DATOS DEL NUEVO USUARIO Y LO AGREGO EN EL ARCHIVO
                    lista= agregarppiodeUsuario(lista, nuevouser);
                    PasardeListaToArchivoMenuUsuario(lista, nombrearchivousuario);
                    printf("Registro exitoso! :)\n\n Ahora inicie sesion...\n");
                }
            }
            else if(eleccion==1)            /// SI QUIERE INICIAR SESION
            {

                lista = ArchivoToListadeUsuario(lista, nombrearchivousuario);  /// PASO A LISTA PARA BUSCAR SU DNI Y VER SU CONTRASEÑA
                login= iniciarSesion(lista);

                if(login==1)
                {
                    printf("Ingreso exitoso :) \n\n");
                    system("pause");
                    system("cls");
                    MenuUsuario();
                }
            }else
            {
                printf("Opcion incorrecta\n");
            }
            system("pause");
            system("cls");
            break;

        case 2:
            MenuCliente();
            system("pause");
            system("cls");
            break;

        case 3:
            printf("\nHas cerrado el programa.\n");
            system("pause");
            system("cls");
            printf(" \n\n Hasta luego :)  \n\n\n              Vuelva pronto\n\n\n\n                       Aqui lo esperaremos! \n\n");
            break;

        default:
            printf("\nOpcion incorrecta.\n");
            break;
        }
    }
    while(opcion!=3);
}


/// ESTA VA EN EL .C DE MENU
void MenuUsuario()
{
    int opcion=0;
    do
    {
        printf("\n---1---Venta de libros----\n");
        printf("---2---Manejo del sistema interno----\n");
        printf("---3---Registro de Ventas----\n");
        printf("---4---Sistema de Rentas/Alquileres----\n");
        printf("---5-------Salir----------\n");

        printf("\nOpcion: \n");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:

                    system("cls");
                    comprar();
                    system("pause");

                    break;

        case 2:

                    system("cls");
                    ManejoSistemaInterno();
                    system("pause");
                    break;

        case 3:

                    system("cls");
                    RegistroVentasUsuario();
                    system("pause");
                    break;


        case 4:
                    system("cls");
                    SistemadeRentasUsuario();
                    system("pause");
                    break;

        case 5: ///este si es el unico que rompe directamente. xq es salir

                    system("cls");
                    printf(" \n\n Hasta luego :)  \n\n\n              Vuelva pronto\n\n\n\n                       Aqui lo esperaremos! \n\n");
                    system("pause");
                    break;

        default:
                    printf("\nOpcion Incorrecta. Ingrese nuevamente\n");
                    break;
        }
    }while(opcion!=5);
}


/// ESTA VA EN EL .C DE MENU
void VentaDeLibros()
{
    int opcion=0;
    do
    {
        printf("\n---1---Ingresar Codigo de Libro----\n");
        printf("---2-------Salir----------\n");

        printf("\nOpcion: \n");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
                    system("pause");
                    system("cls");
                    CompraLibro();
                    break;

        case 2:
                    system("pause");
                    system("cls");
                    break;

        default:
            printf("\nOpcion Incorrecta. Ingrese nuevamente\n");
            break;
        }
    }
    while(opcion!=2);
}



/// ESTA VA EN EL .C DE MENU
void CompraLibro()
{
       int opcion=0;
    do
    {
        printf("\n---1---Comprar Libro----\n");
        printf("---2-------Salir----------\n");

        printf("\nOpcion: \n");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1: ///funcion de comprar libro
                    comprar();
                    system("pause");
                    system("cls");
                    break;

        case 2:
                    system("pause");
                    system("cls");
                    break;

        default:
                    printf("\nOpcion Incorrecta. Ingrese nuevamente\n");
                    break;
        }
    }while(opcion!=2);
}



/// ESTA VA EN EL .C DE MENU
void ManejoSistemaInterno()
{
    int opcion=0;
    do
    {
        printf("\n---1---Agregar un nuevo libro al sistema----\n");
        printf("---2-------Eliminar un libro del sistema----------\n");
        printf("---3-------Salir----------\n");

        printf("\nOpcion: \n");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:

                    system("cls");
                    AgregarLibroAlSistemaUsuario();
                    system("pause");
                    break;

        case 2:

                    system("cls");
                    EliminarUnLibroDelSistemaUsuario();
                    system("pause");
                    break;
        case 3:
                    system("cls");
                    break;

        default:

                    system("cls");
                    printf("\nOpcion Incorrecta. Ingrese nuevamente\n");
                    break;
        }
    }
    while(opcion!=3);
}


/// ESTA VA EN EL .C DE MENU
void AgregarLibroAlSistemaUsuario(){
    int opcion=0;
    do
    {
        printf("\n---1---Alta a un nuevo libro----\n");
        printf("---2-----Agregar stock ---------\n");
        printf("---3---------SALIR---------\n");

        printf("\nOpcion: \n");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1: ///funcion alta a nuevo libro
            agregarLibroMenu();
            system("pause");
            break;

        case 2:
            agregarStockLibroMenu();
            system("cls");
            break;

        case 3:
            system("cls");
            break;

        default:

            system("cls");
            printf("\nOpcion Incorrecta. Ingrese nuevamente\n");
            break;
        }
    }while(opcion!=3);
}



/// ESTA VA EN EL .C DE MENU
void EliminarUnLibroDelSistemaUsuario()
{
int opcion=0;
    do
    {
        printf("\n---1---Baja libro----\n");
        printf("---2-------Salir----------\n");

        printf("\nOpcion: \n");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1: ///funcion baja libro

                    borrarParaMenuUnLibro();
                    system("cls");
                    break;

        case 2:

                    system("cls");
                    break;

        default:

                    system("cls");
                    printf("\nOpcion Incorrecta. Ingrese nuevamente\n");
                    break;
        }
    }while(opcion!=2);
}



/// ESTA VA EN EL .C DE MENU
void RegistroVentasUsuario()
{
int opcion=0;
    do
    {
        printf("\n---1---Revision Facturas----\n");
        printf("---2----Facturas Del Dia-----------\n");
        printf("---3----Facturas Del Mes----------\n");
        printf("---4-------Salir----------\n");

        printf("\nOpcion: \n");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1: ///funcion revision facturas
                    mostrarTodasLasFacturas();
                    system("pause");
                    system("cls");
                    break;

        case 2:   ///funcion que muestra Resumen del dia-semana-mes-anio
                    mostrarFacturasDelDiaMenu();
                    system("pause");
                    system("cls");
                    break;

        case 3:
                    mostrarFacturasDelMesMenu();
                    system("pause");
                    system("cls");
                    break;

        case 4:
                    system("cls");
                    break;

        default:
                    printf("\nOpcion Incorrecta. Ingrese nuevamente\n");
                    break;
        }
    }
    while(opcion!=4);
}



/// ESTA VA EN EL .C DE MENU
void SistemadeRentasUsuario()
{
    int opcion=0;
    do
    {
        printf("\n---1---Alquiler----\n");
        printf("---2-------Devolucion----------\n");
        printf("---3-------Clientes Activos----------\n");
        printf("---4-------Clientes Excentos----------\n");
        printf("---5-------Salir----------\n");

        printf("\nOpcion: \n");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1: ///funcion alquiler
            alquilar();
            printf("\n");
            system("pause");
            system("cls");
            break;

        case 2: ///funcion devolucion
            devolucion();
            printf("\n");
            system("pause");
            system("cls");
            break;

        case 3:  /// funcion muestra clientes activos;
            mostrarClientesConAlquilerMenu();
            printf("\n");
            system("pause");
            system("cls");
            break;

        case 4:
            mostrarClientesExcentosMenu();
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            break;

        default:
            system("pause");
            system("cls");
            printf("\nOpcion Incorrecta. Ingrese nuevamente\n");
            break;
        }
    }while(opcion!=5);
}




/// ESTA VA EN EL .C DE MENU
void MenuCliente()
{
    char nombreArchivoLibro[]={"libros.dat"};
    nodoGeneros *listaGeneros= inicListaGeneros();
    listaGeneros=pasarArchToListaGenero(listaGeneros,nombreArchivoLibro);
    int opcion=0;


    do
    {
        printf("\n---1---Buscar libro por Codigo----\n");
        printf("---2---Buscar libro por Titulo----\n");
        printf("---3---Buscar libro por Autor----\n");
        printf("---4---Mostrar por Generos----\n");
        printf("---5---Mostrar Por Rango Edad---\n");
        printf("---6-------Salir----------\n");

        printf("\nOpcion: \n");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)          /// aca van las funciones de valen en cada case. segun cada caso.
        {
        case 1:
                    system("cls");
                    BusquedaDeLibroPorCodigo(listaGeneros);
                    system("pause");
                    break;

        case 2:

                    system("cls");
                    BusquedaDeLibroPorTitulo(listaGeneros);
                    system("pause");
                    break;

        case 3:

                    system("cls");
                    BusquedaDeLibrosPorAutor(listaGeneros);
                    system("pause");
                    break;
        case 4:

                    system("cls");
                    BusquedaDeLibrosPorGenero(listaGeneros);
                    system("pause");
                    break;

         case 5:

                mostrarLibrosPorRangoMenu();
                printf("\n\n");
                system("pause");

                break;

        case 6: ///este si es el unico que rompe directamente. xq es salir
                    system("pause");
                    system("cls");
                    break;

        default:
                    system("pause");
                    system("cls");
                    printf("\nOpcion Incorrecta. Ingrese nuevamente\n");
                    break;
        }
        system("cls");
    }
    while(opcion!=6);
}




/// ESTA VA EN EL .C DE MENU
void enmascaraCadena(char *cadena, int longitud, char asterisco,int dni)
{
    int i = 0;
    printf("\n - INICIAR SESION - \n");
    printf("\n - DNI: %d ",dni);
    printf("\n - PASSWORD: ");
    for (i = 0; i < longitud; i++)
    {
        printf("%c", asterisco);
    }
    return 0;
}




/*
/// ESTA VA EN EL .C DE MENU
void menuPrincipal()
{

    hideCursor();
    char control;
    menu();
    control= getch();
    menuPrincipal:
    do
    {
        system("cls");
        switch(control)
        {

        case '1':
            busqueda();
            control= getch();
            if(control == TECLA_ENTER)
            {
                menuBusqueda();
                goto menuPrincipal;
            }
            else
            {
                goto menuPrincipal;
            }

        case '2':
            suscripcion();
            control= getch();
            goto menuPrincipal;

        case '3':
            devolucionMenu();
            control= getch();
            goto menuPrincipal;

        case '4':
            bajaDeLibros();
            control= getch();
            goto menuPrincipal;

        default :
            menu();
            control= getch();
        }

    }
    while(control != TECLA_ESCAPE);

    return 0;
}

/// ESTA VA EN EL .C DE MENU
void menuBusqueda()
{
    char bControl;
    system("cls");
    pantallaDeBusqueda();
    bControl= getch();
tagMenuBusqueda:
    do
    {
        system("cls");
        switch(bControl)
        {
        case 't':
            ingresarTitulo();
            bControl=getch();
            goto tagMenuBusqueda;

        case 'g':
            fPorGenero();
            bControl=getch();
            goto tagMenuBusqueda;

        case 'a':
            fPorAutor();
            bControl=getch();
            goto tagMenuBusqueda;

        default:
            pantallaDeBusqueda();
            bControl=getch();
        }

    }
    while(bControl != TECLA_ESCAPE);
    return 0;
}


/// ESTA VA EN EL .C DE MENU
void menu()
{

    printf("\n-1--Busqueda---");
    printf("\n");
    printf("\n-2--Suscripcion---");
    printf("\n");
    printf("\n-3--Devolucion---");
    printf("\n");
    printf("\n-4--Baja de Libro---");
    printf("\n");
}


/// ESTA VA EN EL .C DE MENU
void busqueda()
{
    printf("\n1--O-Busqueda-O-");
    printf("\n");
    printf("\n---Suscripcion---");
    printf("\n");
    printf("\n---Devolucion---");
    printf("\n");
    printf("\n---Baja de Libro---");
    printf("\n");
}


/// ESTA VA EN EL .C DE MENU
void pantallaDeBusqueda()
{
    system("cls");
    printf("\n---Ingresar (T)itulo---");
    printf("\n");
    printf("\n---Filtrar por (G)enero---");
    printf("\n");
    printf("\n---Filtrar por (A)utor---");
    printf("\n");
}

/// ESTA VA EN EL .C DE MENU
void ingresarTitulo()
{

    printf("\n-O-Ingresar (T)itulo-O-");
    printf("\n");
    printf("\n---Filtrar por (G)enero---");
    printf("\n");
    printf("\n---Filtrar por (A)utor---");
    printf("\n");
}

/// ESTA VA EN EL .C DE MENU
void fPorGenero()
{
    printf("\n---Ingresar (T)itulo---");
    printf("\n");
    printf("\n-O-Filtrar por (G)enero-O-");
    printf("\n");
    printf("\n---Filtrar por (A)utor---");
    printf("\n");
}

/// ESTA VA EN EL .C DE MENU
void fPorAutor()
{
    printf("\n---Ingresar (T)itulo---");
    printf("\n");
    printf("\n---Filtrar por (G)enero---");
    printf("\n");
    printf("\n-O-Filtrar por (A)utor-O-");
    printf("\n");
}


/// ESTA VA EN EL .C DE MENU
void suscripcion()
{
    printf("\n---Busqueda---");
    printf("\n");
    printf("\n--O-Suscripcion-O-");
    printf("\n");
    printf("\n---Devolucion---");
    printf("\n");
    printf("\n---BaJa de Libro---");
    printf("\n");
}


/// ESTA VA EN EL .C DE MENU
void devolucionMenu()
{
    printf("\n---(B)usqueda---");
    printf("\n");
    printf("\n---(S)uscripcion---");
    printf("\n");
    printf("\n-O-(D)evolucion-O-");
    printf("\n");
    printf("\n---Ba(J)a de Libro---");
    printf("\n");
}


/// ESTA VA EN EL .C DE MENU
void bajaDeLibros()
{
    printf("\n---(B)usqueda---");
    printf("\n");
    printf("\n---(S)uscripcion---");
    printf("\n");
    printf("\n---(D)evolucion---");
    printf("\n");
    printf("\n-O-Ba(J)a de Libro-O-");
    printf("\n");
}


/// ESTA VA EN EL .C DE MENU
void hideCursor()///oculta el cursor parpadeante
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}


/// ESTA VA EN EL .C DE MENU
void showCursor()///oculta el cursor parpadeante
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 1;
    info.bVisible = TRUE;
    SetConsoleCursorInfo(consoleHandle, &info);
}
*/



