#pragma once

#include "Usuario.h"
#include "NivelRiesgo.h"

using namespace System;

namespace SigmaModel {

	ref class RecomendacionTurno;
	ref class Zona;
	ref class Alarma;


	public ref class Supervisor :  Usuario
	{
	public:
		Supervisor();
		Supervisor(String^ id, String^ nombre, String^ credenciales, String^ correo, String^ telefono);

		void AprobarRecomendacion(RecomendacionTurno^ recomendacion);
		void RechazarRecomendacion(RecomendacionTurno^ recomendacion, String^ motivo);
		Alarma^ ActivarAlarmaManual(Zona^ zona, String^ causa, NivelRiesgo nivelRiesgo);
		void ConsultarReportes();
	};
}