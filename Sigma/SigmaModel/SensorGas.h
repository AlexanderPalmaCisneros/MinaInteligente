#pragma once

#include "Dispositivo.h"
#include "EstadoDispositivo.h"
#include "TipoGas.h"
#include "FuenteDatos.h"

using namespace System;

namespace SigmaModel {

	public ref class SensorGas : public Dispositivo
	{
	private:
		TipoGas^ tipoGas;
		double lecturaActual;
		FuenteDatos^ fuenteLectura;

	public:
		SensorGas();
		SensorGas(String^ id, Zona^ zonaAsociada, EstadoDispositivo estado, TipoGas^ tipoGas);

		// Obtiene la lectura actual desde fuenteLectura (real o simulada).
		virtual void Actualizar() override;

		double GetLecturaActual();
		void SetFuenteLectura(FuenteDatos^ fuente);
		void SetTipoGas(TipoGas^ tipoGas);
		TipoGas^ GetTipoGas();
	};
}