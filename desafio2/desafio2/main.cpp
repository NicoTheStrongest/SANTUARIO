#include <iostream>
#include "funcionesGenerales.h"
#include "class_RedNacional.h"
#include "class_Estacion.h"
#include "class_Surtidor.h"
#include "class_Tanque.h"
#include "class_Ventas.h"

using namespace std;

int main(){
    RedNacional redNacional;
    Estacion estacion;
    Surtidor surtidor;
    Tanque tanque;
    Ventas ventas;
    leerArchivoClases(redNacional, estacion, surtidor, tanque, ventas);
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
                {
                estacion.agregarSurtidor();
                }
                break;
            case 2: //Eliminar surtidor
                {
                string codigo = estacion.obtenerCodigosurtidor();
                estacion.eliminarSurtidor(codigo);
                surtidor.eliminarVentaSurtidor(codigo);
                }
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

/* para imprimir
for (int i = 0; i < sizeEstaciones; ++i) {
    estaciones[i].mostrarEstaciones();
}
*/
