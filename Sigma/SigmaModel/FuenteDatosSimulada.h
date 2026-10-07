#pragma once

#include "FuenteDatos.h"

using namespace System;

namespace SigmaModel {

	ref class Zona;

	public ref class FuenteDatosSimulada :  FuenteDatos
	{
	private:
		double valorSimulado;
		double generacionGas;
		Zona^ zonaSimulada;
		DateTime ultimaActualizacion;

		void SimularAumento(bool ventiladorActivo);
		void SimularDescenso(bool ventiladorActivo);

	public:
		FuenteDatosSimulada();
		FuenteDatosSimulada(Zona^ zonaSimulada, double generacionGas);

		virtual double ObtenerLectura() override;

		void ConfigurarValor(double valor);
	};
}