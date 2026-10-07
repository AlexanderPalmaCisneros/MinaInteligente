#include "pch.h"
#include "SistemaMonitoreo.h"
#include "GrafoZonas.h"
#include "Alarma.h"
#include "Zona.h"
#include "SensorGas.h"
#include "Ventilador.h"
#include "LED.h"
#include "OrigenAlarma.h"
#include "FuenteDatosReal.h"
#include "FuenteDatosSimulada.h"

using namespace SigmaModel;

SistemaMonitoreo::SistemaMonitoreo(GrafoZonas^ grafoZonas)
{
    this->grafoZonas = grafoZonas;
    this->alarmasActivas = gcnew List<Alarma^>();
}

void SistemaMonitoreo::ActualizarCiclo()
{
    for each (Zona ^ zona in this->grafoZonas->ObtenerZonas())
    {
        SensorGas^ sensor = zona->ObtenerSensorGas();
        if (sensor != nullptr)
        {
            sensor->Actualizar();
        }

        zona->ActualizarConcentracion();

        Ventilador^ ventilador = zona->ObtenerVentilador();
        if (ventilador != nullptr)
        {
            ventilador->Actualizar();
        }

        this->EvaluarZona(zona);
    }
}

void SistemaMonitoreo::EvaluarZona(Zona^ zona)
{
    TipoRiesgo riesgo = zona->EvaluarRiesgoDirecto();
    zona->SetTipoRiesgo(riesgo);

    if (riesgo == TipoRiesgo::DIRECTO)
    {
        this->grafoZonas->PropagarRiesgoIndirecto(zona);
        this->GenerarAlarmaAutomatica(zona, NivelRiesgo::CRITICO, TipoRiesgo::DIRECTO);
    }

    LED^ led = zona->ObtenerLed();
    if (led != nullptr)
    {
        led->Actualizar();
    }
}

Alarma^ SistemaMonitoreo::GenerarAlarmaAutomatica(Zona^ zona, NivelRiesgo nivelRiesgo, TipoRiesgo tipoRiesgo)
{
    SensorGas^ sensor = zona->ObtenerSensorGas();
    double concentracion = (sensor != nullptr) ? sensor->GetLecturaActual() : 0.0;

    Alarma^ alarma = gcnew Alarma(zona, tipoRiesgo, "Umbral critico superado", concentracion,
        nivelRiesgo, OrigenAlarma::AUTOMATICA, nullptr);

    this->alarmasActivas->Add(alarma);
    return alarma;
}

List<Alarma^>^ SistemaMonitoreo::ObtenerAlarmasActivas()
{
    return this->alarmasActivas;
}

void SistemaMonitoreo::CambiarModoOperacion(ModoOperacion modo)
{
    // Recorre GrafoZonas -> Zona -> SensorGas e inyecta la fuente
    // correspondiente (Strategy). No toca ConfiguracionSistema: eso ya lo
    // hace el Administrador antes de llamar a este metodo.
    for each (Zona ^ zona in this->grafoZonas->ObtenerZonas())
    {
        SensorGas^ sensor = zona->ObtenerSensorGas();
        if (sensor == nullptr)
        {
            continue;
        }

        FuenteDatos^ fuente;
        if (modo == ModoOperacion::REAL)
        {
            fuente = gcnew FuenteDatosReal();
        }
        else
        {
            fuente = gcnew FuenteDatosSimulada(zona, 0.0);
        }

        sensor->SetFuenteLectura(fuente);
    }
}
