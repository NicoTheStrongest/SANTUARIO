#ifndef CLASS_VENTAS_H
#define CLASS_VENTAS_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Ventas{
private:
    //Atributos
    std::string codigoVentas, tipoCombustible, fechaHora, metodoPago, documentoCliente;
    int cantidadCombustible;
    int  monto;
public:
    //Constructor
    Ventas();
    Ventas(string codigoSurtidor, string tipoCombustible, string fechaHora, int cantidadCombustible, string metodoPago, string documentoCliente, int monto);
    //Destructor
    ~Ventas();

    //Getters
    string getCodigoVentas() const;
    std::string getfechaHora() const;
    std::string getTipoCombustible() const;
    std::string getMetodoPago() const;
    std::string getDocumentoCliente() const;
    double getMonto() const;
    double getCantidadCombustible() const;

    //Setters
    std::string setFechaHora(std::string newFechaHora);
    std::string setTipoCombustible(std::string newTipoCombustible);
    std::string setMetodoPago(std::string newMetodoPago);
    std::string setDocumentoCliente(std::string newDocumentoCliente);
    double setMonto(double newMonto);
    double setCantidadCombustible(double newCantidadCombustible);

    //metodos
    std::string calcularFechaHora();
    void mostrarVentas();
};

#endif // CLASS_VENTAS_H
