#include "pch.h"
#include "Ventilador.h"
#include "ConfiguracionSistema.h"
#include "Zona.h"
#include "SensorGas.h"

using namespace SigmaModel;

Ventilador::Ventilador() : Dispositivo()
{
	this->caudal = 0.0;
	this->estadoVentilador = EstadoVentilador::APAGADO;
}

Ventilador::Ventilador(String^ id, Zona^ zonaAsociada, double caudal, EstadoDispositivo estado) : Dispositivo(id, zonaAsociada)
{
	this->caudal = caudal;
	this->SetEstado(estado);
	this->estadoVentilador = EstadoVentilador::APAGADO;
}

Ventilador::Ventilador(String^ id, double caudal, EstadoDispositivo estado) : Dispositivo(id) {
	this->caudal = caudal;
	this->SetEstado(estado);
	this->estadoVentilador = EstadoVentilador::APAGADO;
}

void Ventilador::Actualizar()
{
	double concentracionActual = this->GetZonaAsociada()->ObtenerSensorGas()->GetLecturaActual();
	this->EvaluarHisteresis(concentracionActual);
}

void Ventilador::EvaluarHisteresis(double concentracionActual)
{
	ConfiguracionSistema^ config = ConfiguracionSistema::ObtenerInstancia();
	double umbralActivacion = config->GetUmbralActivacion();
	double umbralDesactivacion = config->GetUmbralDesactivacion();

	if (this->estadoVentilador == EstadoVentilador::APAGADO && concentracionActual >= umbralActivacion) {
		this->estadoVentilador = EstadoVentilador::ENCENDIDO;
	}
	else if (this->estadoVentilador == EstadoVentilador::ENCENDIDO && concentracionActual <= umbralDesactivacion) {
		this->estadoVentilador = EstadoVentilador::APAGADO;
	}
}

double Ventilador::GetCaudal()
{
	return this->caudal;
}

bool Ventilador::EstaEncendido()
{
	return this->estadoVentilador == EstadoVentilador::ENCENDIDO;
}