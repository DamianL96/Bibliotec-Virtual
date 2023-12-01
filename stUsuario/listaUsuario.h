#ifndef LISTASIMPLE_USUARIO_H_INCLUDED
#define LISTASIMPLE_USUARIO_H_INCLUDED


typedef struct
{
    char contrasenia[10];
    int usuario;
    char nombreyapellido[20];
}Usuario;

typedef struct
{
    Usuario usuario;
    struct _nodo * siguiente;
} nodoUsuario;



                                    /// PROTOTIPADO funciones lista
nodoUsuario * inicListaMenuGeneral();
nodoUsuario * cargarNodoUsuarioMenuGeneral(int dni);
nodoUsuario * crearNodoUsuarioMenuGeneral(Usuario Nuevousuario);
nodoUsuario * crearUsuario(nodoUsuario * lista);
nodoUsuario * ArchivoToListadeUsuario(nodoUsuario * lista, char arch[]);
nodoUsuario * cargarListadeUsuariosDesdeCero(nodoUsuario * lista);
void RegistrarUsuario(char nombreArchivo [30], nodoUsuario * lista);
int buscarNodoUsuarioMenuGeneral(nodoUsuario * lista, char dni[]);


#endif // LISTASIMPLE_USUARIO_H_INCLUDED
