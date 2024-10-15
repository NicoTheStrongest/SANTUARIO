#include <iostream>

#include "fLecturaEscritura.h"
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
                {
                redNacional.agregarEstacion();
                }
                break;
            case 2: //Eliminar estacion
                {
                string codigo = redNacional.obtenerCodigoEstacion();
                bool eliminar = estacion.surtidoresInactivos(codigo);
                redNacional.eliminarEstacion(eliminar, codigo);
                estacion.eliminarSurtidoresNavesEstacion(eliminar, codigo);
                //surtidor.eliminarVentasEstacion(eliminar, codigo);
                }
                break;
            case 3: //Mostrar monto total de venta (por estacion y por categoria de combustible)
                {
                Estacion* ptrEstacion = redNacional.getEstaciones();
                int sizeEstacion = redNacional.getSizetaciones();
                Ventas* ptrVentas = surtidor.getVentas();
                int sizeVentas = surtidor.getSizeVentas();
                mostrarMontoTotal(ptrEstacion, sizeEstacion, ptrVentas, sizeVentas);
                }
                break;
            case 4: //Fijar precios de combustible
                {
                //
                }
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
                // {
                // estacion.agregarSurtidor();
                // }
                break;
            case 2: //Eliminar surtidor
                // {
                // string codigo = estacion.obtenerCodigoSurtidor();
                // estacion.eliminarSurtidor(codigo);
                // surtidor.eliminarVentaSurtidor(codigo);
                // }
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
    system("pause");
    //guardar cambios?
    mensajeSalida();
}

/*
Estacion* nico = redNacional.getEstaciones();
int size = redNacional.getSizetaciones();
for (int i = 0; i < size; ++i) {
    nico[i].mostrarEstaciones();
}
*/

/* para imprimir
for (int i = 0; i < sizeEstaciones; ++i) {
    estaciones[i].mostrarEstaciones();
}
*/
