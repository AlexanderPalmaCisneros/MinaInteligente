#pragma once

using namespace System;

#include "Dispositivo.h"
#include "EstadoDispositivo.h"

namespace MinaInteligente {

    ref class Zona;
    ref class RegistroExposicion;

    public ref class LectorRFID : public Dispositivo
    {
    public:
        LectorRFID(String^ id, Zona^ zonaAsociada, EstadoDispositivo estado);

        // Lee directamente el hardware RFID (ESP32); no usa FuenteDatos, ya que su
        // naturaleza es un evento de identificacion (idRFID), no una medicion numerica continua.
        virtual void Actualizar() override;

        // Identifica al trabajador por idRFID y abre/cierra su RegistroExposicion.
        RegistroExposicion^ LeerEvento();
    };
}
