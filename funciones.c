#include <stdio.h>
#include "funciones.h"

// Datos de ejemplo
Usuario usuarios[10];
Producto productos[50];
int cantidadUsuarios = 0;
int cantidadProductos = 0;


void IniciarSesion(TipoUsuario tipoUsuario) {
    if (tipoUsuario == ADMINISTRADOR) {
        printf("Inició sesión como Administrador.\n");
        printf("-------------------------------------------------\n");
        CrearUsuario(); // Llama a la función para crear usuario
        printf("-------------------------------------------------\n");
        ActualizarUsuario(); // Llama a la función para actualizar usuario
    } else if (tipoUsuario == BODEGUERO) {
        printf("Inició sesión como Bodeguero.\n");
        printf("-------------------------------------------------\n");
        CrearProducto(); // Llama a la función para crear producto
        printf("-------------------------------------------------\n");
        ActualizarProducto(); // Llama a la función para actualizar producto
    } else if (tipoUsuario == VENDEDOR) {
        printf("Inició sesión como Vendedor.\n");
        printf("-------------------------------------------------\n");
        RegistrarVenta(); // Llama a la función para registrar venta
    }
}

void CrearUsuario() {
    int deseaCrearUsuario;
    printf("¿Desea crear un nuevo usuario? (1: Sí / 0: No): ");
    scanf("%d", &deseaCrearUsuario);

    if (deseaCrearUsuario) {
        if (cantidadUsuarios < 10) {
            Usuario nuevoUsuario;
            printf("Ingrese el nombre del nuevo usuario: ");
            scanf("%s", nuevoUsuario.nombre);
            printf("Tipo de usuario (0: Administrador, 1: Bodeguero, 2: Vendedor): ");
            int tipoUsuario;
            scanf("%d", &tipoUsuario);

            if (tipoUsuario < 0 || tipoUsuario > 2) {
                printf("Tipo de usuario no válido. Se asignará como Vendedor por defecto.\n");
                nuevoUsuario.tipo = VENDEDOR;
            } else {
                nuevoUsuario.tipo = (TipoUsuario)tipoUsuario;
            }

            usuarios[cantidadUsuarios++] = nuevoUsuario;
            printf("Usuario creado con éxito.\n");
        } else {
            printf("Límite de usuarios alcanzado. No se pueden agregar más usuarios.\n");
        }
    } else {
        printf("No se crearán nuevos usuarios.\n");
    }
}



