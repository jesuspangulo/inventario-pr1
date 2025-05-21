# Proyecto Inventario en C

Este proyecto es un sistema de inventario sencillo para una tienda de computadoras, desarrollado en lenguaje C. Permite realizar operaciones CRUD (Crear, Leer, Actualizar, Eliminar) sobre productos almacenados en un archivo de texto. El programa puede ejecutarse en dos modos: **lectura** (solo consulta) y **escritura** (todas las operaciones).

## Estructura de Archivos

- **main.c**: Archivo principal. Contiene la función `main`, el menú interactivo y la lógica de flujo del programa. Llama a funciones de los módulos de inventario y producto.
- **inventario.h**: Encabezado del módulo de inventario. Declara funciones para cargar, guardar, buscar y mostrar productos, así como utilidades para validar el modo de operación.
- **inventario.c**: Implementa las funciones declaradas en `inventario.h`. Aquí se encuentran las funciones para manejar el arreglo de productos, cargar y guardar desde/para el archivo, y validaciones de modo.
- **producto.h**: Encabezado del módulo de producto. Define la estructura `Producto` y declara las funciones CRUD para un producto individual.
- **producto.c**: Implementa las funciones CRUD para la estructura `Producto` (crear, mostrar, actualizar, eliminar).
- **productos.txt**: Archivo de texto que almacena la lista de productos. Cada línea representa un producto con el formato: `id,nombre,cantidad,precio`.
- **run.sh**: Script bash para compilar y ejecutar el proyecto fácilmente en sistemas compatibles con bash (Linux, WSL, Git Bash, etc.).

## Descripción de Archivos

### main.c
- Presenta un menú interactivo al usuario.
- Permite seleccionar entre ver inventario, crear, mostrar, actualizar, eliminar productos o salir.
- Valida el modo de operación (lectura/escritura) y restringe las opciones del menú según corresponda.
- Utiliza funciones de los módulos de inventario y producto para realizar las operaciones.

### inventario.h / inventario.c
- **inventario.h** declara funciones para:
  - Validar el modo de operación (`modoValido`, `modoEscritura`).
  - Mostrar el inventario completo (`mostrarInventario`).
  - Buscar un producto por ID (`buscarProductoPorId`).
  - Cargar productos desde el archivo (`cargarProductosDesdeArchivo`).
  - Guardar productos en el archivo (`guardarProductosEnArchivo`).
- **inventario.c** implementa estas funciones, gestionando el arreglo de productos y la interacción con el archivo de texto.

### producto.h / producto.c
- **producto.h** define la estructura `Producto` con los campos: `id`, `nombre`, `cantidad`, `precio`.
- Declara funciones para:
  - Crear un producto (`crearProducto`).
  - Mostrar un producto (`mostrarProducto`).
  - Actualizar un producto (`actualizarProducto`).
  - Eliminar un producto (`eliminarProducto`).
- **producto.c** implementa estas funciones, manipulando los datos de un producto individual.

### productos.txt
- Archivo de datos persistente.
- Cada línea representa un producto: `id,nombre,cantidad,precio`.
- Ejemplo:
  ```
  1,Teclado,15,12.99
  2,Mouse,20,9.99
  ...
  ```

### run.sh
- Script para compilar y ejecutar el proyecto.
- Compila los archivos fuente y ejecuta el binario resultante, pasando cualquier argumento recibido (por ejemplo, el modo de operación).

## Ejecución

Para compilar y ejecutar el proyecto en bash:
```bash
bash run.sh escritura   # Modo escritura (CRUD)
bash run.sh lectura     # Modo solo lectura
```

## Notas Técnicas
- El proyecto no utiliza `string.h`; todas las operaciones de cadenas se realizan manualmente con `stdio.h`.
- El menú valida que las opciones sean del 1 al 6.
- El modo de operación se valida al inicio y solo acepta "lectura" o "escritura".
- El nombre del producto se lee con `scanf` y tiene un límite de 49 caracteres.

## Autores y Licencia
Este proyecto es para fines educativos en un curso introductorio de programación en C.
