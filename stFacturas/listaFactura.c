#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "listaFactura.h"
#include "stFactura.h"

nodoFactura* inicLista(){
    return NULL;
}

nodoFactura* crearNodo(stFactura dato){
    nodoFactura *nuevo = (nodoFactura*) malloc(sizeof(nodoFactura));
    nuevo->factura = dato;
    nuevo->sig=NULL;
    return nuevo;
}

nodoFactura* cargarLista(nodoFactura *lista){
    char c ='s';
    nodoFactura *nuevo;
    stFactura factura;


    while(c == 's'){
        printf("\nIngresar Factura-\n");
        factura=ingresarFactura();

        nuevo=crearNodo(factura);///los datos ingresados pasan al nuevo nodo
        lista=agregarAlPrincipio(nuevo,lista);///el nuevo nodo se agrega al principio
        controlListaFactura(&c);
    }
    return lista;
}

void controlListaFactura(char *c){
    printf("\n\t INGRESAR OTRA FACTURA? si = s: ");
    fflush(stdin);
    scanf("%c",c);
}

nodoFactura* agregarAlPrincipio(nodoFactura *nuevo,nodoFactura *lista){

    if(lista == NULL){
        lista =nuevo;
    }
    else{
        nuevo->sig =lista;
        lista =nuevo;
    }
    return lista;
}


nodoFactura* agregarAlFinal(nodoFactura *nuevo,nodoFactura *lista){

    if(lista != NULL){
        nodoFactura *ultimo= buscarUltimo(lista);
        ultimo->sig= nuevo;///el ultimo elemento apunta al nuevo elemento
    }
    else{
        lista=nuevo;
    }
    return lista;
}


nodoFactura* buscarUltimo(nodoFactura *lista){
    nodoFactura *ultimo= lista;

    if(lista != NULL){///si la lista tiene al menos un elemento
        while(ultimo->sig != NULL){///si la lista tiene mas de un elemento
            ultimo= ultimo->sig;///avanza hasta el ultimo elemento
        }
    }
    return ultimo;
}

void mostrarFacturasDelMes(nodoFactura* listaFactura,char mes[]){
    char inicioMes[21];
    char finMes[21];
    nodoFactura*copia=listaFactura;
    ingresarMes(mes,&inicioMes,&finMes);

    int rta=0;
    while(copia != NULL){
        if( (strcmp(inicioMes,copia->factura.fecha) <=0 ) && ( strcmp(copia->factura.fecha,finMes) <= 0)  ){
            imprimirFactura(copia->factura);
            rta= rta+ copia->factura.total;
        }
        copia= copia->sig;
    }
    printf("\n\n  TOTAL MENSUAL: $ %d \n",rta);
    }

void mostrarFacturasDelDia(nodoFactura*listaFactura,char dia[]){
    char inicioDia[21];
    char finDia[21];
    nodoFactura*copia=listaFactura;
    ingresarDia(dia,&inicioDia,&finDia);
    int rta=0;
    while(copia != NULL){
        if(   ( strcmp(inicioDia,copia->factura.fecha) <= 0 ) && (strcmp(copia->factura.fecha,finDia)<=0)  ){
            imprimirFactura(copia->factura);
            rta= rta+ copia->factura.total;
        }
        copia= copia->sig;
    }
    printf("\n\n  TOTAL DEL DIA: $ %d \n",rta);
}


void ingresarDia(char diaBuscado[],char *inicioDia[],char *finDia[]){
    char primerHora[21]={"/2022 00:00:00"};
    char ultimaHora[21]={"/2022 23:59:59"};
    strcpy(inicioDia,diaBuscado);
    strcpy(finDia,diaBuscado);

    strcat(inicioDia,primerHora);
    strcat(finDia,ultimaHora);
}

void ingresarMes(char mesBuscado[],char *inicioMes[],char *finMes[]){
    char primerDia[21]={"01/"};
    char ultimoDia[21]={"31/"};

    char primerHora[21]={"/2022 00:00:00"};
    char ultimaHora[21]={"/2022 23:59:59"};

    strcat(primerDia,mesBuscado);
    strcat(ultimoDia,mesBuscado);

    strcat(primerDia,primerHora);
    strcat(ultimoDia,ultimaHora);

    strcpy(inicioMes,primerDia);
    strcpy(finMes,ultimoDia);
}


