#include <stdio.h>
#include "funciones.h"

int main() {
    int opcion;
    Usuario iniciarsesion;
    while (1) {
        printf("-------------------------------------------------\n");
        printf("Bienvenido a la tienda de productos electrónicos.\n");
        printf("-------------------------------------------------\n");
        /*Validar El usuario y contraseña
        ValidarUsuario(){
        printf("Ingrese su nombre de usuario: ");
        scanf("%s", iniciarsesion.nombre);
        printf("Ingrese su contraseña: ");
        scanf("%s", iniciarsesion.password);
        printf("Ingrese su tipo de usuario (0: Administrador, 1: Bodeguero, 2: Vendedor): ");
        scanf("%d", &iniciarsesion.tipo);*/
        
        printf("1. Iniciar sesión como Administrador\n");
        printf("2. Iniciar sesión como Bodeguero\n");
        printf("3. Iniciar sesión como Vendedor\n");
        printf("4. Salir\n");
        printf("Elija una opción: ");
        scanf("%d", &opcion);
        //opcion = iniciarsesion.tipo;
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









