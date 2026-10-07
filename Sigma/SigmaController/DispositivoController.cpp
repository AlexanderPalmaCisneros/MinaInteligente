#include "pch.h"
#include "DispositivoController.h"
#include "Validaciones.h"
#include "LEDController.h"
#include "VentiladorController.h"
#include "SensorGasController.h"
#include "LectorRFIDController.h"

using namespace SigmaController;
using namespace SigmaDAO;

DispositivoController::DispositivoController() {
}

array<String^>^ DispositivoController::ObtenerTipos() {
    return gcnew array<String^> { "LED", "VENTILADOR", "SENSOR GAS", "LECTOR RFID" };
}

List<Dispositivo^>^ DispositivoController::ListarDispositivos() {
    List<Dispositivo^>^ lista = gcnew List<Dispositivo^>();

    for each (LED ^ led in (gcnew LEDController())->ListarLEDs()) {
        lista->Add(led);
    }
    for each (Ventilador ^ ventilador in (gcnew VentiladorController())->ListarVentiladores()) {
        lista->Add(ventilador);
    }
    for each (SensorGas ^ sensor in (gcnew SensorGasController())->ListarSensoresGas()) {
        lista->Add(sensor);
    }
    for each (LectorRFID ^ lector in (gcnew LectorRFIDController())->ListarLectoresRFID()) {
        lista->Add(lector);
    }
    return lista;
}

List<Dispositivo^>^ DispositivoController::BuscarDispositivos(String^ texto, String^ tipo) {
    List<Dispositivo^>^ filtrados = gcnew List<Dispositivo^>();
    bool todosLosTipos = String::IsNullOrEmpty(tipo) || tipo == "TODOS";

    for each (Dispositivo ^ d in ListarDispositivos()) {
        String^ tipoDispositivo = ObtenerTipo(d);
        if (!todosLosTipos && tipoDispositivo != tipo) {
            continue;
        }

        bool coincide = Validaciones::Contiene(d->GetId(), texto) || Validaciones::Contiene(tipoDispositivo, texto);
        if (!coincide && d->GetZonaAsociada() != nullptr) {
            coincide = Validaciones::Contiene(d->GetZonaAsociada()->GetId(), texto) ||
                Validaciones::Contiene(d->GetZonaAsociada()->GetNombre(), texto);
        }
        if (coincide) {
            filtrados->Add(d);
        }
    }
    return filtrados;
}

Dispositivo^ DispositivoController::ConsultarDispositivo(String^ id) {
    for each (Dispositivo ^ d in ListarDispositivos()) {
        if (UtilDAO::Igual(d->GetId(), id)) {
            return d;
        }
    }
    return nullptr;
}

String^ DispositivoController::ObtenerTipo(Dispositivo^ dispositivo) {
    if (dynamic_cast<LED^>(dispositivo) != nullptr) return "LED";
    if (dynamic_cast<Ventilador^>(dispositivo) != nullptr) return "VENTILADOR";
    if (dynamic_cast<SensorGas^>(dispositivo) != nullptr) return "SENSOR GAS";
    if (dynamic_cast<LectorRFID^>(dispositivo) != nullptr) return "LECTOR RFID";
    return "DESCONOCIDO";
}

String^ DispositivoController::ObtenerDetalle(Dispositivo^ dispositivo) {
    LED^ led = dynamic_cast<LED^>(dispositivo);
    if (led != nullptr) {
        return "Color: " + led->GetColor().ToString() + " / " + (led->GetEncendido() ? "Encendido" : "Apagado");
    }

    Ventilador^ ventilador = dynamic_cast<Ventilador^>(dispositivo);
    if (ventilador != nullptr) {
        return "Caudal: " + ventilador->GetCaudal().ToString(System::Globalization::CultureInfo::InvariantCulture) + " m3/min";
    }

    SensorGas^ sensor = dynamic_cast<SensorGas^>(dispositivo);
    if (sensor != nullptr) {
        if (sensor->GetTipoGas() == nullptr) {
            return "Gas: (sin asignar)";
        }
        return "Gas: " + sensor->GetTipoGas()->GetNombre() + " (" + sensor->GetTipoGas()->GetSimbolo() + ")";
    }
    return "";
}

String^ DispositivoController::EliminarDispositivo(String^ id) {
    Dispositivo^ dispositivo = ConsultarDispositivo(id);
    if (dispositivo == nullptr) {
        return "No existe un dispositivo con el id " + id + ".";
    }

    if (dynamic_cast<LED^>(dispositivo) != nullptr) return (gcnew LEDController())->EliminarLED(id);
    if (dynamic_cast<Ventilador^>(dispositivo) != nullptr) return (gcnew VentiladorController())->EliminarVentilador(id);
    if (dynamic_cast<SensorGas^>(dispositivo) != nullptr) return (gcnew SensorGasController())->EliminarSensorGas(id);
    return (gcnew LectorRFIDController())->EliminarLectorRFID(id);
}
