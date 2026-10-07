Historialexposicion · CPP
#include "pch.h"
#include "HistorialExposicion.h"
#include "RegistroExposicion.h"
#include "RecomendacionTurno.h"
#include "Trabajador.h"
#include "Zona.h"
#include "SensorGas.h"
#include "ConfiguracionSistema.h"
#include "NivelRiesgo.h"
#include "TipoRecomendacion.h"

using namespace SigmaModel;

HistorialExposicion::HistorialExposicion()
{
	this->trabajador = nullptr;
	this->registros = gcnew List<RegistroExposicion^>();
}

HistorialExposicion::HistorialExposicion(Trabajador^ trabajador)
{
	this->trabajador = trabajador;
	this->registros = gcnew List<RegistroExposicion^>();
}

void HistorialExposicion::AgregarRegistro(RegistroExposicion^ registro)
{
	this->registros->Add(registro);
}

double HistorialExposicion::ObtenerExposicionDiaria(DateTime fecha)
{
	double total = 0.0;
	for each (RegistroExposicion ^ registro in this->registros) {
		if (registro->GetFecha().Date == fecha.Date) {
			total += registro->GetDosisCalculada();
		}
	}
	return total;
}

double HistorialExposicion::ObtenerExposicionTotal()
{
	double total = 0.0;
	for each (RegistroExposicion ^ registro in this->registros) {
		total += registro->GetDosisCalculada();
	}
	return total;
}

RecomendacionTurno^ HistorialExposicion::GenerarRecomendacion()
{
	ConfiguracionSistema^ config = ConfiguracionSistema::ObtenerInstancia();
	double limite = config->GetLimiteExposicion();

	// Sin registros o sin limite configurado no hay nada que comparar.
	if (this->registros->Count == 0 || limite <= 0.0) {
		return nullptr;
	}

	// Exposicion del dia de hoy comparada contra el limite de exposicion.
	double exposicion = this->ObtenerExposicionDiaria(DateTime::Now);
	double proporcion = exposicion / limite;
	double porcentaje = proporcion * 100.0;

	// Tipo de recomendacion segun el porcentaje del limite alcanzado.
	TipoRecomendacion tipo;
	String^ motivo;
	if (proporcion >= 1.0) {
		tipo = TipoRecomendacion::RETIRO_DE_ZONA;
		motivo = "Alcanzo el " + porcentaje.ToString("F0") + "% del limite de exposicion";
	}
	else if (proporcion >= 0.8) {
		tipo = TipoRecomendacion::TURNO_COMPLETO;
		motivo = "Alcanzo el " + porcentaje.ToString("F0") + "% del limite de exposicion";
	}
	else if (proporcion >= 0.6) {
		tipo = TipoRecomendacion::MEDIO_TURNO;
		motivo = "Alcanzo el " + porcentaje.ToString("F0") + "% del limite de exposicion";
	}
	else {
		return nullptr;
	}

	// El nivel de riesgo describe a la zona (no al trabajador): se toma la zona
	// del ultimo registro y se compara su concentracion actual con los umbrales.
	Zona^ zona = this->registros[this->registros->Count - 1]->GetZona();
	double concentracion = 0.0;
	if (zona != nullptr) {
		SensorGas^ sensor = zona->ObtenerSensorGas();
		if (sensor != nullptr) {
			concentracion = sensor->GetLecturaActual();
		}
	}

	double umbralCritico = config->GetUmbralCritico();
	double umbralActivacion = config->GetUmbralActivacion();
	NivelRiesgo nivel;
	if (concentracion >= umbralCritico) {
		nivel = NivelRiesgo::CRITICO;
	}
	else if (concentracion >= 0.8 * umbralCritico) {
		nivel = NivelRiesgo::ALTO;   // por superar el umbral critico
	}
	else if (concentracion >= umbralActivacion) {
		nivel = NivelRiesgo::MEDIO;
	}
	else {
		nivel = NivelRiesgo::BAJO;
	}

	return gcnew RecomendacionTurno(this->trabajador, exposicion, nivel, tipo, motivo);
}