#include <iostream>

#include "class_Estacion.h"
#include "class_Surtidor.h"
#include "class_Tanque.h"
#include "class_Ventas.h"

#include <fstream>
#include <string>

using namespace std;

Estacion::Estacion(){}

Estacion::Estacion(string nombreO, string codigoEstacionO, string gerenteO, string regionO, string coordenadasO) {
    //Constructor
    nombre = nombreO;
    codigoEstacion = codigoEstacionO;
    gerente = gerenteO;
    region = regionO;
    coordenadas = coordenadasO;
}

Estacion::~Estacion() {}

//Getters
string Estacion:: getnombre() const { return nombre; }
string Estacion:: getcodigoEstacion()const{return codigoEstacion;}
string Estacion:: getgerente()const{return gerente;}
string Estacion:: getregion()const{return region;}
string Estacion:: getcoordenadas()const{return coordenadas;}
int Estacion:: getsizeSurtidores()const{return sizeSurtidores;}
int Estacion:: getCapacidadSurtidores()const{return capacidadSurtidores;}
Surtidor* Estacion:: getSurtidores() const {return surtidores;}

//Setters
void Estacion::setNombre(std::string newNombre){
    //Validar formato del parametro
    if(newNombre.empty()){
        nombre = newNombre;
    }
    else{
        cout << "El nombre no puede estar vacio." << endl;
    }
}
void Estacion::setCodigoEstacion(std::string newCodigoEstacion){
    //Validar formato del parametro
    if(newCodigoEstacion.length() == 1){
        codigoEstacion = newCodigoEstacion;
    }
    else{
        cout << "El codigo de la estacion deber contener un solo caracter." << endl;
    }
}
void Estacion::setGerente(std::string newGerente){
    //Validar formato del parametro
    if (newGerente.length() == 10){
        gerente = newGerente;
    }
    else{
        cout << "El documento del gerente debe tener diez caracteres." << endl;
    }
}
void Estacion::setRegion(std::string newRegion){
    //Validar formato del parametro
    if(newRegion == "norte" || newRegion == "centro" || newRegion == "sur" ){
        region = newRegion;
    }
    else{
        cout << "La region debe ser 'norte', 'centro' o 'sur'." << endl;
    }
}
void Estacion::setCoordenadas(std::string newCoordenadas){
    //Validar formato del parametro
    coordenadas = newCoordenadas;
}
void Estacion::setSizeSurtidores(int newSizeSurtidores){
    //Validar formato del parametro
    if(newSizeSurtidores > 0){
        sizeSurtidores = newSizeSurtidores;
    }
    else{
        cout << "sizeSurtidores debe ser mayor a cero." << endl;
    }
}

//                  METODOS


void Estacion:: expandirSurtidores() {
    //Metodo publico para expandir el arreglo de surtidores
    // Crear un nuevo arreglo con una posición más
    capacidadSurtidores = capacidadSurtidores + 1;
    Surtidor* nuevoArr = new Surtidor[capacidadSurtidores];

    // Copiar elementos al nuevo arreglo
    for (int i = 0; i < sizeSurtidores; ++i) {
        nuevoArr[i] = surtidores[i];
    }

    // Liberar la memoria del arreglo original
    delete[] surtidores;

    // Actualizar el puntero para que apunte al nuevo arreglo
    surtidores = nuevoArr;
}



