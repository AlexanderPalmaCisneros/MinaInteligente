#include "pch.h"
#include "Supervisor.h"
#include "RecomendacionTurno.h"
#include "Zona.h"
#include "SensorGas.h"
#include "Alarma.h"
#include "OrigenAlarma.h"

using namespace SigmaModel;

Supervisor::Supervisor()
	: Usuario()
{
}

Supervisor::Supervisor(String^ id, String^ nombre, String^ credenciales, String^ correo, String^ telefono)
	: Usuario(id, nombre, credenciales, correo, telefono)
{
}

void Supervisor::AprobarRecomendacion(RecomendacionTurno^ recomendacion)
{
	recomendacion->Aprobar(this);
}

void Supervisor::RechazarRecomendacion(RecomendacionTurno^ recomendacion, String^ motivo)
{
	recomendacion->Rechazar(this, motivo);
}

Alarma^ Supervisor::ActivarAlarmaManual(Zona^ zona, String^ causa, NivelRiesgo nivelRiesgo)
{
	// La concentracion y el tipo de riesgo vigentes se toman de la zona.
	SensorGas^ sensor = zona->ObtenerSensorGas();
	double concentracion = (sensor != nullptr) ? sensor->GetLecturaActual() : 0.0;

	return gcnew Alarma(zona, zona->GetTipoRiesgoActual(), causa, concentracion,
		nivelRiesgo, OrigenAlarma::MANUAL, this);
}

void Supervisor::ConsultarReportes()
{
	// Pendiente de implementar (depende de GeneradorReportes).
}