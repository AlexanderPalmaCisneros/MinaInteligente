#pragma once

namespace SigmaDAO {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace SigmaModel;

	/*Metodos sencillos que reutilizan todos los DAO (ids autogenerados y lectura de campos)*/
	public ref class UtilDAO abstract sealed {
	public:
		/*Devuelve prefijo + (mayor numero existente + 1) con 2 digitos. Ej.: sensor01, sensor02...*/
		static String^ SiguienteId(String^ prefijo, List<String^>^ idsExistentes) {
			int maximo = 0;
			for each (String ^ id in idsExistentes) {
				if (id != nullptr && id->StartsWith(prefijo, StringComparison::OrdinalIgnoreCase)) {
					int numero;
					if (Int32::TryParse(id->Substring(prefijo->Length), numero) && numero > maximo) {
						maximo = numero;
					}
				}
			}
			return prefijo + (maximo + 1).ToString("00");
		}

		/*Lee la columna indicada; si la linea es de un formato viejo y no la tiene, devuelve vacio*/
		static String^ Campo(array<String^>^ datos, int indice) {
			if (indice < datos->Length) {
				return datos[indice];
			}
			return String::Empty;
		}

		/*Compara textos sin distinguir mayusculas ni espacios en los extremos*/
		static bool Igual(String^ a, String^ b) {
			if (a == nullptr) a = String::Empty;
			if (b == nullptr) b = String::Empty;
			return String::Equals(a->Trim(), b->Trim(), StringComparison::OrdinalIgnoreCase);
		}

		static Zona^ BuscarZona(List<Zona^>^ zonas, String^ idZona) {
			if (String::IsNullOrEmpty(idZona)) {
				return nullptr;
			}
			for each (Zona ^ z in zonas) {
				if (Igual(z->GetId(), idZona)) {
					return z;
				}
			}
			return nullptr;
		}

		static TipoGas^ BuscarTipoGas(List<TipoGas^>^ tipos, String^ idTipoGas) {
			if (String::IsNullOrEmpty(idTipoGas)) {
				return nullptr;
			}
			for each (TipoGas ^ t in tipos) {
				if (Igual(t->GetId(), idTipoGas)) {
					return t;
				}
			}
			return nullptr;
		}

		static String^ IdDeZona(Dispositivo^ dispositivo) {
			if (dispositivo->GetZonaAsociada() != nullptr) {
				return dispositivo->GetZonaAsociada()->GetId();
			}
			return String::Empty;
		}
	};
}
