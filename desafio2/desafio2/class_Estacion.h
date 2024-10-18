#ifndef CLASS_ESTACION_H
#define CLASS_ESTACION_H

#include <iostream>

#include "funcionesGenerales.h"
#include "class_Surtidor.h"
#include "class_Tanque.h"
#include "class_Ventas.h"

#include <fstream>
#include <string>

using namespace std;

class Estacion{
private:
    //                  ATRIBUTOS
    Surtidor* surtidores; // Arreglo dinamico de surtidores de la estacion
    string nombre, codigoEstacion, gerente, region, coordenadas; // atributos surtidor
    int sizeSurtidores = 0;
    int capacidadSurtidores = 1;
    int navesActuales = 0;
    int capacidadNaves = 1;
    string* naves;

    Tanque tanqueAsociado;
    void expandirSurtidores();
    void expandirNaves();
public:
    //                  CONSTRUCTOR Y DESTRUCTOR
    Estacion();
    Estacion(string nombreO, string codigoEstacionO, string gerenteO, string regionO, string coordenadasO);
    ~Estacion();

    //                  GETTERS
    string getnombre()const;
    string getcodigoEstacion()const;
    string getgerente()const;
    string getregion()const;
    string getcoordenadas()const;
    int getsizeSurtidores()const;
    int getCapacidadSurtidores()const;
    Surtidor* getSurtidores() const;
    Tanque getTanqueAsociado()const;

    //                  SETTERS
    void setNombre(std::string newNombre);
    void setCodigoEstacion(std::string newCodigoEstacion);
    void setGerente(std::string newGerente);
    void setRegion(std::string newRegion);
    void setCoordenadas(std::string newCoordenadas);
    void setSizeSurtidores(int newSizeSurtidores);
    void setCapacidadSurtidores(int newCapacidadSurtidores);
    Tanque setTanqueAsociado();

    //                  METODOS
    void agregarSurtidor(string codigoEstacion);
    void agregarSurtidorLectura(string codigo, string modelo, bool estado);
    void mostrarEstaciones();
    string obtenerCodigoSurtidor(string codigoEstacion);
    void eliminarSurtidor(string codigo);
    void eliminarSurtidoresNavesEstacion(bool eliminar, string codigo);
    void activarSurtidor(string codSurtidor);
    void desactivarSurtidor(string codSurtidor);
    void consultarHistorico(Ventas* ventas, int sizeVentas, string codEstacion);
    void simularVenta();
    void verificarFugas(Ventas* ventas, int sizeVentas,string estacion);
    void agregarNaveLectura(string codigo);
    void mostrarNaves();
    bool surtidoresInactivos(string codigoEstacion);
    void asignarTanque();
    void disminuirTanque(string tipoCombustible, int litros);
    int venderResto(string tipoCombustible, int litros);
};

#endif // CLASS_ESTACION_H
