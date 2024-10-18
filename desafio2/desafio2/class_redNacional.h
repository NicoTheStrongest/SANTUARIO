#ifndef CLASS_REDNACIONAL_H
#define CLASS_REDNACIONAL_H

#include <iostream>

#include "funcionesGenerales.h"
#include "class_Estacion.h"
#include "class_Surtidor.h"
#include "class_Tanque.h"
#include "class_Ventas.h"

#include <fstream>
#include <string>

using namespace std;

//Clase para gestionar la red nacional
class RedNacional{
private:
    //                  ATRIBUTOS
    Estacion* estaciones; // arreglo dinamico de estaciones
    int sizeEstaciones = 0; // cantidad de estaciones
    int capacidadEstaciones = 2;

    int precios[3][3];

    static const int sizeRegion = 3;
    string regiones[sizeRegion];

    void expandirEstaciones();
public:
    //                  CONSTRUCTOR Y DESTRUCTOR
    RedNacional();
    ~RedNacional();

    //                  GETTERS
    int getSizetaciones()const;
    int getCapacidadEstaciones()const;
    Estacion* getEstaciones()const;

    //                  SETTERS
    void setSizeEstaciones(int newSize);
    void setCapacidadEstaciones(int newCapacidad);

    //                  METODOS
    void agregarEstacionLectura(string nombreO, string codigoEstacionO, string gerenteO, string regionO, string coordenadasO);
    void agregarEstacion();
    void eliminarEstacion(bool bandera, string codigoEliminar);
    string obtenerCodigoEstacion();
    string obtenerRegionEstacion(string* codigoEstacion);
    void fijarPrecios();
    void mostrarArregloEstaciones();
    string elegirEstacion();
    void agregarRegiones(string arreglo[]);
    void asignarCapacidadTanque();
    int calcularMontoPago(string tipoCombustible, int litros, string region);
};

#endif // CLASS_REDNACIONAL_H
