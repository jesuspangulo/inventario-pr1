#include <stdio.h>
#include "inventario.h"

// Función para validar el modo
int modoValido(const char *modo) {
    int i = 0;
    // Comparar con "lectura"
    const char *lectura = "lectura";
    while (modo[i] && lectura[i] && modo[i] == lectura[i]) i++;
    if (modo[i] == '\0' && lectura[i] == '\0') return 1;
    // Comparar con "escritura"
    i = 0;
    const char *escritura = "escritura";
    while (modo[i] && escritura[i] && modo[i] == escritura[i]) i++;
    if (modo[i] == '\0' && escritura[i] == '\0') return 1;
    return 0;
}

// Función para saber si el modo es escritura
int modoEscritura(const char *modo) {
    int i = 0;
    const char *escritura = "escritura";
    while (modo[i] && escritura[i] && modo[i] == escritura[i]) i++;
    return (modo[i] == '\0' && escritura[i] == '\0');
}

void mostrarInventario(Producto inventario[], int total) {
    printf("\n--- INVENTARIO TOTAL ---\n");
    for (int i = 0; i < total; i++) {
        mostrarProducto(inventario[i]);
    }
    if (total == 0) printf("Inventario vacio.\n");
}

int buscarProductoPorId(Producto inventario[], int total, int id) {
    for (int i = 0; i < total; i++) {
        if (inventario[i].id == id) return i;
    }
    return -1;
}

int cargarProductosDesdeArchivo(const char *filename, Producto inventario[], int max_productos) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("No se pudo abrir el archivo %s\n", filename);
        return 0;
    }
    int count = 0;
    while (count < max_productos && fscanf(file, "%d,%49[^,],%d,%f\n", &inventario[count].id, inventario[count].nombre, &inventario[count].cantidad, &inventario[count].precio) == 4) {
        count++;
    }
    fclose(file);
    return count;
}

void guardarProductosEnArchivo(const char *filename, Producto inventario[], int total) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("No se pudo abrir el archivo %s para guardar\n", filename);
        return;
    }
    for (int i = 0; i < total; i++) {
        fprintf(file, "%d,%s,%d,%.2f\n", inventario[i].id, inventario[i].nombre, inventario[i].cantidad, inventario[i].precio);
    }
    fclose(file);
}
