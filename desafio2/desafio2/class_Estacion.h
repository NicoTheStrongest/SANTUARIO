#ifndef CLASS_ESTACION_H
#define CLASS_ESTACION_H

#include <iostream>

#include "funcionesGenerales.h"
#include "class_Surtidor.h"
#include "class_Tanque.h"

#include <fstream>
#include <string>

using namespace std;

class Estacion{
private:
    //Atributos
    Surtidor* surtidores; // Arreglo dinamico de surtidores de la estacion
    std::string nombre, codigoEstacion, gerente, region, coordenadas; // atributos surtidor
    int sizeSurtidores = 0;
    int capacidadSurtidores = 0;
    std::string naves[6];
    int navesActuales = 0;

    void expandirSurtidores();
public:
    //Constructor
    Estacion();
    Estacion(string nombreO, string codigoEstacionO, string gerenteO, string regionO, string coordenadasO);
    //Destructor
    ~Estacion();
    //Getters
    std::string getnombre()const;
    std::string getcodigoEstacion()const;
    std::string getgerente()const;
    std::string getregion()const;
    std::string getcoordenadas()const;
    int getsizeSurtidores()const;

    //Setters
    std::string setNombre();
    std::string setCodigoEstacion();
    std::string setGerente();
    std::string setRegion();
    std::string setCoordenadas();
    int setSizeSurtidores();

    //Metodos
    void agregarSurtidor(Surtidor& nuevoSurtidor);
    void eliminarSurtidor(const std::string& codigoSurtidor);
    void activarSurtidor(const std::string& codigoSurtidor);
    void desactivarSurtidor(const std::string& codigoSurtidor);
    void consultarHistorico();
    void asignarCapacidadTanque();
    void reportarLitrosVendidos();
    void mostrarEstaciones();
    void agregarNave(string codigo);
    void mostrarNaves();
};

#endif // CLASS_ESTACION_H
