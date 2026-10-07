#include "pch.h"
#include "RecomendacionTurno.h"
#include "Supervisor.h"

using namespace SigmaModel;

RecomendacionTurno::RecomendacionTurno()
{
	this->trabajador = nullptr;
	this->exposicionAcumulada = 0.0;
	this->motivo = String::Empty;
	this->estado = EstadoRecomendacion::PENDIENTE;
	this->supervisorQueDecide = nullptr;
}

RecomendacionTurno::RecomendacionTurno(Trabajador^ trabajador, double exposicionAcumulada, NivelRiesgo nivelRiesgo,
	TipoRecomendacion recomendacion, String^ motivo)
{
	this->trabajador = trabajador;
	this->exposicionAcumulada = exposicionAcumulada;
	this->nivelRiesgo = nivelRiesgo;
	this->recomendacion = recomendacion;
	this->motivo = motivo;
	// Toda recomendacion nace pendiente: solo el Supervisor la aprueba o rechaza.
	this->estado = EstadoRecomendacion::PENDIENTE;
	this->supervisorQueDecide = nullptr;
}

void RecomendacionTurno::Aprobar(Supervisor^ supervisor)
{
	this->estado = EstadoRecomendacion::APROBADA;
	this->supervisorQueDecide = supervisor;
	this->fechaDecision = DateTime::Now;
}

void RecomendacionTurno::Rechazar(Supervisor^ supervisor, String^ motivo)
{
	this->estado = EstadoRecomendacion::RECHAZADA;
	this->supervisorQueDecide = supervisor;
	this->motivo = motivo;
	this->fechaDecision = DateTime::Now;
}