#ifndef CLASS_VENTAS_H
#define CLASS_VENTAS_H

#include <iostream>
#include <funcionesGenerales.h>
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
    ventas(const string& fechaHora,const string& tipoCombustible,const string& metodoPago,const string& documentoCliente,const string& codigoSurtidor,double cantidadCombustible,double monto);
    //Getters
    string getfechaHora() const;
    std::string getTipoCombustible() const;
    std::string getMetodoPago() const;
    std::string getDocumentoCliente() const;
    float getMonto() const;
    double getCantidadCombustible() const;
    //metodos
    string fechaHora();
};

#endif // CLASS_VENTAS_H
