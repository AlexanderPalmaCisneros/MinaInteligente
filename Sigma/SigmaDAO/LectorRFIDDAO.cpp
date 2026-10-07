#include "pch.h"
#include "LectorRFIDDAO.h"
#include "UtilDAO.h"
#include "ZonaDAO.h"

using namespace SigmaDAO;
using namespace System::IO;
using namespace System::Globalization;

LectorRFIDDAO::LectorRFIDDAO() {
}

List<LectorRFID^>^ LectorRFIDDAO::LeerArchivo() {
	List<LectorRFID^>^ lista = gcnew List<LectorRFID^>();
	List<Zona^>^ zonas = (gcnew ZonaDAO())->ListarZonas();

	if (File::Exists("LectorRFID.txt")) {
		array<String^>^ lineas = File::ReadAllLines("LectorRFID.txt");
		String^ separadores = ";";

		for each (String ^ linea in lineas) {
			if (String::IsNullOrWhiteSpace(linea)) continue;

			try {
				array<String^>^ datos = linea->Split(separadores->ToCharArray());
				EstadoDispositivo estado = (EstadoDispositivo)Convert::ToInt32(datos[1]);
				Zona^ zona = UtilDAO::BuscarZona(zonas, UtilDAO::Campo(datos, 2));
				LectorRFID^ obj = gcnew LectorRFID(datos[0], zona, estado);
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

void LectorRFIDDAO::EscribirArchivo(List<LectorRFID^>^ lista) {
	array<String^>^ lineas = gcnew array<String^>(lista->Count);

	for (int i = 0; i < lista->Count; i++) {
		LectorRFID^ obj = lista[i];
		lineas[i] = obj->GetId() + ";" + ((int)obj->GetEstado()).ToString() + ";" + UtilDAO::IdDeZona(obj);
	}
	File::WriteAllLines("LectorRFID.txt", lineas);
}

String^ LectorRFIDDAO::GenerarId() {
	List<LectorRFID^>^ lista = LeerArchivo();
	List<String^>^ ids = gcnew List<String^>();
	for each (LectorRFID ^ e in lista) {
		ids->Add(e->GetId());
	}
	return UtilDAO::SiguienteId("lector", ids);
}

bool LectorRFIDDAO::RegistrarLectorRFID(LectorRFID^ elemento) {
	List<LectorRFID^>^ lista = LeerArchivo();

	for each (LectorRFID ^ e in lista) {
		if (UtilDAO::Igual(e->GetId(), elemento->GetId())) {
			return false; // Id repetido
		}
	}

	lista->Add(elemento);
	EscribirArchivo(lista);
	return true;
}

LectorRFID^ LectorRFIDDAO::ConsultarLectorRFID(String^ id) {
	List<LectorRFID^>^ lista = LeerArchivo();

	for each (LectorRFID ^ e in lista) {
		if (UtilDAO::Igual(e->GetId(), id)) {
			return e;
		}
	}
	return nullptr;
}

List<LectorRFID^>^ LectorRFIDDAO::ListarLectoresRFID() {
	return LeerArchivo();
}

bool LectorRFIDDAO::ModificarLectorRFID(LectorRFID^ elemento) {
	List<LectorRFID^>^ lista = LeerArchivo();

	for (int i = 0; i < lista->Count; i++) {
		if (UtilDAO::Igual(lista[i]->GetId(), elemento->GetId())) {
			lista[i] = elemento;
			EscribirArchivo(lista);
			return true;
		}
	}
	return false;
}

bool LectorRFIDDAO::EliminarLectorRFID(String^ id) {
	List<LectorRFID^>^ lista = LeerArchivo();

	for (int i = 0; i < lista->Count; i++) {
		if (UtilDAO::Igual(lista[i]->GetId(), id)) {
			lista->RemoveAt(i);
			EscribirArchivo(lista);
			return true;
		}
	}
	return false;
}
