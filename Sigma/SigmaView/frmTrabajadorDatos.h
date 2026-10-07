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
	/// Datos del obrero
	/// </summary>
	public ref class frmTrabajadorDatos : public System::Windows::Forms::Form
	{
	public:
		frmTrabajadorDatos(String^ id, Trabajador^ trabajador)
		{
			InitializeComponent();
			this->Text = (trabajador == nullptr) ? "Nuevo obrero" : "Modificar obrero";
			this->txtId->Text = id;
			if (trabajador != nullptr) {
				this->txtNombre->Text = trabajador->GetNombre();
				this->txtIdRFID->Text = trabajador->GetIdRFID();
				this->txtCorreo->Text = trabajador->GetCorreo();
				this->txtTelefono->Text = trabajador->GetTelefono();
			}
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmTrabajadorDatos()
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
	private: System::Windows::Forms::Label^ lblIdRFID;
	private: System::Windows::Forms::TextBox^ txtIdRFID;
	private: System::Windows::Forms::Label^ lblCorreo;
	private: System::Windows::Forms::TextBox^ txtCorreo;
	private: System::Windows::Forms::Label^ lblTelefono;
	private: System::Windows::Forms::TextBox^ txtTelefono;
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
			this->lblIdRFID = (gcnew System::Windows::Forms::Label());
			this->txtIdRFID = (gcnew System::Windows::Forms::TextBox());
			this->lblCorreo = (gcnew System::Windows::Forms::Label());
			this->txtCorreo = (gcnew System::Windows::Forms::TextBox());
			this->lblTelefono = (gcnew System::Windows::Forms::Label());
			this->txtTelefono = (gcnew System::Windows::Forms::TextBox());
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
			// lblIdRFID
			// 
			this->lblIdRFID->AutoSize = true;
			this->lblIdRFID->Location = System::Drawing::Point(20, 91);
			this->lblIdRFID->Name = L"lblIdRFID";
			this->lblIdRFID->Size = System::Drawing::Size(42, 13);
			this->lblIdRFID->Text = L"ID RFID";
			// 
			// txtIdRFID
			// 
			this->txtIdRFID->Location = System::Drawing::Point(210, 88);
			this->txtIdRFID->Name = L"txtIdRFID";
			this->txtIdRFID->Size = System::Drawing::Size(250, 20);
			this->txtIdRFID->TabIndex = 2;
			// 
			// lblCorreo
			// 
			this->lblCorreo->AutoSize = true;
			this->lblCorreo->Location = System::Drawing::Point(20, 125);
			this->lblCorreo->Name = L"lblCorreo";
			this->lblCorreo->Size = System::Drawing::Size(36, 13);
			this->lblCorreo->Text = L"Correo";
			// 
			// txtCorreo
			// 
			this->txtCorreo->Location = System::Drawing::Point(210, 122);
			this->txtCorreo->Name = L"txtCorreo";
			this->txtCorreo->Size = System::Drawing::Size(250, 20);
			this->txtCorreo->TabIndex = 3;
			// 
			// lblTelefono
			// 
			this->lblTelefono->AutoSize = true;
			this->lblTelefono->Location = System::Drawing::Point(20, 159);
			this->lblTelefono->Name = L"lblTelefono";
			this->lblTelefono->Size = System::Drawing::Size(48, 13);
			this->lblTelefono->Text = L"Teléfono";
			// 
			// txtTelefono
			// 
			this->txtTelefono->Location = System::Drawing::Point(210, 156);
			this->txtTelefono->Name = L"txtTelefono";
			this->txtTelefono->Size = System::Drawing::Size(250, 20);
			this->txtTelefono->TabIndex = 4;
			// 
			// btnGuardar
			// 
			this->btnGuardar->Location = System::Drawing::Point(250, 200);
			this->btnGuardar->Name = L"btnGuardar";
			this->btnGuardar->Size = System::Drawing::Size(100, 30);
			this->btnGuardar->TabIndex = 5;
			this->btnGuardar->Text = L"Guardar";
			this->btnGuardar->UseVisualStyleBackColor = true;
			this->btnGuardar->Click += gcnew System::EventHandler(this, &frmTrabajadorDatos::btnGuardar_Click);
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
			// frmTrabajadorDatos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AcceptButton = this->btnGuardar;
			this->CancelButton = this->btnCancelar;
			this->ClientSize = System::Drawing::Size(490, 250);
			this->Controls->Add(this->lblId);
			this->Controls->Add(this->txtId);
			this->Controls->Add(this->lblNombre);
			this->Controls->Add(this->txtNombre);
			this->Controls->Add(this->lblIdRFID);
			this->Controls->Add(this->txtIdRFID);
			this->Controls->Add(this->lblCorreo);
			this->Controls->Add(this->txtCorreo);
			this->Controls->Add(this->lblTelefono);
			this->Controls->Add(this->txtTelefono);
			this->Controls->Add(this->btnGuardar);
			this->Controls->Add(this->btnCancelar);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"frmTrabajadorDatos";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Datos del obrero";
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

		String^ GetIdRFID() {
			return this->txtIdRFID->Text->Trim();
		}

		String^ GetCorreo() {
			return this->txtCorreo->Text->Trim();
		}

		String^ GetTelefono() {
			return this->txtTelefono->Text->Trim();
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
			if (String::IsNullOrWhiteSpace(this->txtIdRFID->Text)) {
				Avisar("El campo 'ID RFID' es obligatorio.", this->txtIdRFID);
				return;
			}
			if (String::IsNullOrWhiteSpace(this->txtCorreo->Text)) {
				Avisar("El campo 'Correo' es obligatorio.", this->txtCorreo);
				return;
			}
			if (String::IsNullOrWhiteSpace(this->txtTelefono->Text)) {
				Avisar("El campo 'Teléfono' es obligatorio.", this->txtTelefono);
				return;
			}
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
		}
	};
}
