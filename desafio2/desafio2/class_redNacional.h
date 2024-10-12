#ifndef CLASS_REDNACIONAL_H
#define CLASS_REDNACIONAL_H

#include <iostream>
#include <funcionesGenerales.h>
#include <fstream>
#include <string>
#include <class_Estacion.h>

using namespace std;

//Clase para gestionar la red nacional
class RedNacional{
private:
    //Atributos
    Estacion** estaciones;
    int numEstaciones;
    int capacidadEstaciones;
    void expandirEstaciones();
    void liberarEstaciones();
public:
    //Constructor
    RedNacional(int capacidadInicialEstaciones = 10);
    //Destructor
    ~RedNacional();
    //Getters
    Estacion getestaciones() const;
    int getnumEstaciones() const;
    //Setters
    //Metodos
    void agregarEstacion(Estacion* nuevaEstacion);
    void eliminarEstacion(const string& codigoEstacion);
    void ventasCombustible();
    void fijarPrecios(double precioRegular,double precioPremium,double precioEcoExtra);
    bool verificarFugas(const string& codigoEstacion);

};

#endif // CLASS_REDNACIONAL_H
