#pragma once

using namespace System;
using namespace System::Collections::Generic;

namespace MinaInteligente {

    ref class Trabajador;
    ref class RegistroExposicion;
    ref class RecomendacionTurno;

    public ref class HistorialExposicion
    {
    private:
        Trabajador^ trabajador;
        List<RegistroExposicion^>^ registros;

    public:
        HistorialExposicion(Trabajador^ trabajador);

        void AgregarRegistro(RegistroExposicion^ registro);
        double ObtenerExposicionDiaria(DateTime fecha);
        double ObtenerExposicionTotal();
        RecomendacionTurno^ GenerarRecomendacion();
    };
}
