#include "pch.h"
#include "SupervisorController.h"
#include "Validaciones.h"

using namespace SigmaController;
using namespace SigmaDAO;

SupervisorController::SupervisorController() {
}

String^ SupervisorController::ValidarDatos(Supervisor^ elemento) {
	if (elemento == nullptr) {
		return "Los datos ingresados no son válidos.";
	}
	if (!Validaciones::TextoValido(elemento->GetNombre())) return "El nombre es obligatorio y no puede contener ';'.";
	if (!Validaciones::TextoValido(elemento->GetCredenciales()) || elemento->GetCredenciales()->Length < 4)
		return "La contraseña es obligatoria, de al menos 4 caracteres y sin ';'.";
	if (!Validaciones::CorreoValido(elemento->GetCorreo())) return "El correo no tiene un formato válido (ejemplo: nombre@dominio.com).";
	if (!Validaciones::TelefonoValido(elemento->GetTelefono())) return "El teléfono debe tener entre 7 y 15 dígitos (puede iniciar con +).";

	SupervisorDAO^ dao = gcnew SupervisorDAO();
	for each (Supervisor ^ otro in dao->ListarSupervisores()) {
		if (UtilDAO::Igual(otro->GetId(), elemento->GetId())) continue;
		if (UtilDAO::Igual(otro->GetNombre(), elemento->GetNombre()))
			return "Ya existe un supervisor llamado '" + otro->GetNombre() + "' (" + otro->GetId() + ").";
		if (UtilDAO::Igual(otro->GetCorreo(), elemento->GetCorreo()))
			return "El correo '" + otro->GetCorreo() + "' ya está registrado para el supervisor " + otro->GetId() + ".";
	}
	return nullptr;
}

String^ SupervisorController::GenerarId() {
    SupervisorDAO^ dao = gcnew SupervisorDAO();
    return dao->GenerarId();
}

String^ SupervisorController::RegistrarSupervisor(Supervisor^ elemento) {
    String^ error = ValidarDatos(elemento);
    if (error != nullptr) {
        return error;
    }
    SupervisorDAO^ dao = gcnew SupervisorDAO();
    if (!dao->RegistrarSupervisor(elemento)) {
        return "Ya existe un supervisor con el id " + elemento->GetId() + ".";
    }
    return nullptr;
}

Supervisor^ SupervisorController::ConsultarSupervisor(String^ id) {
    if (String::IsNullOrEmpty(id)) {
        return nullptr;
    }
    SupervisorDAO^ dao = gcnew SupervisorDAO();
    return dao->ConsultarSupervisor(id);
}

List<Supervisor^>^ SupervisorController::ListarSupervisores() {
    SupervisorDAO^ dao = gcnew SupervisorDAO();
    return dao->ListarSupervisores();
}

List<Supervisor^>^ SupervisorController::BuscarSupervisores(String^ texto) {
    List<Supervisor^>^ filtrados = gcnew List<Supervisor^>();
    for each (Supervisor ^ e in ListarSupervisores()) {
        if (Validaciones::Contiene(e->GetNombre(), texto) || Validaciones::Contiene(e->GetId(), texto) || Validaciones::Contiene(e->GetCorreo(), texto)) {
            filtrados->Add(e);
        }
    }
    return filtrados;
}

String^ SupervisorController::ModificarSupervisor(Supervisor^ elemento) {
    String^ error = ValidarDatos(elemento);
    if (error != nullptr) {
        return error;
    }
    SupervisorDAO^ dao = gcnew SupervisorDAO();
    if (!dao->ModificarSupervisor(elemento)) {
        return "No existe un supervisor con el id " + elemento->GetId() + ".";
    }
    return nullptr;
}

String^ SupervisorController::EliminarSupervisor(String^ id) {
    SupervisorDAO^ dao = gcnew SupervisorDAO();
    if (!dao->EliminarSupervisor(id)) {
        return "No existe un supervisor con el id " + id + ".";
    }
    return nullptr;
}

Supervisor^ SupervisorController::Autenticar(String^ usuario, String^ clave) {
    if (String::IsNullOrWhiteSpace(usuario) || String::IsNullOrEmpty(clave)) {
        return nullptr;
    }
    SupervisorDAO^ dao = gcnew SupervisorDAO();
    for each (Supervisor ^ s in dao->ListarSupervisores()) {
        if ((UtilDAO::Igual(s->GetId(), usuario) || UtilDAO::Igual(s->GetNombre(), usuario)) && s->ValidarCredenciales(clave)) {
            return s;
        }
    }
    return nullptr;
}
