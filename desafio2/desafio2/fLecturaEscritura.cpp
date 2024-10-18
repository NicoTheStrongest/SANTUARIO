#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time()

#include "fLecturaEscritura.h"
#include "class_RedNacional.h"
#include "class_Estacion.h"
#include "class_Surtidor.h"
#include "class_Tanque.h"
#include "class_Ventas.h"

void limpiarPantallaLectura(){
    // Imprime varias líneas en blanco para dar la ilusión de limpiar la pantalla
    for (int i = 0; i < 50; ++i) {
        cout << endl;
    }
}

void leerArchivoClases(RedNacional& redNacional, Estacion& estacion, Surtidor& surtidor, Tanque& tanque, Ventas& ventas){
    //Lectura del archivo de texto para guardar en los arreglo de las clases
    string nombreArchivo = "./../../simulacionBaseDatos.txt";
    fstream archivo(nombreArchivo, ios::in);
    if (!archivo.is_open()){
        cout << "Error al abrir el archivo\n";
        return;
    }

    string linea;

    while (getline(archivo, linea)){
        if (linea[0] == '-'){
            int sizeAux = 3;
            string arreglo[sizeAux];
            string lineaRegion = "";
            for(int i = 1, j = 0; i < (int)linea.size(); i++){
                if(linea[i] != ','){lineaRegion += linea[i];}
                else{arreglo[j] = lineaRegion; lineaRegion = ""; j++;}
            }
            arreglo[2] = lineaRegion;
            redNacional.agregarRegiones(arreglo);
        }
        else if(linea[0]>=48 && linea[0]<=57){
            string leerNombre = "";
            string leerCodigo = "";
            string leerGerente = "";
            string leerRegion = "";
            string leerCoordenadas = "";
            string lineaEstacion = "";
            for(int i = 0, j = 0; i < (int)linea.size(); i++){
                if(linea[i] != ','){lineaEstacion += linea[i];}
                else{
                    if(j == 0){leerCodigo = lineaEstacion; lineaEstacion = ""; j++;}
                    else if(j == 1){leerNombre = lineaEstacion; lineaEstacion = ""; j++;}
                    else if(j == 2){leerGerente = lineaEstacion; lineaEstacion = ""; j++;}
                    else if(j == 3){leerRegion = lineaEstacion; lineaEstacion = ""; j++;}
                }
            }
            leerCoordenadas = lineaEstacion;
            redNacional.agregarEstacionLectura(leerNombre, leerCodigo, leerGerente, leerRegion, leerCoordenadas);
        }
        else if(linea[0] == 'n'){
            string lineaNaves = "";
            for(int i = 1; i < (int)linea.size(); i++){
                if(linea[i] != ','){lineaNaves += linea[i];}
                else{
                    estacion.agregarNaveLectura(lineaNaves);
                    lineaNaves = "";
                    i++;
                }
            }
            estacion.agregarNaveLectura(lineaNaves);
        }
        else if(linea[0] == 's'){
            string lineaNaves = "";
            int sizeAux = 3;
            string arregloAux[sizeAux];
            for(int i = 1, j = 0; i < (int)linea.size(); i++){
                if(linea[i] != ','){lineaNaves += linea[i];}
                else{arregloAux[j] = lineaNaves; lineaNaves = ""; j++;}
            }
            bool estado = false;
            if(lineaNaves == "activo"){
                estado = true;
            }
            else{
                estado = false;
            }
            estacion.agregarSurtidorLectura(arregloAux[0], arregloAux[1], estado);
        }
    }
    //Lectura del archivo de texto para guardar en los arreglo de las clases
    string nombreArchivoVentas = "./../../ventas.txt";
    fstream archivo2(nombreArchivoVentas, ios::in);
    if (!archivo2.is_open()){
        cout << "Error al abrir el archivo\n";
        return;
    }

    string lineaVentas, prueba;

    while(getline(archivo2, lineaVentas)){
        string transaccion = "";
        string codigoVentas, tipoCombustible, fechaHora, litros, metodoPago, docCliente;
        for (int i = 1, j = 0; i < (int)lineaVentas.size(); ++i) {
            prueba = lineaVentas[i];
            if(prueba != ","){transaccion += lineaVentas[i];}
            else{
                if(j == 0){codigoVentas = transaccion; transaccion = ""; j++;}
                else if(j == 1){tipoCombustible = transaccion; transaccion = ""; j++;}
                else if(j == 2){fechaHora = transaccion; transaccion = ""; j++;}
                else if(j == 3){litros = transaccion; transaccion = ""; j++;}
                else if(j == 4){metodoPago = transaccion; transaccion = ""; j++;}
                else if(j == 5){docCliente = transaccion; transaccion = ""; j++;}
            }
        }
        int monto = stoi(transaccion);
        int litrosVendidos = stoi(litros);
        surtidor.agregarVentaLectura(codigoVentas, tipoCombustible, fechaHora, litrosVendidos, metodoPago, docCliente, monto);
        Estacion* aux = redNacional.getEstaciones();
        int sizeAux = redNacional.getSizetaciones();
        for (int i = 0; i < sizeAux; ++i) {
            if(aux[i].getcodigoEstacion() == to_string(codigoVentas[0])){
                aux[i].disminuirTanque(tipoCombustible, litrosVendidos);
            }
        }
    }
}

