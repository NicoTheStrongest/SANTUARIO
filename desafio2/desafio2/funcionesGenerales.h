#ifndef FUNCIONESGENERALES_H
#define FUNCIONESGENERALES_H

#include <iostream>
#include <fstream>
#include <string>

//          Funciones de Red

void formatoDocumentoGerente(std::string* documento);
void leerArchivoPorLinea(const std::string& fileName);
int opcionesMenuGeneral(const std::string& mensaje1, const std::string& mensaje2, const std::string opcionesValidas[], int size);
bool menuSalida();
void mensajeSalida();
int menuGestionDeRed();
int menuGestionEstaciones();
void limpiarPantalla();
int inicioSesion();
bool validarNumerosGenerales(std::string cadena);

#endif // FUNCIONESGENERALES_H
