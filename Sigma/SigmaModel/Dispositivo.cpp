#include "pch.h"
#include "Dispositivo.h"
#include "Zona.h"

using namespace SigmaModel;

Dispositivo::Dispositivo() {
}

Dispositivo::Dispositivo(String^ id, Zona^ zonaAsociada)
{

	this->id = id;
	this->zonaAsociada = zonaAsociada;
	this->estado = EstadoDispositivo::ACTIVO;
}

Dispositivo::Dispositivo(String^ id) {
	this->id = id;
	this->estado = EstadoDispositivo::ACTIVO;
	this->zonaAsociada = nullptr;
}
String^ Dispositivo::GetId()
{
	return this->id;
}

Zona^ Dispositivo::GetZonaAsociada()
{
	return this->zonaAsociada;
}

EstadoDispositivo Dispositivo::GetEstado()
{
	return this->estado;
}

void Dispositivo::SetEstado(EstadoDispositivo nuevoEstado)
{
	this->estado = nuevoEstado;
}

void Dispositivo::SetZona(Zona^ zonaAsociada) {
	this->zonaAsociada = zonaAsociada;
}