#include <iostream>

#include "class_Surtidor.h"
#include "class_Ventas.h"

#include <fstream>
#include <string>

using namespace std;

//                  CONSTRUCTOR Y DESTRUCTOR

Surtidor::Surtidor(){}

Surtidor::Surtidor(string codigoSurtidor, string modelo, bool estado)
    : codigoSurtidor(codigoSurtidor), modelo(modelo), estado(estado){
    ventas = new Ventas[capacidadVentas];
    precioRegular = 0;
    precioPremium = 0;
    precioEcoextra = 0;
}

Surtidor::~Surtidor(){/*delete[] ventas;*/}

//                  GETTERS

string Surtidor:: getCodigoSurtidor() const {return codigoSurtidor;}
string Surtidor:: getModelo() const {return modelo;}
bool Surtidor:: getEstado() const {return estado;}
int Surtidor:: getSizeVentas() const {return sizeVentas;}
int Surtidor:: getPrecioRegular() const {return precioRegular;}
int Surtidor:: getPrecioPremium() const {return precioRegular;}
int Surtidor:: getPrecioEcoExtra() const {return precioEcoextra;}
Ventas* Surtidor:: getVentas() const {return ventas;}

//                  SETTERS

void Surtidor::setCodigoSurtidor(std::string newCodigoSurtidor){
    //Validar formato del parametro
    if(newCodigoSurtidor.length() == 6){
        codigoSurtidor = newCodigoSurtidor;
    }
    else{
        cout << "newCodigoSurtidor debe tener seis caracteres." << endl;
    }
}
void Surtidor::setModelo(std::string newModelo){
    if(newModelo == "modelo1" || newModelo == "modelo2" || newModelo == "modelo3"){
        modelo = newModelo;
    }
    else{
        cout << "newModelo debe ser 'modelo1','modelo2' o 'modelo3'" << endl;
    }
}
void Surtidor::setEstado(bool condicion){
    if(condicion != estado){
        estado = condicion;
    }
}
void Surtidor::setSizeVentas(int newSizeVentas){
    if(newSizeVentas > 0){
        sizeVentas = newSizeVentas;
    }
    else{
        cout << "newSizeVentas de ser mayor a cero" << endl;
    }
}
void Surtidor::setPrecioRegular(int newPrecioRegular){
    if(newPrecioRegular > 0){
            precioRegular = newPrecioRegular;
    }
    else{
        cout << "newPrecioRegular de ser mayor a cero" << endl;
    }
}
void Surtidor::setPrecioPremium(int newPrecioPremium){
    if(newPrecioPremium > 0){
        precioPremium = newPrecioPremium;
    }
    else{
        cout << "newPrecioPremium de ser mayor a cero" << endl;
    }
}
void Surtidor::setPrecioEcoExtra(int newPrecioEcoextra){
    if(newPrecioEcoextra > 0){
        precioEcoextra = newPrecioEcoextra;
    }
    else{
        cout << "newPrecioEcoextra de ser mayor a cero" << endl;
    }
}

//                  METODOS (PRIVADOS)

void Surtidor:: expandirVentas(){
    //Metodo privado para expandir el arreglo de ventas
    int nuevaCapacidad = capacidadVentas + 1;
    Ventas* nuevoArr = new Ventas[nuevaCapacidad];

    // Copiar elementos al nuevo arreglo
    for (int i = 0; i < sizeVentas; ++i) {
        nuevoArr[i] = ventas[i];
    }

    // Liberar la memoria del arreglo original
    delete[] ventas;

    // Actualizar el puntero para que apunte al nuevo arreglo
    ventas = nuevoArr;
    capacidadVentas = nuevaCapacidad;
}

//                  METODOS (PUBLICOS)

void Surtidor:: agregarVentaLectura(string codigoSurtidor, string tipoCombustible, string fechaHora, int cantidadCombustible, string metodoPago, string documentoCliente, int monto){
    //Metodo para agregar venta al arreglo
    if(sizeVentas == 0){ventas = new Ventas[capacidadVentas];}
    else{
        if (sizeVentas == capacidadVentas) {
            expandirVentas();  // Si el arreglo está lleno, lo expandimos
        }
    }
    ventas[sizeVentas] = Ventas(codigoSurtidor, tipoCombustible, fechaHora, cantidadCombustible, metodoPago, documentoCliente, monto);
    sizeVentas++;
}

void Surtidor:: agregarCodSurtidoresLectura(string codigo){
    //Agregar codigos al arreglo de surtidores.
    if(numCodigosSurtidores <= 12){
        codSurtidores[numCodigosSurtidores] = codigo;
        numCodigosSurtidores++;
    }
    else{
        cout<<"No se pueden agregar mas sutidores" << endl;
    }
}

void Surtidor:: mostrarCodigos(){
    //mostrar los codigos del codSurtidores
    for (int i = 0; i < numCodigosSurtidores; ++i) {
        cout << codSurtidores[i];
    }
}

void Surtidor:: eliminarVentaSurtidor(string codigo){
    //Metodo para eliminar las ventas asociadas a un surtidor
    int ventaSurtidor = 0;
    for(int i = 0; i < sizeVentas; i++){
        if(ventas[i].getCodigoVentas() == codigo){
            ventaSurtidor++;
        }
    }
    if(ventaSurtidor == 0){
        cout << "No hay ventas asociadas al surtidor " << codigo << endl;
        system("pause");
        return;
    }
    //Inicializa el arreglo
    int nuevoSizeVentas = sizeVentas - ventaSurtidor;
    Ventas* nuevoArregloVentas = new Ventas[nuevoSizeVentas];
    //Copia las ventas que no estan asociadas al surtidor
    int ventaNoAsociada = 0;
    for(int i = 0; i < sizeVentas; i++){
        if(ventas[i].getCodigoVentas() != codigo){
            nuevoArregloVentas[ventaNoAsociada] = ventas[i];
            ventaNoAsociada++;
        }
    }
    //Elimina el arreglo antiguo
    delete[] ventas;
    //Actualiza el arreglo
    ventas = nuevoArregloVentas;
    //Actualiza el tamaño del arreglo
    sizeVentas = nuevoSizeVentas;
    cout << "Ventas asociadas a el surtidor " << codigo << " eliminadas con exito." << endl;
    system("pause");
}

