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
    double precioRegular,precioPremium,precioEcoExtra;

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
    double getPrecioRegular() const;
    double getPrecioPremium() const;
    double getPrecioEcoExtra() const;

    //setters
    void setCodigoSurtidor(std::string newCodigoSurtidor);
    void setModelo(std::string newModelo);
    void setEstado(bool estado);
    void setSizeVentas(int newSizeVentas);
    void setPrecioRegular(double newPrecioRegular);
    void setPrecioPremium(double newPrecioPremium);
    void setPrecioEcoExtra(double newPrecioEcoextra);

    //Metodos
    void registrarVenta(const Ventas& nuevaVenta);
    void agregarCodSurtidoresLectura(std::string codigo);
    void mostrarCodigos();
    void mostrarAtributos();
    void agregarVentaLectura(string codigoSurtidor, string tipoCombustible, string fechaHora, int cantidadCombustible, string metodoPago, string documentoCliente, int monto);
    Ventas* getVentas() const;
    void detallesVentas();
    void eliminarVentaSurtidor(string codigo);
};

#endif // CLASS_SURTIDOR_H
