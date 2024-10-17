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
    Surtidor* nico = estacion.getSurtidores();
    int size = estacion.getsizeSurtidores();
    for (int i = 0; i < size; ++i) {
        nico[i].mostrarAtributos();
    }
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
                redNacional.fijarPrecios();
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
                {
                string codigo = redNacional.obtenerCodigoEstacion();
                Ventas* ventas6 = surtidor.getVentas();
                int size = surtidor.getSizeVentas();
                mostrarLitrosTotales(ventas6, size, codigo);
                }
                break;
            case 5: //Simulador de venta
                {
                string region = redNacional.obtenerRegionEstacion();
                //Estacion* Estacion5 = redNacional.getEstaciones();
                //int sizeEstaciones = redNacional.getSizetaciones();
                Surtidor* Surtidores4 = estacion.getSurtidores();
                int sizeSurtidores = estacion.getsizeSurtidores();
                Ventas* ventas5 = surtidor.getVentas();
                int sizeVentas = surtidor.getSizeVentas();
                simularVentas(Surtidores4, sizeSurtidores, ventas5, sizeVentas, &redNacional, region);
                }
                break;
            case 6: //Asignar capacidad de tanque
                {
                redNacional.asignarCapacidadTanque();
                }
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
