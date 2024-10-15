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
    //Atributos
    Estacion* estaciones; // arreglo dinamico de estaciones
    int sizeEstaciones = 0; // cantidad de estaciones
    int capacidadEstaciones = 2;

    double precios[3][3];

    static const int sizeRegion = 3;
    string regiones[sizeRegion];

    void expandirEstaciones();
public:
    //Constructor - Destructor
    RedNacional();
    ~RedNacional();

    //Getters - Setters
    int getSizetaciones()const;
    int setSizeEstaciones(int newSize);
    int setCapacidadEstaciones();
    Estacion* getEstaciones()const;

    //Metodos
    void agregarEstacionLectura(string nombreO, string codigoEstacionO, string gerenteO, string regionO, string coordenadasO);
    void agregarEstacion();
    void eliminarEstacion(bool bandera, string codigoEliminar);
    string obtenerCodigoEstacion();
    void ventasCombustible();
    void fijarPrecios(double precioRegular,double precioPremium,double precioEcoExtra);
    bool verificarFugas(const std::string& codigoEstacion);
    void mostrarArregloEstaciones();
    void agregarRegiones(string arreglo[]);
};

#endif // CLASS_REDNACIONAL_H
