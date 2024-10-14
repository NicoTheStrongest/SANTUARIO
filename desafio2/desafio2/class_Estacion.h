#ifndef CLASS_ESTACION_H
#define CLASS_ESTACION_H

#include <iostream>

#include "class_Surtidor.h"
#include "class_Tanque.h"
#include "class_Ventas.h"

#include <fstream>
#include <string>

using namespace std;

class Estacion{
private:
    //Atributos
    Surtidor* surtidores; // Arreglo dinamico de surtidores de la estacion
    std::string nombre, codigoEstacion, gerente, region, coordenadas; // atributos surtidor
    int sizeSurtidores = 0;
    int capacidadSurtidores = 1;
    int navesActuales = 0;
    int capacidadNaves = 1;
    string* naves;

    void expandirSurtidores();
    void expandirNaves();
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
    void setNombre(std::string newNombre);
    void setCodigoEstacion(std::string newCodigoEstacion);
    void setGerente(std::string newGerente);
    void setRegion(std::string newRegion);
    void setCoordenadas(std::string newCoordenadas);
    void setSizeSurtidores(int newSizeSurtidores);

    //Metodos
    void agregarSurtidor(string codigo, string modelo, bool estado);
    void eliminarSurtidor(const std::string& codigoSurtidor);
    void activarSurtidor(const std::string& codigoSurtidor);
    void desactivarSurtidor(const std::string& codigoSurtidor);
    void consultarHistorico();
    void asignarCapacidadTanque();
    void reportarLitrosVendidos();
    void mostrarEstaciones();
    void agregarNaveLectura(string codigo);
    void mostrarNaves();
};

#endif // CLASS_ESTACION_H
