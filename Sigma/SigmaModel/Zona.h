#pragma once

#include "Dispositivo.h"
#include "TipoRiesgo.h"

using namespace System;
using namespace System::Collections::Generic;

namespace SigmaModel {

	ref class Ventilador;
	ref class SensorGas;
	ref class LED;


	public ref class Zona
	{
	private:
		String^ id;
		String^ nombre;
		double volumen;
		List<Dispositivo^>^ dispositivos;
		List<Zona^>^ conexiones;
		double concentracionActual;
		bool esZonaSalida;
		TipoRiesgo tipoRiesgoActual;

	public:
		Zona();
		Zona(String^ id, String^ nombre, double volumen);


		void ActualizarConcentracion();

		TipoRiesgo EvaluarRiesgoDirecto();
		void AgregarDispositivo(Dispositivo^ dispositivo);
		void ConectarCon(Zona^ destino);
		Ventilador^ ObtenerVentilador();
		SensorGas^ ObtenerSensorGas();
		LED^ ObtenerLed();
		List<Zona^>^ ObtenerConexiones();

		double GetVolumen();
		

		TipoRiesgo GetTipoRiesgoActual();
		void SetTipoRiesgo(TipoRiesgo riesgo);

		bool GetEsZonaSalida();
		void SetEsZonaSalida(bool esSalida);

		String^ GetId();
		String^ GetNombre();
		//AGREGADO
		void SetNombre(String^ nombre);

		//AGREGADO
		double GetConcentracionActual();
		void SetConcentracionActual(double concentracion);

		void SetVolumen(double nuevoVolumen);//AGREGADO
		bool QuitarDispositivo(String^ idDispositivo);
	
	};
}