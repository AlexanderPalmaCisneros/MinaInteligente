#pragma once

using namespace System;

#include "NivelRiesgo.h"
#include "TipoRecomendacion.h"
#include "EstadoRecomendacion.h"

namespace MinaInteligente {

    ref class Trabajador;
    ref class Supervisor;

    // El sistema nunca asigna turno automaticamente; solo el Supervisor decide (seccion 3.4).
    public ref class RecomendacionTurno
    {
    private:
        Trabajador^ trabajador;
        double exposicionAcumulada;
        NivelRiesgo nivelRiesgo;
        TipoRecomendacion recomendacion;
        String^ motivo;
        EstadoRecomendacion estado;
        DateTime fechaDecision;
        Supervisor^ supervisorQueDecide;

    public:
        RecomendacionTurno();

        void Aprobar(Supervisor^ supervisor);
        void Rechazar(Supervisor^ supervisor, String^ motivo);
    };
}
