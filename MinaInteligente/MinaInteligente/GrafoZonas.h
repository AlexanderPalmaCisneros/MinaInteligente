#pragma once

using namespace System::Collections::Generic;

namespace MinaInteligente {

    ref class Zona;
    ref class Trabajador;

    // Encapsula la topologia de la mina como grafo dirigido de zonas (seccion 3.2/8).
    public ref class GrafoZonas
    {
    private:
        List<Zona^>^ zonas;

    public:
        GrafoZonas();

        void AgregarZona(Zona^ zona);
        List<Zona^>^ ObtenerRutaEscape(Zona^ origen);

        // Seccion 3.2: riesgo de aislamiento por zona intermedia en riesgo en la ruta de escape.
        bool EvaluarRiesgoAislamiento(Trabajador^ trabajador, Zona^ zonaActual);
    };
}
