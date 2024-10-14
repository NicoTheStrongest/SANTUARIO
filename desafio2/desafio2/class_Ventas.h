#ifndef CLASS_VENTAS_H
#define CLASS_VENTAS_H

#include <iostream>
#include <fstream>
#include <string>

class Ventas{
private:
    //Atributos
    std::string fechaHora, tipoCombustible, metodoPago, documentoCliente, codigoSurtidor;
    double cantidadCombustible, monto;
public:
    //Constructor
    Ventas();
    Ventas(const std::string fechaHora,const std::string tipoCombustible,const std::string metodoPago,const std::string documentoCliente,const std::string codigoSurtidor,double cantidadCombustible,double monto);
    //Destructor
    ~Ventas();

    //Getters
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
};

#endif // CLASS_VENTAS_H
