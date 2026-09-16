#include "Alarma.h"
#include "Zona.h"
#include "Supervisor.h"

using namespace MinaInteligente;

Alarma::Alarma(Zona^ zona, TipoRiesgo tipoRiesgo, String^ causa, double concentracionRegistrada,
    NivelRiesgo nivelRiesgo, OrigenAlarma origen, Supervisor^ activadaPor)
{
    throw gcnew System::NotImplementedException();
}

String^ Alarma::GetDescripcion()
{
    throw gcnew System::NotImplementedException();
}
