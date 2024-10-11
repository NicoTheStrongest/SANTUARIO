#include <iostream>
#include <funcionesGenerales.h>
#include <fstream>
#include <string>

using namespace std;

class Surtidor{
private:
    string codigo;
    string modelo;
    string combustible;
    string venta;
public:
    Surtidor(){}
    string getCodigo () const{}
    string getModelo () const{}
    string getCombustible () const{}
    string getVenta () const{}
    string setCodigo(){}
    string setModelo(){}
    string setCombustible(){}
    string setVenta(){}
    ~Surtidor(){}
};
