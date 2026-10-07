#include "pch.h"
#include "FuenteDatosSimulada.h"
#include "Zona.h"

using namespace SigmaModel;

FuenteDatosSimulada::FuenteDatosSimulada()
{
	this->valorSimulado = 0.0;
	this->generacionGas = 0.0;
	this->zonaSimulada = nullptr;
	this->ultimaActualizacion = DateTime::Now;
}

FuenteDatosSimulada::FuenteDatosSimulada(Zona^ zonaSimulada, double generacionGas)
{
	this->valorSimulado = 0.0;
	this->generacionGas = generacionGas;
	this->zonaSimulada = zonaSimulada;
	this->ultimaActualizacion = DateTime::Now;
}

double FuenteDatosSimulada::ObtenerLectura()
{
	// Solo devuelve el valor simulado vigente; SimularAumento/SimularDescenso
	// son las que lo modifican.
	return this->valorSimulado;
}

void FuenteDatosSimulada::ConfigurarValor(double valor)
{
	this->valorSimulado = valor;
}

void FuenteDatosSimulada::SimularAumento(bool ventiladorActivo)
{
	// Pendiente de implementar.
}

void FuenteDatosSimulada::SimularDescenso(bool ventiladorActivo)
{
	// Pendiente de implementar.
}