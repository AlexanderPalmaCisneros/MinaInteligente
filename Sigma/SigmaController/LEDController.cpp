#include "pch.h"
#include "LEDController.h"
#include "Validaciones.h"

using namespace SigmaController;
using namespace SigmaDAO;

LEDController::LEDController() {
}

String^ LEDController::ValidarDatos(LED^ elemento) {
	if (elemento == nullptr) {
		return "Los datos ingresados no son válidos.";
	}
	// Una zona puede tener varios dispositivos del mismo tipo: no hay limite por zona.
	return nullptr;
}

String^ LEDController::GenerarId() {
    LEDDAO^ dao = gcnew LEDDAO();
    return dao->GenerarId();
}

String^ LEDController::RegistrarLED(LED^ elemento) {
    String^ error = ValidarDatos(elemento);
    if (error != nullptr) {
        return error;
    }
    LEDDAO^ dao = gcnew LEDDAO();
    if (!dao->RegistrarLED(elemento)) {
        return "Ya existe un LED con el id " + elemento->GetId() + ".";
    }
    return nullptr;
}

LED^ LEDController::ConsultarLED(String^ id) {
    if (String::IsNullOrEmpty(id)) {
        return nullptr;
    }
    LEDDAO^ dao = gcnew LEDDAO();
    return dao->ConsultarLED(id);
}

List<LED^>^ LEDController::ListarLEDs() {
    LEDDAO^ dao = gcnew LEDDAO();
    return dao->ListarLEDs();
}

String^ LEDController::ModificarLED(LED^ elemento) {
    String^ error = ValidarDatos(elemento);
    if (error != nullptr) {
        return error;
    }
    LEDDAO^ dao = gcnew LEDDAO();
    if (!dao->ModificarLED(elemento)) {
        return "No existe un LED con el id " + elemento->GetId() + ".";
    }
    return nullptr;
}

String^ LEDController::EliminarLED(String^ id) {
    LEDDAO^ dao = gcnew LEDDAO();
    if (!dao->EliminarLED(id)) {
        return "No existe un LED con el id " + id + ".";
    }
    return nullptr;
}
