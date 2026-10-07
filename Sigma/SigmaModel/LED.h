#pragma once

#include "Dispositivo.h"
#include "ColorLED.h"
#include "TipoRiesgo.h"

using namespace System;

namespace SigmaModel {

	public ref class LED : Dispositivo {
	private:
		ColorLED colorActual;
		bool encendido;

	public:
		LED();
		LED(String^ id, Zona^ zona, ColorLED colorActual, bool encendido);
		LED(String^ id, ColorLED colorActual, bool encendido);

		virtual void Actualizar() override;

		void ActualizarColor(TipoRiesgo riesgo);
		void SetEncendido(bool nuevaEstado);
		bool GetEncendido();
		ColorLED GetColor();
	};
}