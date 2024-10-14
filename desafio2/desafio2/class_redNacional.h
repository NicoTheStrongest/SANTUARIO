#ifndef CLASS_REDNACIONAL_H
#define CLASS_REDNACIONAL_H

#include <iostream>

#include "class_Estacion.h"

#include <fstream>
#include <string>

//Clase para gestionar la red nacional
class RedNacional{
private:
    //Atributos
    static const int sizeRegion = 3;
    string regiones[sizeRegion];
    Estacion* estaciones; // arreglo dinamico de estaciones
    int sizeEstaciones = 0; // cantidad de estaciones
    int capacidadEstaciones = 0;

    void expandirEstaciones();
public:
    //Constructor
    RedNacional();
    RedNacional(const string arreglo[], int size);
    //Destructor
    ~RedNacional();
    //Getters
    int getSizetaciones()const;
    //Setters
    int setSizeEstaciones(int newSize);
    int setCapacidadEstaciones();
    //Metodos
    void agregarEstacion(string nombreO, string codigoEstacionO, string gerenteO, string regionO, string coordenadasO);
    void eliminarEstacion(const std::string& codigoEstacion);
    void ventasCombustible();
    void fijarPrecios(double precioRegular,double precioPremium,double precioEcoExtra);
    bool verificarFugas(const std::string& codigoEstacion);
    void mostrarArreglo();
};

#endif // CLASS_REDNACIONAL_H
