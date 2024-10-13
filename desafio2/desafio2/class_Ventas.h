#ifndef CLASS_VENTAS_H
#define CLASS_VENTAS_H

#include <iostream>

#include "funcionesGenerales.h"

#include <fstream>
#include <string>

using namespace std;

class Ventas{
private:
    //Atributos
    string fechaHora,tipoCombustible,metodoPago,documentoCliente,codigoSurtidor;
    double cantidadCombustible, monto;
public:
    //Constructor
    Ventas(const string& fechaHora,const string& tipoCombustible,const string& metodoPago,const string& documentoCliente,const string& codigoSurtidor,double cantidadCombustible,double monto);
    //Destructor
    ~Ventas();

    //Getters
    string getfechaHora() const;
    string getTipoCombustible() const;
    string getMetodoPago() const;
    string getDocumentoCliente() const;
    double getMonto() const;
    double getCantidadCombustible() const;

    //Setters
    string setFechaHora(string newFechaHora);
    string setTipoCombustible(string newTipoCombustible);
    string setMetodoPago(string newMetodoPago);
    string setDocumentoCliente(string newDocumentoCliente);
    double setMonto(double newMonto);
    double setCantidadCombustible(double newCantidadCombustible);

    //metodos
    string calcularFechaHora();
};

#endif // CLASS_VENTAS_H
