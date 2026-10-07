#include "pch.h"
#include "TrabajadorController.h"
#include "Validaciones.h"

using namespace SigmaController;
using namespace SigmaDAO;

TrabajadorController::TrabajadorController() {
}

String^ TrabajadorController::ValidarDatos(Trabajador^ elemento) {
	if (elemento == nullptr) {
		return "Los datos ingresados no son válidos.";
	}
	if (!Validaciones::TextoValido(elemento->GetNombre())) return "El nombre es obligatorio y no puede contener ';'.";
	if (!Validaciones::TextoValido(elemento->GetIdRFID())) return "El RFID es obligatorio y no puede contener ';'.";
	if (!Validaciones::CorreoValido(elemento->GetCorreo())) return "El correo no tiene un formato válido (ejemplo: nombre@dominio.com).";
	if (!Validaciones::TelefonoValido(elemento->GetTelefono())) return "El teléfono debe tener entre 7 y 15 dígitos (puede iniciar con +).";

	TrabajadorDAO^ dao = gcnew TrabajadorDAO();
	for each (Trabajador ^ otro in dao->ListarTrabajadores()) {
		if (UtilDAO::Igual(otro->GetId(), elemento->GetId())) continue;
		if (UtilDAO::Igual(otro->GetNombre(), elemento->GetNombre()))
			return "Ya existe un obrero llamado '" + otro->GetNombre() + "' (" + otro->GetId() + ").";
		if (UtilDAO::Igual(otro->GetIdRFID(), elemento->GetIdRFID()))
			return "El RFID '" + otro->GetIdRFID() + "' ya está asignado al obrero " + otro->GetId() + ".";
		if (UtilDAO::Igual(otro->GetCorreo(), elemento->GetCorreo()))
			return "El correo '" + otro->GetCorreo() + "' ya está registrado para el obrero " + otro->GetId() + ".";
	}
	return nullptr;
}

String^ TrabajadorController::GenerarId() {
    TrabajadorDAO^ dao = gcnew TrabajadorDAO();
    return dao->GenerarId();
}

String^ TrabajadorController::RegistrarTrabajador(Trabajador^ elemento) {
    String^ error = ValidarDatos(elemento);
    if (error != nullptr) {
        return error;
    }
    TrabajadorDAO^ dao = gcnew TrabajadorDAO();
    if (!dao->RegistrarTrabajador(elemento)) {
        return "Ya existe un obrero con el id " + elemento->GetId() + ".";
    }
    return nullptr;
}

Trabajador^ TrabajadorController::ConsultarTrabajador(String^ id) {
    if (String::IsNullOrEmpty(id)) {
        return nullptr;
    }
    TrabajadorDAO^ dao = gcnew TrabajadorDAO();
    return dao->ConsultarTrabajador(id);
}

List<Trabajador^>^ TrabajadorController::ListarTrabajadores() {
    TrabajadorDAO^ dao = gcnew TrabajadorDAO();
    return dao->ListarTrabajadores();
}

List<Trabajador^>^ TrabajadorController::BuscarTrabajadores(String^ texto) {
    List<Trabajador^>^ filtrados = gcnew List<Trabajador^>();
    for each (Trabajador ^ e in ListarTrabajadores()) {
        if (Validaciones::Contiene(e->GetNombre(), texto) || Validaciones::Contiene(e->GetId(), texto) || Validaciones::Contiene(e->GetIdRFID(), texto) || Validaciones::Contiene(e->GetCorreo(), texto)) {
            filtrados->Add(e);
        }
    }
    return filtrados;
}

String^ TrabajadorController::ModificarTrabajador(Trabajador^ elemento) {
    String^ error = ValidarDatos(elemento);
    if (error != nullptr) {
        return error;
    }
    TrabajadorDAO^ dao = gcnew TrabajadorDAO();
    if (!dao->ModificarTrabajador(elemento)) {
        return "No existe un obrero con el id " + elemento->GetId() + ".";
    }
    return nullptr;
}

String^ TrabajadorController::EliminarTrabajador(String^ id) {
    TrabajadorDAO^ dao = gcnew TrabajadorDAO();
    if (!dao->EliminarTrabajador(id)) {
        return "No existe un obrero con el id " + id + ".";
    }
    return nullptr;
}
