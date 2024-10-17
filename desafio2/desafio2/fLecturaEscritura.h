#ifndef FLECTURAESCRITURA_H
#define FLECTURAESCRITURA_H

#include <iostream>
#include <fstream>
#include <string>

#include "fLecturaEscritura.h"
#include "class_RedNacional.h"
#include "class_Estacion.h"
#include "class_Surtidor.h"
#include "class_Tanque.h"
#include "class_Ventas.h"

//              Funciones de lectura y escritura

void limpiarPantallaLectura();

void leerArchivoClases(RedNacional& redNacional, Estacion& estacion, Surtidor& surtidor, Tanque& tanque, Ventas& ventas);

void mostrarMontoTotal(Estacion* ptrEstacion, int sizeEstacion, Ventas* ptrVentas, int sizeVentas);

void mostrarLitrosTotales(Ventas* ventas6, int size, string codigo);

void simularVentas(Surtidor* surtidores, int sizeSurtidores, Ventas* ventas, int sizeVentas, RedNacional* redNacional, string region);

void mostrarTransaccion(string codigoVenta, string tipoCombustible, string fechaHora, string metodoPago, string docCliente, int montoPago, int litros);

bool validarNumeros(string cadena);

void formatoDocumento(string* documento);

string calcularFechaHoraSimulador();

#endif // FLECTURAESCRITURA_H
