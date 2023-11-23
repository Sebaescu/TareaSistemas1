#include <stdio.h>
#include <string.h>
#include "funciones.h"

// Datos de ejemplo
Usuario usuarios[MAXU];
Producto productos[MAX];
int cantidadUsuarios = 0;
int cantidadProductos = 0;

/* Función para validar el usuario y contraseña
int validar_usuario(char *usuario, char *contraseña) {

 // Declarar variables
 struct usuario usuario_registrado;

 // Abrir el archivo de usuarios
 FILE *archivo_usuarios = fopen("usuarios.txt", "r");

 // Si el archivo no existe, crearlo en modo de solo lectura
 if (archivo_usuarios == NULL) {
  archivo_usuarios = fopen("usuarios.txt", "r+");
 }

 // Leer el archivo de usuarios
 while (fread(&usuario_registrado, sizeof(struct usuario), 1, archivo_usuarios) == 1) {
 // Comparar el usuario y contraseña ingresados con los registrados
 if (strcmp(usuario_registrado.nombre, usuario) == 0 &&
  strcasecmp(usuario_registrado.contraseña, contraseña) == 0) {
  return usuario_registrado.rol;
  }
}

// Si el usuario no se encuentra registrado, devolver -1
fclose(archivo_usuarios);
return -1;
}*/
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

    // Concatena los datos del usuario en una cadena
    char cadenaUsuario[MAX];
    sprintf(cadenaUsuario, "%s|%s|%d", nuevoUsuario.nombre, nuevoUsuario.password, nuevoUsuario.tipo);

    // Abre el archivo usuarios.txt para escritura
    FILE *archivo = fopen("usuarios.txt", "a");

    // Escribe la cadena del usuario en el archivo
    fprintf(archivo, "%s\n", cadenaUsuario);

    // Cierra el archivo
    fclose(archivo);

    printf("Usuario creado con éxito.\n");
  } else {
    printf("Límite de usuarios alcanzado. No se pueden agregar más usuarios.\n");
  }
}

void ActualizarUsuario() {
  // Read the users from the file
  int usuarioCount = 0;
  FILE *archivo = fopen("usuarios.txt", "r");
  while (!feof(archivo)) {
    Usuario usuarioLeido;
    fscanf(archivo, "%[^|]|%[^|]|%d\n", usuarioLeido.nombre, usuarioLeido.password, &usuarioLeido.tipo);
    usuarios[usuarioCount] = usuarioLeido;
    usuarioCount++;
  }
  fclose(archivo);

  // Prompt for the user to update
  printf("Ingrese el nombre del usuario a actualizar: ");
  char nombreUsuario[50];
  scanf("%s", nombreUsuario);

  // Search for the user in the array
  int usuarioIndex = -1;
  for (int i = 0; i < usuarioCount; i++) {
    if (strcmp(usuarios[i].nombre, nombreUsuario) == 0) {
      usuarioIndex = i;
      break;
    }
  }

  // Update the user if found
  if (usuarioIndex != -1) {
    // Prompt for the attribute to update
    printf("¿Qué desea actualizar?\n");
    printf("1. Nombre\n");
    printf("2. Contraseña\n");
    printf("3. Tipo de usuario\n");
    int opcion;
    scanf("%d", &opcion);

    // Update the user based on the selected attribute
    switch (opcion) {
      case 1:
        printf("Ingrese el nuevo nombre del usuario: ");
        scanf("%s", usuarios[usuarioIndex].nombre);
        break;
      case 2:
        printf("Ingrese la nueva contraseña del usuario: ");
        scanf("%s", usuarios[usuarioIndex].password);
        break;
      case 3:
        printf("Ingrese el nuevo tipo de usuario (0: Administrador, 1: Bodeguero, 2: Vendedor): ");
        scanf("%d", &usuarios[usuarioIndex].tipo);
        break;
    }

    // Rewrite the users file
    archivo = fopen("usuarios.txt", "w");
    for (int i = 0; i < usuarioCount; i++) {
      fprintf(archivo, "%s|%s|%d\n", usuarios[i].nombre, usuarios[i].password, usuarios[i].tipo);
    }
    fclose(archivo);

    printf("Usuario actualizado con éxito.\n");
  } else {
    printf("Usuario no encontrado con el nombre ingresado.\n");
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
    char cadenaProducto[MAX];
    sprintf(cadenaProducto, "%s|%s|%s|%d|%f|%d", nuevoProducto.nombre, nuevoProducto.categoria, nuevoProducto.marca,nuevoProducto.codigo,nuevoProducto.precioCompra,nuevoProducto.cantidadBodega);

    // Abre el archivo productos.txt para escritura
    FILE *archivo = fopen("productos.txt", "a");

    // Escribe la cadena del producto en el archivo
    fprintf(archivo, "%s\n", cadenaProducto);

    // Cierra el archivo
    fclose(archivo);
     printf("Producto creado con éxito.\n");
  } else {
      printf("Límite de productos alcanzado. No se pueden agregar más productos.\n");
  }
}


