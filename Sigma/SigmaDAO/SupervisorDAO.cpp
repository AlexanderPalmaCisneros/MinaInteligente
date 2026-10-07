#include "pch.h"
#include "SupervisorDAO.h"
#include "UtilDAO.h"

using namespace SigmaDAO;
using namespace System::IO;
using namespace System::Globalization;

SupervisorDAO::SupervisorDAO() {
}

List<Supervisor^>^ SupervisorDAO::LeerArchivo() {
	List<Supervisor^>^ lista = gcnew List<Supervisor^>();
	

	if (File::Exists("Supervisor.txt")) {
		array<String^>^ lineas = File::ReadAllLines("Supervisor.txt");
		String^ separadores = ";";

		for each (String ^ linea in lineas) {
			if (String::IsNullOrWhiteSpace(linea)) continue;

			try {
				array<String^>^ datos = linea->Split(separadores->ToCharArray());
				Supervisor^ obj = gcnew Supervisor(datos[0], datos[1], datos[2], UtilDAO::Campo(datos, 3), UtilDAO::Campo(datos, 4));
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

void SupervisorDAO::EscribirArchivo(List<Supervisor^>^ lista) {
	array<String^>^ lineas = gcnew array<String^>(lista->Count);

	for (int i = 0; i < lista->Count; i++) {
		Supervisor^ obj = lista[i];
		lineas[i] = obj->GetId() + ";" + obj->GetNombre() + ";" + obj->GetCredenciales() + ";" + obj->GetCorreo() + ";" + obj->GetTelefono();
	}
	File::WriteAllLines("Supervisor.txt", lineas);
}

String^ SupervisorDAO::GenerarId() {
	List<Supervisor^>^ lista = LeerArchivo();
	List<String^>^ ids = gcnew List<String^>();
	for each (Supervisor ^ e in lista) {
		ids->Add(e->GetId());
	}
	return UtilDAO::SiguienteId("supervisor", ids);
}

bool SupervisorDAO::RegistrarSupervisor(Supervisor^ elemento) {
	List<Supervisor^>^ lista = LeerArchivo();

	for each (Supervisor ^ e in lista) {
		if (UtilDAO::Igual(e->GetId(), elemento->GetId())) {
			return false; // Id repetido
		}
	}

	lista->Add(elemento);
	EscribirArchivo(lista);
	return true;
}

Supervisor^ SupervisorDAO::ConsultarSupervisor(String^ id) {
	List<Supervisor^>^ lista = LeerArchivo();

	for each (Supervisor ^ e in lista) {
		if (UtilDAO::Igual(e->GetId(), id)) {
			return e;
		}
	}
	return nullptr;
}

List<Supervisor^>^ SupervisorDAO::ListarSupervisores() {
	return LeerArchivo();
}

bool SupervisorDAO::ModificarSupervisor(Supervisor^ elemento) {
	List<Supervisor^>^ lista = LeerArchivo();

	for (int i = 0; i < lista->Count; i++) {
		if (UtilDAO::Igual(lista[i]->GetId(), elemento->GetId())) {
			lista[i] = elemento;
			EscribirArchivo(lista);
			return true;
		}
	}
	return false;
}

bool SupervisorDAO::EliminarSupervisor(String^ id) {
	List<Supervisor^>^ lista = LeerArchivo();

	for (int i = 0; i < lista->Count; i++) {
		if (UtilDAO::Igual(lista[i]->GetId(), id)) {
			lista->RemoveAt(i);
			EscribirArchivo(lista);
			return true;
		}
	}
	return false;
}
