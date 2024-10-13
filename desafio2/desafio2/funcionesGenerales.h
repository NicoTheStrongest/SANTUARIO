#ifndef FUNCIONESGENERALES_H
#define FUNCIONESGENERALES_H

#include <iostream>
#include <fstream>
#include <string>

void leerArchivoPorLinea(const std::string& fileName);

int opcionesMenuGeneral(const std::string& mensaje1, const std::string& mensaje2, const std::string opcionesValidas[], int size);
bool menuSalida();
void mensajeSalida();
void limpiarPantalla();
int inicioSesion();
int menuGestionDeRed();
int menuGestionEstaciones();
bool validarNumeros(std::string cadena);

#endif // FUNCIONESGENERALES_H