void ActualizarProducto() {
  int productoCount = 0;
  FILE *archivo = fopen("productos.txt", "r");
  while (!feof(archivo)) {
    Producto productoLeido;
    fscanf(archivo, "%[^|]|%[^|]|%[^|]|%d|%f|%d\n", productoLeido.nombre, productoLeido.categoria, productoLeido.marca, &productoLeido.codigo, &productoLeido.precioCompra, &productoLeido.cantidadBodega);
    productos[productoCount] = productoLeido;
    productoCount++;
  }
  fclose(archivo);

  int codigoProducto;
  printf("-------------------------------------------------\n");
  printf("Ingrese el código del producto que desea actualizar: ");
  int productoIndex = -1;
  for (int i = 0; i < productoCount; i++) {
    if (productos[i].codigo == codigoProducto) {
      productoIndex = i;
      break;
    }
  }
  printf("%d\n",productoIndex);
  int encontrado = 0;
  if (productoIndex != -1) {
      // El producto ha sido encontrado
      printf("-------------------------------------------------\n");
      printf("Producto encontrado:\n");
      printf("Nombre: %s\n", productos[productoIndex].nombre);
      printf("Categoría: %s\n", productos[productoIndex].categoria);
      printf("Marca: %s\n", productos[productoIndex].marca);
      printf("Código: %d\n", productos[productoIndex].codigo);
      printf("Precio de compra: %.2f\n", productos[productoIndex].precioCompra);
      printf("Cantidad en bodega: %d\n", productos[productoIndex].cantidadBodega);
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
          scanf("%s", productos[productoIndex].nombre);
          printf("Producto actualizado con éxito.\n");
          break;
        case 2:
          printf("Ingrese la nueva categoría del producto: ");
          scanf("%s", productos[productoIndex].categoria);
          printf("Producto actualizado con éxito.\n");
          break;
        case 3:
          printf("Ingrese la nueva marca del producto: ");
          scanf("%s", productos[productoIndex].marca);
          printf("Producto actualizado con éxito.\n");
          break;
        case 4:
          printf("Ingrese el nuevo precio de compra del producto: ");
          scanf("%f", &productos[productoIndex].precioCompra);
          printf("Producto actualizado con éxito.\n");
          break;
        case 5:
          printf("Ingrese la nueva cantidad en bodega del producto: ");
          scanf("%d", &productos[productoIndex].cantidadBodega);
          printf("Producto actualizado con éxito.\n");
          break;
        default:
          printf("Opción no válida.\n");
          break;
      }
    // Rewrite the users file
    archivo = fopen("productos.txt", "w");
    for (int i = 0; i < productoCount; i++) {
      fprintf(archivo, "%s|%s|%s|%d|%f|%d\n", productos[i].nombre, productos[i].categoria, productos[i].marca,productos[i].codigo,productos[i].precioCompra,productos[i].cantidadBodega);
    }
    fclose(archivo);
    
  }
  if (productoIndex == -1) {
    printf("Producto no encontrado con el código ingresado.\n");
  }
}
void RegistrarVenta() {
    Venta nuevaVenta;
    int productoCount = 0;
    FILE *archivo = fopen("productos.txt", "r");
    while (!feof(archivo)) {
      Producto productoLeido;
      fscanf(archivo, "%[^|]|%[^|]|%[^|]|%d|%f|%d\n", productoLeido.nombre, productoLeido.categoria, productoLeido.marca, &productoLeido.codigo, &productoLeido.precioCompra, &productoLeido.cantidadBodega);
      productos[productoCount] = productoLeido;
      productoCount++;
    }
    fclose(archivo);
    int codigoProducto;
    printf("-------------------------------------------------\n");
    printf("Código del producto vendido: ");
    scanf("%d", &codigoProducto);
    int productoIndex = -1;
    for (int i = 0; i < productoCount; i++) {
      if (productos[i].codigo == codigoProducto) {
        productoIndex = i;
        break;
      }
    }
    if (productoIndex != -1){
            // Solicita detalles de la venta
      printf("-------------------------------------------------\n");
      printf("Producto Encontrado: \n");
      scanf("Nombre: %s", productos[productoIndex].nombre);
      printf("-------------------------------------------------\n");
      printf("Detalles de la venta: \n");
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
    productos[productoIndex].cantidadBodega -= nuevaVenta.cantidadVendida;
    char cadenaVenta[MAX];
    sprintf(cadenaVenta, "%d|%s|%s|%s|%f|%d",productos[productoIndex].codigo,nuevaVenta.local, nuevaVenta.vendedor, nuevaVenta.fechaVenta,nuevaVenta.precioVenta,nuevaVenta.cantidadVendida);

            // Abre el archivo productos.txt para escritura
      FILE *archivo = fopen("ventas.txt", "a");

            // Escribe la cadena del producto en el archivo
      fprintf(archivo, "%s\n", cadenaVenta);

            // Cierra el archivo
      fclose(archivo);
      archivo = fopen("productos.txt", "w");
      for (int i = 0; i < productoCount; i++) {
        fprintf(archivo, "%s|%s|%s|%d|%f|%d\n", productos[i].nombre, productos[i].categoria, productos[i].marca,productos[i].codigo,productos[i].precioCompra,productos[i].cantidadBodega);
      }
      fclose(archivo);
      printf("Venta registrada con éxito.\n");
    }
    if (productoIndex == -1) {
        printf("Producto no encontrado con el código ingresado. No se puede registrar la venta.\n");
    }
  }