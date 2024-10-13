#ifndef CLASS_REDNACIONAL_H
#define CLASS_REDNACIONAL_H

#include <iostream>

#include "funcionesGenerales.h"
#include "class_Estacion.h"

#include <fstream>
#include <string>

//using namespace std;

//Clase para gestionar la red nacional
class RedNacional{
private:
    //Atributos
    Estacion** estaciones; ///arreglo dinamico de estaciones
    int sizeEstaciones; // cantidad de estaciones

    void expandirEstaciones();
public:
    //Constructor
    RedNacional(int capacidadInicialEstaciones = 12);
    //Destructor
    ~RedNacional();
    //Getters
    int getSizetaciones()const;
    //Setters
    int setSizeEstaciones(int newSize);
    int setCapacidadEstaciones();
    //Metodos
    void agregarEstacion(Estacion* nuevaEstacion);
    void eliminarEstacion(const string& codigoEstacion);
    void ventasCombustible();
    void fijarPrecios(double precioRegular,double precioPremium,double precioEcoExtra);
    bool verificarFugas(const string& codigoEstacion);

};

#endif // CLASS_REDNACIONAL_H
