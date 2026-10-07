#pragma once

using namespace System;
using namespace System::Collections::Generic;

namespace SigmaModel {

	ref class Trabajador;
	ref class RegistroExposicion;
	ref class RecomendacionTurno;

	/// <summary>
	/// Historial de exposicion de un Trabajador: agrupa todos sus
	/// RegistroExposicion y calcula la exposicion acumulada.
	/// </summary>
	public ref class HistorialExposicion
	{
	private:
		Trabajador^ trabajador;
		List<RegistroExposicion^>^ registros;

	public:
		HistorialExposicion();
		HistorialExposicion(Trabajador^ trabajador);

		void AgregarRegistro(RegistroExposicion^ registro);
		double ObtenerExposicionDiaria(DateTime fecha);
		double ObtenerExposicionTotal();
		RecomendacionTurno^ GenerarRecomendacion();
	};
}