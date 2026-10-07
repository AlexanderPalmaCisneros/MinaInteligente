#pragma once

namespace SigmaView {

	using namespace System;
	using namespace System::Globalization;
	using namespace System::Windows::Forms;

	/*Metodos sencillos que reutilizan todos los formularios de mantenimiento*/
	public ref class Utilidades abstract {
	public:
		/*Acepta punto o coma decimal; el archivo siempre usa punto decimal*/
		static bool TryParseDouble(String^ texto, double% valor) {
			if (String::IsNullOrWhiteSpace(texto)) {
				return false;
			}
			String^ normalizado = texto->Trim()->Replace(',', '.');
			return Double::TryParse(normalizado, NumberStyles::Float, CultureInfo::InvariantCulture, valor);
		}

		static String^ FormatoDouble(double valor) {
			return valor.ToString(CultureInfo::InvariantCulture);
		}

		static bool Confirmar(String^ mensaje) {
			return MessageBox::Show(mensaje, "Sigma", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == DialogResult::Yes;
		}

		static void Limpiar(array<TextBox^>^ cajas) {
			for each (TextBox ^ caja in cajas) {
				caja->Text = "";
			}
		}
	};
}
