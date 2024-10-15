#ifndef CLASS_VENTAS_H
#define CLASS_VENTAS_H

#include <iostream>
#include <fstream>
#include <string>

class Ventas{
private:
    //Atributos
    std::string codigoVenta,fechaHora, tipoCombustible, metodoPago, documentoCliente;
    double cantidadCombustible, monto;
public:
    //Constructor
    Ventas();
    Ventas(const std::string codigoVenta,const std::string fechaHora,const std::string tipoCombustible,const std::string metodoPago,const std::string documentoCliente,double cantidadCombustible,double monto);
    //Destructor
    ~Ventas();

    //Getters
    std::string getCodigoVenta() const;
    std::string getfechaHora() const;
    std::string getTipoCombustible() const;
    std::string getMetodoPago() const;
    std::string getDocumentoCliente() const;
    double getMonto() const;
    double getCantidadCombustible() const;

    //Setters
    void setFechaHora(std::string newFechaHora);
    void setTipoCombustible(std::string newTipoCombustible);
    void setMetodoPago(std::string newMetodoPago);
    void setDocumentoCliente(std::string newDocumentoCliente);
    void setMonto(double newMonto);
    void setCantidadCombustible(double newCantidadCombustible);

    //metodos
    std::string calcularFechaHora();
    void detallesVentas();
};

#endif // CLASS_VENTAS_H
