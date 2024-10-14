#ifndef FUNCIONESGENERALES_H
#define FUNCIONESGENERALES_H

#include <iostream>
#include <fstream>
#include <string>

#include "class_Estacion.h"
#include "class_RedNacional.h"
// #include "class_Surtidor.h"
// #include "class_Tanque.h"
// #include "class_Ventas.h"

//          Funciones de Red

void agregarEstacion();






void formatoDocumento(std::string* documento);


void leerArchivoPorLinea(const std::string& fileName);
void leerArchivoClases();

int opcionesMenuGeneral(const std::string& mensaje1, const std::string& mensaje2, const std::string opcionesValidas[], int size);
bool menuSalida();
void mensajeSalida();
void limpiarPantalla();
int inicioSesion();
int menuGestionDeRed();
int menuGestionEstaciones();
bool validarNumeros(std::string cadena);

#endif // FUNCIONESGENERALES_H
