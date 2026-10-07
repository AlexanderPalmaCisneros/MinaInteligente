#include "pch.h"
#include "VentiladorDAO.h"
#include "UtilDAO.h"
#include "ZonaDAO.h"

using namespace SigmaDAO;
using namespace System::IO;
using namespace System::Globalization;

VentiladorDAO::VentiladorDAO() {
}

List<Ventilador^>^ VentiladorDAO::LeerArchivo() {
	List<Ventilador^>^ lista = gcnew List<Ventilador^>();
	List<Zona^>^ zonas = (gcnew ZonaDAO())->ListarZonas();

	if (File::Exists("Ventilador.txt")) {
		array<String^>^ lineas = File::ReadAllLines("Ventilador.txt");
		String^ separadores = ";";

		for each (String ^ linea in lineas) {
			if (String::IsNullOrWhiteSpace(linea)) continue;

			try {
				array<String^>^ datos = linea->Split(separadores->ToCharArray());
				double caudal = Convert::ToDouble(datos[1], CultureInfo::InvariantCulture);
				EstadoDispositivo estado = (EstadoDispositivo)Convert::ToInt32(datos[2]);
				Zona^ zona = UtilDAO::BuscarZona(zonas, UtilDAO::Campo(datos, 3));
				Ventilador^ obj = gcnew Ventilador(datos[0], zona, caudal, estado);
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

void VentiladorDAO::EscribirArchivo(List<Ventilador^>^ lista) {
	array<String^>^ lineas = gcnew array<String^>(lista->Count);

	for (int i = 0; i < lista->Count; i++) {
		Ventilador^ obj = lista[i];
		lineas[i] = obj->GetId() + ";" + obj->GetCaudal().ToString(CultureInfo::InvariantCulture) + ";" +
			((int)obj->GetEstado()).ToString() + ";" + UtilDAO::IdDeZona(obj);
	}
	File::WriteAllLines("Ventilador.txt", lineas);
}

String^ VentiladorDAO::GenerarId() {
	List<Ventilador^>^ lista = LeerArchivo();
	List<String^>^ ids = gcnew List<String^>();
	for each (Ventilador ^ e in lista) {
		ids->Add(e->GetId());
	}
	return UtilDAO::SiguienteId("ventilador", ids);
}

bool VentiladorDAO::RegistrarVentilador(Ventilador^ elemento) {
	List<Ventilador^>^ lista = LeerArchivo();

	for each (Ventilador ^ e in lista) {
		if (UtilDAO::Igual(e->GetId(), elemento->GetId())) {
			return false; // Id repetido
		}
	}

	lista->Add(elemento);
	EscribirArchivo(lista);
	return true;
}

Ventilador^ VentiladorDAO::ConsultarVentilador(String^ id) {
	List<Ventilador^>^ lista = LeerArchivo();

	for each (Ventilador ^ e in lista) {
		if (UtilDAO::Igual(e->GetId(), id)) {
			return e;
		}
	}
	return nullptr;
}

List<Ventilador^>^ VentiladorDAO::ListarVentiladores() {
	return LeerArchivo();
}

bool VentiladorDAO::ModificarVentilador(Ventilador^ elemento) {
	List<Ventilador^>^ lista = LeerArchivo();

	for (int i = 0; i < lista->Count; i++) {
		if (UtilDAO::Igual(lista[i]->GetId(), elemento->GetId())) {
			lista[i] = elemento;
			EscribirArchivo(lista);
			return true;
		}
	}
	return false;
}

bool VentiladorDAO::EliminarVentilador(String^ id) {
	List<Ventilador^>^ lista = LeerArchivo();

	for (int i = 0; i < lista->Count; i++) {
		if (UtilDAO::Igual(lista[i]->GetId(), id)) {
			lista->RemoveAt(i);
			EscribirArchivo(lista);
			return true;
		}
	}
	return false;
}