void Estacion::agregarSurtidor(string codigoEstacion) {
    //Metodo para agregar un surtidor
    //Verificamos que la estacion no tenga mas de doce surtidores
    int surtidoresEstacion = 0;
    string codigoSurtidores;
    for (int i = 0; i < sizeSurtidores; i++) {
        codigoSurtidores = (surtidores[i].getCodigoSurtidor())[0];
        if(codigoSurtidores == codigoEstacion){
            surtidoresEstacion++;
        }
    }
    if(surtidoresEstacion >= 12){
        cout << "No se pueden agregar mas surtidores. Se ha alcanzado el limite." << endl;
        return;
    }
    //Agregamos el surtidor
    string codigoNave, codigo, modelo;
    cout << "Ingrese el codigo de la nave a la cual pertenecera el surtidor: " << endl;
    cin >> codigoNave;
    int cod = surtidoresEstacion + 1;
    codigo = to_string(cod);
    string codigoSurtidor = codigoEstacion + "_" + codigoNave + "_" + codigo;
    //verificar codigo no repetido
    for(int i = 0; i < sizeSurtidores; i++ ){
        if(surtidores[i].getCodigoSurtidor() == codigoSurtidor){
            cout << "El surtidor " << codigoSurtidor << " ya existe" << endl;
            return;
        }
    }
    //Menu para seleccionar el modelo del surtidor
    int opcion;
    do{
        cout << "Seleccione el modelo del surtidor: " << endl;
        cout << "1. Modelo 1 " << endl;
        cout << "2. Modelo 2 " << endl;
        cout << "3. Modelo 3 " << endl;
        cin >> opcion;
        switch(opcion) {
        case 1:
            modelo = "modelo1";
            break;
        case 2:
            modelo = "modelo2";
            break;
        case 3:
            modelo = "modelo3";
            break;
        default:
            cout << "Opcion no valida. Por favor, intente nuevamente. " << endl;
            break;
        }
    } while((opcion < 1) || (opcion > 3));
    //agregar el surtidor
    agregarSurtidorLectura(codigo,modelo,true);
    cout << "Surtidor " << codigoSurtidor << " agregado exitosamente." << endl;
    system("pause");
}

void Estacion:: agregarSurtidorLectura(string codigo, string modelo, bool estado) {
    //Metodo para agregar un surtidor
    if(sizeSurtidores == 0){surtidores = new Surtidor[capacidadSurtidores];}
    else{
        if (sizeSurtidores == capacidadSurtidores) {
            expandirSurtidores();
        }
    }
    surtidores[sizeSurtidores] = Surtidor(codigo, modelo, estado);
    sizeSurtidores++;
}

void Estacion:: mostrarEstaciones(){cout << codigoEstacion << "->\t" << nombre << endl;}

string Estacion::obtenerCodigoSurtidor(string codigoEstacion){
    bool surtidorEstacion = false;
    //Encontrar surtidor en el arreglo
    string codigoSurtidores;
    for(int i = 0; i < sizeSurtidores; i++){
        codigoSurtidores = surtidores[i].getCodigoSurtidor()[0];
        if(codigoSurtidores == codigoEstacion){
            codigoSurtidores = surtidores[i].getCodigoSurtidor();
            cout << "Surtidores de la estacion: " << endl;
            cout << codigoSurtidores << endl;
            surtidorEstacion = true;
        }
    }
    if(surtidorEstacion == false){
        cout << "No hay surtidores en la estacion " << codigoEstacion << endl;
        return "";
    }
    string codigo;
    cout << "De los anteriores ingrese el codigo del surtidor que desea eliminar: " << endl;
    cin >> codigo;
    for(int i = 0; i < sizeSurtidores; i++){
        if(surtidores[i].getCodigoSurtidor() == codigo){
            return codigo;
        }
    }
    cout << "El surtidor " << codigo << " no existe." << endl;
    return "";
}

void Estacion:: eliminarSurtidor(string codigo) {
    //Metodo para eliminar un surtidor
    int posicion = -1;
    //Encontrar surtidor en el arreglo
    for(int i = 0; i < sizeSurtidores; i++){
        if(surtidores[i].getCodigoSurtidor() == codigo){
            posicion = i;
            break;
        }
    }
    if(posicion == -1){
        cout << "Surtidor " << codigo << " no existe." << endl;
        return;
    }

    //Inicializa el arreglo
    Surtidor* nuevoArregloSurtidores = new Surtidor[ sizeSurtidores - 1];
    //Copia los elementos hasta encontrar al surtidor
    for(int i = 0; i < posicion; i++){
        nuevoArregloSurtidores[i] = surtidores[i];
    }
    for(int j = posicion; j < sizeSurtidores - 1; j++){
        nuevoArregloSurtidores[j] = surtidores[j + 1];
    }
    //Elimina el arreglo antiguo
    delete[] surtidores;
    //Actualiza el arreglo
    surtidores = nuevoArregloSurtidores;
    //Actualiza el tamaño del arreglo
    sizeSurtidores--;
    cout << "Surtidor " << codigo << " eliminado con exito." << endl;
}

