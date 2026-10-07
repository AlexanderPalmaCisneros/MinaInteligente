#include "pch.h"
#include "AdministradorController.h"
#include "Validaciones.h"

using namespace SigmaController;
using namespace SigmaDAO;

AdministradorController::AdministradorController() {
}

String^ AdministradorController::ValidarDatos(Administrador^ elemento) {
	if (elemento == nullptr) {
		return "Los datos ingresados no son válidos.";
	}
	if (!Validaciones::TextoValido(elemento->GetNombre())) return "El nombre es obligatorio y no puede contener ';'.";
	if (!Validaciones::TextoValido(elemento->GetCredenciales()) || elemento->GetCredenciales()->Length < 4)
		return "La contraseña es obligatoria, de al menos 4 caracteres y sin ';'.";
	if (!Validaciones::CorreoValido(elemento->GetCorreo())) return "El correo no tiene un formato válido (ejemplo: nombre@dominio.com).";
	if (!Validaciones::TelefonoValido(elemento->GetTelefono())) return "El teléfono debe tener entre 7 y 15 dígitos (puede iniciar con +).";

	AdministradorDAO^ dao = gcnew AdministradorDAO();
	for each (Administrador ^ otro in dao->ListarAdministradores()) {
		if (UtilDAO::Igual(otro->GetId(), elemento->GetId())) continue;
		if (UtilDAO::Igual(otro->GetNombre(), elemento->GetNombre()))
			return "Ya existe un administrador llamado '" + otro->GetNombre() + "' (" + otro->GetId() + ").";
		if (UtilDAO::Igual(otro->GetCorreo(), elemento->GetCorreo()))
			return "El correo '" + otro->GetCorreo() + "' ya está registrado para el administrador " + otro->GetId() + ".";
	}
	return nullptr;
}

String^ AdministradorController::GenerarId() {
    AdministradorDAO^ dao = gcnew AdministradorDAO();
    return dao->GenerarId();
}

String^ AdministradorController::RegistrarAdministrador(Administrador^ elemento) {
    String^ error = ValidarDatos(elemento);
    if (error != nullptr) {
        return error;
    }
    AdministradorDAO^ dao = gcnew AdministradorDAO();
    if (!dao->RegistrarAdministrador(elemento)) {
        return "Ya existe un administrador con el id " + elemento->GetId() + ".";
    }
    return nullptr;
}

Administrador^ AdministradorController::ConsultarAdministrador(String^ id) {
    if (String::IsNullOrEmpty(id)) {
        return nullptr;
    }
    AdministradorDAO^ dao = gcnew AdministradorDAO();
    return dao->ConsultarAdministrador(id);
}

List<Administrador^>^ AdministradorController::ListarAdministradores() {
    AdministradorDAO^ dao = gcnew AdministradorDAO();
    return dao->ListarAdministradores();
}

List<Administrador^>^ AdministradorController::BuscarAdministradores(String^ texto) {
    List<Administrador^>^ filtrados = gcnew List<Administrador^>();
    for each (Administrador ^ e in ListarAdministradores()) {
        if (Validaciones::Contiene(e->GetNombre(), texto) || Validaciones::Contiene(e->GetId(), texto) || Validaciones::Contiene(e->GetCorreo(), texto)) {
            filtrados->Add(e);
        }
    }
    return filtrados;
}

String^ AdministradorController::ModificarAdministrador(Administrador^ elemento) {
    String^ error = ValidarDatos(elemento);
    if (error != nullptr) {
        return error;
    }
    AdministradorDAO^ dao = gcnew AdministradorDAO();
    if (!dao->ModificarAdministrador(elemento)) {
        return "No existe un administrador con el id " + elemento->GetId() + ".";
    }
    return nullptr;
}

String^ AdministradorController::EliminarAdministrador(String^ id) {
    AdministradorDAO^ dao = gcnew AdministradorDAO();
	if (dao->ListarAdministradores()->Count <= 1) {
		return "No se puede eliminar al único administrador del sistema.";
	}
    if (!dao->EliminarAdministrador(id)) {
        return "No existe un administrador con el id " + id + ".";
    }
    return nullptr;
}

Administrador^ AdministradorController::Autenticar(String^ usuario, String^ clave) {
    if (String::IsNullOrWhiteSpace(usuario) || String::IsNullOrEmpty(clave)) {
        return nullptr;
    }
    AdministradorDAO^ dao = gcnew AdministradorDAO();
    for each (Administrador ^ a in dao->ListarAdministradores()) {
        if ((UtilDAO::Igual(a->GetId(), usuario) || UtilDAO::Igual(a->GetNombre(), usuario)) && a->ValidarCredenciales(clave)) {
            return a;
        }
    }
    return nullptr;
}
