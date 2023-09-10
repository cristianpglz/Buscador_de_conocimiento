#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ficheros.h"


void CargarArchivos(struct Archivo *archivos, int *numArchivos) {
    FILE *archivo = fopen("archivos.bin", "rb");
    if (archivo == NULL) {
        // Si el archivo no existe, inicializamos los archivos con valores predeterminados
        for (int i = 0; i < *numArchivos; i++) {
            strcpy(archivos[i].titulo, "");
            strcpy(archivos[i].cuerpo, "");
        }
    } else {
        // Si el archivo existe, lo leemos y cargamos los archivos
        fread(archivos, sizeof(struct Archivo), *numArchivos, archivo);
        fclose(archivo);
    }
}

// Implementación de la función para guardar archivos en un archivo binario
void GuardarArchivos(struct Archivo *archivos, int *numArchivos) {
    FILE *archivo = fopen("archivos.bin", "wb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para guardar.\n");
    } else {
        fwrite(archivos, sizeof(struct Archivo), *numArchivos, archivo);
        fclose(archivo);
    }
}

// Función para cargar referencias desde un archivo de texto
void CargarReferencias(struct Referencia *referencias, int *numReferencias) {
    FILE *archivo = fopen("referencias.txt", "r");
    if (archivo == NULL) {
        // Si el archivo no existe, inicializamos numReferencias a 0
        *numReferencias = 0;
        return;
    }

    // Leemos las referencias desde el archivo de texto
    while (fscanf(archivo, "%99[^;];%99[^;];%d\n", referencias[*numReferencias].autor, 
    referencias[*numReferencias].titulo, &referencias[*numReferencias].anoPublicacion) == 3) {
        (*numReferencias)++;
    }

    // Cerramos el archivo
    fclose(archivo);
}

// Función para guardar referencias en un archivo de texto
void GuardarReferencias(struct Referencia *referencias, int *numReferencias) {
    FILE *archivo = fopen("referencias.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    // Escribimos las referencias en el archivo de texto
    for (int i = 0; i < *numReferencias; i++) {
        fprintf(archivo, "%s;%s;%d\n", referencias[i].autor, referencias[i].titulo, referencias[i].anoPublicacion);
    }

    // Cerramos el archivo
    fclose(archivo);
}
