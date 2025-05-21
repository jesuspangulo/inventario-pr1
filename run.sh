#!/bin/bash

# Compilar todos los archivos fuente
gcc producto.c -c
gcc inventario.c -c
gcc producto.o inventario.o main.c -o main

# Ejecutar el programa
./main $*
