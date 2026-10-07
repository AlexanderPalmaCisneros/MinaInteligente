#include "pch.h"
#include "SensorGasDAO.h"
#include "UtilDAO.h"
#include "ZonaDAO.h"
#include "TipoGasDAO.h"

using namespace SigmaDAO;
using namespace System::IO;
using namespace System::Globalization;

SensorGasDAO::SensorGasDAO() {
}

List<SensorGas^>^ SensorGasDAO::LeerArchivo() {
	List<SensorGas^>^ lista = gcnew List<SensorGas^>();
	List<Zona^>^ zonas = (gcnew ZonaDAO())->ListarZonas();
	List<TipoGas^>^ tiposGas = (gcnew TipoGasDAO())->ListarTiposGas();

	if (File::Exists("SensorGas.txt")) {
		array<String^>^ lineas = File::ReadAllLines("SensorGas.txt");
		String^ separadores = ";";

		for each (String ^ linea in lineas) {
			if (String::IsNullOrWhiteSpace(linea)) continue;

			try {
				array<String^>^ datos = linea->Split(separadores->ToCharArray());
				TipoGas^ tipoGas = UtilDAO::BuscarTipoGas(tiposGas, datos[1]);
				EstadoDispositivo estado = (EstadoDispositivo)Convert::ToInt32(datos[2]);
				Zona^ zona = UtilDAO::BuscarZona(zonas, UtilDAO::Campo(datos, 3));
				SensorGas^ obj = gcnew SensorGas(datos[0], zona, estado, tipoGas);
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

void SensorGasDAO::EscribirArchivo(List<SensorGas^>^ lista) {
	array<String^>^ lineas = gcnew array<String^>(lista->Count);

	for (int i = 0; i < lista->Count; i++) {
		SensorGas^ obj = lista[i];
		lineas[i] = obj->GetId() + ";" + (obj->GetTipoGas() != nullptr ? obj->GetTipoGas()->GetId() : "") + ";" +
			((int)obj->GetEstado()).ToString() + ";" + UtilDAO::IdDeZona(obj);
	}
	File::WriteAllLines("SensorGas.txt", lineas);
}

String^ SensorGasDAO::GenerarId() {
	List<SensorGas^>^ lista = LeerArchivo();
	List<String^>^ ids = gcnew List<String^>();
	for each (SensorGas ^ e in lista) {
		ids->Add(e->GetId());
	}
	return UtilDAO::SiguienteId("sensor", ids);
}

bool SensorGasDAO::RegistrarSensorGas(SensorGas^ elemento) {
	List<SensorGas^>^ lista = LeerArchivo();

	for each (SensorGas ^ e in lista) {
		if (UtilDAO::Igual(e->GetId(), elemento->GetId())) {
			return false; // Id repetido
		}
	}

	lista->Add(elemento);
	EscribirArchivo(lista);
	return true;
}

SensorGas^ SensorGasDAO::ConsultarSensorGas(String^ id) {
	List<SensorGas^>^ lista = LeerArchivo();

	for each (SensorGas ^ e in lista) {
		if (UtilDAO::Igual(e->GetId(), id)) {
			return e;
		}
	}
	return nullptr;
}

List<SensorGas^>^ SensorGasDAO::ListarSensoresGas() {
	return LeerArchivo();
}

bool SensorGasDAO::ModificarSensorGas(SensorGas^ elemento) {
	List<SensorGas^>^ lista = LeerArchivo();

	for (int i = 0; i < lista->Count; i++) {
		if (UtilDAO::Igual(lista[i]->GetId(), elemento->GetId())) {
			lista[i] = elemento;
			EscribirArchivo(lista);
			return true;
		}
	}
	return false;
}

bool SensorGasDAO::EliminarSensorGas(String^ id) {
	List<SensorGas^>^ lista = LeerArchivo();

	for (int i = 0; i < lista->Count; i++) {
		if (UtilDAO::Igual(lista[i]->GetId(), id)) {
			lista->RemoveAt(i);
			EscribirArchivo(lista);
			return true;
		}
	}
	return false;
}
