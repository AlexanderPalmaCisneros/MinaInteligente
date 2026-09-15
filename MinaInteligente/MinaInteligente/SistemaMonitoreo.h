#pragma once

using namespace System::Collections::Generic;

#include "NivelRiesgo.h"
#include "TipoRiesgo.h"
#include "ModoOperacion.h"

namespace MinaInteligente {

    ref class GrafoZonas;
    ref class Alarma;
    ref class Zona;

    public ref class SistemaMonitoreo
    {
    private:
        GrafoZonas^ grafoZonas;
        List<Alarma^>^ alarmasActivas;

    public:
        SistemaMonitoreo(GrafoZonas^ grafoZonas);

        void ActualizarCiclo();
        void EvaluarZona(Zona^ zona);
        Alarma^ GenerarAlarmaAutomatica(Zona^ zona, NivelRiesgo nivelRiesgo, TipoRiesgo tipoRiesgo);
        List<Alarma^>^ ObtenerAlarmasActivas();
        void CambiarModoOperacion(ModoOperacion modo);
    };
}
