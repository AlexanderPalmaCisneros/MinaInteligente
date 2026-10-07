#include "pch.h"
#include "ConfiguracionSistema.h"

using namespace SigmaModel;
using namespace System::IO;
using namespace System::Globalization;


// Constructor privado
ConfiguracionSistema::ConfiguracionSistema() {
    tiposGasDisponibles = gcnew List<TipoGas^>();
    // Valores por defecto (requisitos 7): se usan si no existe configuracion.txt.
    umbralActivacion = 80.0;
    umbralDesactivacion = 40.0;
    umbralCritico = 150.0;
    limiteExposicion = 5000.0;
    modoOperacion = ModoOperacion::SIMULACION;
}

ConfiguracionSistema^ ConfiguracionSistema::ObtenerInstancia() {
    if (instancia == nullptr) {
        instancia = gcnew ConfiguracionSistema();
        instancia->CargarConfiguracion();
    }
    return instancia;
}

void ConfiguracionSistema::CargarConfiguracion() {
    if (!File::Exists("configuracion.txt")) {
        return;
    }

    // Se parte de los valores actuales y se sobrescribe lo que el archivo traiga bien formado.
    double activacion = umbralActivacion;
    double desactivacion = umbralDesactivacion;
    double critico = umbralCritico;
    double limite = limiteExposicion;

    array<String^>^ lineas = File::ReadAllLines("configuracion.txt");
    String^ separadores = ";";

    for each (String ^ linea in lineas) {
        if (String::IsNullOrWhiteSpace(linea)) continue;

        array<String^>^ datos = linea->Split(separadores->ToCharArray());
        if (datos->Length < 2) continue;

        String^ clave = datos[0]->Trim();
        double valor;
        if (!Double::TryParse(datos[1], NumberStyles::Float, CultureInfo::InvariantCulture, valor)) continue;

        if (clave == "umbralActivacion") activacion = valor;
        else if (clave == "umbralDesactivacion") desactivacion = valor;
        else if (clave == "umbralCritico") critico = valor;
        else if (clave == "limiteExposicion") limite = valor;
        else if (clave == "modoOperacion") modoOperacion = (valor == 0.0) ? ModoOperacion::REAL : ModoOperacion::SIMULACION;
    }

    // Un archivo inconsistente no debe dejar al sistema con umbrales invalidos.
    if (desactivacion > 0 && desactivacion < activacion && activacion < critico) {
        umbralActivacion = activacion;
        umbralDesactivacion = desactivacion;
        umbralCritico = critico;
    }
    if (limite > 0) {
        limiteExposicion = limite;
    }
}

void ConfiguracionSistema::GuardarConfiguracion() {
    array<String^>^ lineas = gcnew array<String^>(5);
    lineas[0] = "umbralActivacion;" + umbralActivacion.ToString(CultureInfo::InvariantCulture);
    lineas[1] = "umbralDesactivacion;" + umbralDesactivacion.ToString(CultureInfo::InvariantCulture);
    lineas[2] = "umbralCritico;" + umbralCritico.ToString(CultureInfo::InvariantCulture);
    lineas[3] = "limiteExposicion;" + limiteExposicion.ToString(CultureInfo::InvariantCulture);
    lineas[4] = "modoOperacion;" + ((modoOperacion == ModoOperacion::REAL) ? "0" : "1");
    File::WriteAllLines("configuracion.txt", lineas);
}

ModoOperacion ConfiguracionSistema::GetModoOperacion() {
    return modoOperacion;
}

void ConfiguracionSistema::SetModoOperacion(ModoOperacion modo) {
    modoOperacion = modo;
    GuardarConfiguracion();
}

void ConfiguracionSistema::AgregarTipoGas(TipoGas^ tipo) {
    tiposGasDisponibles->Add(tipo);
}

List<TipoGas^>^ ConfiguracionSistema::ObtenerTiposGas() {
    return tiposGasDisponibles;
}

bool ConfiguracionSistema::ActualizarUmbrales(double activacion, double desactivacion, double critico) {
    // Histeresis (requisito 4.2): desactivacion < activacion < critico.
    if (desactivacion <= 0 || desactivacion >= activacion || activacion >= critico) {
        return false;
    }
    umbralActivacion = activacion;
    umbralDesactivacion = desactivacion;
    umbralCritico = critico;
    GuardarConfiguracion();
    return true;
}

bool ConfiguracionSistema::SetLimiteExposicion(double valor) {
    if (valor <= 0) {
        return false;
    }
    limiteExposicion = valor;
    GuardarConfiguracion();
    return true;
}

double ConfiguracionSistema::GetLimiteExposicion() {
    return limiteExposicion;
}

double ConfiguracionSistema::GetUmbralActivacion() {
    return umbralActivacion;
}

double ConfiguracionSistema::GetUmbralDesactivacion() {
    return umbralDesactivacion;
}

double ConfiguracionSistema::GetUmbralCritico() {
    return umbralCritico;
}