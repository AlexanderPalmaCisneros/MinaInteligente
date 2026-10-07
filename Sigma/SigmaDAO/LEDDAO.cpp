#include "pch.h"
#include "LEDDAO.h"
#include "UtilDAO.h"
#include "ZonaDAO.h"

using namespace SigmaDAO;
using namespace System::IO;
using namespace System::Globalization;

LEDDAO::LEDDAO() {
}

List<LED^>^ LEDDAO::LeerArchivo() {
	List<LED^>^ lista = gcnew List<LED^>();
	List<Zona^>^ zonas = (gcnew ZonaDAO())->ListarZonas();

	if (File::Exists("LED.txt")) {
		array<String^>^ lineas = File::ReadAllLines("LED.txt");
		String^ separadores = ";";

		for each (String ^ linea in lineas) {
			if (String::IsNullOrWhiteSpace(linea)) continue;

			try {
				array<String^>^ datos = linea->Split(separadores->ToCharArray());
				ColorLED color = (ColorLED)Convert::ToInt32(datos[1]);
				bool encendido = Convert::ToInt32(datos[2]) != 0;
				Zona^ zona = UtilDAO::BuscarZona(zonas, UtilDAO::Campo(datos, 4));
				LED^ obj = gcnew LED(datos[0], zona, color, encendido);
				if (!String::IsNullOrEmpty(UtilDAO::Campo(datos, 3))) {
					obj->SetEstado((EstadoDispositivo)Convert::ToInt32(datos[3]));
				}
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

void LEDDAO::EscribirArchivo(List<LED^>^ lista) {
	array<String^>^ lineas = gcnew array<String^>(lista->Count);

	for (int i = 0; i < lista->Count; i++) {
		LED^ obj = lista[i];
		lineas[i] = obj->GetId() + ";" + ((int)obj->GetColor()).ToString() + ";" +
			(obj->GetEncendido() ? "1" : "0") + ";" +
			((int)obj->GetEstado()).ToString() + ";" + UtilDAO::IdDeZona(obj);
	}
	File::WriteAllLines("LED.txt", lineas);
}

String^ LEDDAO::GenerarId() {
	List<LED^>^ lista = LeerArchivo();
	List<String^>^ ids = gcnew List<String^>();
	for each (LED ^ e in lista) {
		ids->Add(e->GetId());
	}
	return UtilDAO::SiguienteId("led", ids);
}

bool LEDDAO::RegistrarLED(LED^ elemento) {
	List<LED^>^ lista = LeerArchivo();

	for each (LED ^ e in lista) {
		if (UtilDAO::Igual(e->GetId(), elemento->GetId())) {
			return false; // Id repetido
		}
	}

	lista->Add(elemento);
	EscribirArchivo(lista);
	return true;
}

LED^ LEDDAO::ConsultarLED(String^ id) {
	List<LED^>^ lista = LeerArchivo();

	for each (LED ^ e in lista) {
		if (UtilDAO::Igual(e->GetId(), id)) {
			return e;
		}
	}
	return nullptr;
}

List<LED^>^ LEDDAO::ListarLEDs() {
	return LeerArchivo();
}

bool LEDDAO::ModificarLED(LED^ elemento) {
	List<LED^>^ lista = LeerArchivo();

	for (int i = 0; i < lista->Count; i++) {
		if (UtilDAO::Igual(lista[i]->GetId(), elemento->GetId())) {
			lista[i] = elemento;
			EscribirArchivo(lista);
			return true;
		}
	}
	return false;
}

bool LEDDAO::EliminarLED(String^ id) {
	List<LED^>^ lista = LeerArchivo();

	for (int i = 0; i < lista->Count; i++) {
		if (UtilDAO::Igual(lista[i]->GetId(), id)) {
			lista->RemoveAt(i);
			EscribirArchivo(lista);
			return true;
		}
	}
	return false;
}
