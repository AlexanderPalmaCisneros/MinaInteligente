#include "ConfiguracionSistema.h"
#include "TipoGas.h"

using namespace MinaInteligente;

ConfiguracionSistema::ConfiguracionSistema()
{
    throw gcnew System::NotImplementedException();
}

ConfiguracionSistema^ ConfiguracionSistema::ObtenerInstancia()
{
    throw gcnew System::NotImplementedException();
}

void ConfiguracionSistema::CargarConfiguracion()
{
    throw gcnew System::NotImplementedException();
}

void ConfiguracionSistema::GuardarConfiguracion()
{
    throw gcnew System::NotImplementedException();
}

ModoOperacion ConfiguracionSistema::GetModoOperacion()
{
    throw gcnew System::NotImplementedException();
}

void ConfiguracionSistema::SetModoOperacion(ModoOperacion modo)
{
    throw gcnew System::NotImplementedException();
}

void ConfiguracionSistema::AgregarTipoGas(TipoGas^ tipo)
{
    throw gcnew System::NotImplementedException();
}

List<TipoGas^>^ ConfiguracionSistema::ObtenerTiposGas()
{
    throw gcnew System::NotImplementedException();
}

void ConfiguracionSistema::ActualizarUmbrales(double activacion, double desactivacion, double critico)
{
    throw gcnew System::NotImplementedException();
}

void ConfiguracionSistema::SetLimiteExposicion(double valor)
{
    throw gcnew System::NotImplementedException();
}

double ConfiguracionSistema::GetLimiteExposicion()
{
    throw gcnew System::NotImplementedException();
}

void ConfiguracionSistema::GetUmbrales()
{
    throw gcnew System::NotImplementedException();
}
