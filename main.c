#include <stdio.h>
#include "funciones.h"

int main() {
    int opcion;

    while (1) {
        printf("-------------------------------------------------\n");
        printf("Bienvenido a la tienda de productos electrónicos.\n");
        printf("-------------------------------------------------\n");
        printf("1. Iniciar sesión como Administrador\n");
        printf("2. Iniciar sesión como Bodeguero\n");
        printf("3. Iniciar sesión como Vendedor\n");
        printf("4. Salir\n");
        printf("Elija una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // Iniciar sesión como Administrador
                IniciarSesion(ADMINISTRADOR);
                break;
            case 2:
                // Iniciar sesión como Bodeguero
                IniciarSesion(BODEGUERO);
                break;
            case 3:
                // Iniciar sesión como Vendedor
                IniciarSesion(VENDEDOR);
                break;
            case 4:
                // Salir del programa
                printf("Gracias por usar el sistema. Hasta luego.\n");
                return 0;
            default:
                printf("Opción no válida. Por favor, elija una opción válida.\n");
        }
    }

    return 0;
}





