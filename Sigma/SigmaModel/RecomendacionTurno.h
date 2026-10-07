#pragma once

#include "NivelRiesgo.h"
#include "TipoRecomendacion.h"
#include "EstadoRecomendacion.h"

using namespace System;

namespace SigmaModel {

	ref class Trabajador;
	ref class Supervisor;

	/// <summary>
	/// Recomendacion de turno generada para un Trabajador segun su exposicion
	/// acumulada. El sistema nunca asigna turno automaticamente; solo el
	/// Supervisor decide (seccion 3.4).
	/// </summary>
	public ref class RecomendacionTurno
	{
	private:
		Trabajador^ trabajador;
		double exposicionAcumulada;
		NivelRiesgo nivelRiesgo;
		TipoRecomendacion recomendacion;
		String^ motivo;
		EstadoRecomendacion estado;
		DateTime fechaDecision;
		Supervisor^ supervisorQueDecide;

	public:
		RecomendacionTurno();
		RecomendacionTurno(Trabajador^ trabajador, double exposicionAcumulada, NivelRiesgo nivelRiesgo,
			TipoRecomendacion recomendacion, String^ motivo);

		void Aprobar(Supervisor^ supervisor);
		void Rechazar(Supervisor^ supervisor, String^ motivo);
	};
}