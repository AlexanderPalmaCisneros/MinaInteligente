#include "Supervisor.h"
#include "RecomendacionTurno.h"
#include "Zona.h"
#include "Alarma.h"

using namespace MinaInteligente;

Supervisor::Supervisor(String^ id, String^ nombre, String^ credenciales)
{
    throw gcnew System::NotImplementedException();
}

void Supervisor::AprobarRecomendacion(RecomendacionTurno^ recomendacion)
{
    throw gcnew System::NotImplementedException();
}

void Supervisor::RechazarRecomendacion(RecomendacionTurno^ recomendacion, String^ motivo)
{
    throw gcnew System::NotImplementedException();
}

Alarma^ Supervisor::ActivarAlarmaManual(Zona^ zona, String^ causa, NivelRiesgo nivelRiesgo)
{
    throw gcnew System::NotImplementedException();
}

void Supervisor::ConsultarReportes()
{
    throw gcnew System::NotImplementedException();
}
