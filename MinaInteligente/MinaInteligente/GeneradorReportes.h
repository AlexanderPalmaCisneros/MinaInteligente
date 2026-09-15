#pragma once

using namespace System;

namespace MinaInteligente {

    ref class Trabajador;
    ref class Zona;

    // Seccion 3.9: consume HistorialExposicion, Alarma y el historial de Ventilador/RecomendacionTurno.
    public ref class GeneradorReportes
    {
    public:
        void GenerarReporteExposicion(Trabajador^ trabajador, DateTime fecha);
        void GenerarReporteAlarmas();
        void GenerarReporteVentilador(Zona^ zona);
        void GenerarReporteRecomendaciones();
    };
}
