#ifndef CLASS_SURTIDOR_H
#define CLASS_SURTIDOR_H

#include <iostream>

#include "funcionesGenerales.h"
#include "class_Ventas.h"

#include <fstream>
#include <string>

class Surtidor{
private:
    //Atributos
    std::string codigoSurtidor,modelo;
    bool activo;
    Ventas* ventas;
    int sizeVentas;
    double precioRegular,precioPremium,precioEcoExtra;

    void expandirVentas(Ventas*& arr, int* size);
public:
    //Constructor
    Surtidor();
    Surtidor(std::string codigoSurtidor, std::string modelo, bool activo = true);
    //Destructor
    ~Surtidor();
    //Getters
    std::string getCodigoSurtidor() const;
    std::string getModelo() const;
    bool getActivo() const;
    int getSizeVentas() const;
    double getPrecioRegular() const;
    double getPrecioPremium() const;
    double getPrecioEcoExtra() const;

    //setters
    void setCodigoSurtidor(std::string newCodigoSurtidor);
    void setModelo(std::string newModelo);
    void setSizeVentas(int newSizeVentas);
    void setPrecioRegular(double newPrecioRegular);
    void setPrecioPremium(double newPrecioPremium);
    void setPrecioEcoExtra(double newPrecioEcoextra);

    //Metodos
    bool CambiarActivo()const;
    void registrarVenta(const Ventas& nuevaVenta);
};

#endif // CLASS_SURTIDOR_H
