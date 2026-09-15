#pragma once

using namespace System;

#include "NivelRiesgo.h"
#include "TipoRiesgo.h"
#include "OrigenAlarma.h"

namespace MinaInteligente {

    ref class Zona;
    ref class Supervisor;

    // activadaPor solo aplica cuando origen = MANUAL.
    public ref class Alarma
    {
    private:
        String^ id;
        DateTime fecha;
        DateTime hora;
        Zona^ zona;
        String^ causa;
        double concentracionRegistrada;
        NivelRiesgo nivelRiesgo;
        TipoRiesgo tipoRiesgo;
        OrigenAlarma origen;
        Supervisor^ activadaPor;

    public:
        Alarma(Zona^ zona, TipoRiesgo tipoRiesgo, String^ causa, double concentracionRegistrada,
            NivelRiesgo nivelRiesgo, OrigenAlarma origen, Supervisor^ activadaPor);

        String^ GetDescripcion();
    };
}
