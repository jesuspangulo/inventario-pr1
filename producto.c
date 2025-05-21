#include <stdio.h>
#include "producto.h"

void crearProducto(Producto *p, int id, const char *nombre, int cantidad, float precio) {
    int i = 0;
    while (nombre[i] != '\0' && i < (int)sizeof(p->nombre) - 1) {
        p->nombre[i] = nombre[i];
        i++;
    }
    p->nombre[i] = '\0';
    p->id = id;
    p->cantidad = cantidad;
    p->precio = precio;
}

void mostrarProducto(Producto p) {
    printf("ID: %d | Nombre: %s | Cantidad: %d | Precio: $%.2f\n", p.id, p.nombre, p.cantidad, p.precio);
}

void actualizarProducto(Producto *p, const char *nombre, int cantidad, float precio) {
    int i = 0;
    while (nombre[i] != '\0' && i < (int)sizeof(p->nombre) - 1) {
        p->nombre[i] = nombre[i];
        i++;
    }
    p->nombre[i] = '\0';
    p->cantidad = cantidad;
    p->precio = precio;
}

void eliminarProducto(Producto *p) {
    p->id = -1;
    p->nombre[0] = '\0';
    p->cantidad = 0;
    p->precio = 0.0;
}
