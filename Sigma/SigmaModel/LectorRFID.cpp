#include "pch.h"
#include "LectorRFID.h"
#include "Zona.h"
#include "RegistroExposicion.h"

using namespace SigmaModel;

LectorRFID::LectorRFID() : Dispositivo()
{
}


LectorRFID::LectorRFID(String^ id, Zona^ zonaAsociada, EstadoDispositivo estado)
    : Dispositivo(id, zonaAsociada)
{
    this->SetEstado(estado);
}
LectorRFID::LectorRFID(String^ id, EstadoDispositivo estado) : Dispositivo(id) {
    this->SetEstado(estado);
}

void LectorRFID::Actualizar()
{
    // Pendiente: se implementara junto con la capa de persistencia
    // (identificacion del trabajador y manejo de RegistroExposicion).
}

RegistroExposicion^ LectorRFID::LeerEvento()
{
    // Pendiente: se implementara junto con la capa de persistencia
    // (identificacion del trabajador y manejo de RegistroExposicion).
    return nullptr;
}