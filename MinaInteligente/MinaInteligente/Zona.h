#pragma once

using namespace System;
using namespace System::Collections::Generic;

#include "TipoRiesgo.h"

namespace MinaInteligente {

    ref class Dispositivo;
    ref class Ventilador;
    ref class SensorGas;

    public ref class Zona
    {
    private:
        String^ id;
        String^ nombre;
        double volumen;
        List<Dispositivo^>^ dispositivos;
        List<Zona^>^ conexiones;

        // Valor autoritativo del entorno de la zona. Ya no se calcula con formula propia:
        // ActualizarConcentracion() lo sincroniza directamente desde el SensorGas de la zona.
        double concentracionActual;
        bool esZonaSalida;

    public:
        Zona(String^ id, String^ nombre, double volumen);

        // Ya no aplica formula matematica. Simplemente refleja la lectura del sensor de gas:
        // concentracionActual = ObtenerSensorGas()->GetLecturaActual(). La formula de la
        // seccion 4.1 (decaimiento/generacion) vive ahora en FuenteDatosSimulada, que es
        // quien la necesita cuando no hay sensor fisico real.
        void ActualizarConcentracion();

        TipoRiesgo EvaluarRiesgoDirecto();
        void AgregarDispositivo(Dispositivo^ dispositivo);
        void ConectarCon(Zona^ destino);
        Ventilador^ ObtenerVentilador();
        SensorGas^ ObtenerSensorGas();

        // Getter necesario para que FuenteDatosSimulada pueda calcular Q/V (formula 4.1).
        double GetVolumen();
    };
}
