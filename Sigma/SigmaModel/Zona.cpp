#include "pch.h"
#include "Zona.h"
#include "Ventilador.h"
#include "SensorGas.h"
#include "LED.h"
#include "ConfiguracionSistema.h"

using namespace SigmaModel;
Zona::Zona()
{
	this->id = String::Empty;
	this->nombre = String::Empty;
	this->volumen = 0.0;
	this->dispositivos = gcnew List<Dispositivo^>();
	this->conexiones = gcnew List<Zona^>();
	this->concentracionActual = 0.0;
	this->esZonaSalida = false;
	this->tipoRiesgoActual = TipoRiesgo::NINGUNO;
}

Zona::Zona(String^ id, String^ nombre, double volumen)
{

	this->id = id;
	this->nombre = nombre;
	this->volumen = volumen;
	this->dispositivos = gcnew List<Dispositivo^>();
	this->conexiones = gcnew List<Zona^>();
	this->concentracionActual = 0.0;
	this->esZonaSalida = false;
	this->tipoRiesgoActual = TipoRiesgo::NINGUNO;
}

void Zona::ActualizarConcentracion()
{
	SensorGas^ sensor = this->ObtenerSensorGas();
	if (sensor != nullptr) {
		this->concentracionActual = sensor->GetLecturaActual();
	}
}

TipoRiesgo Zona::EvaluarRiesgoDirecto()
{
	double umbralCritico = ConfiguracionSistema::ObtenerInstancia()->GetUmbralCritico();
	if (this->concentracionActual >= umbralCritico) {
		return TipoRiesgo::DIRECTO;
	}
	return TipoRiesgo::NINGUNO;
}

void Zona::AgregarDispositivo(Dispositivo^ dispositivo)
{
	this->dispositivos->Add(dispositivo);
}

void Zona::ConectarCon(Zona^ destino)
{
	this->conexiones->Add(destino);
}

Ventilador^ Zona::ObtenerVentilador()
{
	for each (Dispositivo ^ d in this->dispositivos) {
		Ventilador^ v = dynamic_cast<Ventilador^>(d);
		if (v != nullptr) {
			return v;
		}
	}
	return nullptr;
}

SensorGas^ Zona::ObtenerSensorGas()
{
	for each (Dispositivo ^ d in this->dispositivos) {
		SensorGas^ s = dynamic_cast<SensorGas^>(d);
		if (s != nullptr) {
			return s;
		}
	}
	return nullptr;
}

LED^ Zona::ObtenerLed()
{
	for each (Dispositivo ^ d in this->dispositivos) {
		LED^ led = dynamic_cast<LED^>(d);
		if (led != nullptr) {
			return led;
		}
	}
	return nullptr;
}

List<Zona^>^ Zona::ObtenerConexiones()
{
	return this->conexiones;
}

double Zona::GetVolumen()
{
	return this->volumen;
}
//AGREGADO
void Zona::SetVolumen(double nuevoVolumen)
{
	this->volumen = nuevoVolumen;
}
//.......
TipoRiesgo Zona::GetTipoRiesgoActual()
{
	return this->tipoRiesgoActual;
}

void Zona::SetTipoRiesgo(TipoRiesgo riesgo)
{
	this->tipoRiesgoActual = riesgo;
}

bool Zona::GetEsZonaSalida()
{
	return this->esZonaSalida;
}

void Zona::SetEsZonaSalida(bool esSalida)
{
	this->esZonaSalida = esSalida;
}

String^ Zona::GetId() {
	return this->id;
}
String^ Zona::GetNombre() {
	return this->nombre;
}
//AGREGADOS 
void Zona::SetNombre(String^ nombre) {
	this->nombre = nombre;
}

double Zona::GetConcentracionActual() {
	return this->concentracionActual;
}

void Zona::SetConcentracionActual(double concentracion) {
	this->concentracionActual = concentracion;
}

bool Zona::QuitarDispositivo(String^ idDispositivo)
{
	for (int i = 0; i < this->dispositivos->Count; i++) {
		if (this->dispositivos[i]->GetId() == idDispositivo) {
			this->dispositivos->RemoveAt(i);
			return true;
		}
	}
	return false;
}