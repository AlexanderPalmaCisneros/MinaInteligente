#include "Zona.h"
#include "Dispositivo.h"
#include "Ventilador.h"
#include "SensorGas.h"

using namespace MinaInteligente;

Zona::Zona(String^ id, String^ nombre, double volumen)
{
    throw gcnew System::NotImplementedException();
}

void Zona::ActualizarConcentracion()
{
    throw gcnew System::NotImplementedException();
}

TipoRiesgo Zona::EvaluarRiesgoDirecto()
{
    throw gcnew System::NotImplementedException();
}

void Zona::AgregarDispositivo(Dispositivo^ dispositivo)
{
    throw gcnew System::NotImplementedException();
}

void Zona::ConectarCon(Zona^ destino)
{
    throw gcnew System::NotImplementedException();
}

Ventilador^ Zona::ObtenerVentilador()
{
    throw gcnew System::NotImplementedException();
}

SensorGas^ Zona::ObtenerSensorGas()
{
    throw gcnew System::NotImplementedException();
}

double Zona::GetVolumen()
{
    throw gcnew System::NotImplementedException();
}
