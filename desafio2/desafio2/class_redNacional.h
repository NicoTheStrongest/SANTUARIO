#ifndef CLASS_REDNACIONAL_H
#define CLASS_REDNACIONAL_H

#include <iostream>

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

    static const int sizeRegion = 3;
    string regiones[sizeRegion];

    void expandirEstaciones();
public:
    static int codEstacion;

    //Constructor
    RedNacional();
    //Destructor
    ~RedNacional();
    //Getters
    int getSizetaciones()const;
    //Setters
    int setSizeEstaciones(int newSize);
    int setCapacidadEstaciones();
    //Metodos
    void agregarEstacionLectura(string nombreO, string codigoEstacionO, string gerenteO, string regionO, string coordenadasO);
    void eliminarEstacion(const std::string& codigoEstacion);
    void ventasCombustible();
    void fijarPrecios(double precioRegular,double precioPremium,double precioEcoExtra);
    bool verificarFugas(const std::string& codigoEstacion);
    void mostrarArreglo();

    void agregarRegiones(string arreglo[]);

    Estacion* getEstaciones()const;
};

#endif // CLASS_REDNACIONAL_H
