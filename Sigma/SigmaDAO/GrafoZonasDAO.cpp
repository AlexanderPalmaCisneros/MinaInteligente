#include "pch.h"
#include "GrafoZonasDAO.h"
#include "UtilDAO.h"

using namespace SigmaDAO;
using namespace System::IO;

GrafoZonasDAO::GrafoZonasDAO() {
}

GrafoZonas^ GrafoZonasDAO::CargarGrafo(List<Zona^>^ zonas) {
	GrafoZonas^ grafo = gcnew GrafoZonas();

	if (File::Exists("GrafoZonas.txt")) {
		array<String^>^ lineas = File::ReadAllLines("GrafoZonas.txt");
		String^ separadores = ";";

		for each (String ^ linea in lineas) {
			if (String::IsNullOrWhiteSpace(linea)) continue;

			array<String^>^ datos = linea->Split(separadores->ToCharArray());
			Zona^ zona = UtilDAO::BuscarZona(zonas, UtilDAO::Campo(datos, 0));
			if (zona == nullptr) {
				// La zona fue eliminada: se descarta (y con ella las que colgaban de ella)
				continue;
			}

			String^ idPadre = UtilDAO::Campo(datos, 1);
			if (String::IsNullOrEmpty(idPadre)) {
				grafo->AgregarZonaSalida(zona);
				continue;
			}

			String^ textoCara = UtilDAO::Campo(datos, 2);
			CaraZona cara = CaraZona::DERECHA;
			if (textoCara == "ARRIBA") {
				cara = CaraZona::ARRIBA;
			}
			else if (textoCara == "ABAJO") {
				cara = CaraZona::ABAJO;
			}
			// La celda se vuelve a calcular a partir del padre; si algo no cuadra la linea se ignora
			grafo->AgregarZona(zona, UtilDAO::BuscarZona(zonas, idPadre), cara);
		}
	}

	return grafo;
}

void GrafoZonasDAO::GuardarGrafo(GrafoZonas^ grafo) {
	List<Zona^>^ zonas = grafo->ObtenerZonas();
	array<String^>^ lineas = gcnew array<String^>(zonas->Count);

	for (int i = 0; i < zonas->Count; i++) {
		Zona^ zona = zonas[i];
		String^ idPadre = (zona->GetZonaPadre() != nullptr) ? zona->GetZonaPadre()->GetId() : String::Empty;
		String^ cara = (zona->GetZonaPadre() != nullptr) ? zona->GetCaraConexion().ToString() : String::Empty;
		lineas[i] = zona->GetId() + ";" + idPadre + ";" + cara + ";" +
			zona->GetFila().ToString() + ";" + zona->GetColumna().ToString();
	}
	File::WriteAllLines("GrafoZonas.txt", lineas);
}
