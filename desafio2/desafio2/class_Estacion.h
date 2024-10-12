#ifndef CLASS_ESTACION_H
#define CLASS_ESTACION_H

#include <iostream>
#include <funcionesGenerales.h>
#include <fstream>
#include <string>
#include <class_Surtidor.h>
#include <class_Tanque.h>

using namespace std;

class Estacion{
private:
    //Atributos
    string nombre,codigoEstacion,gerente,region,coordenadas;
    Surtidor** Surtidores;
    int numSurtidores;
    int capacidadSurtidores;
    int naves;
    void expandirSurtidores();
    void liberarSurtidores();
public:
    //Constructor
    Estacion(int capacidadInicialSurtidores = 10);
    //Destructor
    ~Estacion();
    //Getters
    string getnombre()const;
    string getcodigoEstacion()const;
    string getsurtidor(const string& codigoSurtidor);
    //Metodos
    void agregarSurtidor(const string& codigoSurtidor, const string& modelo);
    void eliminarSurtidor(const string& codigoSurtidor);
    void activarSurtidor(const string& codigoSurtidor);
    void desactivarSurtidor(const string& codigoSurtidor);
    void consultarHistorico();
    void asignarCapacidadTanque();
    void litrosVendidos();
