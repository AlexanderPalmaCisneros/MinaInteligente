#include "pch.h"
#include "Trabajador.h"
#include "HistorialExposicion.h"

using namespace SigmaModel;

Trabajador::Trabajador()
{
	this->id = String::Empty;
	this->nombre = String::Empty;
	this->idRFID = String::Empty;
	this->correo = String::Empty;
	this->telefono = String::Empty;
	this->historial = gcnew HistorialExposicion(this);
}

Trabajador::Trabajador(String^ id, String^ nombre, String^ idRFID, String^ correo, String^ telefono)
{
	this->id = id;
	this->nombre = nombre;
	this->idRFID = idRFID;
	this->correo = correo;
	this->telefono = telefono;
	this->historial = gcnew HistorialExposicion(this);
}

String^ Trabajador::GetId()
{
	return this->id;
}

String^ Trabajador::GetNombre()
{
	return this->nombre;
}

String^ Trabajador::GetIdRFID()
{
	return this->idRFID;
}

String^ Trabajador::GetCorreo()
{
	return this->correo;
}

String^ Trabajador::GetTelefono()
{
	return this->telefono;
}

HistorialExposicion^ Trabajador::GetHistorial()
{
	return this->historial;
}
