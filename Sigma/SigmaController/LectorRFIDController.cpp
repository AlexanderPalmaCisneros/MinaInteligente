#include "pch.h"
#include "LectorRFIDController.h"
#include "Validaciones.h"

using namespace SigmaController;
using namespace SigmaDAO;

LectorRFIDController::LectorRFIDController() {
}

String^ LectorRFIDController::ValidarDatos(LectorRFID^ elemento) {
	if (elemento == nullptr) {
		return "Los datos ingresados no son válidos.";
	}
	// Una zona puede tener varios lectores (por ejemplo, entrada y salida).
	return nullptr;
}

String^ LectorRFIDController::GenerarId() {
    LectorRFIDDAO^ dao = gcnew LectorRFIDDAO();
    return dao->GenerarId();
}

String^ LectorRFIDController::RegistrarLectorRFID(LectorRFID^ elemento) {
    String^ error = ValidarDatos(elemento);
    if (error != nullptr) {
        return error;
    }
    LectorRFIDDAO^ dao = gcnew LectorRFIDDAO();
    if (!dao->RegistrarLectorRFID(elemento)) {
        return "Ya existe un lector RFID con el id " + elemento->GetId() + ".";
    }
    return nullptr;
}

LectorRFID^ LectorRFIDController::ConsultarLectorRFID(String^ id) {
    if (String::IsNullOrEmpty(id)) {
        return nullptr;
    }
    LectorRFIDDAO^ dao = gcnew LectorRFIDDAO();
    return dao->ConsultarLectorRFID(id);
}

List<LectorRFID^>^ LectorRFIDController::ListarLectoresRFID() {
    LectorRFIDDAO^ dao = gcnew LectorRFIDDAO();
    return dao->ListarLectoresRFID();
}

String^ LectorRFIDController::ModificarLectorRFID(LectorRFID^ elemento) {
    String^ error = ValidarDatos(elemento);
    if (error != nullptr) {
        return error;
    }
    LectorRFIDDAO^ dao = gcnew LectorRFIDDAO();
    if (!dao->ModificarLectorRFID(elemento)) {
        return "No existe un lector RFID con el id " + elemento->GetId() + ".";
    }
    return nullptr;
}

String^ LectorRFIDController::EliminarLectorRFID(String^ id) {
    LectorRFIDDAO^ dao = gcnew LectorRFIDDAO();
    if (!dao->EliminarLectorRFID(id)) {
        return "No existe un lector RFID con el id " + id + ".";
    }
    return nullptr;
}
