#include "pch.h"
#include "SensorGas.h"

using namespace SigmaModel;

SensorGas::SensorGas()
	: Dispositivo()
{
	this->tipoGas = nullptr;
	this->lecturaActual = 0.0;
	this->fuenteLectura = nullptr;
}

SensorGas::SensorGas(String^ id, Zona^ zonaAsociada, EstadoDispositivo estado, TipoGas^ tipoGas)
	: Dispositivo(id, zonaAsociada)
{
	this->SetEstado(estado);
	this->tipoGas = tipoGas;
	this->lecturaActual = 0.0;
	this->fuenteLectura = nullptr;
}

void SensorGas::Actualizar()
{
	// La lectura viene de la fuente (real o simulada); el sensor no sabe cual.
	if (this->fuenteLectura != nullptr) {
		this->lecturaActual = this->fuenteLectura->ObtenerLectura();
	}
}

double SensorGas::GetLecturaActual()
{
	return this->lecturaActual;
}

void SensorGas::SetFuenteLectura(FuenteDatos^ fuente)
{
	this->fuenteLectura = fuente;
}

void SensorGas::SetTipoGas(TipoGas^ tipoGas) {
	this->tipoGas = tipoGas;
}
TipoGas^ SensorGas::GetTipoGas() {
	return this->tipoGas;
}