#include "pch.h"
#include "VentiladorController.h"
#include "Validaciones.h"

using namespace SigmaController;
using namespace SigmaDAO;

VentiladorController::VentiladorController() {
}

String^ VentiladorController::ValidarDatos(Ventilador^ elemento) {
	if (elemento == nullptr) {
		return "Los datos ingresados no son válidos.";
	}
	if (elemento->GetCaudal() <= 0) return "El caudal debe ser mayor que cero.";
	// Una zona puede tener varios dispositivos del mismo tipo: no hay limite por zona.
	return nullptr;
}

String^ VentiladorController::GenerarId() {
    VentiladorDAO^ dao = gcnew VentiladorDAO();
    return dao->GenerarId();
}

String^ VentiladorController::RegistrarVentilador(Ventilador^ elemento) {
    String^ error = ValidarDatos(elemento);
    if (error != nullptr) {
        return error;
    }
    VentiladorDAO^ dao = gcnew VentiladorDAO();
    if (!dao->RegistrarVentilador(elemento)) {
        return "Ya existe un ventilador con el id " + elemento->GetId() + ".";
    }
    return nullptr;
}

Ventilador^ VentiladorController::ConsultarVentilador(String^ id) {
    if (String::IsNullOrEmpty(id)) {
        return nullptr;
    }
    VentiladorDAO^ dao = gcnew VentiladorDAO();
    return dao->ConsultarVentilador(id);
}

List<Ventilador^>^ VentiladorController::ListarVentiladores() {
    VentiladorDAO^ dao = gcnew VentiladorDAO();
    return dao->ListarVentiladores();
}

String^ VentiladorController::ModificarVentilador(Ventilador^ elemento) {
    String^ error = ValidarDatos(elemento);
    if (error != nullptr) {
        return error;
    }
    VentiladorDAO^ dao = gcnew VentiladorDAO();
    if (!dao->ModificarVentilador(elemento)) {
        return "No existe un ventilador con el id " + elemento->GetId() + ".";
    }
    return nullptr;
}

String^ VentiladorController::EliminarVentilador(String^ id) {
    VentiladorDAO^ dao = gcnew VentiladorDAO();
    if (!dao->EliminarVentilador(id)) {
        return "No existe un ventilador con el id " + id + ".";
    }
    return nullptr;
}
