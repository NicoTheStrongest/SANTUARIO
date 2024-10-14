#include <iostream>
#include <fstream>
#include <string>

#include "funcionesGenerales.h"

using namespace std;

//          Funciones de Red


void agregarEstacion(){
    //agregar una estacion al arreglo de Red nacional
    string nombre, documento, codigo, region, gps;
    int cod;
    cout<<"Ingrese nombre de la estacion: ";
    getline(cin, nombre);

    cout<<"Ingrese documento del gerente de la estacion: ";
    getline(cin, documento);
    formatoDocumento(&documento);

    string prints;
    prints = "./../../prints/MenuRegion.txt";
    leerArchivoPorLinea(prints);
    string mensaje1 = "Escoja un opcion: ";
    string mensaje2 = "Opción no valida, intenta de nuevo.";
    const int size = 3;
    string opcionesValidas[size] = {"1", "2", "3"};
    int opcionElegida = opcionesMenuGeneral(mensaje1, mensaje2, opcionesValidas, size);
    if(opcionElegida == 1){region = "Norte";}
    if(opcionElegida == 2){region = "Centro";}
    if(opcionElegida == 3){region = "Sur";}

    cout<<"Ingrese las coordenadas de la estacion: ";
    getline(cin, gps);

    //RedNacional::codEstacion += 1;
    //cod = RedNacional::codEstacion;
    //codigo = "s"+(to_string(cod));

    //RedNacional.agregarEstacion(nombre, codigo, documento, region, gps);
}











void formatoDocumento(string* documento){
    //Valida que una cadena solo tengo numero y que tengo size 10;
    string documento2;
    bool docValido = validarNumeros(*documento);
    if ((int)(*documento).size() != 10){docValido = false;}
    while (docValido == false){
        cout<<"Formato Invalido\n";
        cout<<"Ingrese documento del gerente de la estacion: ";
        getline(cin, documento2);
        docValido = validarNumeros(documento2);
        if ((int)documento2.size() != 10){docValido = false;}
        if (docValido == true){*documento = documento2;}
    }
}




//              Menu y funciones de interfaz

void leerArchivoPorLinea(const string& fileName) {
    // Función que abre un archivo, lo imprime y lo cierra
    ifstream archivo(fileName);

    // Comprobar si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo " << fileName << endl;
        return;
    }

    // Leer el archivo línea por línea y mostrar el contenido
    string linea;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    // Cerrar el archivo
    archivo.close();
}

int opcionesMenuGeneral(const string& mensaje1, const string& mensaje2, const string opcionesValidas[], int size) {
    string opcion;
    // Bucle infinito hasta que se reciba una opción válida
    while (true) {
        cout << mensaje1;
        cin >> opcion;
        // Verificar si la opción ingresada está en el arreglo de opciones válidas
        bool esValida = false;
        for (int i = 0; i < size; ++i) {
            if (opcionesValidas[i] == opcion) {
                esValida = true;
                break;
            }
        }
        // Si la opción es válida, convertirla a entero y retornarla
        if (esValida) {
            return stoi(opcion);  // Convertir la opción válida a entero y retornarla
        } else {
            cout << mensaje2 << endl;  // Mensaje de opción incorrecta
        }
    }
}

bool menuSalida(){
    //muestra menu salida y devulve false si quiere salir y true si quiere ir al menu unicial
    limpiarPantalla();
    string nombre = "./../../prints/MenuSalida.txt";
    leerArchivoPorLinea(nombre);
    string mensaje1 = "Elige una opcion (1, 2): ";
    string mensaje2 = "Opción no valida, intenta de nuevo.";
    const int size = 2;
    string opcionesValidas[size] = {"1", "2"};
    int opcionElegida = opcionesMenuGeneral(mensaje1, mensaje2, opcionesValidas, size);
    if(opcionElegida == 1){return false;}
    else if (opcionElegida == 2){return true;}
}

void mensajeSalida(){
    //Imprime el mensaje cuando sale del programa.
    limpiarPantalla();
    string prints = "./../../prints/MensajeSalida.txt";
    leerArchivoPorLinea(prints);
}

