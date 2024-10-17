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
    int capacidadVentas = 1;
    std::string codSurtidores[13];
    int numCodigosSurtidores = 0;
    int precioRegular,precioPremium,precioEcoextra;

    void expandirVentas();
public:
    //Constructor
    Surtidor();
    Surtidor(std::string codigoSurtidor, std::string modelo, bool estado = true);
    //Destructor
    ~Surtidor();
    //Getters
    std::string getCodigoSurtidor() const;
    std::string getModelo() const;
    bool getEstado() const;
    int getSizeVentas() const;
    int getPrecioRegular() const;
    int getPrecioPremium() const;
    int getPrecioEcoExtra() const;
    Ventas* getVentas() const;

    //setters
    void setCodigoSurtidor(std::string newCodigoSurtidor);
    void setModelo(std::string newModelo);
    void setEstado(bool estado);
    void setSizeVentas(int newSizeVentas);
    void setPrecioRegular(int newPrecioRegular);
    void setPrecioPremium(int newPrecioPremium);
    void setPrecioEcoExtra(int newPrecioEcoextra);

    //Metodos
    void discriminarVentas(int& totalRegular, int& totalPremium, int& totalEcoextra);
    void agregarCodSurtidoresLectura(string codigo);
    void mostrarCodigos();
    void mostrarAtributos();
    void agregarVentaLectura(string codigoSurtidor, string tipoCombustible, string fechaHora, int cantidadCombustible, string metodoPago, string documentoCliente, int monto);
    void eliminarVentaSurtidor(string codigo);
    void mostrarVentasSurtidor(string codigo, Ventas& ventas);
};

#endif // CLASS_SURTIDOR_H
