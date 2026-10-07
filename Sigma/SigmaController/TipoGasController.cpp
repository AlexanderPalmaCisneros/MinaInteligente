#include "pch.h"
#include "TipoGasController.h"
#include "Validaciones.h"

using namespace SigmaController;
using namespace SigmaDAO;

TipoGasController::TipoGasController() {
}

String^ TipoGasController::ValidarDatos(TipoGas^ elemento) {
	if (elemento == nullptr) {
		return "Los datos ingresados no son válidos.";
	}
	if (!Validaciones::TextoValido(elemento->GetNombre())) return "El nombre es obligatorio y no puede contener ';'.";
	if (!Validaciones::TextoValido(elemento->GetSimbolo())) return "El símbolo es obligatorio y no puede contener ';'.";
	if (elemento->GetGeneracionGasDefault() < 0) return "La generación de gas por defecto no puede ser negativa.";

	TipoGasDAO^ dao = gcnew TipoGasDAO();
	for each (TipoGas ^ otro in dao->ListarTiposGas()) {
		if (UtilDAO::Igual(otro->GetId(), elemento->GetId())) continue;
		if (UtilDAO::Igual(otro->GetNombre(), elemento->GetNombre()))
			return "Ya existe un tipo de gas llamado '" + otro->GetNombre() + "' (" + otro->GetId() + ").";
		if (UtilDAO::Igual(otro->GetSimbolo(), elemento->GetSimbolo()))
			return "El símbolo '" + otro->GetSimbolo() + "' ya lo usa el tipo de gas " + otro->GetId() + ".";
	}
	return nullptr;
}

String^ TipoGasController::GenerarId() {
    TipoGasDAO^ dao = gcnew TipoGasDAO();
    return dao->GenerarId();
}

String^ TipoGasController::RegistrarTipoGas(TipoGas^ elemento) {
    String^ error = ValidarDatos(elemento);
    if (error != nullptr) {
        return error;
    }
    TipoGasDAO^ dao = gcnew TipoGasDAO();
    if (!dao->RegistrarTipoGas(elemento)) {
        return "Ya existe un tipo de gas con el id " + elemento->GetId() + ".";
    }
    return nullptr;
}

TipoGas^ TipoGasController::ConsultarTipoGas(String^ id) {
    if (String::IsNullOrEmpty(id)) {
        return nullptr;
    }
    TipoGasDAO^ dao = gcnew TipoGasDAO();
    return dao->ConsultarTipoGas(id);
}

List<TipoGas^>^ TipoGasController::ListarTiposGas() {
    TipoGasDAO^ dao = gcnew TipoGasDAO();
    return dao->ListarTiposGas();
}

List<TipoGas^>^ TipoGasController::BuscarTiposGas(String^ texto) {
    List<TipoGas^>^ filtrados = gcnew List<TipoGas^>();
    for each (TipoGas ^ e in ListarTiposGas()) {
        if (Validaciones::Contiene(e->GetNombre(), texto) || Validaciones::Contiene(e->GetId(), texto) || Validaciones::Contiene(e->GetSimbolo(), texto)) {
            filtrados->Add(e);
        }
    }
    return filtrados;
}

String^ TipoGasController::ModificarTipoGas(TipoGas^ elemento) {
    String^ error = ValidarDatos(elemento);
    if (error != nullptr) {
        return error;
    }
    TipoGasDAO^ dao = gcnew TipoGasDAO();
    if (!dao->ModificarTipoGas(elemento)) {
        return "No existe un tipo de gas con el id " + elemento->GetId() + ".";
    }
    return nullptr;
}

String^ TipoGasController::EliminarTipoGas(String^ id) {
    TipoGasDAO^ dao = gcnew TipoGasDAO();
	SensorGasDAO^ sensorDAO = gcnew SensorGasDAO();
	for each (SensorGas ^ s in sensorDAO->ListarSensoresGas()) {
		if (s->GetTipoGas() != nullptr && UtilDAO::Igual(s->GetTipoGas()->GetId(), id)) {
			return "No se puede eliminar: el sensor " + s->GetId() + " usa este tipo de gas.";
		}
	}
    if (!dao->EliminarTipoGas(id)) {
        return "No existe un tipo de gas con el id " + id + ".";
    }
    return nullptr;
}