int menuGestionDeRed(){
    //retorna int asociado a la funcionalidad de gestion de red a realizar
    limpiarPantalla();
    string prints;
    prints = "./../../prints/MenuGestionDeRed.txt";
    leerArchivoPorLinea(prints);
    string mensaje1 = "Escoja un opcion: ";
    string mensaje2 = "Opción no valida, intenta de nuevo.";
    const int size = 5;
    string opcionesValidas[size] = {"1", "2", "3", "4", "0"};
    int opcionElegida = opcionesMenuGeneral(mensaje1, mensaje2, opcionesValidas, size);
    return opcionElegida;
}

int menuGestionEstaciones(){
    //retorna int asociado a la funcionalidad de gestion de Estacion a realizar
    limpiarPantalla();
    string prints;
    prints = "./../../prints/MenuGestionDeEstaciones.txt";
    leerArchivoPorLinea(prints);
    string mensaje1 = "Escoja un opcion: ";
    string mensaje2 = "Opción no valida, intenta de nuevo.";
    const int size = 8;
    string opcionesValidas[size] = {"1", "2", "3", "4", "5", "6", "7", "0"};
    int opcionElegida = opcionesMenuGeneral(mensaje1, mensaje2, opcionesValidas, size);
    return opcionElegida;
}

void limpiarPantalla(){
    // Imprime varias líneas en blanco para dar la ilusión de limpiar la pantalla
    for (int i = 0; i < 50; ++i) {
        cout << endl;
    }
}

int inicioSesion(){
    //Iniciar sesion comparando el codigo del gerente gerente

    //imprimir mesaje de bienvenida.
    limpiarPantalla();
    string prints = "./../../prints/MenuBienvenida.txt";
    leerArchivoPorLinea(prints);

    //funcionalidad aparte --> verificar gerente.

    //menu de regiones
    prints = "./../../prints/MenuPrincipal.txt";
    leerArchivoPorLinea(prints);
    string mensaje1 = "Escoja un opcion: ";
    string mensaje2 = "Opción no valida, intenta de nuevo.";
    const int size = 6;
    string opcionesValidas[size] = {"1", "2", "3", "0"};
    int opcionElegida = opcionesMenuGeneral(mensaje1, mensaje2, opcionesValidas, size);
    return opcionElegida;
}

bool validarNumeros(string cadena){
    //valida que una cadena solo contenga numeros
    for (int i = 0; i < (int)cadena.size(); ++i) {
        if (!(cadena[i]>=48  && cadena[i]<=57)){return false;}
    }
    return true;
}

void leerArchivoClases(){
    //Lectura del archivo de texto para guardar en los arreglo de las clases
    string nombreArchivo = "./../../simulacionBaseDatos.txt";
    fstream archivo(nombreArchivo, ios::in);
    if (!archivo.is_open()){
        cout << "Error al abrir el archivo\n";
        return;
    }

    string linea;

    while (getline(archivo, linea)){
        RedNacional jerarquiaSuperior;
        Estacion leerNaves;
        Surtidor leerCodigos;
        if (linea[0] == '-'){
            int sizeAux = 3;
            string arreglo[sizeAux];
            string lineaRegion = "";
            for(int i = 1, j = 0; i < (int)linea.size(); i++){
                if(linea[i] != ','){lineaRegion += linea[i];}
                else{arreglo[j] = lineaRegion; lineaRegion = ""; j++;}
            }
            arreglo[2] = lineaRegion;
            RedNacional arregloRegiones(arreglo, sizeAux);
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
            jerarquiaSuperior.agregarEstacion(leerNombre, leerCodigo, leerGerente, leerRegion, leerCoordenadas);
        }
        else if(linea[0] == 'n'){
            string lineaNaves = "";
            bool nave = true;
            for(int i = 0; i < (int)linea.size(); i++){
                if(linea[i] != ','){lineaNaves += linea[i];}
                else{
                    if(nave){
                        leerNaves.agregarNave(lineaNaves);
                        leerCodigos.agregarCodSurtidores(lineaNaves);
                        lineaNaves = "";
                        nave = false;
                    }
                    else{
                        leerCodigos.agregarCodSurtidores(lineaNaves);
                        lineaNaves = "";
                    }
                }
            }
            leerCodigos.agregarCodSurtidores(lineaNaves);
        }
        else if(linea[0] == 's'){
            for(int i = 0; i < (int)linea.size(); i++){

            }
        }
    }
}






















