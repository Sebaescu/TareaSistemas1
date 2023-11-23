#ifndef FUNCIONES_H
#define FUNCIONES_H
#define MAX 50
#define MAXS 20
#define MAXU 10
// Enumeración para los tipos de usuarios
typedef enum {
    ADMINISTRADOR,
    BODEGUERO,
    VENDEDOR
} TipoUsuario;

// Estructura para los productos
typedef struct {
    char nombre[MAXS];
    char categoria[MAXS];
    char marca[MAXS];
    int codigo;
    float precioCompra;
    int cantidadBodega;
} Producto;

// Estructura para los usuarios
typedef struct {
    char nombre[MAXS];
    char password[MAXS];
    TipoUsuario tipo;
} Usuario;
// Estructura para las ventas
typedef struct {
    char local[MAXS];
    char vendedor[MAXS];
    char fechaVenta[MAXS];
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



