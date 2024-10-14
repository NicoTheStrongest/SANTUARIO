#ifndef CLASS_SURTIDOR_H
#define CLASS_SURTIDOR_H

#include <iostream>

#include "class_Ventas.h"

#include <fstream>
#include <string>

class Surtidor{
private:
    //Atributos
    std::string codigoSurtidor, modelo;
    bool estado;
    Ventas* ventas;
    int sizeVentas = 0;
    int capacidadVentas = 0;
    std::string codSurtidores[13];
    int numCodigosSurtidores = 0;
    double precioRegular,precioPremium,precioEcoExtra;

    void expandirVentas(Ventas*& arr, int* size);
public:
    //Constructor
    Surtidor();
    Surtidor(std::string codigoSurtidor, std::string modelo, bool estado = false);
    //Destructor
    ~Surtidor();
    //Getters
    std::string getCodigoSurtidor() const;
    std::string getModelo() const;
    bool getEstado() const;
    int getSizeVentas() const;
    int getCapacidadVentas() const;
    double getPrecioRegular() const;
    double getPrecioPremium() const;
    double getPrecioEcoExtra() const;

    //Metodos
    bool CambiarActivo()const;
    void registrarVenta(const Ventas& nuevaVenta);
    void agregarCodSurtidoresLectura(std::string codigo);
    void mostrarCodigos();
};

#endif // CLASS_SURTIDOR_H
