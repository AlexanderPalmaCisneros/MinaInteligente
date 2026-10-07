#include "pch.h"
#include "TrabajadorDAO.h"
#include "UtilDAO.h"

using namespace SigmaDAO;
using namespace System::IO;
using namespace System::Globalization;

TrabajadorDAO::TrabajadorDAO() {
}

List<Trabajador^>^ TrabajadorDAO::LeerArchivo() {
	List<Trabajador^>^ lista = gcnew List<Trabajador^>();
	

	if (File::Exists("Trabajador.txt")) {
		array<String^>^ lineas = File::ReadAllLines("Trabajador.txt");
		String^ separadores = ";";

		for each (String ^ linea in lineas) {
			if (String::IsNullOrWhiteSpace(linea)) continue;

			try {
				array<String^>^ datos = linea->Split(separadores->ToCharArray());
				Trabajador^ obj = gcnew Trabajador(datos[0], datos[1], UtilDAO::Campo(datos, 2), UtilDAO::Campo(datos, 3), UtilDAO::Campo(datos, 4));
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

void TrabajadorDAO::EscribirArchivo(List<Trabajador^>^ lista) {
	array<String^>^ lineas = gcnew array<String^>(lista->Count);

	for (int i = 0; i < lista->Count; i++) {
		Trabajador^ obj = lista[i];
		lineas[i] = obj->GetId() + ";" + obj->GetNombre() + ";" + obj->GetIdRFID() + ";" + obj->GetCorreo() + ";" + obj->GetTelefono();
	}
	File::WriteAllLines("Trabajador.txt", lineas);
}

String^ TrabajadorDAO::GenerarId() {
	List<Trabajador^>^ lista = LeerArchivo();
	List<String^>^ ids = gcnew List<String^>();
	for each (Trabajador ^ e in lista) {
		ids->Add(e->GetId());
	}
	return UtilDAO::SiguienteId("obrero", ids);
}

bool TrabajadorDAO::RegistrarTrabajador(Trabajador^ elemento) {
	List<Trabajador^>^ lista = LeerArchivo();

	for each (Trabajador ^ e in lista) {
		if (UtilDAO::Igual(e->GetId(), elemento->GetId())) {
			return false; // Id repetido
		}
	}

	lista->Add(elemento);
	EscribirArchivo(lista);
	return true;
}

Trabajador^ TrabajadorDAO::ConsultarTrabajador(String^ id) {
	List<Trabajador^>^ lista = LeerArchivo();

	for each (Trabajador ^ e in lista) {
		if (UtilDAO::Igual(e->GetId(), id)) {
			return e;
		}
	}
	return nullptr;
}

List<Trabajador^>^ TrabajadorDAO::ListarTrabajadores() {
	return LeerArchivo();
}

bool TrabajadorDAO::ModificarTrabajador(Trabajador^ elemento) {
	List<Trabajador^>^ lista = LeerArchivo();

	for (int i = 0; i < lista->Count; i++) {
		if (UtilDAO::Igual(lista[i]->GetId(), elemento->GetId())) {
			lista[i] = elemento;
			EscribirArchivo(lista);
			return true;
		}
	}
	return false;
}

bool TrabajadorDAO::EliminarTrabajador(String^ id) {
	List<Trabajador^>^ lista = LeerArchivo();

	for (int i = 0; i < lista->Count; i++) {
		if (UtilDAO::Igual(lista[i]->GetId(), id)) {
			lista->RemoveAt(i);
			EscribirArchivo(lista);
			return true;
		}
	}
	return false;
}
