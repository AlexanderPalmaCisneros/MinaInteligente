#pragma once

#include "NivelRiesgo.h"
#include "TipoRiesgo.h"
#include "OrigenAlarma.h"

using namespace System;

namespace SigmaModel {

	ref class Zona;
	ref class Supervisor;

	public ref class Alarma
	{
	private:
		String^ id;
		DateTime fecha;
		DateTime hora;
		Zona^ zona;
		String^ causa;
		double concentracionRegistrada;
		NivelRiesgo nivelRiesgo;
		TipoRiesgo tipoRiesgo;
		OrigenAlarma origen;
		Supervisor^ activadaPor;

	public:
		Alarma();
		Alarma(Zona^ zona, TipoRiesgo tipoRiesgo, String^ causa, double concentracionRegistrada,
			NivelRiesgo nivelRiesgo, OrigenAlarma origen, Supervisor^ activadaPor);

		String^ GetDescripcion();
	};
}