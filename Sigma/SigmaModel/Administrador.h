#pragma once

#include "Usuario.h"

using namespace System;

namespace SigmaModel {

	ref class TipoGas;


	public ref class Administrador : public Usuario
	{
	public:
		Administrador();
		Administrador(String^ id, String^ nombre, String^ credenciales, String^ correo, String^ telefono);

		void GestionarUsuarios();
		void GestionarZonas();
		void GestionarDispositivos();
		void ConfigurarParametros();
		TipoGas^ AgregarTipoGas(String^ id, String^ nombre, String^ simbolo, double generacionGasDefault);
	};
}