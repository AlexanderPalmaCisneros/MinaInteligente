#pragma once

using namespace System;

namespace SigmaModel {

	ref class Trabajador;
	ref class Zona;


	public ref class RegistroExposicion
	{
	private:
		Trabajador^ trabajador;
		Zona^ zona;
		DateTime fecha;
		DateTime horaIngreso;
		DateTime horaSalida;
		double tiempoPermanencia;
		double concentracionPromedio;
		double dosisCalculada;

	public:
		RegistroExposicion();
		RegistroExposicion(Trabajador^ trabajador, Zona^ zona, DateTime fecha, DateTime horaIngreso);

		// Seccion 4.3: dosis = concentracionPromedio x tiempoPermanencia.
		double CalcularDosis();
		void CerrarRegistro(DateTime horaSalida);

		DateTime GetFecha();
		double GetDosisCalculada();
		Zona^ GetZona();
	};
}