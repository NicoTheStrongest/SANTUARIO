#ifndef CLASS_ESTACION_H
#define CLASS_ESTACION_H

#include <iostream>

#include "funcionesGenerales.h"
#include "class_Surtidor.h"
#include "class_Tanque.h"

#include <fstream>
#include <string>

//using namespace std;

class Estacion{
private:
    //Atributos
    Surtidor** surtidores; // Arreglo dinamico de surtidores de la estacion
    string nombre, codigoEstacion, gerente, region, coordenadas; // atributos surtidor
    int sizeSurtidores;
    int naves[6];

    void expandirSurtidores();
public:
    //Constructor
    Estacion();
    //Destructor
    ~Estacion();
    //Getters
    string getnombre()const;
    string getcodigoEstacion()const;
    string getgerente()const;
    string getregion()const;
    string getcoordenadas()const;
    int getSizeSurtidores() const;

    //Setters
    string setNombre();
    string setCodigoEstacion();
    string setGerente();
    string setRegion();
    string setCoordenadas();
    int setSizeSurtidores();

    //Metodos
    void agregarSurtidor(const string& codigoSurtidor, const string& modelo);
    void eliminarSurtidor(const string& codigoSurtidor);
    void activarSurtidor(const string& codigoSurtidor);
    void desactivarSurtidor(const string& codigoSurtidor);
    void consultarHistorico();
    void asignarCapacidadTanque();
    void reportarLitrosVendidos();

#endif // CLASS_ESTACION_H
