#ifndef CLASS_SURTIDOR_H
#define CLASS_SURTIDOR_H

#include <iostream>

#include "funcionesGenerales.h"
#include "class_Ventas.h"

#include <fstream>
#include <string>

using namespace std;

class Surtidor{

    //Atributos
    string codigoSurtidor,modelo;
    bool activo = true;
    Ventas** ventas;
    int sizeVentas;
    double precioRegular,precioPremium,precioEcoExtra;

    void expandirVentas();
public:
    //Constructor
    Surtidor();
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
    bool CambiarActivo()const;
    void registrarVenta(const Ventas& nuevaVenta);

#endif // CLASS_SURTIDOR_H
