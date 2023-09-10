#ifndef FICHEROS_H
#define FICHEROS_H

// Definir estructura de Archivo
struct Archivo {
    char titulo[100];
    char cuerpo[1000];
};

// Declaración de funciones relacionadas con archivos
void CargarArchivos(struct Archivo *archivos, int *numArchivos);
void GuardarArchivos(struct Archivo *archivos, int *numArchivos);

// Definir estructura de Referencia
struct Referencia {
    char autor[100];    // Nombre del autor de la referencia
    char titulo[100];   // Título de la referencia
    int anoPublicacion; // Año de publicación de la referencia
    // Otros campos relevantes para las referencias
};

// Declaración de funciones relacionadas con referencias
void CargarReferencias(struct Referencia *referencias, int *numReferencias);
void GuardarReferencias(struct Referencia *referencias, int *numReferencias);

#endif
