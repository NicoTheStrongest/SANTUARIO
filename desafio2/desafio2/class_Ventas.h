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
    int getMonto() const;
    int getCantidadCombustible() const;

    //Setters
    void setFechaHora(std::string newFechaHora);
    void setTipoCombustible(std::string newTipoCombustible);
    void setMetodoPago(std::string newMetodoPago);
    void setDocumentoCliente(std::string newDocumentoCliente);
    void setMonto(int newMonto);
    void setCantidadCombustible(int newCantidadCombustible);

    //metodos
    std::string calcularFechaHora();
    void mostrarVentas();
    void detallesVentas();
};

#endif // CLASS_VENTAS_H
