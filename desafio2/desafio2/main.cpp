#include <iostream>
#include "class_Estacion.h"
#include "class_RedNacional.h"
#include "class_Surtidor.h"
#include "class_Tanque.h"
#include "class_Ventas.h"
#include "funcionesGenerales.h"

using namespace std;

/*
archivo base de datos general
archivo historico de ventas
*/

int main(){
    bool sesionActiva = true;
    while(sesionActiva == true){
        int inicioValido = inicioSesion();
        switch (inicioValido) {
        case 1: {
            //Gestion de red
            int opcionGestionRed = menuGestionDeRed();
            switch (opcionGestionRed) {
            case 1: //Agregar estacion
                break;
            case 2: //Eliminar estacion
                break;
            case 3: //Mostrar monto total de venta (por estacion y por categoria de combustible)
                break;
            case 4: //Fijar precios de combustible
                break;
            case 0: //Salir
                sesionActiva = false;
                break;
            default:
                break;
            }
            break;
        }
        case 2: {
            //Gestion de estaciones
            int opcionGestionEstaciones = menuGestionEstaciones();
            switch (opcionGestionEstaciones) {
            case 1: //Agregar surtidor
                break;
            case 2: //Eliminar surtidor
                break;
            case 3: //Consultar Historico de transacciones
                break;
            case 4: //Reporte de litros vendidos
                break;
            case 5: //Simulador de venta
                break;
            case 6: //Asignar capacidad de tanques
                break;
            case 7: //Sistema nacional de fugas
                break;
            case 0: //Salir
                sesionActiva = false;
                break;
            default:
                break;
            }
            break;
        }
        case 0: {
            //Salir
            sesionActiva = false;
            break;
        }
        default: {
            break;
        }
        }
    }
    //guardar cambios?
    mensajeSalida();
}
