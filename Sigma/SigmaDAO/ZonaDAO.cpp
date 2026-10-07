#include "pch.h"
#include "ZonaDAO.h"
#include "UtilDAO.h"

using namespace SigmaDAO;
using namespace System::IO;
using namespace System::Globalization;

ZonaDAO::ZonaDAO() {
}

List<Zona^>^ ZonaDAO::LeerArchivo() {
	List<Zona^>^ lista = gcnew List<Zona^>();
	

	if (File::Exists("Zona.txt")) {
		array<String^>^ lineas = File::ReadAllLines("Zona.txt");
		String^ separadores = ";";

		for each (String ^ linea in lineas) {
			if (String::IsNullOrWhiteSpace(linea)) continue;

			try {
				array<String^>^ datos = linea->Split(separadores->ToCharArray());
				double volumen = Convert::ToDouble(datos[2], CultureInfo::InvariantCulture);
				double concentracionActual = 0.0;
				if (!String::IsNullOrEmpty(UtilDAO::Campo(datos, 3))) {
					concentracionActual = Convert::ToDouble(datos[3], CultureInfo::InvariantCulture);
				}
				Zona^ obj = gcnew Zona(datos[0], datos[1], volumen);
				obj->SetConcentracionActual(concentracionActual);
				obj->SetEsZonaSalida(UtilDAO::Campo(datos, 4) == "1");
				lista->Add(obj);
			}
			catch (Exception^) {
				// Linea danada: se ignora para no tumbar todo el archivo.
				continue;
			}
		}
	}
	
	return lista;
}

void ZonaDAO::EscribirArchivo(List<Zona^>^ lista) {
	array<String^>^ lineas = gcnew array<String^>(lista->Count);

	for (int i = 0; i < lista->Count; i++) {
		Zona^ obj = lista[i];
		lineas[i] = obj->GetId() + ";" + obj->GetNombre() + ";" +
			obj->GetVolumen().ToString(CultureInfo::InvariantCulture) + ";" +
			obj->GetConcentracionActual().ToString(CultureInfo::InvariantCulture) + ";" +
			(obj->GetEsZonaSalida() ? "1" : "0");
	}
	File::WriteAllLines("Zona.txt", lineas);
}

String^ ZonaDAO::GenerarId() {
	List<Zona^>^ lista = LeerArchivo();
	List<String^>^ ids = gcnew List<String^>();
	for each (Zona ^ e in lista) {
		ids->Add(e->GetId());
	}
	return UtilDAO::SiguienteId("zona", ids);
}

bool ZonaDAO::RegistrarZona(Zona^ elemento) {
	List<Zona^>^ lista = LeerArchivo();

	for each (Zona ^ e in lista) {
		if (UtilDAO::Igual(e->GetId(), elemento->GetId())) {
			return false; // Id repetido
		}
	}

	lista->Add(elemento);
	EscribirArchivo(lista);
	return true;
}

Zona^ ZonaDAO::ConsultarZona(String^ id) {
	List<Zona^>^ lista = LeerArchivo();

	for each (Zona ^ e in lista) {
		if (UtilDAO::Igual(e->GetId(), id)) {
			return e;
		}
	}
	return nullptr;
}

List<Zona^>^ ZonaDAO::ListarZonas() {
	return LeerArchivo();
}

bool ZonaDAO::ModificarZona(Zona^ elemento) {
	List<Zona^>^ lista = LeerArchivo();

	for (int i = 0; i < lista->Count; i++) {
		if (UtilDAO::Igual(lista[i]->GetId(), elemento->GetId())) {
			lista[i] = elemento;
			EscribirArchivo(lista);
			return true;
		}
	}
	return false;
}

bool ZonaDAO::EliminarZona(String^ id) {
	List<Zona^>^ lista = LeerArchivo();

	for (int i = 0; i < lista->Count; i++) {
		if (UtilDAO::Igual(lista[i]->GetId(), id)) {
			lista->RemoveAt(i);
			EscribirArchivo(lista);
			return true;
		}
	}
	return false;
}
