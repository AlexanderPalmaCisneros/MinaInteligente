#include "LectorRFID.h"

using namespace MinaInteligente;

LectorRFID::LectorRFID(String^ id, Zona^ zonaAsociada, EstadoDispositivo estado)
    : Dispositivo(id, zonaAsociada)
{
    throw gcnew System::NotImplementedException();
}

void LectorRFID::Actualizar()
{
    throw gcnew System::NotImplementedException();
}

RegistroExposicion^ LectorRFID::LeerEvento()
{
    throw gcnew System::NotImplementedException();
}
