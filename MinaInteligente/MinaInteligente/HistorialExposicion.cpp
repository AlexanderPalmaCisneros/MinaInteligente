#include "HistorialExposicion.h"
#include "Trabajador.h"
#include "RegistroExposicion.h"
#include "RecomendacionTurno.h"

using namespace MinaInteligente;

HistorialExposicion::HistorialExposicion(Trabajador^ trabajador)
{
    throw gcnew System::NotImplementedException();
}

void HistorialExposicion::AgregarRegistro(RegistroExposicion^ registro)
{
    throw gcnew System::NotImplementedException();
}

double HistorialExposicion::ObtenerExposicionDiaria(DateTime fecha)
{
    throw gcnew System::NotImplementedException();
}

double HistorialExposicion::ObtenerExposicionTotal()
{
    throw gcnew System::NotImplementedException();
}

RecomendacionTurno^ HistorialExposicion::GenerarRecomendacion()
{
    throw gcnew System::NotImplementedException();
}
