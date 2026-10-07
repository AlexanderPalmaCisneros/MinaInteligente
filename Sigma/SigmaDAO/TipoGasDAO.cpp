#include "pch.h"
#include "TipoGasDAO.h"
#include "UtilDAO.h"

using namespace SigmaDAO;
using namespace System::IO;
using namespace System::Globalization;

TipoGasDAO::TipoGasDAO() {
}

List<TipoGas^>^ TipoGasDAO::LeerArchivo() {
	List<TipoGas^>^ lista = gcnew List<TipoGas^>();
	

	if (File::Exists("TipoGas.txt")) {
		array<String^>^ lineas = File::ReadAllLines("TipoGas.txt");
		String^ separadores = ";";

		for each (String ^ linea in lineas) {
			if (String::IsNullOrWhiteSpace(linea)) continue;

			try {
				array<String^>^ datos = linea->Split(separadores->ToCharArray());
				double generacion = 0.0;
				if (!String::IsNullOrEmpty(UtilDAO::Campo(datos, 3))) {
					generacion = Convert::ToDouble(datos[3], CultureInfo::InvariantCulture);
				}
				TipoGas^ obj = gcnew TipoGas(datos[0], datos[1], datos[2], generacion);
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

void TipoGasDAO::EscribirArchivo(List<TipoGas^>^ lista) {
	array<String^>^ lineas = gcnew array<String^>(lista->Count);

	for (int i = 0; i < lista->Count; i++) {
		TipoGas^ obj = lista[i];
		lineas[i] = obj->GetId() + ";" + obj->GetNombre() + ";" + obj->GetSimbolo() + ";" + obj->GetGeneracionGasDefault().ToString(CultureInfo::InvariantCulture);
	}
	File::WriteAllLines("TipoGas.txt", lineas);
}

String^ TipoGasDAO::GenerarId() {
	List<TipoGas^>^ lista = LeerArchivo();
	List<String^>^ ids = gcnew List<String^>();
	for each (TipoGas ^ e in lista) {
		ids->Add(e->GetId());
	}
	return UtilDAO::SiguienteId("tipogas", ids);
}

bool TipoGasDAO::RegistrarTipoGas(TipoGas^ elemento) {
	List<TipoGas^>^ lista = LeerArchivo();

	for each (TipoGas ^ e in lista) {
		if (UtilDAO::Igual(e->GetId(), elemento->GetId())) {
			return false; // Id repetido
		}
	}

	lista->Add(elemento);
	EscribirArchivo(lista);
	return true;
}

TipoGas^ TipoGasDAO::ConsultarTipoGas(String^ id) {
	List<TipoGas^>^ lista = LeerArchivo();

	for each (TipoGas ^ e in lista) {
		if (UtilDAO::Igual(e->GetId(), id)) {
			return e;
		}
	}
	return nullptr;
}

List<TipoGas^>^ TipoGasDAO::ListarTiposGas() {
	return LeerArchivo();
}

bool TipoGasDAO::ModificarTipoGas(TipoGas^ elemento) {
	List<TipoGas^>^ lista = LeerArchivo();

	for (int i = 0; i < lista->Count; i++) {
		if (UtilDAO::Igual(lista[i]->GetId(), elemento->GetId())) {
			lista[i] = elemento;
			EscribirArchivo(lista);
			return true;
		}
	}
	return false;
}

bool TipoGasDAO::EliminarTipoGas(String^ id) {
	List<TipoGas^>^ lista = LeerArchivo();

	for (int i = 0; i < lista->Count; i++) {
		if (UtilDAO::Igual(lista[i]->GetId(), id)) {
			lista->RemoveAt(i);
			EscribirArchivo(lista);
			return true;
		}
	}
	return false;
}
