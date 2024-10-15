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


void leerArchivoClases(RedNacional& redNacional, Estacion& estacion, Surtidor& surtidor, Tanque& tanque, Ventas& ventas);

void mostrarMontoTotal(Estacion* ptrEstacion, int sizeEstacion, Ventas* ptrVentas, int sizeVentas);

#endif // FLECTURAESCRITURA_H
