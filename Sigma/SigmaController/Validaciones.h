#pragma once

namespace SigmaController {

	using namespace System;
	using namespace System::Text::RegularExpressions;

	/*Validaciones sencillas de formato que reutilizan todos los controladores*/
	public ref class Validaciones abstract sealed {
	public:
		/*Obligatorio y sin ';' ni saltos de linea (el ';' separa las columnas de los .txt)*/
		static bool TextoValido(String^ texto) {
			if (String::IsNullOrWhiteSpace(texto)) {
				return false;
			}
			return texto->IndexOfAny(gcnew array<wchar_t>{ L';', L'\r', L'\n' }) < 0;
		}

		static bool CorreoValido(String^ correo) {
			if (!TextoValido(correo)) {
				return false;
			}
			return Regex::IsMatch(correo->Trim(), "^[^@\\s;]+@[^@\\s;]+\\.[^@\\s;]+$");
		}

		/*Entre 7 y 15 digitos, con un '+' opcional al inicio*/
		static bool TelefonoValido(String^ telefono) {
			if (!TextoValido(telefono)) {
				return false;
			}
			return Regex::IsMatch(telefono->Trim(), "^\\+?[0-9]{7,15}$");
		}

		/*true si 'buscado' esta contenido en 'texto' (sin distinguir mayusculas); vacio coincide con todo*/
		static bool Contiene(String^ texto, String^ buscado) {
			if (String::IsNullOrWhiteSpace(buscado)) {
				return true;
			}
			if (texto == nullptr) {
				return false;
			}
			return texto->IndexOf(buscado->Trim(), StringComparison::OrdinalIgnoreCase) >= 0;
		}
	};
}
