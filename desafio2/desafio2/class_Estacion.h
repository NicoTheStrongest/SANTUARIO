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
    Surtidor** surtidores;
    int numSurtidores;
    int capacidadSurtidores;
    int naves;

    void expandirSurtidores();
    void liberarSurtidores();
public:
    //Constructor
    Estacion(int capacidadInicialSurtidores = 12,const string& nombre,const string& codigoEstacion,const string& gerente,const string& region,const string& coordenadas);
    //Destructor
    ~Estacion();
    //Getters
    string getnombre()const;
    string getcodigoEstacion()const;
    //Surtidor* getsurtidores()const;
    string getgerente()const;
    string getregion()const;
    string getcoordenadas()const;
    int getnumSurtidores()const;
    int getcapacidadSurtidores()const;

    //Metodos
    void agregarSurtidor(const string& codigoSurtidor, const string& modelo);
    void eliminarSurtidor(const string& codigoSurtidor);
    void activarSurtidor(const string& codigoSurtidor);
    void desactivarSurtidor(const string& codigoSurtidor);
    void consultarHistorico();
    void asignarCapacidadTanque();
    void litrosVendidos();
