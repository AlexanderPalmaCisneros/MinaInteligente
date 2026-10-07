#include "pch.h"
#include "ZonaController.h"
#include "Validaciones.h"
#include "DispositivoController.h"

using namespace SigmaController;
using namespace SigmaDAO;

ZonaController::ZonaController() {
}

String^ ZonaController::ValidarDatos(Zona^ elemento) {
	if (elemento == nullptr) {
		return "Los datos ingresados no son válidos.";
	}
	if (!Validaciones::TextoValido(elemento->GetNombre())) return "El nombre es obligatorio y no puede contener ';'.";
	if (elemento->GetVolumen() <= 0) return "El volumen debe ser mayor que cero.";

	ZonaDAO^ dao = gcnew ZonaDAO();
	for each (Zona ^ otro in dao->ListarZonas()) {
		if (UtilDAO::Igual(otro->GetId(), elemento->GetId())) continue;
		if (UtilDAO::Igual(otro->GetNombre(), elemento->GetNombre()))
			return "Ya existe una zona llamada '" + otro->GetNombre() + "' (" + otro->GetId() + ").";
	}
	return nullptr;
}

String^ ZonaController::GenerarId() {
    ZonaDAO^ dao = gcnew ZonaDAO();
    return dao->GenerarId();
}

String^ ZonaController::RegistrarZona(Zona^ elemento) {
    String^ error = ValidarDatos(elemento);
    if (error != nullptr) {
        return error;
    }
    ZonaDAO^ dao = gcnew ZonaDAO();
    if (!dao->RegistrarZona(elemento)) {
        return "Ya existe una zona con el id " + elemento->GetId() + ".";
    }
    return nullptr;
}

Zona^ ZonaController::ConsultarZona(String^ id) {
    if (String::IsNullOrEmpty(id)) {
        return nullptr;
    }
    ZonaDAO^ dao = gcnew ZonaDAO();
    return dao->ConsultarZona(id);
}

List<Zona^>^ ZonaController::ListarZonas() {
    ZonaDAO^ dao = gcnew ZonaDAO();
    return dao->ListarZonas();
}

List<Zona^>^ ZonaController::BuscarZonas(String^ texto) {
    List<Zona^>^ filtrados = gcnew List<Zona^>();
    for each (Zona ^ e in ListarZonas()) {
        if (Validaciones::Contiene(e->GetNombre(), texto) || Validaciones::Contiene(e->GetId(), texto)) {
            filtrados->Add(e);
        }
    }
    return filtrados;
}

String^ ZonaController::ModificarZona(Zona^ elemento) {
    String^ error = ValidarDatos(elemento);
    if (error != nullptr) {
        return error;
    }
    ZonaDAO^ dao = gcnew ZonaDAO();
    if (!dao->ModificarZona(elemento)) {
        return "No existe una zona con el id " + elemento->GetId() + ".";
    }
    return nullptr;
}

String^ ZonaController::EliminarZona(String^ id) {
    ZonaDAO^ dao = gcnew ZonaDAO();
	DispositivoController^ dispositivoController = gcnew DispositivoController();
	for each (Dispositivo ^ d in dispositivoController->ListarDispositivos()) {
		if (d->GetZonaAsociada() != nullptr && UtilDAO::Igual(d->GetZonaAsociada()->GetId(), id)) {
			return "No se puede eliminar: el dispositivo " + d->GetId() + " pertenece a esta zona. Reasígnelo o elimínelo primero.";
		}
	}
    if (!dao->EliminarZona(id)) {
        return "No existe una zona con el id " + id + ".";
    }
    return nullptr;
}
