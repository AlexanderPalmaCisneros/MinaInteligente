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
	/// Datos de la zona
	/// </summary>
	public ref class frmZonaDatos : public System::Windows::Forms::Form
	{
	public:
		frmZonaDatos(String^ id, Zona^ zona)
		{
			InitializeComponent();
			this->Text = (zona == nullptr) ? "Nueva zona" : "Modificar zona";
			this->txtId->Text = id;
			if (zona != nullptr) {
				this->txtNombre->Text = zona->GetNombre();
				this->txtVolumen->Text = Utilidades::FormatoDouble(zona->GetVolumen());
				this->chkEsZonaSalida->Checked = zona->GetEsZonaSalida();
			}
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmZonaDatos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblId;
	private: System::Windows::Forms::TextBox^ txtId;
	private: System::Windows::Forms::Label^ lblNombre;
	private: System::Windows::Forms::TextBox^ txtNombre;
	private: System::Windows::Forms::Label^ lblVolumen;
	private: System::Windows::Forms::TextBox^ txtVolumen;
	private: System::Windows::Forms::Label^ lblEsZonaSalida;
	private: System::Windows::Forms::CheckBox^ chkEsZonaSalida;
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
			this->lblId = (gcnew System::Windows::Forms::Label());
			this->txtId = (gcnew System::Windows::Forms::TextBox());
			this->lblNombre = (gcnew System::Windows::Forms::Label());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->lblVolumen = (gcnew System::Windows::Forms::Label());
			this->txtVolumen = (gcnew System::Windows::Forms::TextBox());
			this->lblEsZonaSalida = (gcnew System::Windows::Forms::Label());
			this->chkEsZonaSalida = (gcnew System::Windows::Forms::CheckBox());
			this->btnGuardar = (gcnew System::Windows::Forms::Button());
			this->btnCancelar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblId
			// 
			this->lblId->AutoSize = true;
			this->lblId->Location = System::Drawing::Point(20, 23);
			this->lblId->Name = L"lblId";
			this->lblId->Size = System::Drawing::Size(12, 13);
			this->lblId->Text = L"Id";
			// 
			// txtId
			// 
			this->txtId->Location = System::Drawing::Point(210, 20);
			this->txtId->Name = L"txtId";
			this->txtId->ReadOnly = true;
			this->txtId->Size = System::Drawing::Size(250, 20);
			this->txtId->TabIndex = 0;
			this->txtId->TabStop = false;
			// 
			// lblNombre
			// 
			this->lblNombre->AutoSize = true;
			this->lblNombre->Location = System::Drawing::Point(20, 57);
			this->lblNombre->Name = L"lblNombre";
			this->lblNombre->Size = System::Drawing::Size(36, 13);
			this->lblNombre->Text = L"Nombre";
			// 
			// txtNombre
			// 
			this->txtNombre->Location = System::Drawing::Point(210, 54);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(250, 20);
			this->txtNombre->TabIndex = 1;
			// 
			// lblVolumen
			// 
			this->lblVolumen->AutoSize = true;
			this->lblVolumen->Location = System::Drawing::Point(20, 91);
			this->lblVolumen->Name = L"lblVolumen";
			this->lblVolumen->Size = System::Drawing::Size(72, 13);
			this->lblVolumen->Text = L"Volumen (m3)";
			// 
			// txtVolumen
			// 
			this->txtVolumen->Location = System::Drawing::Point(210, 88);
			this->txtVolumen->Name = L"txtVolumen";
			this->txtVolumen->Size = System::Drawing::Size(250, 20);
			this->txtVolumen->TabIndex = 2;
			// 
			// lblEsZonaSalida
			// 
			this->lblEsZonaSalida->AutoSize = true;
			this->lblEsZonaSalida->Location = System::Drawing::Point(20, 125);
			this->lblEsZonaSalida->Name = L"lblEsZonaSalida";
			this->lblEsZonaSalida->Size = System::Drawing::Size(84, 13);
			this->lblEsZonaSalida->Text = L"Zona de salida";
			// 
			// chkEsZonaSalida
			// 
			this->chkEsZonaSalida->AutoSize = true;
			this->chkEsZonaSalida->Location = System::Drawing::Point(210, 124);
			this->chkEsZonaSalida->Name = L"chkEsZonaSalida";
			this->chkEsZonaSalida->Size = System::Drawing::Size(15, 14);
			this->chkEsZonaSalida->TabIndex = 3;
			this->chkEsZonaSalida->Text = L"";
			this->chkEsZonaSalida->UseVisualStyleBackColor = true;
			// 
			// btnGuardar
			// 
			this->btnGuardar->Location = System::Drawing::Point(250, 166);
			this->btnGuardar->Name = L"btnGuardar";
			this->btnGuardar->Size = System::Drawing::Size(100, 30);
			this->btnGuardar->TabIndex = 4;
			this->btnGuardar->Text = L"Guardar";
			this->btnGuardar->UseVisualStyleBackColor = true;
			this->btnGuardar->Click += gcnew System::EventHandler(this, &frmZonaDatos::btnGuardar_Click);
			// 
			// btnCancelar
			// 
			this->btnCancelar->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnCancelar->Location = System::Drawing::Point(360, 166);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(100, 30);
			this->btnCancelar->TabIndex = 5;
			this->btnCancelar->Text = L"Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = true;
			// 
			// frmZonaDatos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AcceptButton = this->btnGuardar;
			this->CancelButton = this->btnCancelar;
			this->ClientSize = System::Drawing::Size(490, 216);
			this->Controls->Add(this->lblId);
			this->Controls->Add(this->txtId);
			this->Controls->Add(this->lblNombre);
			this->Controls->Add(this->txtNombre);
			this->Controls->Add(this->lblVolumen);
			this->Controls->Add(this->txtVolumen);
			this->Controls->Add(this->lblEsZonaSalida);
			this->Controls->Add(this->chkEsZonaSalida);
			this->Controls->Add(this->btnGuardar);
			this->Controls->Add(this->btnCancelar);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"frmZonaDatos";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Datos de la zona";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		String^ GetId() {
			return this->txtId->Text->Trim();
		}

		String^ GetNombre() {
			return this->txtNombre->Text->Trim();
		}

		double GetVolumen() {
			double valor = 0.0;
			Utilidades::TryParseDouble(this->txtVolumen->Text, valor);
			return valor;
		}

		bool GetEsZonaSalida() {
			return this->chkEsZonaSalida->Checked;
		}

	private:
		void Avisar(String^ mensaje, Control^ control) {
			MessageBox::Show(mensaje, "Datos incompletos", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			control->Focus();
		}

	/*Valida que lo obligatorio este lleno y que los numeros sean numeros; recien ahi cierra*/
	private: System::Void btnGuardar_Click(System::Object^ sender, System::EventArgs^ e) {
			if (String::IsNullOrWhiteSpace(this->txtNombre->Text)) {
				Avisar("El campo 'Nombre' es obligatorio.", this->txtNombre);
				return;
			}
			{
				double valor;
				if (!Utilidades::TryParseDouble(this->txtVolumen->Text, valor)) {
					Avisar("El campo 'Volumen (m3)' debe ser un número.", this->txtVolumen);
					return;
				}
			}
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
		}
	};
}
