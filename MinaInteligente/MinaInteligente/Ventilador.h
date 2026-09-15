#pragma once

using namespace System;

#include "Dispositivo.h"
#include "EstadoDispositivo.h"
#include "EstadoVentilador.h"

namespace MinaInteligente {

    ref class Zona;

    public ref class Ventilador : public Dispositivo
    {
    private:
        EstadoVentilador estadoVentilador;
        double caudal;

    public:
        Ventilador(String^ id, Zona^ zonaAsociada, double caudal, EstadoDispositivo estado);

        virtual void Actualizar() override;

        // Seccion 4.2: enciende sobre umbralActivacion, apaga bajo umbralDesactivacion.
        void EvaluarHisteresis(double concentracionActual);

        double GetCaudal();
        bool EstaEncendido();
    };
}
