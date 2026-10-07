#pragma once

using namespace System;

#include "Dispositivo.h"
#include "EstadoDispositivo.h"

namespace SigmaModel {

    ref class Zona;
    ref class RegistroExposicion;

    public ref class LectorRFID : public Dispositivo
    {
    public:
        LectorRFID();
        LectorRFID(String^ id, Zona^ zonaAsociada, EstadoDispositivo estado);
        LectorRFID(String^ id, EstadoDispositivo estado);

        virtual void Actualizar() override;

        RegistroExposicion^ LeerEvento();
    };
}