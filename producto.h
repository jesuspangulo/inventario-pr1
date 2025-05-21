#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <stdio.h>

// Estructura para representar un producto en el inventario
typedef struct {
    int id;
    char nombre[50];
    int cantidad;
    float precio;
} Producto;

// Prototipos de funciones
void crearProducto(Producto *p, int id, const char *nombre, int cantidad, float precio);
void mostrarProducto(Producto p);
void actualizarProducto(Producto *p, const char *nombre, int cantidad, float precio);
void eliminarProducto(Producto *p);

#endif // PRODUCTO_H
