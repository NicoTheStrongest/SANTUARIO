#ifndef CLASS_SURTIDOR_H
#define CLASS_SURTIDOR_H

#include <iostream>

#include "class_Ventas.h"

#include <fstream>
#include <string>

using namespace std;

class Surtidor{
private:
    //                  ATRIBUTOS
    string codigoSurtidor, modelo;
    bool estado;
    Ventas* ventas;
    int sizeVentas = 0;
    int capacidadVentas = 1;
    std::string codSurtidores[13];
    int numCodigosSurtidores = 0;
    int precioRegular,precioPremium,precioEcoextra;

    void expandirVentas();
public:
    //                  CONSTRUCTOR Y DESTRUCTOR
    Surtidor();
    Surtidor(string codigoSurtidor, string modelo, bool estado = true);
    ~Surtidor();

    //                  GETTERS
    std::string getCodigoSurtidor() const;
    std::string getModelo() const;
    bool getEstado() const;
    int getSizeVentas() const;
    int getPrecioRegular() const;
    int getPrecioPremium() const;
    int getPrecioEcoExtra() const;
    Ventas* getVentas() const;

    //                  SETTERS
    void setCodigoSurtidor(std::string newCodigoSurtidor);
    void setModelo(std::string newModelo);
    void setEstado(bool estado);
    void setSizeVentas(int newSizeVentas);
    void setPrecioRegular(int newPrecioRegular);
    void setPrecioPremium(int newPrecioPremium);
    void setPrecioEcoExtra(int newPrecioEcoextra);

    //                  METODOS
    void agregarVentaLectura(string codigoSurtidor, string tipoCombustible, string fechaHora, int cantidadCombustible, string metodoPago, string documentoCliente, int monto);
    void agregarCodSurtidoresLectura(string codigo);
    void mostrarCodigos();
    void eliminarVentaSurtidor(string codigo);
    //void discriminarVentas(int& totalRegular, int& totalPremium, int& totalEcoextra);
    //void mostrarAtributos();
    //void mostrarVentasSurtidor(string codigo, Ventas& ventas);
    //void detallesVentas();
};

#endif // CLASS_SURTIDOR_H
