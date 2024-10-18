#ifndef CLASS_VENTAS_H
#define CLASS_VENTAS_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Ventas{
private:
    //                  ATRIBUTOS
    string codigoVentas, tipoCombustible, fechaHora, metodoPago, documentoCliente;
    int cantidadCombustible;
    int  monto;
public:
    //                  CONSTRUCTOR Y DESTRUCTOR
    Ventas();
    Ventas(string codigoVentas, string tipoCombustible, string fechaHora, int cantidadCombustible, string metodoPago, string documentoCliente, int monto);
    ~Ventas();

    //                  GETTERS
    string getCodigoVentas() const;
    string getfechaHora() const;
    string getTipoCombustible() const;
    string getMetodoPago() const;
    string getDocumentoCliente() const;
    int getMonto() const;
    int getCantidadCombustible() const;

    //                  SETTERS
    void setFechaHora(string newFechaHora);
    void setTipoCombustible(string newTipoCombustible);
    void setMetodoPago(string newMetodoPago);
    void setDocumentoCliente(string newDocumentoCliente);
    void setMonto(int newMonto);
    void setCantidadCombustible(int newCantidadCombustible);

    //                  METODOS
    void mostrarVentas();
    void detallesVentas();
    void discriminarVentas(int &totalRegular, int &totalPremium, int &totalEcoextra);
};

#endif // CLASS_VENTAS_H
