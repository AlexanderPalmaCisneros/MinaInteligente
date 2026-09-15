#pragma once

using namespace System;

#include "Dispositivo.h"
#include "EstadoDispositivo.h"

namespace MinaInteligente {

    ref class Zona;
    ref class TipoGas;
    ref class FuenteDatos;

    public ref class SensorGas : public Dispositivo
    {
    private:
        TipoGas^ tipoGas;
        double lecturaActual;
        FuenteDatos^ fuenteLectura;

    public:
        SensorGas(String^ id, Zona^ zonaAsociada, EstadoDispositivo estado);

        // Obtiene la lectura actual desde fuenteLectura (real o simulada).
        virtual void Actualizar() override;

        double GetLecturaActual();
        void SetFuenteLectura(FuenteDatos^ fuente);
    };
}
