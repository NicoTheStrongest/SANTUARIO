#include <iostream>
#include <fstream>
#include <string>

#include "fLecturaEscritura.h"
#include "class_RedNacional.h"
#include "class_Estacion.h"
#include "class_Surtidor.h"
#include "class_Tanque.h"
#include "class_Ventas.h"

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
            if(lineaNaves == "activo"){estado = true;}
            else{estado = false;}
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
    }
}

void mostrarMontoTotal(Estacion* ptrEstacion, int sizeEstacion, Ventas* ptrVentas, int sizeVentas){
    //mostrar monto total de ventas por cada estacion, separando por categoria de combustible.
    int montoPremium = 0;
    int montoRegular = 0;
    int montoEcoextra = 0;
    cout<<endl<<endl;
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
        cout<<"Ecoextra: "<<montoEcoextra<<endl<<endl;
        montoPremium = 0;
        montoRegular = 0;
        montoEcoextra = 0;
    }
    system("pause");
}













