#ifndef FUNCIONES_H
#define FUNCIONES_H

// Enumeración para los tipos de usuarios
typedef enum {
    ADMINISTRADOR,
    BODEGUERO,
    VENDEDOR
} TipoUsuario;

// Estructura para los productos
typedef struct {
    char nombre[50];
    char categoria[50];
    char marca[50];
    int codigo;
    float precioCompra;
    int cantidadBodega;
} Producto;

// Estructura para los usuarios
typedef struct {
    char nombre[50];
    char password[50];
    TipoUsuario tipo;
} Usuario;
// Estructura para las ventas
typedef struct {
    char local[50];
    char vendedor[50];
    char fechaVenta[20];
    float precioVenta;
    int codigoProducto;
    int cantidadVendida;
} Venta;
// Funciones
void IniciarSesion(TipoUsuario tipoUsuario);
void CrearUsuario();
void ActualizarUsuario();
void CrearProducto();
void ActualizarProducto();
void RegistrarVenta();

#endif


