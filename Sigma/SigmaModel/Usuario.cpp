#include "pch.h"
#include "Usuario.h"

using namespace SigmaModel;

Usuario::Usuario()
{
	this->id = String::Empty;
	this->nombre = String::Empty;
	this->credenciales = String::Empty;
	this->correo = String::Empty;
	this->telefono = String::Empty;
}

Usuario::Usuario(String^ id, String^ nombre, String^ credenciales, String^ correo, String^ telefono)
{
	this->id = id;
	this->nombre = nombre;
	this->credenciales = credenciales;
	this->correo = correo;
	this->telefono = telefono;
}

String^ Usuario::GetId()
{
	return this->id;
}

String^ Usuario::GetNombre()
{
	return this->nombre;
}

String^ Usuario::GetCredenciales()
{
	return this->credenciales;
}

String^ Usuario::GetCorreo()
{
	return this->correo;
}

String^ Usuario::GetTelefono()
{
	return this->telefono;
}

bool Usuario::ValidarCredenciales(String^ clave)
{
	return this->credenciales == clave;
}
