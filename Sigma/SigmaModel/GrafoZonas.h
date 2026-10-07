#pragma once

using namespace System::Collections::Generic;

namespace SigmaModel {

    ref class Zona;
    ref class Trabajador;

    public ref class GrafoZonas
    {
    private:
        List<Zona^>^ zonas;

    public:
        GrafoZonas();

        void AgregarZona(Zona^ zona);
        List<Zona^>^ ObtenerRutaEscape(Zona^ origen);
        List<Zona^>^ ObtenerZonas();

        bool EvaluarRiesgoAislamiento(Trabajador^ trabajador, Zona^ zonaActual);

        void PropagarRiesgoIndirecto(Zona^ zonaOrigen);
    };
}
