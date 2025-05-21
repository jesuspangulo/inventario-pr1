#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "producto.h"

#define MAX_PRODUCTOS 100

// Prototipos de funciones de inventario
int modoValido(const char *modo);
int modoEscritura(const char *modo);
void mostrarInventario(Producto inventario[], int total);
int buscarProductoPorId(Producto inventario[], int total, int id);
int cargarProductosDesdeArchivo(const char *filename, Producto inventario[], int max_productos);
void guardarProductosEnArchivo(const char *filename, Producto inventario[], int total);

#endif
