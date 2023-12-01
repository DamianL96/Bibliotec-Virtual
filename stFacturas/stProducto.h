#ifndef STPRODUCTO_H_INCLUDED
#define STPRODUCTO_H_INCLUDED


typedef struct{
    int precio;
    char titulo[30];
    int alquila;/// =1 si se alquilo -  =0 si se compro
}stProducto;

stProducto cargarProducto();
stProducto ingresarProducto();
void imprimirProducto(stProducto libro);
int libroAlquilado(stProducto libro);
#endif // STPRODUCTO_H_INCLUDED
