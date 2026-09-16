#include "SistemaMonitoreo.h"
#include "GrafoZonas.h"
#include "Alarma.h"
#include "Zona.h"

using namespace MinaInteligente;

SistemaMonitoreo::SistemaMonitoreo(GrafoZonas^ grafoZonas)
{
    throw gcnew System::NotImplementedException();
}

void SistemaMonitoreo::ActualizarCiclo()
{
    throw gcnew System::NotImplementedException();
}

void SistemaMonitoreo::EvaluarZona(Zona^ zona)
{
    throw gcnew System::NotImplementedException();
}

Alarma^ SistemaMonitoreo::GenerarAlarmaAutomatica(Zona^ zona, NivelRiesgo nivelRiesgo, TipoRiesgo tipoRiesgo)
{
    throw gcnew System::NotImplementedException();
}

List<Alarma^>^ SistemaMonitoreo::ObtenerAlarmasActivas()
{
    throw gcnew System::NotImplementedException();
}

void SistemaMonitoreo::CambiarModoOperacion(ModoOperacion modo)
{
    throw gcnew System::NotImplementedException();
}
