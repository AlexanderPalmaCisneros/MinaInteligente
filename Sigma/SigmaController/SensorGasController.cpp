#include "pch.h"
#include "SensorGasController.h"
#include "Validaciones.h"

using namespace SigmaController;
using namespace SigmaDAO;

SensorGasController::SensorGasController() {
}

String^ SensorGasController::ValidarDatos(SensorGas^ elemento) {
	if (elemento == nullptr) {
		return "Los datos ingresados no son válidos.";
	}
	if (elemento->GetTipoGas() == nullptr) return "Debe seleccionar un tipo de gas.";
	// Una zona puede tener varios dispositivos del mismo tipo: no hay limite por zona.
	return nullptr;
}

String^ SensorGasController::GenerarId() {
    SensorGasDAO^ dao = gcnew SensorGasDAO();
    return dao->GenerarId();
}

String^ SensorGasController::RegistrarSensorGas(SensorGas^ elemento) {
    String^ error = ValidarDatos(elemento);
    if (error != nullptr) {
        return error;
    }
    SensorGasDAO^ dao = gcnew SensorGasDAO();
    if (!dao->RegistrarSensorGas(elemento)) {
        return "Ya existe un sensor de gas con el id " + elemento->GetId() + ".";
    }
    return nullptr;
}

SensorGas^ SensorGasController::ConsultarSensorGas(String^ id) {
    if (String::IsNullOrEmpty(id)) {
        return nullptr;
    }
    SensorGasDAO^ dao = gcnew SensorGasDAO();
    return dao->ConsultarSensorGas(id);
}

List<SensorGas^>^ SensorGasController::ListarSensoresGas() {
    SensorGasDAO^ dao = gcnew SensorGasDAO();
    return dao->ListarSensoresGas();
}

String^ SensorGasController::ModificarSensorGas(SensorGas^ elemento) {
    String^ error = ValidarDatos(elemento);
    if (error != nullptr) {
        return error;
    }
    SensorGasDAO^ dao = gcnew SensorGasDAO();
    if (!dao->ModificarSensorGas(elemento)) {
        return "No existe un sensor de gas con el id " + elemento->GetId() + ".";
    }
    return nullptr;
}

String^ SensorGasController::EliminarSensorGas(String^ id) {
    SensorGasDAO^ dao = gcnew SensorGasDAO();
    if (!dao->EliminarSensorGas(id)) {
        return "No existe un sensor de gas con el id " + id + ".";
    }
    return nullptr;
}
