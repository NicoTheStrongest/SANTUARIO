#include <iostream>

#include "class_Surtidor.h"
#include "class_Ventas.h"

#include <fstream>
#include <string>

using namespace std;

Surtidor::Surtidor(){}

Surtidor::Surtidor(string codigoSurtidor, string modelo, bool estado)
    : codigoSurtidor(codigoSurtidor), modelo(modelo), estado(estado){
    //constructor que inicializa el arreglo de ventas
    precioRegular = 0;
    precioPremium = 0;
    precioEcoExtra = 0;
}

Surtidor::~Surtidor(){
    //Destructor, liberar dinamicos
    //liberarVentas();
}

//Getters
string Surtidor:: getCodigoSurtidor() const {return codigoSurtidor;}

string Surtidor:: getModelo() const {return modelo;}

bool Surtidor:: getEstado() const {return estado;}

int Surtidor:: getSizeVentas() const {return sizeVentas;}

double Surtidor:: getPrecioRegular() const {return precioRegular;}

double Surtidor:: getPrecioPremium() const {return precioRegular;}

double Surtidor:: getPrecioEcoExtra() const {return precioEcoExtra;}

//Setters
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
void Surtidor::setPrecioRegular(double newPrecioRegular){
    if(newPrecioRegular > 0){
            precioRegular = newPrecioRegular;
    }
    else{
        cout << "newPrecioRegular de ser mayor a cero" << endl;
    }
}
void Surtidor::setPrecioPremium(double newPrecioPremium){
    if(newPrecioPremium > 0){
        precioPremium = newPrecioPremium;
    }
    else{
        cout << "newPrecioPremium de ser mayor a cero" << endl;
    }
}
void Surtidor::setPrecioEcoExtra(double newPrecioEcoextra){
    if(newPrecioEcoextra > 0){
        precioEcoExtra = newPrecioEcoextra;
    }
    else{
        cout << "newPrecioEcoextra de ser mayor a cero" << endl;
    }
}

//                  METODOS

//Metodo para expandir el arreglo de ventas
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

void Surtidor:: agregarVentaLectura(string codigoSurtidor, string tipoCombustible, string fechaHora, int cantidadCombustible, string metodoPago, string documentoCliente, int monto){
    //
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
        numCodigosSurtidores += 1;
    }
    else{
        cout<<"No se pueden agregar mas sutidores";
    }
}

void Surtidor:: mostrarCodigos(){
    //mostrar los codigos del codSurtidores
    for (int i = 0; i < numCodigosSurtidores; ++i) {
        cout << codSurtidores[i];
    }
}
/*
//Metodo que muestra los detalles de las ventas
void Surtidor::detallesVentas(){
    cout << "Fecha y hora: " << arregloVentas->getfechaHora() << endl;
    cout << "Cantidad de combustible: " << arregloVentas->getCantidadCombustible() << endl;
    cout << "Categoria de combustible: " << arregloVentas->getTipoCombustible() << endl;
    cout << "Metodo de pago: " << arregloVentas->getMetodoPago() << endl;
    cout << "Cliente: " << arregloVentas->getDocumentoCliente() << endl;
    cout << "Monto: $" << arregloVentas->getMonto() << endl;
}
*/
void registrarVenta(const Ventas& nuevaVenta){}
void agregarCodSurtidoresLectura(std::string codigo){}
void mostrarCodigos(){}
void detallesVentas(){}

void Surtidor::eliminarVentaSurtidor(string codigo){
    //Metodo para eliminar las ventas asociadas a un surtidor
    int ventaSurtidor = 0;
    for(int i = 0; i < sizeVentas; i++){
        if(ventas[i].getCodigoVentas() == codigo){
            ventaSurtidor++;
        }
    }
    if(ventaSurtidor == 0){
        cout << "No hay ventas asociadas al surtidor " << codigo << endl;
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
}

void Surtidor:: mostrarAtributos(){
    cout<<codigoSurtidor<<"->\t"<<modelo<<"->\t"<<estado<<endl;
}

Ventas* Surtidor:: getVentas() const {return ventas;}



















