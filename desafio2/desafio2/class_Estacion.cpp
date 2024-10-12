#include <iostream>
#include <funcionesGenerales.h>
#include <fstream>
#include <string>

using namespace std;

class Estacion{
private:
    string nombre;
    string codigo;
    string docGerente;
    string region;
    string ubicacion;
public:
    Estacion(string nombre, string codigo, string gerente, string region, string ubicacion){}
    string getNombre() const{}
    string getCodigo() const{}
    string getDocGerente() const{}
    string getRegion() const{}
    string getUbicacion() const{}
    string setNombre(string nombreEstacion){}
    string setCodigo(string nuevoCodigo){}
    string setDocGerente(string docGerente){}
    string setRegion(string nuevaRegion){} //??
    string setUbicacion(string nuevaUbicacion){}
    ~Estacion(){}
};
