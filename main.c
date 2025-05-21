#include <stdio.h>
#include "inventario.h"

int main(int argc, char *argv[]) {
    char *modo = "";
    if (argc > 1) {        
        modo = argv[1];
    }

    if (!modoValido(modo)) {
        printf("Modo invalido. Use 'lectura' o 'escritura'.\n");
        return 1;
    }
    
    Producto inventario[MAX_PRODUCTOS];
    int total = 0;
    int opcion;
    total = cargarProductosDesdeArchivo("productos.txt", inventario, MAX_PRODUCTOS);
    do {
        printf("\n--- MENU INVENTARIO ---\n");
        printf("1. Ver inventario total\n");
        if (modoEscritura(modo)) {
            printf("2. Crear producto\n");
        }
        printf("3. Mostrar producto\n");
        if (modoEscritura(modo)) {
            printf("4. Actualizar producto\n");
            printf("5. Eliminar producto\n");
        }
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar buffer
        if (opcion < 1 || opcion > 6) {
            printf("Opcion invalida. Debe ser un numero entre 1 y 6.\n");
            continue;
        }
        int id, cantidad, idx;
        char nombre[50];
        float precio;
        switch(opcion) {
            case 1:
                mostrarInventario(inventario, total);
                break;
            case 2:
                if (!modoEscritura(modo)) {
                    printf("Opcion no disponible en modo lectura.\n");
                    break;
                }
                if (total < MAX_PRODUCTOS) {
                    printf("ID: "); scanf("%d", &id); getchar();
                    printf("Nombre: "); scanf("%49s", nombre);
                    printf("Cantidad: "); scanf("%d", &cantidad); getchar();
                    printf("Precio: "); scanf("%f", &precio); getchar();
                    crearProducto(&inventario[total], id, nombre, cantidad, precio);
                    total++;
                    guardarProductosEnArchivo("productos.txt", inventario, total);
                    printf("Producto creado.\n");
                } else {
                    printf("Inventario lleno.\n");
                }
                break;
            case 3:
                printf("ID del producto a mostrar: "); scanf("%d", &id); getchar();
                idx = buscarProductoPorId(inventario, total, id);
                if (idx != -1) mostrarProducto(inventario[idx]);
                else printf("Producto no encontrado.\n");
                break;
            case 4:
                if (!modoEscritura(modo)) {
                    printf("Opcion no disponible en modo lectura.\n");
                    break;
                }
                printf("ID del producto a actualizar: "); scanf("%d", &id); getchar();
                idx = buscarProductoPorId(inventario, total, id);
                if (idx != -1) {
                    printf("Nuevo nombre: "); scanf("%49s", nombre);
                    printf("Nueva cantidad: "); scanf("%d", &cantidad); getchar();
                    printf("Nuevo precio: "); scanf("%f", &precio); getchar();
                    actualizarProducto(&inventario[idx], nombre, cantidad, precio);
                    guardarProductosEnArchivo("productos.txt", inventario, total);
                    printf("Producto actualizado.\n");
                } else printf("Producto no encontrado.\n");
                break;
            case 5:
                if (!modoEscritura(modo)) {
                    printf("Opcion no disponible en modo lectura.\n");
                    break;
                }
                printf("ID del producto a eliminar: "); scanf("%d", &id); getchar();
                idx = buscarProductoPorId(inventario, total, id);
                if (idx != -1) {
                    eliminarProducto(&inventario[idx]);
                    inventario[idx] = inventario[total-1];
                    total--;
                    guardarProductosEnArchivo("productos.txt", inventario, total);
                    printf("Producto eliminado.\n");
                } else printf("Producto no encontrado.\n");
                break;
            case 6:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while(opcion != 6);
    return 0;
}



