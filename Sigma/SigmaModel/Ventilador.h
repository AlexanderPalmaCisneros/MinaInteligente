#pragma once

#include "Dispositivo.h"
#include "EstadoVentilador.h"
#include "EstadoDispositivo.h"

using namespace System;

namespace SigmaModel {

	ref class Zona;
	public ref class Ventilador : Dispositivo
	{
	private:
		EstadoVentilador estadoVentilador;
		double caudal;

	public:
		Ventilador();
		Ventilador(String^ id, Zona^ zonaAsociada, double caudal, EstadoDispositivo estado);
		Ventilador(String^ id, double caudal, EstadoDispositivo estado);

		virtual void Actualizar() override;

		void EvaluarHisteresis(double concentracionActual);

		double GetCaudal();
		bool EstaEncendido();
	};
}