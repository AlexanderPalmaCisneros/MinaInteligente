#include "pch.h"
#include "AdministradorDAO.h"
#include "UtilDAO.h"

using namespace SigmaDAO;
using namespace System::IO;
using namespace System::Globalization;

AdministradorDAO::AdministradorDAO() {
}

List<Administrador^>^ AdministradorDAO::LeerArchivo() {
	List<Administrador^>^ lista = gcnew List<Administrador^>();
	

	if (File::Exists("Administrador.txt")) {
		array<String^>^ lineas = File::ReadAllLines("Administrador.txt");
		String^ separadores = ";";

		for each (String ^ linea in lineas) {
			if (String::IsNullOrWhiteSpace(linea)) continue;

			try {
				array<String^>^ datos = linea->Split(separadores->ToCharArray());
				Administrador^ obj = gcnew Administrador(datos[0], datos[1], datos[2], UtilDAO::Campo(datos, 3), UtilDAO::Campo(datos, 4));
				lista->Add(obj);
			}
			catch (Exception^) {
				// Linea danada: se ignora para no tumbar todo el archivo.
				continue;
			}
		}
	}
	
	// Sin administradores nadie podria entrar al sistema: se siembra uno inicial.
	if (lista->Count == 0) {
		lista->Add(gcnew Administrador("admin01", "admin", "admin", "admin@sigma.com", "999999999"));
		EscribirArchivo(lista);
	}
	return lista;
}

void AdministradorDAO::EscribirArchivo(List<Administrador^>^ lista) {
	array<String^>^ lineas = gcnew array<String^>(lista->Count);

	for (int i = 0; i < lista->Count; i++) {
		Administrador^ obj = lista[i];
		lineas[i] = obj->GetId() + ";" + obj->GetNombre() + ";" + obj->GetCredenciales() + ";" + obj->GetCorreo() + ";" + obj->GetTelefono();
	}
	File::WriteAllLines("Administrador.txt", lineas);
}

String^ AdministradorDAO::GenerarId() {
	List<Administrador^>^ lista = LeerArchivo();
	List<String^>^ ids = gcnew List<String^>();
	for each (Administrador ^ e in lista) {
		ids->Add(e->GetId());
	}
	return UtilDAO::SiguienteId("admin", ids);
}

bool AdministradorDAO::RegistrarAdministrador(Administrador^ elemento) {
	List<Administrador^>^ lista = LeerArchivo();

	for each (Administrador ^ e in lista) {
		if (UtilDAO::Igual(e->GetId(), elemento->GetId())) {
			return false; // Id repetido
		}
	}

	lista->Add(elemento);
	EscribirArchivo(lista);
	return true;
}

Administrador^ AdministradorDAO::ConsultarAdministrador(String^ id) {
	List<Administrador^>^ lista = LeerArchivo();

	for each (Administrador ^ e in lista) {
		if (UtilDAO::Igual(e->GetId(), id)) {
			return e;
		}
	}
	return nullptr;
}

List<Administrador^>^ AdministradorDAO::ListarAdministradores() {
	return LeerArchivo();
}

bool AdministradorDAO::ModificarAdministrador(Administrador^ elemento) {
	List<Administrador^>^ lista = LeerArchivo();

	for (int i = 0; i < lista->Count; i++) {
		if (UtilDAO::Igual(lista[i]->GetId(), elemento->GetId())) {
			lista[i] = elemento;
			EscribirArchivo(lista);
			return true;
		}
	}
	return false;
}

bool AdministradorDAO::EliminarAdministrador(String^ id) {
	List<Administrador^>^ lista = LeerArchivo();

	for (int i = 0; i < lista->Count; i++) {
		if (UtilDAO::Igual(lista[i]->GetId(), id)) {
			lista->RemoveAt(i);
			EscribirArchivo(lista);
			return true;
		}
	}
	return false;
}
