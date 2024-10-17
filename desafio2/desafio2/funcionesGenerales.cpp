#include <iostream>
#include <fstream>
#include <string>

#include "funcionesGenerales.h"

using namespace std;

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
    const int size = 10;
    string opcionesValidas[size] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};
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




















