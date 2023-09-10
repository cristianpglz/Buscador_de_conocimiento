#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "ficheros.h"

// Prototipos de funciones auxiliares
void MostrarArchivo(struct Archivo *archivos, int numArchivo);

void MenuInicio() {
    int opcion; // Resultado del menú
    struct Archivo archivos[3]; // Array de archivos
    int numArchivos = 0; // Número de archivos cargados

    // Cargar archivos desde el archivo binario
    CargarArchivos(archivos, &numArchivos);

    printf("\n--Bienvenido al Buscador de Conocimiento--\n");
    printf("\n1. Acceder a los archivos\n");
    printf("2. Agregar a los archivos\n");
    printf("3. Salir\n");
    printf("\nEscribe el número: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            // Limpiar Consola
            system("cls");
            // Acceder a los archivos
            MenuAccederArchivos(archivos, numArchivos);
            break;
        case 2:
            // Limpiar Consola
            system("cls");
            // Agregar a los archivos
            MenuIngresarArchivos(archivos, &numArchivos);
            break;
        case 3:
            // Limpiar Consola
            system("cls");
            // Guardar archivos antes de salir
            GuardarArchivos(archivos, &numArchivos);
            // Salir
            printf("Hasta pronto!!\n");
            exit(0);
        default:
            // Limpiar Consola
            system("cls");
            // Resultado no válido, repetir menú
            printf("\nOpción no válida. Introduce una opción válida.\n");
            MenuInicio();
    }
}

void MenuAccederArchivos(struct Archivo *archivos, int numArchivos) {
    int opcion;

    if (numArchivos == 0) {
        // Si no hay archivos, muestra un mensaje y regresa al menú anterior
        printf("\nVaya!Todavia no has ingresado ningun archivo\n");
        printf("\nVolviendo al menu anterior...");
        MenuInicio();
    }

    while (1) {
        printf("Menu Acceder Archivos\n");
        for (int i = 0; i < numArchivos; i++) {
            printf("%d. Ver archivo %d\n", i + 1, i + 1);
        }
        printf("%d. Volver al menú anterior\n", numArchivos + 1);

        printf("Elija una opción: ");
        scanf("%d", &opcion);

        if (opcion >= 1 && opcion <= numArchivos) {
            // Limpiar Consola
            system("cls");
            // Mostrar archivo seleccionado
            MostrarArchivo(archivos, opcion - 1);
        } else if (opcion == numArchivos + 1) {
            // Limpiar Consola
            system("cls");
            printf("Volviendo al Menú...\n");
            MenuInicio();
        } else {
            // Limpiar Consola
            system("cls");
            printf("Opción no válida. Intente de nuevo.\n");
        }
    }
}

void MostrarArchivo(struct Archivo *archivos, int numArchivo) {
    printf("Mostrando contenido del archivo %d:\n", numArchivo + 1);
    printf("Título: %s\n", archivos[numArchivo].titulo);
    printf("Contenido:\n%s\n", archivos[numArchivo].cuerpo);
}

void MenuIngresarArchivos(struct Archivo *archivos, int *numArchivos) {
    int opcion;

    while (1) {
        printf("Menu Ingresar Archivos\n");
        printf("\n1. Ingresar archivo\n");
        printf("2. Volver al menú anterior\n");

        printf("\nElija una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // Limpiar Consola
                system("cls");
                if (*numArchivos < 3) {
                    // Ingresar un nuevo archivo si hay espacio
                    printf("Ingresar archivo %d:\n", *numArchivos + 1);
                    printf("Título: ");
                    scanf(" %[^\n]", archivos[*numArchivos].titulo);
                    printf("Contenido (hasta 1000 caracteres):\n");
                    scanf(" %[^\n]", archivos[*numArchivos].cuerpo);
                    (*numArchivos)++;
                } else {
                    printf("No hay espacio para más archivos.\n");
                }
                break;
            case 2:
                // Limpiar Consola
                system("cls");
                printf("Volviendo al Menú...\n");
                MenuInicio();
            default:
                // Limpiar Consola
                system("cls");
                printf("Opción no válida. Intente de nuevo.\n");
        }
    }
}
