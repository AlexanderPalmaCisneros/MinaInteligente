#include "SensorGas.h"

using namespace MinaInteligente;

SensorGas::SensorGas(String^ id, Zona^ zonaAsociada, EstadoDispositivo estado)
    : Dispositivo(id, zonaAsociada)
{
    throw gcnew System::NotImplementedException();
}

void SensorGas::Actualizar()
{
    throw gcnew System::NotImplementedException();
}

double SensorGas::GetLecturaActual()
{
    throw gcnew System::NotImplementedException();
}

void SensorGas::SetFuenteLectura(FuenteDatos^ fuente)
{
    throw gcnew System::NotImplementedException();
}
