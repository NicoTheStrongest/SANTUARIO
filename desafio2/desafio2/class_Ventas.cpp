#include <iostream>
#include <class_Ventas.h>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;


    //Constructor
    //Destructor
    //Getters, Setters
    //metodos
    string fechaHora(){
        //funcion que retorna la fecha y hora en el formato deseado
        time_t tiempoActual = time(nullptr);
        tm* tiempoLocal = localtime(&tiempoActual);
        char fechaHora[20];
        strftime(fechaHora, sizeof(fechaHora), "%Y-%m-%d %H:%M:%S", tiempoLocal);
        return string(fechaHora);





