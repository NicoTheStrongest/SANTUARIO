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
    Tanque tanque;
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
    int getCapacidadSurtidores()const;
    Surtidor* getSurtidores() const;

    //Setters
    void setNombre(std::string newNombre);
    void setCodigoEstacion(std::string newCodigoEstacion);
    void setGerente(std::string newGerente);
    void setRegion(std::string newRegion);
    void setCoordenadas(std::string newCoordenadas);
    void setSizeSurtidores(int newSizeSurtidores);
    void setCapacidadSurtidores(int newCapacidadSurtidores);

    //Metodos
    void agregarCodSurtidoresLectura(string codigo);
    void agregarSurtidor(string codigoEstacion);
    void agregarSurtidorLectura(string codigo, string modelo, bool estado);
    void eliminarSurtidor(string codigo);
    void activarSurtidor();
    void desactivarSurtidor();
    string obtenerCodigoSurtidor(string codigoEstacion);
    void consultarHistorico(Ventas* ventas, int sizeVentas, string codEstacion);
    void reportarLitrosVendidos();
    void simularVenta();
    void asignarCapacidadTanque();
    void verificarFugas(Ventas* ventas, int sizeVentas,string estacion);
    void mostrarEstaciones();
    void agregarNaveLectura(string codigo);
    void mostrarNaves();
    bool surtidoresInactivos(string codigoEstacion);
    void eliminarSurtidoresNavesEstacion(bool eliminar, string codigo);

};

#endif // CLASS_ESTACION_H
