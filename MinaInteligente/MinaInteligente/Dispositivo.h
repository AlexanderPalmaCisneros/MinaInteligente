#pragma once

using namespace System;

#include "EstadoDispositivo.h"

namespace MinaInteligente {

    ref class Zona;

    // Clase abstracta: cada dispositivo define como se actualiza a si mismo.
    public ref class Dispositivo abstract
    {
    private:
        String^ id;
        Zona^ zonaAsociada;
        EstadoDispositivo estado;

    public:
        Dispositivo(String^ id, Zona^ zonaAsociada);

        virtual void Actualizar() abstract;

        String^ GetId();
        Zona^ GetZonaAsociada();
        EstadoDispositivo GetEstado();
        void SetEstado(EstadoDispositivo nuevoEstado);
    };
}
