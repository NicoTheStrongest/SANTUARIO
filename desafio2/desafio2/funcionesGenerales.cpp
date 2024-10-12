#include <iostream>
#include <funcionesGenerales.h>
#include <fstream>
#include <string>

using namespace std;


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
    Le(prints);
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

