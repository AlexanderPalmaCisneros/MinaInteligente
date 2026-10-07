#include "pch.h"
#include "Administrador.h"
#include "TipoGas.h"
#include "ConfiguracionSistema.h"

using namespace SigmaModel;

Administrador::Administrador()
	: Usuario()
{
}

Administrador::Administrador(String^ id, String^ nombre, String^ credenciales, String^ correo, String^ telefono)
	: Usuario(id, nombre, credenciales, correo, telefono)
{
}

void Administrador::GestionarUsuarios()
{
	// Pendiente de implementar.
}

void Administrador::GestionarZonas()
{
	// Pendiente de implementar.
}

void Administrador::GestionarDispositivos()
{
	// Pendiente de implementar.
}

void Administrador::ConfigurarParametros()
{
	// Pendiente de implementar.
}

TipoGas^ Administrador::AgregarTipoGas(String^ id, String^ nombre, String^ simbolo, double generacionGasDefault)
{
	TipoGas^ nuevoTipo = gcnew TipoGas(id, nombre, simbolo, generacionGasDefault);

	// Registra el nuevo tipo en la configuracion global del sistema.
	ConfiguracionSistema::ObtenerInstancia()->AgregarTipoGas(nuevoTipo);
	return nuevoTipo;
}