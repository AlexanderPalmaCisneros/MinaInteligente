#pragma once

using namespace System;

namespace SigmaModel {

	/// <summary>
	/// Estrategia abstracta para obtener la lectura de gas de un SensorGas
	/// (patron Strategy). Las subclases definen si la lectura proviene del
	/// hardware real o de una simulacion.
	/// </summary>
	public ref class FuenteDatos abstract
	{
	public:
		virtual double ObtenerLectura() abstract;
	};
}
