#pragma once

#include "Dispositivo.h"
#include "TipoRiesgo.h"
#include "NivelRiesgo.h"
#include "CaraZona.h"

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
		// Ubicacion en el grafo: zona de la que cuelga, por cual de sus caras y celda (fila, columna)
		Zona^ zonaPadre;
		CaraZona caraConexion;
		int fila;
		int columna;

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

		/*Nivel de emergencia segun los umbrales de ConfiguracionSistema (BAJO, MEDIO, ALTO, CRITICO)*/
		NivelRiesgo EvaluarNivelRiesgo();

		/*Guarda la ubicacion de la zona en el grafo (padre nullptr = zona de salida)*/
		void UbicarEn(Zona^ padre, CaraZona cara, int fila, int columna);
		Zona^ GetZonaPadre();
		CaraZona GetCaraConexion();
		int GetFila();
		int GetColumna();
	
	};
}