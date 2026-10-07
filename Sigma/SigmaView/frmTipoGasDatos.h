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
	/// Datos del tipo de gas
	/// </summary>
	public ref class frmTipoGasDatos : public System::Windows::Forms::Form
	{
	public:
		frmTipoGasDatos(String^ id, TipoGas^ tipoGas)
		{
			InitializeComponent();
			this->Text = (tipoGas == nullptr) ? "Nuevo tipo de gas" : "Modificar tipo de gas";
			this->txtId->Text = id;
			this->txtGeneracion->Text = "0";
			if (tipoGas != nullptr) {
				this->txtNombre->Text = tipoGas->GetNombre();
				this->txtSimbolo->Text = tipoGas->GetSimbolo();
				this->txtGeneracion->Text = Utilidades::FormatoDouble(tipoGas->GetGeneracionGasDefault());
			}
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmTipoGasDatos()
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
	private: System::Windows::Forms::Label^ lblSimbolo;
	private: System::Windows::Forms::TextBox^ txtSimbolo;
	private: System::Windows::Forms::Label^ lblGeneracion;
	private: System::Windows::Forms::TextBox^ txtGeneracion;
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
			this->lblSimbolo = (gcnew System::Windows::Forms::Label());
			this->txtSimbolo = (gcnew System::Windows::Forms::TextBox());
			this->lblGeneracion = (gcnew System::Windows::Forms::Label());
			this->txtGeneracion = (gcnew System::Windows::Forms::TextBox());
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
			// lblSimbolo
			// 
			this->lblSimbolo->AutoSize = true;
			this->lblSimbolo->Location = System::Drawing::Point(20, 91);
			this->lblSimbolo->Name = L"lblSimbolo";
			this->lblSimbolo->Size = System::Drawing::Size(102, 13);
			this->lblSimbolo->Text = L"Símbolo (ej. CH4)";
			// 
			// txtSimbolo
			// 
			this->txtSimbolo->Location = System::Drawing::Point(210, 88);
			this->txtSimbolo->Name = L"txtSimbolo";
			this->txtSimbolo->Size = System::Drawing::Size(250, 20);
			this->txtSimbolo->TabIndex = 2;
			// 
			// lblGeneracion
			// 
			this->lblGeneracion->AutoSize = true;
			this->lblGeneracion->Location = System::Drawing::Point(20, 125);
			this->lblGeneracion->Name = L"lblGeneracion";
			this->lblGeneracion->Size = System::Drawing::Size(132, 13);
			this->lblGeneracion->Text = L"Generación por defecto";
			// 
			// txtGeneracion
			// 
			this->txtGeneracion->Location = System::Drawing::Point(210, 122);
			this->txtGeneracion->Name = L"txtGeneracion";
			this->txtGeneracion->Size = System::Drawing::Size(250, 20);
			this->txtGeneracion->TabIndex = 3;
			// 
			// btnGuardar
			// 
			this->btnGuardar->Location = System::Drawing::Point(250, 166);
			this->btnGuardar->Name = L"btnGuardar";
			this->btnGuardar->Size = System::Drawing::Size(100, 30);
			this->btnGuardar->TabIndex = 4;
			this->btnGuardar->Text = L"Guardar";
			this->btnGuardar->UseVisualStyleBackColor = true;
			this->btnGuardar->Click += gcnew System::EventHandler(this, &frmTipoGasDatos::btnGuardar_Click);
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
			// frmTipoGasDatos
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
			this->Controls->Add(this->lblSimbolo);
			this->Controls->Add(this->txtSimbolo);
			this->Controls->Add(this->lblGeneracion);
			this->Controls->Add(this->txtGeneracion);
			this->Controls->Add(this->btnGuardar);
			this->Controls->Add(this->btnCancelar);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"frmTipoGasDatos";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Datos del tipo de gas";
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

		String^ GetSimbolo() {
			return this->txtSimbolo->Text->Trim();
		}

		double GetGeneracion() {
			double valor = 0.0;
			Utilidades::TryParseDouble(this->txtGeneracion->Text, valor);
			return valor;
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
			if (String::IsNullOrWhiteSpace(this->txtSimbolo->Text)) {
				Avisar("El campo 'Símbolo' es obligatorio.", this->txtSimbolo);
				return;
			}
			{
				double valor;
				if (!Utilidades::TryParseDouble(this->txtGeneracion->Text, valor)) {
					Avisar("El campo 'Generación por defecto' debe ser un número.", this->txtGeneracion);
					return;
				}
			}
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
		}
	};
}
