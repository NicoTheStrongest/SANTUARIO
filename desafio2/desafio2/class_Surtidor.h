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
    bool activo;
    ventas** venta;
    int numVentas;
    int capacidadVentas;
    double precioRegular,precioPremium,precioEcoExtra;
    void expandirVentas();
    void liberarVentas();
public:
    //Constructor
    Surtidor(int capacidadInicialVentas = 10);
    //Destructor
    ~Surtidor();
    //Getters
    string getcodigoSurtidor() const;
    string getmodelo() const;
    double getprecioRegular() const;
    double getprecioPremium() const;
    double getprecioEcoExtra() const;
    ventas* getventa()const;
    int getnumVentas()const;

    //Metodos
    bool activo()const;
    void registrarVenta(const ventas& nuevaVenta);

#endif // CLASS_SURTIDOR_H