void ActualizarUsuario() {
    int deseaActualizarUsuario;
    printf("¿Desea actualizar un usuario existente? (1: Sí / 0: No): ");
    scanf("%d", &deseaActualizarUsuario);

    if (deseaActualizarUsuario) {
        char nombreUsuario[50];
        printf("Ingrese el nombre del usuario que desea actualizar: ");
        scanf("%s", nombreUsuario);

        int encontrado = 0;
        for (int i = 0; i < cantidadUsuarios; i++) {
            if (strcmp(usuarios[i].nombre, nombreUsuario) == 0) {
                // El usuario ha sido encontrado
                printf("Usuario encontrado:\n");
                printf("Nombre: %s\n", usuarios[i].nombre);
                printf("Tipo de usuario (0: Administrador, 1: Bodeguero, 2: Vendedor): %d\n", usuarios[i].tipo);

                // Solicita al usuario que ingrese el nuevo tipo de usuario
                printf("Ingrese el nuevo tipo de usuario (0: Administrador, 1: Bodeguero, 2: Vendedor): ");
                int nuevoTipoUsuario;
                scanf("%d", &nuevoTipoUsuario);

                if (nuevoTipoUsuario < 0 || nuevoTipoUsuario > 2) {
                    printf("Tipo de usuario no válido. No se actualizará.\n");
                } else {
                    usuarios[i].tipo = (TipoUsuario)nuevoTipoUsuario;
                    printf("Usuario actualizado con éxito.\n");
                }

                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            printf("Usuario no encontrado con el nombre ingresado.\n");
        }
    } else {
        printf("No se actualizarán usuarios.\n");
    }
}


void CrearProducto() {
    int deseaCrearProducto;
    printf("¿Desea crear un nuevo producto? (1: Sí / 0: No): ");
    scanf("%d", &deseaCrearProducto);

    if (deseaCrearProducto) {
        if (cantidadProductos < 50) {
            Producto nuevoProducto;
            printf("Nombre del producto: ");
            scanf("%s", nuevoProducto.nombre);
            printf("Categoría: ");
            scanf("%s", nuevoProducto.categoria);
            printf("Marca: ");
            scanf("%s", nuevoProducto.marca);
            printf("Código: ");
            scanf("%d", &nuevoProducto.codigo);
            printf("Precio de compra: ");
            scanf("%f", &nuevoProducto.precioCompra);
            printf("Cantidad en bodega: ");
            scanf("%d", &nuevoProducto.cantidadBodega);

            productos[cantidadProductos++] = nuevoProducto;
            printf("Producto creado con éxito.\n");
        } else {
            printf("Límite de productos alcanzado. No se pueden agregar más productos.\n");
        }
    } else {
        printf("No se crearán nuevos productos.\n");
    }
}


void ActualizarProducto() {
int codigoProducto;
printf("¿Desea actualizar un producto? (1: Sí / 0: No): ");
int deseaActualizar;
scanf("%d", &deseaActualizar);

if (deseaActualizar) {
    printf("Ingrese el código del producto que desea actualizar: ");
    scanf("%d", &codigoProducto);

    int encontrado = 0;
    for (int i = 0; i < cantidadProductos; i++) {
        if (productos[i].codigo == codigoProducto) {
            // El producto ha sido encontrado
            printf("Producto encontrado:\n");
            printf("Nombre: %s\n", productos[i].nombre);
            printf("Categoría: %s\n", productos[i].categoria);
            printf("Marca: %s\n", productos[i].marca);
            printf("Código: %d\n", productos[i].codigo);
            printf("Precio de compra: %.2f\n", productos[i].precioCompra);
            printf("Cantidad en bodega: %d\n", productos[i].cantidadBodega);

            // Solicita al usuario que ingrese los nuevos valores
            printf("Ingrese los nuevos valores:\n");
            printf("Nombre del producto: ");
            scanf("%s", productos[i].nombre);
            printf("Categoría: ");
            scanf("%s", productos[i].categoria);
            printf("Marca: ");
            scanf("%s", productos[i].marca);
            printf("Precio de compra: ");
            scanf("%f", &productos[i].precioCompra);
            printf("Cantidad en bodega: ");
            scanf("%d", &productos[i].cantidadBodega);

            printf("Producto actualizado con éxito.\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado con el código ingresado.\n");
    }
} else {
    printf("No se actualizarán productos.\n");
}
}


void RegistrarVenta() {
    Venta nuevaVenta;
    printf("Código del producto vendido: ");
    scanf("%d", &nuevaVenta.codigoProducto);

    int encontrado = 0;
    for (int i = 0; i < cantidadProductos; i++) {
        if (productos[i].codigo == nuevaVenta.codigoProducto) {
            // Producto encontrado
            encontrado = 1;

            // Solicita detalles de la venta
            printf("Local de la venta: ");
            scanf("%s", nuevaVenta.local);
            printf("Vendedor: ");
            scanf("%s", nuevaVenta.vendedor);
            printf("Fecha de la venta: ");
            scanf("%s", nuevaVenta.fechaVenta);
            printf("Precio de la venta: ");
            scanf("%f", &nuevaVenta.precioVenta);
            printf("Cantidad vendida: ");
            scanf("%d", &nuevaVenta.cantidadVendida);

            // Actualiza la cantidad en bodega del producto
            productos[i].cantidadBodega -= nuevaVenta.cantidadVendida;

            printf("Venta registrada con éxito.\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado con el código ingresado. No se puede registrar la venta.\n");
    }
}