void mostrarMontoTotal(Estacion* ptrEstacion, int sizeEstacion, Ventas* ptrVentas, int sizeVentas){
    //mostrar monto total de ventas por cada estacion, separando por categoria de combustible.
    int montoPremium = 0;
    int montoRegular = 0;
    int montoEcoextra = 0;
    limpiarPantallaLectura();
    cout<<"**********MONTO TOTAL DE VENTAS POR ESTACION**********"<<endl<<endl;
    string cod1, cod2;
    for (int i = 0; i < sizeEstacion; ++i) {
        (ptrEstacion+i)->mostrarEstaciones();
        cod2 = (ptrEstacion+i)->getcodigoEstacion();
        for (int j = 0; j < sizeVentas; ++j) {
            cod1 = ((ptrVentas+j)->getCodigoVentas());
            cod1 = cod1[0];
            if(cod1 == cod2){
                if((ptrVentas+j)->getTipoCombustible() == "premium"){montoPremium += (ptrVentas+j)->getMonto();}
                if((ptrVentas+j)->getTipoCombustible() == "regular"){montoRegular += (ptrVentas+j)->getMonto();}
                if((ptrVentas+j)->getTipoCombustible() == "ecoextra"){montoEcoextra += (ptrVentas+j)->getMonto();}
            }
        }
        cout<<"Premium: "<<montoPremium<<endl;
        cout<<"Regular: "<<montoRegular<<endl;
        cout<<"Ecoextra: "<<montoEcoextra<<endl<<endl<<endl;
        montoPremium = 0;
        montoRegular = 0;
        montoEcoextra = 0;
    }
    system("pause");
}

void mostrarLitrosTotales(Ventas* ventas6, int size, string codigo){
    //Mostrar litros por categoria de combustible dada una estacion.
    int litrosPremium = 0;
    int litrosRegular = 0;
    int litrosEcoextra = 0;
    limpiarPantallaLectura();
    cout<<"**********LITROS TOTALES VENDIDOS POR ESTACION**********"<<endl<<endl;
    string cod1;
    for (int i = 0; i < size; ++i) {
        cod1 = (ventas6+i)->getCodigoVentas()[0];
        if(cod1 == codigo){
            if((ventas6+i)->getTipoCombustible() == "premium"){litrosPremium += (ventas6+i)->getCantidadCombustible();}
            if((ventas6+i)->getTipoCombustible() == "regular"){litrosRegular += (ventas6+i)->getCantidadCombustible();}
            if((ventas6+i)->getTipoCombustible() == "ecoextra"){litrosEcoextra += (ventas6+i)->getCantidadCombustible();}
        }
    }
    cout<<"Premium: "<<litrosPremium<<endl;
    cout<<"Regular: "<<litrosRegular<<endl;
    cout<<"Ecoextra: "<<litrosEcoextra<<endl<<endl;
    system("pause");
}