void Estacion:: eliminarSurtidoresNavesEstacion(bool eliminar, string codigo){
    //Metodo publico para eliminar una surtidores y naves asociados a una estacion.
    if(eliminar == false){
        cout <<"No se pueden eliminar los surtidores ni las naves de la estacion "<<codigo<<endl;
        system("pause");
        return;
    }
    else{
        //Eliminar surtidores.
        //contar codigos que inician por el codigo
        int menosSize = 0;
        string codigoSurtidor;
        for (int i = 0; i < sizeSurtidores; ++i) {
            codigoSurtidor = (surtidores[i].getCodigoSurtidor())[0];
            if(codigoSurtidor == codigo){menosSize++;}
        }
        Surtidor* nuevoArr = new Surtidor[sizeSurtidores - menosSize];
        //Copia los elementos hasta encontrar al surtidor
        for(int i = 0, j = 0; i < sizeSurtidores; i++){
            codigoSurtidor = (surtidores[i].getCodigoSurtidor())[0];
            if(codigoSurtidor != codigo){nuevoArr[j] = surtidores[i]; j++;}
        }
        //Elimina el arreglo antiguo
        delete[] surtidores;
        //Actualiza el arreglo
        surtidores = nuevoArr;
        //Actualiza el tamaño del arreglo
        sizeSurtidores = sizeSurtidores - menosSize;
        cout << "Estacion " << codigo << " eliminada con exito." << endl;

        //eliminar naves.
        string codNaves;
        for (int i = 0; i < navesActuales; ++i) {
            codNaves = naves[i][0];
            if (codNaves == codigo){naves[i] = "libre";}
        }
    }
}

void Estacion:: activarSurtidor(){
    // Metodo para activar un surtidor
    string codigo;
    cout << "Ingrese el codigo del surtidor que desea activar: " << endl;
    cin >> codigo;
    //Verifica si el codigo existe
    bool surtidorExiste = false;
    for(int i = 0; i < sizeSurtidores; i++){
        if(surtidores[i].getCodigoSurtidor() == codigo){
            surtidorExiste = true;
            //Verifica si esta desactivado
            if(!surtidores[i].getEstado()){
                surtidores[i].setEstado(true);
                cout << "Surtidor " << codigo << " ha sido activado con exito." << endl;
            }
            else{
                cout << "El surtidor " << codigo << " ya esta activo." << endl;
            }
            system("pause");
            break;
        }
    }
    if(!surtidorExiste){
        cout << "Surtidor " << codigo << " no existe." << endl;
        system("pause");
    }
}

void Estacion::desactivarSurtidor(){
    //Metodo para desactivar un surtidor
    string codigo;
    cout << "Ingrese el codigo del surtidor que desea activar: " << endl;
    cin >> codigo;
    //Verifica si el codigo existe
    bool surtidorExiste = false;
    for(int i = 0; i < sizeSurtidores; i++){
        if(surtidores[i].getCodigoSurtidor() == codigo){
            surtidorExiste = true;
            //Verifica si esta activo
            if(surtidores[i].getEstado()){
                surtidores[i].setEstado(false);
                cout << "Surtidor " << codigo << " ha sido activado con exito." << endl;
            }
            else{
                cout << "El surtidor " << codigo << " ya esta activo." << endl;
            }
            break;
        }
    }
    if(!surtidorExiste){
        cout << "Surtidor " << codigo << " no existe." << endl;
    }
}

void Estacion::consultarHistorico(Ventas* ventas, int sizeVentas, string estacion){
//metodo publico para imprimir por pantalla el historico de transacciones
    //Bandera para verificar si hay ventas en la estacion
    bool ventasEstacion = false;
    //Recorrer el arreglo de surtidores
    string codigoSurtidor;
    for(int i = 0; i < sizeSurtidores; i++){
        codigoSurtidor = (surtidores[i].getCodigoSurtidor())[0];
        //Verificar si hay surtidores asociados a la estacion
        if (codigoSurtidor == estacion){
            codigoSurtidor = surtidores[i].getCodigoSurtidor();
            string codVentas;
            for (int j = 0; j < sizeVentas; ++j) {
                codVentas = (ventas+j)->getCodigoVentas();
                if(codigoSurtidor == codVentas){
                    cout << "Historial de ventas de la estacion." << endl;
                    (ventas+j)->detallesVentas();
                    ventasEstacion = true;
                }
            }
        }
    }
    if(!ventasEstacion){
        cout << "No hay ventas registradas en la estacion." << endl;
        system("pause");
    }
}

void Estacion:: asignarCapacidadTanque(){
    // Asignar la capacidad del tanque de suministro, con un valor aleatorio entre
    //100 y 200 litros para cada una de las categorías

}



void Estacion:: simularVenta(){}

