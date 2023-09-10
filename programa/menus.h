#ifndef MENUS_H
#define MENUS_H

#include "ficheros.h"

void MenuInicio();
void MenuAccederArchivos(struct Archivo *archivos, int numArchivos);
void MenuIngresarArchivos(struct Archivo *archivos, int *numArchivos);

#endif
