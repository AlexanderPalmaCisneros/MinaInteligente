#pragma once

#include "FuenteDatos.h"

using namespace System;

namespace SigmaModel {

	/// <summary>
	/// Fuente de datos que lee la concentracion de gas directamente del
	/// hardware (sensor fisico conectado al ESP32).
	/// </summary>
	public ref class FuenteDatosReal : public FuenteDatos
	{
	public:
		FuenteDatosReal();

		virtual double ObtenerLectura() override;
	};
}