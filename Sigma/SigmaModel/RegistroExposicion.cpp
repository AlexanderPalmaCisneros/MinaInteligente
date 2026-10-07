
#include "pch.h"
#include "RegistroExposicion.h"

using namespace SigmaModel;

RegistroExposicion::RegistroExposicion()
{
	this->trabajador = nullptr;
	this->zona = nullptr;
	this->tiempoPermanencia = 0.0;
	this->concentracionPromedio = 0.0;
	this->dosisCalculada = 0.0;
}

RegistroExposicion::RegistroExposicion(Trabajador^ trabajador, Zona^ zona, DateTime fecha, DateTime horaIngreso)
{
	this->trabajador = trabajador;
	this->zona = zona;
	this->fecha = fecha;
	this->horaIngreso = horaIngreso;
	this->tiempoPermanencia = 0.0;
	this->concentracionPromedio = 0.0;
	this->dosisCalculada = 0.0;
}

double RegistroExposicion::CalcularDosis()
{
	// Seccion 4.3: dosis = concentracionPromedio x tiempoPermanencia.
	this->dosisCalculada = this->concentracionPromedio * this->tiempoPermanencia;
	return this->dosisCalculada;
}

void RegistroExposicion::CerrarRegistro(DateTime horaSalida)
{
	this->horaSalida = horaSalida;
	// Tiempo de permanencia en horas (ver nota sobre unidades).
	this->tiempoPermanencia = (horaSalida - this->horaIngreso).TotalHours;
	this->CalcularDosis();
}

DateTime RegistroExposicion::GetFecha()
{
	return this->fecha;
}

double RegistroExposicion::GetDosisCalculada()
{
	return this->dosisCalculada;
}

Zona^ RegistroExposicion::GetZona()
{
	return this->zona;
}