#include <stdio.h>
#include <string.h>
#include "funciones.h"

// Datos de ejemplo
Usuario usuarios[10];
Producto productos[50];
int cantidadUsuarios = 0;
int cantidadProductos = 0;


void IniciarSesion(TipoUsuario tipoUsuario) {
  // Si el usuario es administrador, le da la opción de crear o actualizar un usuario
  if (tipoUsuario == ADMINISTRADOR) {
    int opcion;
    printf("Inició sesión como Administrador.\n");
    while(opcion !=3){
      printf("-------------------------------------------------\n");
      printf("¿Qué desea realizar?\n");
      printf("1. Crear usuario\n");
      printf("2. Actualizar usuario\n");
      printf("3. Salir\n");
      scanf("%d", &opcion);
      switch (opcion) {
        case 1:
          CrearUsuario();
          break;
        case 2:
          ActualizarUsuario();
          break;
        case 3:
        printf("Saliendo del sistema...\n");
        break;
        default:
          printf("Opción no válida.\n");
          break;
      }
    }
  } else if (tipoUsuario == BODEGUERO) {
    int opcion;
    printf("Inició sesión como Bodeguero.\n");
    while(opcion !=3){
      printf("-------------------------------------------------\n");
      printf("¿Qué desea realizar?\n");
      printf("1. Crear producto\n");
      printf("2. Actualizar producto\n");
      printf("3. Salir\n");
      
      scanf("%d", &opcion);
      switch (opcion) {
        case 1:
          CrearProducto();
          break;
        case 2:
          ActualizarProducto();
          break;
        case 3:
        printf("Saliendo del sistema...\n");
        break;
        default:
          printf("Opción no válida.\n");
          break;
      }
    }
  } else if (tipoUsuario == VENDEDOR){
    int opcion;
    printf("Inició sesión como Vendedor.\n");
    while(opcion !=2){
      printf("-------------------------------------------------\n");
      printf("¿Qué desea realizar?\n");
      printf("1. Registrar venta\n");
      printf("2. Salir\n");
      
      scanf("%d", &opcion);
      switch (opcion) {
        case 1:
          RegistrarVenta();
          break;
        case 2:
          printf("Saliendo del sistema...\n");
          break;
        default:
          printf("Opción no válida.\n");
          break;
      }
    }
  }
}
void CrearUsuario() {
  if (cantidadUsuarios < 10) {
    Usuario nuevoUsuario;
    printf("-------------------------------------------------\n");
    printf("Ingrese el nombre del nuevo usuario: ");
    scanf("%s", nuevoUsuario.nombre);
    printf("Ingrese la contraseña del nuevo usuario: ");
    scanf("%s", nuevoUsuario.password);
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
}

void ActualizarUsuario() {
    char nombreUsuario[50];
    printf("-------------------------------------------------\n");
    printf("Ingrese el nombre del usuario que desea actualizar: ");
    scanf("%s", nombreUsuario);

    int encontrado = 0;
    for (int i = 0; i < cantidadUsuarios; i++) {
      if (strcmp(usuarios[i].nombre, nombreUsuario) == 0) {
                // El usuario ha sido encontrado
        printf("Usuario encontrado:\n");
        printf("Nombre: %s\n", usuarios[i].nombre);
        printf("Contraseña: %s\n",usuarios[i].password);
        printf("Tipo de usuario (0: Administrador, 1: Bodeguero, 2: Vendedor): %d\n", usuarios[i].tipo);
        printf("-------------------------------------------------\n");
        printf("¿Qué desea actualizar?\n");
        printf("1. Nombre\n");
        printf("2. Contraseña\n");
        printf("3. Tipo de usuario\n");
        int opcion;
        scanf("%d", &opcion);
        switch (opcion) {
          case 1:
            printf("Ingrese el nuevo nombre del usuario: ");
            scanf("%s", usuarios[i].nombre);
            printf("Usuario actualizado con éxito.\n");
            break;
          case 2:
            printf("Ingrese la nueva contraseña del usuario: ");
            scanf("%s", usuarios[i].password);
            printf("Usuario actualizado con éxito.\n");
            break;
          case 3:
            printf("Ingrese el nuevo tipo de usuario (0: Administrador, 1: Bodeguero, 2: Vendedor): ");
            int nuevoTipoUsuario;
            scanf("%d", &nuevoTipoUsuario);
    
            if (nuevoTipoUsuario < 0 || nuevoTipoUsuario > 2) {
                printf("Tipo de usuario no válido. No se actualizará.\n");
            } else {
                usuarios[i].tipo = (TipoUsuario)nuevoTipoUsuario;
                printf("Usuario actualizado con éxito.\n");
            }
            break;
        encontrado = 1;
        break;
      }
    }
    if (!encontrado) {
        printf("Usuario no encontrado con el nombre ingresado.\n");
    }
  } 
}


void CrearProducto() {
  if (cantidadProductos < 50) {
    Producto nuevoProducto;
    printf("-------------------------------------------------\n");
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
}


void ActualizarProducto() {
  int codigoProducto;
  printf("-------------------------------------------------\n");
  printf("Ingrese el código del producto que desea actualizar: ");
  scanf("%d", &codigoProducto);
  int encontrado = 0;
  for (int i = 0; i < cantidadProductos; i++) {
    if (productos[i].codigo == codigoProducto) {
      // El producto ha sido encontrado
      printf("-------------------------------------------------\n");
      printf("Producto encontrado:\n");
      printf("Nombre: %s\n", productos[i].nombre);
      printf("Categoría: %s\n", productos[i].categoria);
      printf("Marca: %s\n", productos[i].marca);
      printf("Código: %d\n", productos[i].codigo);
      printf("Precio de compra: %.2f\n", productos[i].precioCompra);
      printf("Cantidad en bodega: %d\n", productos[i].cantidadBodega);
      printf("-------------------------------------------------\n");
      printf("¿Qué desea actualizar?\n");
      printf("1. Nombre\n");
      printf("2. Categoría\n");
      printf("3. Marca\n");
      printf("4. Precio de compra\n");
      printf("5. Cantidad en bodega\n");
      int opcion;
      scanf("%d", &opcion);
      switch (opcion) {
        case 1:
          printf("Ingrese el nuevo nombre del producto: ");
          scanf("%s", productos[i].nombre);
          printf("Producto actualizado con éxito.\n");
          break;
        case 2:
          printf("Ingrese la nueva categoría del producto: ");
          scanf("%s", productos[i].categoria);
          printf("Producto actualizado con éxito.\n");
          break;
        case 3:
          printf("Ingrese la nueva marca del producto: ");
          scanf("%s", productos[i].marca);
          printf("Producto actualizado con éxito.\n");
          break;
        case 4:
          printf("Ingrese el nuevo precio de compra del producto: ");
          scanf("%f", &productos[i].precioCompra);
          printf("Producto actualizado con éxito.\n");
          break;
        case 5:
          printf("Ingrese la nueva cantidad en bodega del producto: ");
          scanf("%d", &productos[i].cantidadBodega);
          printf("Producto actualizado con éxito.\n");
          break;
        default:
          printf("Opción no válida.\n");
          break;
      }
      encontrado = 1;
      break;
    }
  }
  if (!encontrado) {
    printf("Producto no encontrado con el código ingresado.\n");
  }
}

void RegistrarVenta() {
    Venta nuevaVenta;
    printf("-------------------------------------------------\n");
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

