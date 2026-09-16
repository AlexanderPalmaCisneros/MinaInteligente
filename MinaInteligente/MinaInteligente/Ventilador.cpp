#include "Ventilador.h"

using namespace MinaInteligente;

Ventilador::Ventilador(String^ id, Zona^ zonaAsociada, double caudal, EstadoDispositivo estado)
    : Dispositivo(id, zonaAsociada)
{
    throw gcnew System::NotImplementedException();
}

void Ventilador::Actualizar()
{
    throw gcnew System::NotImplementedException();
}

void Ventilador::EvaluarHisteresis(double concentracionActual)
{
    throw gcnew System::NotImplementedException();
}

double Ventilador::GetCaudal()
{
    throw gcnew System::NotImplementedException();
}

bool Ventilador::EstaEncendido()
{
    throw gcnew System::NotImplementedException();
}
