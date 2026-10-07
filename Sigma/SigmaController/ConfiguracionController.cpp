#include "pch.h"
#include "ConfiguracionController.h"

using namespace SigmaController;

ConfiguracionController::ConfiguracionController() {
}

double ConfiguracionController::GetUmbralActivacion() {
    return ConfiguracionSistema::ObtenerInstancia()->GetUmbralActivacion();
}

double ConfiguracionController::GetUmbralDesactivacion() {
    return ConfiguracionSistema::ObtenerInstancia()->GetUmbralDesactivacion();
}

double ConfiguracionController::GetUmbralCritico() {
    return ConfiguracionSistema::ObtenerInstancia()->GetUmbralCritico();
}

double ConfiguracionController::GetLimiteExposicion() {
    return ConfiguracionSistema::ObtenerInstancia()->GetLimiteExposicion();
}

ModoOperacion ConfiguracionController::GetModoOperacion() {
    return ConfiguracionSistema::ObtenerInstancia()->GetModoOperacion();
}

String^ ConfiguracionController::ActualizarUmbrales(double activacion, double desactivacion, double critico) {
    if (desactivacion <= 0) {
        return "Los umbrales deben ser mayores que cero.";
    }
    if (desactivacion >= activacion) {
        return "El umbral de desactivación debe ser menor que el de activación (histéresis).";
    }
    if (activacion >= critico) {
        return "El umbral de activación debe ser menor que el umbral crítico.";
    }
    if (!ConfiguracionSistema::ObtenerInstancia()->ActualizarUmbrales(activacion, desactivacion, critico)) {
        return "Los umbrales ingresados no son válidos.";
    }
    return nullptr;
}

String^ ConfiguracionController::ActualizarLimiteExposicion(double limite) {
    if (!ConfiguracionSistema::ObtenerInstancia()->SetLimiteExposicion(limite)) {
        return "El límite de exposición debe ser mayor que cero.";
    }
    return nullptr;
}

void ConfiguracionController::CambiarModoOperacion(ModoOperacion modo) {
    ConfiguracionSistema::ObtenerInstancia()->SetModoOperacion(modo);
}
