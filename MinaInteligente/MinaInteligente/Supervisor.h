#pragma once

using namespace System;

#include "Usuario.h"
#include "NivelRiesgo.h"

namespace MinaInteligente {

    ref class RecomendacionTurno;
    ref class Zona;
    ref class Alarma;

    public ref class Supervisor : public Usuario
    {
    public:
        Supervisor(String^ id, String^ nombre, String^ credenciales);

        void AprobarRecomendacion(RecomendacionTurno^ recomendacion);
        void RechazarRecomendacion(RecomendacionTurno^ recomendacion, String^ motivo);
        Alarma^ ActivarAlarmaManual(Zona^ zona, String^ causa, NivelRiesgo nivelRiesgo);
        void ConsultarReportes();
    };
}
