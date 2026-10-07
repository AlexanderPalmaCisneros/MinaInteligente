#include "pch.h"
#include "FuenteDatosReal.h"

using namespace SigmaModel;

FuenteDatosReal::FuenteDatosReal()
{
}

double FuenteDatosReal::ObtenerLectura()
{
	// TODO: leer el valor del sensor fisico (ESP32) cuando se integre el
	// hardware. Por ahora devuelve 0.0 como valor neutro.
	return 0.0;
}