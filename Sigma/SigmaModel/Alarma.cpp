#include "pch.h"
#include "Alarma.h"
#include "Zona.h"

using namespace SigmaModel;

Alarma::Alarma()
{
	this->id = String::Empty;
	this->zona = nullptr;
	this->causa = String::Empty;
	this->concentracionRegistrada = 0.0;
	this->activadaPor = nullptr;
}

Alarma::Alarma(Zona^ zona, TipoRiesgo tipoRiesgo, String^ causa, double concentracionRegistrada,
	NivelRiesgo nivelRiesgo, OrigenAlarma origen, Supervisor^ activadaPor)
{
	// El id, la fecha y la hora se generan al momento de crear la alarma.
	this->id = Guid::NewGuid().ToString();
	DateTime ahora = DateTime::Now;
	this->fecha = ahora.Date;
	this->hora = ahora;

	this->zona = zona;
	this->tipoRiesgo = tipoRiesgo;
	this->causa = causa;
	this->concentracionRegistrada = concentracionRegistrada;
	this->nivelRiesgo = nivelRiesgo;
	this->origen = origen;
	this->activadaPor = activadaPor;
}

String^ Alarma::GetDescripcion()
{
	String^ nombreZona = "desconocida";
	if (this->zona != nullptr) {
		nombreZona = this->zona->GetNombre();
	}

	return "Alarma " + this->origen.ToString() + " [" + this->nivelRiesgo.ToString() + "] en zona "
		+ nombreZona + ": " + this->causa
		+ " (" + this->concentracionRegistrada.ToString("F2") + " ppm)";
}