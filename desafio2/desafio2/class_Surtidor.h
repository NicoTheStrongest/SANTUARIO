#ifndef CLASS_SURTIDOR_H
#define CLASS_SURTIDOR_H

#include <iostream>
#include <funcionesGenerales.h>
#include <fstream>
#include <string>
#include<class_Ventas.h>

using namespace std;

class Surtidor{

    //Atributos
    string codigoSurtidor,modelo;
    bool activo = true;
    Ventas** ventas;
    int numVentas;
    int capacidadVentas;
    double precioRegular,precioPremium,precioEcoExtra;

    void expandirVentas();
    void liberarVentas();
public:
    //Constructor
    Surtidor(int capacidadInicialVentas = 10,const string& codigoSurtidor,const string& modelo,bool activo,double precioRegular,double precioPremium,double precioEcoExtra);
    //Destructor
    ~Surtidor();
    //Getters
    string getcodigoSurtidor() const;
    string getmodelo() const;
    bool getactivo()const;
    int getnumVentas()const;
    int getcapacidadVentas()const;
    double getprecioRegular() const;
    double getprecioPremium() const;
    double getprecioEcoExtra() const;
    //ventas* getventa()const;

    //Metodos
    bool activo()const;
    void registrarVenta(const ventas& nuevaVenta);

#endif // CLASS_SURTIDOR_H