void Estacion::verificarFugas(Ventas* ventas, int sizeVentas,string estacion){
//Metodo para verificar fugas en la estacion dada
    int totalRegular = 0;
    int totalPremium = 0;
    int totalEcoextra = 0;
    //Bandera para verificar si hay ventas en la estacion
    bool ventasEstacion = false;
    string codigoSurtidores;
    for (int i = 0; i < sizeSurtidores; ++i) {
    codigoSurtidores = (surtidores[i].getCodigoSurtidor())[0];
        //Verifica si hay surtidores asociados a la estacion
        if(codigoSurtidores == estacion){
            for(int j = 0; j < sizeVentas; j++){
                //Verifica el codigo de la estacion con el del surtidor
                if(ventas[j].getCodigoVentas() == surtidores[i].getCodigoSurtidor()){
                    ventas[j].discriminarVentas(totalRegular,totalPremium,totalEcoextra);
                    ventasEstacion = true;
                }
            }
        }
    }
    if(!ventasEstacion){
        cout << "No hay ventas de combustible registradas en la estacion." << endl;
        system("pause");
        return;
    }
    string combustibles[3];
    combustibles[0] = "regular";
    combustibles[1] = "premium";
    combustibles[2] = "ecoextra";
    int capacidadesTanque[3];
    capacidadesTanque[0] = tanque.getCapacidadRegular();
    capacidadesTanque[1] = tanque.getCapacidadPremium();
    capacidadesTanque[2] = tanque.getCapacidadEcoextra();
    int disponible[3];
    disponible[0] = tanque.getDisponibleRegular();
    disponible[1] = tanque.getDisponiblePremium();
    disponible[2] = tanque.getDisponibleEcoexptra();
    int vendidos[3];
    vendidos[0] = totalRegular;
    vendidos[1] = totalPremium;
    vendidos[2] = totalEcoextra;
    for (int i = 0; i < 3; i++) {
        float suma = vendidos[i] + disponible[i];
        int porcentaje = (suma / (float)capacidadesTanque[i]) * 100;
        if (porcentaje < 95){
            cout << "Fuga detectada en la estacion " << estacion << endl;
            system("pause");
            return;
        }
        else{
            cout << "No se detecto fuga en la estacion " << estacion << endl;
            system("pause");
            return;
        }
    }
}

void Estacion:: expandirNaves() {
    //Metodo privado para expandir el arreglo de surtidores
    // Crear un nuevo arreglo con una posición más
    int nuevaCapacidad = capacidadNaves + 1;
    string* nuevoArr = new string[nuevaCapacidad];

    // Copiar elementos al nuevo arreglo
    for (int i = 0; i < navesActuales; ++i) {
        nuevoArr[i] = naves[i];
    }

    // Liberar la memoria del arreglo original
    delete[] naves;

    // Actualizar el puntero para que apunte al nuevo arreglo
    naves = nuevoArr;
    capacidadNaves = nuevaCapacidad;
}

void Estacion:: agregarNaveLectura(string codigo){
    //agrega los codios al arreglo de naves
    if(navesActuales == 0){naves = new string[capacidadNaves];}
    else{
        if (navesActuales == capacidadNaves) {
            expandirNaves();  // Si el arreglo está lleno, lo expandimos
        }
    }
    naves[navesActuales] = codigo;
    navesActuales++;
}

void Estacion:: mostrarNaves(){
    //mostar arreglo de naves
    for (int i = 0; i < navesActuales; ++i) {
        cout<<naves[i]<<endl;
    }
}

bool Estacion:: surtidoresInactivos(string codigoEstacion){
    //verificar si una estacion tiene surtidores inactivos
    string codSurtidor;
    bool estado;
    for (int i = 0; i < sizeSurtidores; ++i) {
        codSurtidor = (surtidores[i].getCodigoSurtidor())[0];
        if(codSurtidor == codigoEstacion){
            estado = surtidores[i].getEstado();
            if(estado){return false;}
        }
    }
    return true;
}



/*
Estacion::Estacion(int capacidadInicialSurtidores, const string& nombre, const string& codigoEstacion, const string& gerente, const string& region, const string& coordenadas)
    : nombre(nombre), codigoEstacion(codigoEstacion), gerente(gerente), region(region), coordenadas(coordenadas){
    //Constructor que inicializa el arreglo de surtidores
    numSurtidores = 0;
    capacidadSurtidores = capacidadInicialSurtidores;
    surtidores = new Surtidor*[capacidadSurtidores];
}
*/




