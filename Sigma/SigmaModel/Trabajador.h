#pragma once

using namespace System;

namespace SigmaModel {

	ref class HistorialExposicion;

	public ref class Trabajador
	{
	private:
		String^ id;
		String^ nombre;
		String^ idRFID;
		String^ correo;
		String^ telefono;
		HistorialExposicion^ historial;

	public:
		Trabajador();
		Trabajador(String^ id, String^ nombre, String^ idRFID, String^ correo, String^ telefono);

		String^ GetId();
		String^ GetNombre();
		String^ GetIdRFID();
		String^ GetCorreo();
		String^ GetTelefono();
		HistorialExposicion^ GetHistorial();
	};
}
