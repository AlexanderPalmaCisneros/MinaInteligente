#include "pch.h"
#include "GrafoZonasController.h"

using namespace SigmaController;
using namespace SigmaDAO;

GrafoZonasController::GrafoZonasController() {
}

GrafoZonas^ GrafoZonasController::CargarGrafo() {
	ZonaDAO^ zonaDAO = gcnew ZonaDAO();
	GrafoZonasDAO^ grafoDAO = gcnew GrafoZonasDAO();
	return grafoDAO->CargarGrafo(zonaDAO->ListarZonas());
}

String^ GrafoZonasController::AgregarZonaSalida(String^ idZona) {
	ZonaDAO^ zonaDAO = gcnew ZonaDAO();
	GrafoZonasDAO^ grafoDAO = gcnew GrafoZonasDAO();
	List<Zona^>^ zonas = zonaDAO->ListarZonas();
	GrafoZonas^ grafo = grafoDAO->CargarGrafo(zonas);

	Zona^ zona = UtilDAO::BuscarZona(zonas, idZona);
	if (zona == nullptr) {
		return "Seleccione una zona existente.";
	}
	if (grafo->ObtenerZonas()->Count > 0) {
		return "El grafo ya tiene una zona de salida.";
	}
	grafo->AgregarZonaSalida(zona);

	// La zona queda marcada como salida tambien en Zona.txt
	zonaDAO->ModificarZona(zona);
	grafoDAO->GuardarGrafo(grafo);
	return nullptr;
}

String^ GrafoZonasController::AgregarZona(String^ idZona, String^ idPadre, CaraZona cara) {
	ZonaDAO^ zonaDAO = gcnew ZonaDAO();
	GrafoZonasDAO^ grafoDAO = gcnew GrafoZonasDAO();
	List<Zona^>^ zonas = zonaDAO->ListarZonas();
	GrafoZonas^ grafo = grafoDAO->CargarGrafo(zonas);

	Zona^ zona = UtilDAO::BuscarZona(zonas, idZona);
	Zona^ padre = UtilDAO::BuscarZona(zonas, idPadre);
	if (zona == nullptr) {
		return "Seleccione la zona que desea agregar.";
	}
	if (padre == nullptr || !grafo->ContieneZona(padre)) {
		return "Seleccione en el grafo la zona de la que va a colgar.";
	}
	if (grafo->ContieneZona(zona)) {
		return "La zona " + zona->GetId() + " ya está en el grafo.";
	}
	if (!grafo->AgregarZona(zona, padre, cara)) {
		return "Esa cara de la zona " + padre->GetId() + " ya está ocupada por otra zona.";
	}

	grafoDAO->GuardarGrafo(grafo);
	return nullptr;
}

String^ GrafoZonasController::QuitarZona(String^ idZona) {
	ZonaDAO^ zonaDAO = gcnew ZonaDAO();
	GrafoZonasDAO^ grafoDAO = gcnew GrafoZonasDAO();
	List<Zona^>^ zonas = zonaDAO->ListarZonas();
	GrafoZonas^ grafo = grafoDAO->CargarGrafo(zonas);

	Zona^ zona = UtilDAO::BuscarZona(zonas, idZona);
	if (zona == nullptr || !grafo->ContieneZona(zona)) {
		return "La zona no está en el grafo.";
	}
	int hijas = grafo->ObtenerHijas(zona)->Count;
	if (hijas > 0) {
		return "No se puede quitar: tiene " + hijas.ToString() + " zona(s) colgando. Quítelas primero.";
	}

	bool eraSalida = (zona->GetZonaPadre() == nullptr);
	grafo->QuitarZona(zona);
	if (eraSalida) {
		zonaDAO->ModificarZona(zona);
	}
	grafoDAO->GuardarGrafo(grafo);
	return nullptr;
}

List<Zona^>^ GrafoZonasController::ZonasDisponibles() {
	ZonaDAO^ zonaDAO = gcnew ZonaDAO();
	GrafoZonasDAO^ grafoDAO = gcnew GrafoZonasDAO();
	List<Zona^>^ zonas = zonaDAO->ListarZonas();
	GrafoZonas^ grafo = grafoDAO->CargarGrafo(zonas);

	List<Zona^>^ disponibles = gcnew List<Zona^>();
	for each (Zona ^ zona in zonas) {
		if (!grafo->ContieneZona(zona)) {
			disponibles->Add(zona);
		}
	}
	return disponibles;
}

bool GrafoZonasController::EstaEnGrafo(String^ idZona) {
	for each (Zona ^ zona in CargarGrafo()->ObtenerZonas()) {
		if (UtilDAO::Igual(zona->GetId(), idZona)) {
			return true;
		}
	}
	return false;
}

NivelRiesgo GrafoZonasController::ObtenerNivelRiesgo(Zona^ zona) {
	return zona->EvaluarNivelRiesgo();
}

bool GrafoZonasController::EstaAislada(GrafoZonas^ grafo, Zona^ zona) {
	return grafo->EvaluarRiesgoAislamiento(nullptr, zona);
}
