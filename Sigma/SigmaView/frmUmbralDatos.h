#pragma once
#include "Utilidades.h"

namespace SigmaView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace SigmaController;
	using namespace SigmaModel;

	/// <summary>
	/// Umbrales y parámetros del sistema
	/// </summary>
	public ref class frmUmbralDatos : public System::Windows::Forms::Form
	{
	public:
		frmUmbralDatos(double activacion, double desactivacion, double critico, double limite, int modo)
		{
			InitializeComponent();
			this->txtActivacion->Text = Utilidades::FormatoDouble(activacion);
			this->txtDesactivacion->Text = Utilidades::FormatoDouble(desactivacion);
			this->txtCritico->Text = Utilidades::FormatoDouble(critico);
			this->txtLimite->Text = Utilidades::FormatoDouble(limite);
			this->cmbModo->SelectedIndex = modo;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmUmbralDatos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblActivacion;
	private: System::Windows::Forms::TextBox^ txtActivacion;
	private: System::Windows::Forms::Label^ lblDesactivacion;
	private: System::Windows::Forms::TextBox^ txtDesactivacion;
	private: System::Windows::Forms::Label^ lblCritico;
	private: System::Windows::Forms::TextBox^ txtCritico;
	private: System::Windows::Forms::Label^ lblLimite;
	private: System::Windows::Forms::TextBox^ txtLimite;
	private: System::Windows::Forms::Label^ lblModo;
	private: System::Windows::Forms::ComboBox^ cmbModo;
	private: System::Windows::Forms::Button^ btnGuardar;
	private: System::Windows::Forms::Button^ btnCancelar;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lblActivacion = (gcnew System::Windows::Forms::Label());
			this->txtActivacion = (gcnew System::Windows::Forms::TextBox());
			this->lblDesactivacion = (gcnew System::Windows::Forms::Label());
			this->txtDesactivacion = (gcnew System::Windows::Forms::TextBox());
			this->lblCritico = (gcnew System::Windows::Forms::Label());
			this->txtCritico = (gcnew System::Windows::Forms::TextBox());
			this->lblLimite = (gcnew System::Windows::Forms::Label());
			this->txtLimite = (gcnew System::Windows::Forms::TextBox());
			this->lblModo = (gcnew System::Windows::Forms::Label());
			this->cmbModo = (gcnew System::Windows::Forms::ComboBox());
			this->btnGuardar = (gcnew System::Windows::Forms::Button());
			this->btnCancelar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblActivacion
			// 
			this->lblActivacion->AutoSize = true;
			this->lblActivacion->Location = System::Drawing::Point(20, 23);
			this->lblActivacion->Name = L"lblActivacion";
			this->lblActivacion->Size = System::Drawing::Size(156, 13);
			this->lblActivacion->Text = L"Umbral de activación (ppm)";
			// 
			// txtActivacion
			// 
			this->txtActivacion->Location = System::Drawing::Point(210, 20);
			this->txtActivacion->Name = L"txtActivacion";
			this->txtActivacion->Size = System::Drawing::Size(250, 20);
			this->txtActivacion->TabIndex = 0;
			// 
			// lblDesactivacion
			// 
			this->lblDesactivacion->AutoSize = true;
			this->lblDesactivacion->Location = System::Drawing::Point(20, 57);
			this->lblDesactivacion->Name = L"lblDesactivacion";
			this->lblDesactivacion->Size = System::Drawing::Size(174, 13);
			this->lblDesactivacion->Text = L"Umbral de desactivación (ppm)";
			// 
			// txtDesactivacion
			// 
			this->txtDesactivacion->Location = System::Drawing::Point(210, 54);
			this->txtDesactivacion->Name = L"txtDesactivacion";
			this->txtDesactivacion->Size = System::Drawing::Size(250, 20);
			this->txtDesactivacion->TabIndex = 1;
			// 
			// lblCritico
			// 
			this->lblCritico->AutoSize = true;
			this->lblCritico->Location = System::Drawing::Point(20, 91);
			this->lblCritico->Name = L"lblCritico";
			this->lblCritico->Size = System::Drawing::Size(120, 13);
			this->lblCritico->Text = L"Umbral crítico (ppm)";
			// 
			// txtCritico
			// 
			this->txtCritico->Location = System::Drawing::Point(210, 88);
			this->txtCritico->Name = L"txtCritico";
			this->txtCritico->Size = System::Drawing::Size(250, 20);
			this->txtCritico->TabIndex = 2;
			// 
			// lblLimite
			// 
			this->lblLimite->AutoSize = true;
			this->lblLimite->Location = System::Drawing::Point(20, 125);
			this->lblLimite->Name = L"lblLimite";
			this->lblLimite->Size = System::Drawing::Size(180, 13);
			this->lblLimite->Text = L"Límite de exposición (ppm·min)";
			// 
			// txtLimite
			// 
			this->txtLimite->Location = System::Drawing::Point(210, 122);
			this->txtLimite->Name = L"txtLimite";
			this->txtLimite->Size = System::Drawing::Size(250, 20);
			this->txtLimite->TabIndex = 3;
			// 
			// lblModo
			// 
			this->lblModo->AutoSize = true;
			this->lblModo->Location = System::Drawing::Point(20, 159);
			this->lblModo->Name = L"lblModo";
			this->lblModo->Size = System::Drawing::Size(102, 13);
			this->lblModo->Text = L"Modo de operación";
			// 
			// cmbModo
			// 
			this->cmbModo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbModo->FormattingEnabled = true;
			this->cmbModo->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"REAL", L"SIMULACION"});
			this->cmbModo->Location = System::Drawing::Point(210, 156);
			this->cmbModo->Name = L"cmbModo";
			this->cmbModo->Size = System::Drawing::Size(250, 21);
			this->cmbModo->TabIndex = 4;
			// 
			// btnGuardar
			// 
			this->btnGuardar->Location = System::Drawing::Point(250, 200);
			this->btnGuardar->Name = L"btnGuardar";
			this->btnGuardar->Size = System::Drawing::Size(100, 30);
			this->btnGuardar->TabIndex = 5;
			this->btnGuardar->Text = L"Guardar";
			this->btnGuardar->UseVisualStyleBackColor = true;
			this->btnGuardar->Click += gcnew System::EventHandler(this, &frmUmbralDatos::btnGuardar_Click);
			// 
			// btnCancelar
			// 
			this->btnCancelar->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnCancelar->Location = System::Drawing::Point(360, 200);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(100, 30);
			this->btnCancelar->TabIndex = 6;
			this->btnCancelar->Text = L"Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = true;
			// 
			// frmUmbralDatos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AcceptButton = this->btnGuardar;
			this->CancelButton = this->btnCancelar;
			this->ClientSize = System::Drawing::Size(490, 250);
			this->Controls->Add(this->lblActivacion);
			this->Controls->Add(this->txtActivacion);
			this->Controls->Add(this->lblDesactivacion);
			this->Controls->Add(this->txtDesactivacion);
			this->Controls->Add(this->lblCritico);
			this->Controls->Add(this->txtCritico);
			this->Controls->Add(this->lblLimite);
			this->Controls->Add(this->txtLimite);
			this->Controls->Add(this->lblModo);
			this->Controls->Add(this->cmbModo);
			this->Controls->Add(this->btnGuardar);
			this->Controls->Add(this->btnCancelar);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"frmUmbralDatos";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Umbrales y parámetros del sistema";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		double GetActivacion() {
			double valor = 0.0;
			Utilidades::TryParseDouble(this->txtActivacion->Text, valor);
			return valor;
		}

		double GetDesactivacion() {
			double valor = 0.0;
			Utilidades::TryParseDouble(this->txtDesactivacion->Text, valor);
			return valor;
		}

		double GetCritico() {
			double valor = 0.0;
			Utilidades::TryParseDouble(this->txtCritico->Text, valor);
			return valor;
		}

		double GetLimite() {
			double valor = 0.0;
			Utilidades::TryParseDouble(this->txtLimite->Text, valor);
			return valor;
		}

		/*Posicion elegida en el desplegable (0 = primera opcion)*/
		int GetModoIndice() {
			return this->cmbModo->SelectedIndex;
		}

	private:
		void Avisar(String^ mensaje, Control^ control) {
			MessageBox::Show(mensaje, "Datos incompletos", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			control->Focus();
		}

	/*Valida que lo obligatorio este lleno y que los numeros sean numeros; recien ahi cierra*/
	private: System::Void btnGuardar_Click(System::Object^ sender, System::EventArgs^ e) {
			{
				double valor;
				if (!Utilidades::TryParseDouble(this->txtActivacion->Text, valor)) {
					Avisar("El campo 'Umbral de activación (ppm)' debe ser un número.", this->txtActivacion);
					return;
				}
			}
			{
				double valor;
				if (!Utilidades::TryParseDouble(this->txtDesactivacion->Text, valor)) {
					Avisar("El campo 'Umbral de desactivación (ppm)' debe ser un número.", this->txtDesactivacion);
					return;
				}
			}
			{
				double valor;
				if (!Utilidades::TryParseDouble(this->txtCritico->Text, valor)) {
					Avisar("El campo 'Umbral crítico (ppm)' debe ser un número.", this->txtCritico);
					return;
				}
			}
			{
				double valor;
				if (!Utilidades::TryParseDouble(this->txtLimite->Text, valor)) {
					Avisar("El campo 'Límite de exposición (ppm·min)' debe ser un número.", this->txtLimite);
					return;
				}
			}
			if (this->cmbModo->SelectedIndex < 0) {
				Avisar("Seleccione una opción en 'Modo de operación'.", this->cmbModo);
				return;
			}
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
		}
	};
}