void simularVentas(Surtidor* surtidores, int sizeSurtidores, Ventas* ventas, int sizeVentas, RedNacional* redNacional, string region, string codEstacion, Estacion* ptrEstaciones, int sizeEstaciones){
    //Simula la venta dada una estacion, escogiendo surtidor aleatorio y pudiendo los datos necesarios
    //surtidores activos
    int activos = 0;
    bool estado = false;
    for (int i = 0; i < sizeSurtidores; i++) {
        estado = surtidores[i].getEstado();
        if (estado == true && surtidores[i].getCodigoSurtidor()[0] == '1') {
            activos++;
        }
    }
    if(activos>0){
        //asignar surtidor aleatorio
        srand(static_cast<unsigned int>(time(0)));
        int surtidor =  1 + rand() % activos;
        for (int i = 0; i < sizeSurtidores; ++i) {
            if((i == surtidor) && (surtidores[i].getEstado() == true)){
                string codigoVenta = surtidores[i].getCodigoSurtidor();
                int litros = rand() % (20 - 3 + 1) + 3;
                string docCliente;
                cout<<"Ingrese el documento del cliente: ";
                //cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, docCliente);
                formatoDocumento(&docCliente);
                string tipoCombustible;
                int combustible;
                string mensaje = "Ingrese el tipo de combustible: \n"
                    "1 -> Premium\n"
                    "2 -> Regular\n"
                    "3 -> Ecoextra\n";
                cout<<mensaje<<endl<<"Escoja una opcion: ";
                cin>>combustible;
                while(combustible != 1 && combustible != 2 && combustible != 3){
                    cout<<"**********Opcion invalida**********";
                    cout<<mensaje<<endl<<"Escoja una opcion: ";
                    cin>>combustible;
                }
                int montoPago;
                if(combustible == 1){tipoCombustible = "Premium"; montoPago = redNacional->calcularMontoPago("Premium", litros, region);}
                else if(combustible == 2){tipoCombustible = "Regular"; montoPago = redNacional->calcularMontoPago("Regular", litros, region);}
                else if(combustible == 3){tipoCombustible = "Ecoextra"; montoPago = redNacional->calcularMontoPago("Ecoextra", litros, region);}
                mensaje = "Metodo de pago: \n"
                    "1 -> Efectivo\n"
                    "2 -> Tarjeta Debito\n"
                    "3 -> Tarjeta Credito\n";
                string metodoPago;
                int numMetodoPago;
                cout<<mensaje<<endl<<"Escoja una opcion: ";
                cin>>numMetodoPago;
                while(numMetodoPago != 1 && numMetodoPago != 2 && numMetodoPago != 3){
                    cout<<"**********Opcion invalida**********";
                    cout<<mensaje<<endl<<"Escoja una opcion: ";
                    cin>>numMetodoPago;
                }
                if(combustible == 1){metodoPago = "Efectivo";}
                else if(combustible == 2){metodoPago = "Tarjeta Debito";}
                else if(combustible == 3){metodoPago = "Tarjeta Credito";}
                string fechaHora = calcularFechaHoraSimulador();
                mostrarTransaccion(codigoVenta, tipoCombustible, fechaHora, metodoPago, docCliente, montoPago, litros);
                cout<<endl;
                for (int i = 0; i < sizeSurtidores; ++i) {
                    if(surtidores[i].getCodigoSurtidor() == codigoVenta){
                        surtidores[i].agregarVentaLectura(codigoVenta, tipoCombustible, fechaHora, litros, metodoPago, docCliente, montoPago);
                        for (int j = 0; j < sizeEstaciones; ++j) {
                            if(to_string((ptrEstaciones+j)->getcodigoEstacion()[0]) == codEstacion){
                                (ptrEstaciones+j)->disminuirTanque(tipoCombustible, litros);
                            }
                        }
                    }
                }
                system("pause");
            }
        }
    }
    else{
        limpiarPantalla();
        cout<<"**********No hay surtidores Activos**********\n";
        system("pause");
    }
}

string calcularFechaHoraSimulador(){
    //funcion que retorna la fecha y hora en el formato deseado
    time_t tiempoActual = time(nullptr);
    tm* tiempoLocal = localtime(&tiempoActual);
    char fechaHora[20];
    strftime(fechaHora, sizeof(fechaHora), "%Y-%m-%d %H:%M:%S", tiempoLocal);
    return string(fechaHora);
}

void mostrarTransaccion(string codigoVenta, string tipoCombustible, string fechaHora, string metodoPago, string docCliente, int montoPago, int litros){
    limpiarPantalla();
    cout<<"************* INFORME DE TRANSACCION *************"<<endl<<endl;
    cout<<"Codigo de venta:\t"<<codigoVenta<<endl;
    cout<<"Tipo de combustible:\t"<<tipoCombustible<<endl;
    cout<<"Metodo de pago:  \t"<<metodoPago<<endl;
    cout<<"Documento Cliente:\t"<<docCliente<<endl;
    cout<<"Monto total a pagar:\t"<<montoPago<<endl;
    cout<<"Litros vendidos: \t"<<litros<<endl;
    cout<<endl<<"Fecha: "<<fechaHora<<endl;
}

bool validarNumeros(string cadena){
    //valida que una cadena solo contenga numeros
    for (int i = 0; i < (int)cadena.size(); ++i) {
        if (!(cadena[i]>=48  && cadena[i]<=57)){return false;}
    }
    return true;
}

void formatoDocumento(string* documento){
    //Valida que una cadena solo tengo numero y que tengo size 10;
    string documento2;
    bool docValido = validarNumeros(*documento);
    int size = (int)(*documento).size();
    if (size != 10){docValido = false;}
    while (docValido == false){
        cout<<"Documento Invalido\n";
        cout<<"Documento: ";
        getline(cin, documento2);
        docValido = validarNumeros(documento2);
        if ((int)documento2.size() != 10){docValido = false;}
        if (docValido == true){*documento = documento2;}
    }
}

