/*
void mostrarFacturasDelDia(nodoFactura *listaFactura,char limite[]){



    nodoFactura *copia= listaFactura;
    while( copia != NULL  ){

        if(){
            imprimirFactura(copia->factura);
        }

        copia= copia->sig;
    }
}*/



int compararFecha(nodoFactura *listaFactura,char fecha[]){
    int flag= 0;
    char *rta;

    rta= strstr(listaFactura->factura.fecha, fecha);

    if(rta != NULL){
        flag = 1;
    }
    return flag;
}

///char limiteInferior[10]= "17:28";
///char limiteSuperior[10]= "17:35";

int semaforoInferior(nodoFactura* listaFactura,char limiteInferior[],int semaforo){
    char *rtaInf;
    rtaInf= strstr(listaFactura->factura.fecha,limiteInferior);
    if(rtaInf != NULL){
        semaforo =0;
    }
    return semaforo;
}

int semaforoSuperior(nodoFactura* listaFactura,char limiteSuperior[],int semaforo){
    char *rtaSup;
    rtaSup= strstr(listaFactura->factura.fecha,limiteSuperior);
    if(rtaSup != NULL){
        semaforo =1;
    }
    return semaforo;
}
/// Se debe pedir que se ingrese un numero inferior al que se debe
void mostrarEntreFechas(nodoFactura*listaFactura,char limiteInferior[],char limiteSuperior[]){
    int semaforo=0;
    nodoFactura *copia= listaFactura;
    while(copia != NULL){
        semaforo= semaforoSuperior(copia,limiteSuperior,semaforo);
        if(semaforo == 1){
            imprimirFactura(copia->factura);
        }
        semaforo= semaforoInferior(copia,limiteInferior,semaforo);
        copia= copia->sig;
    }
}

float sumarFacturas(nodoFactura*listaFactura,char limiteInferior[],char limiteSuperior[]){
    int rta=0;
    int semaforo=0;
    nodoFactura *copia= listaFactura;
    while(copia != NULL){
        semaforo= semaforoSuperior(copia,limiteSuperior,semaforo);
        if(semaforo == 1){
           rta= rta + copia->factura.total;
        }
        semaforo= semaforoInferior(copia,limiteInferior,semaforo);
        copia= copia->sig;
    }
    return rta;
}


/*
nodoFactura* buscarXNombre(nodoFactura *lista,char fecha[]){
    nodoFactura *copia= lista;

    while(copia != NULL && strcmp(copia->factura.fecha,nombreBuscado)>=0){///mientras haya elementos y el nombre no coincida recorre la lista
        copia= copia->sig;
    }
    return copia;///devuelve el nodo si lo encuentra, o NULL si no lo encuentra
}*/



/*
nodoFactura *borrarNodo(int edad,nodoFactura *lista){

    if(lista != NULL){
        if(edad == lista->edad){///si el nodo a borrar se encuentra en la primera posicion
            nodoFactura *borrar= lista;/// el nodo a borrar toma el valor de la lista
            lista= lista->sig;///la lista toma el valor del siguiente nodo
            free(borrar);///se elimina el nodo de la memoria
        }
        else{
            nodoFactura *anterior= lista;
            nodoFactura *siguiente= lista->sig;
            while((siguiente != NULL) && (edad != siguiente->edad)){
                anterior =siguiente;///avanzan ambos controladores
                siguiente =siguiente->sig;
            }
            if(siguiente != NULL){
                anterior->sig = siguiente->sig;
                free(siguiente);
            }
        }
    }
    return lista;
}*/

nodoFactura *borrarListaCompleta(nodoFactura *lista){
    nodoFactura *borrar;

    while(lista != NULL){
        borrar =lista;
        lista =lista->sig;
        free(borrar);
    }
    return lista;
}

void mostrarListaFacturas(nodoFactura *lista){
    nodoFactura *a=lista;

    while(a != NULL){
        imprimirFactura(a->factura);
        a= a->sig;
    }
}
/*
void imprimirNodo(nodoFactura *a){
    printf("\nNombre: %s",a->nombre);
    printf("\nEdad %d",a->edad);
}*/



