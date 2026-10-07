#pragma once

using namespace System;

namespace SigmaModel {

	/// <summary>
	/// Clase base abstracta de los usuarios del sistema (Administrador y
	/// Supervisor). No se puede instanciar directamente.
	/// </summary>
	public ref class Usuario abstract
	{
	protected:
		String^ id;
		String^ nombre;
		String^ credenciales;
		String^ correo;
		String^ telefono;

		Usuario();

	public:
		Usuario(String^ id, String^ nombre, String^ credenciales, String^ correo, String^ telefono);

		String^ GetId();
		String^ GetNombre();
		String^ GetCredenciales();
		String^ GetCorreo();
		String^ GetTelefono();
		bool ValidarCredenciales(String^ clave);
	};
}
