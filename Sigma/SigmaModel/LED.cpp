#include "pch.h"
#include "LED.h"
#include "Zona.h"

using namespace SigmaModel;

LED::LED() : Dispositivo()
{
	this->colorActual = ColorLED::ROJO;
	this->encendido = false;
}

LED::LED(String^ id, Zona^ zona, ColorLED colorActual, bool encendido) : Dispositivo(id, zona)
{
	this->colorActual = colorActual;
	this->encendido = encendido;
}
LED::LED(String^ id, ColorLED colorActual, bool encendido) : Dispositivo(id) {
	this->colorActual = colorActual;
	this->encendido = encendido;
}
void LED::Actualizar()
{
	// El LED se actualiza reflejando el tipo de riesgo actual de su zona.
	ActualizarColor(this->GetZonaAsociada()->GetTipoRiesgoActual());
}

void LED::ActualizarColor(TipoRiesgo riesgo)
{
	switch (riesgo)
	{
	case TipoRiesgo::DIRECTO:
		this->colorActual = ColorLED::ROJO;
		this->encendido = true;
		break;
	case TipoRiesgo::AISLAMIENTO:
		this->colorActual = ColorLED::NARANJA;
		this->encendido = true;
		break;
	case TipoRiesgo::NINGUNO:
	default:
		this->encendido = false;
		break;
	}
}

void LED::SetEncendido(bool nuevaEstado)
{
	this->encendido = nuevaEstado;
}

bool LED::GetEncendido()
{
	return this->encendido;
}

ColorLED LED::GetColor()
{
	return this->colorActual;
}