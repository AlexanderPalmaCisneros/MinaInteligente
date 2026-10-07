#pragma once
#include "EstadoDispositivo.h"

using namespace System;
using namespace System::Collections::Generic;

namespace SigmaModel {

	ref class Zona;

	public ref class Dispositivo abstract
	{
	protected:
		String^ id;
		Zona^ zonaAsociada;
		EstadoDispositivo estado;

	public:
		Dispositivo();
		Dispositivo(String^ id, Zona^ zonaAsociada);
		Dispositivo(String^ id);
		// Metodo virtual puro: cada dispositivo define como se actualiza a si mismo.
		virtual void Actualizar() abstract;

		String^ GetId();
		Zona^ GetZonaAsociada();
		EstadoDispositivo GetEstado();
		void SetEstado(EstadoDispositivo nuevoEstado);
		void SetZona(Zona^ zonaAsociada);
	};
}