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
    leerArchivoClases(redNacional, estacion, surtidor);
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
                limpiarPantalla();
                string codigoEstacion1 = redNacional.obtenerCodigoEstacion();
                estacion.agregarSurtidor(codigoEstacion1);
                }
                break;
            case 2: //Eliminar surtidor
                {
                limpiarPantalla();
                string codigo_Estacion = redNacional.obtenerCodigoEstacion();
                string codigo = estacion.obtenerCodigoSurtidor(codigo_Estacion);
                estacion.eliminarSurtidor(codigo);
                surtidor.eliminarVentaSurtidor(codigo);
                }
                break;
            case 3: //Activar surtidor
                {
                limpiarPantalla();
                string codigo_Estacion = redNacional.obtenerCodigoEstacion();
                string codigo = estacion.obtenerCodigoSurtidor(codigo_Estacion);
                estacion.activarSurtidor(codigo);
                }
                break;
            case 4: //Desactivar surtidor
                {
                limpiarPantalla();
                string codigo_Estacion = redNacional.obtenerCodigoEstacion();
                string codigo = estacion.obtenerCodigoSurtidor(codigo_Estacion);
                estacion.desactivarSurtidor(codigo);
                }
                break;
            case 5: //Consultar Historico de transacciones
                {
                limpiarPantalla();
                Ventas* ventas5 = surtidor.getVentas();
                int sizeVentas = surtidor.getSizeVentas();
                string codigo_Estacion = redNacional.elegirEstacion();
                estacion.consultarHistorico(ventas5, sizeVentas, codigo_Estacion);
                }
                break;
            case 6: //Reporte de litros vendidos
                {
                limpiarPantalla();
                string codigo = redNacional.obtenerCodigoEstacion();
                Ventas* ventas6 = surtidor.getVentas();
                int size = surtidor.getSizeVentas();
                mostrarLitrosTotales(ventas6, size, codigo);
                }
                break;
            case 7: //Simulador de venta
                {
                limpiarPantalla();
                string codigo;
                string region = redNacional.obtenerRegionEstacion(&codigo);
                Surtidor* Surtidores4 = estacion.getSurtidores();
                int sizeSurtidores = estacion.getsizeSurtidores();
                Estacion* estaciones7 = redNacional.getEstaciones();
                int sizeEstaciones = redNacional.getSizetaciones();
                simularVentas(Surtidores4, sizeSurtidores, &redNacional, region, codigo, estaciones7, sizeEstaciones);
                }
                break;
            case 8://Asignar capacidad de tanques
                {
                limpiarPantalla();
                redNacional.asignarCapacidadTanque();
                }
                break;
            case 9://Sistema nacional de fugas
                {
                limpiarPantalla();
                string codigo_Estacion = redNacional.obtenerCodigoEstacion();
                Ventas* ventas7 = surtidor.getVentas();
                int sizeVentas = surtidor.getSizeVentas();
                estacion.verificarFugas(ventas7, sizeVentas, codigo_Estacion);
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
    //GUARDAR CAMBIOS***
    mensajeSalida();
}


//          Comentarios Utiles para imprimir
/*
Estacion* nico = redNacional.getEstaciones();
int size = redNacional.getSizetaciones();
for (int i = 0; i < size; ++i) {
    nico[i].mostrarEstaciones();
}

for (int i = 0; i < sizeEstaciones; ++i) {
    estaciones[i].mostrarEstaciones();
}
*/
